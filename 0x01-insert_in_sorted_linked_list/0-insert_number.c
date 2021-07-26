#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts new node to linked list
 * @head: head of singly linked list
 * @number: value in singly linked list
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *aux1 = *head, *aux2;

	if (!head) return (NULL);
	node = malloc(sizeof(listint_t));
	if (!node) return (NULL);

	node->n = number;
	if (!aux1 || aux1->n >= number)
	{
		node->next = aux1;
		*head = node;
		return (node);
	}

	aux2 = aux1->next;
	while (aux1 && aux2 && (aux2->n < number))
	{
		aux1 = aux1->next, aux2 = aux1->next;
	}

	aux1->next = node, node->next = aux2;
	return (node);
}
