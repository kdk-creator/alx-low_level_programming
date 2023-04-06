#include "lists.h"
/**
 * pop_listint - it deletes the head of a link list
 * @head: ponits to the frist element in the link
 * Return: the data in the elements that was being deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);
	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
