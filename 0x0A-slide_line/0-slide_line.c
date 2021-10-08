#include <stddef.h>
#include "slide_line.h"


/**
 * merge - Performs move in  2048 Single Line Game
 *
 * @line: points to an array of integers containing size elements, that must be
 * slided & merged to the direction represented by direction
 * @move: Helps identify left or right move
 * @i: Current value of line beign checked
 * @start: First value of line left or right
 * @current: Current mergeable value
 * @current_idx: idx of current
 * @blank: how many spaces can a value move
 *
 * Return: No Return
 */
void merge(int *line, int move, int i, int start,
	int *current, int *current_idx, int *blank)
{

	if (line[i] == 0)
	{
		*blank += 1;
	}

	if (i == start && line[i] != 0)
	{
		*current = line[i];
		*current_idx = i;
	}

	if (line[i] != 0 && line[i] == *current && i != start)
	{
		line[*current_idx] += line[i];
		line[i] = 0;
		*current = 0;
		*blank += 1;
	}

	if (line[i] != 0 && *current != line[i] && i != start)
	{
		line[i - (*blank * move)] = line[i];
		*current = line[i];
		*current_idx = i - (*blank * move);
		if (*blank)
			line[i] = 0;
	}
}


/**
 * slide_line - slides and merges an array of integers
 *
 * @line: points to an array of integers containing size elements, that must be
 * slided & merged to the direction represented by direction
 * @size: Number of elements in line
 * @direction: Direction of merge SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{

	int i, move, current, current_idx, blank, start;
	int sizeX = (int) size;

	if (!line || (direction != 0 && direction != 1))
		return (0);

	current = 0;
	blank = 0;

	if (direction == 0)
		move = 1;
	else
		move = -1;

	if (direction == 0)
	{
		for (i = start = current_idx =  0; i < sizeX; i++)
		{
			merge(line, move, i, start,
				&current, &current_idx, &blank);

		}
	}
	else
	{
		for (i = start = current_idx = sizeX - 1; i >= 0; i--)
		{
			merge(line, move, i, start,
				&current, &current_idx, &blank);
		}
	}
	return (1);
}
