#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function in C that checks if a singly linked list has
 *  a cycle in it
 * @list: head of singly linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{

	listint_t *tortoise, *hare;

	if (!list)
		return (0);

	tortoise = list;
	hare = list;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (hare == tortoise)
			return (1);
	}

	return (0);
}
