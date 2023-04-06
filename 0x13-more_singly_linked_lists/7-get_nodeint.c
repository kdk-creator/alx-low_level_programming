#include "lists.h"
/**
 * get_nodeint_at_index - this returns the node at a particular index
 * @head: the first node in the linked list
 * @index: index of the node to be return
 * Return: pointer to the node we want
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x = 0;
	listint_t *temp = head;

	while (temp && x < index)
	{
		temp = temp->next;
		x++;
	}
	return (temp ? temp : NULL);
}
