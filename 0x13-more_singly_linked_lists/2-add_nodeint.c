#include "lists.h"
/**
 * add_nodeint - adds a new node at the starting of as linked list
 * @n: the data to insert in the new node
 * @head: points to the first node in the list
 * Return: pointer to a new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
