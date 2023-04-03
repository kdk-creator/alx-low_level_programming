#include "lists.h"
/**
 * listint_len - to return the number of elements in linked list
 * @h: linked list of types listint_t
 * Return: the numbers of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
		num++;
	h = h->next;
	return (num);
}
