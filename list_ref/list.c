/*
** EPITECH PROJECT, 2017
** list.c for lists
** File description:
** description
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

void	*push_front(list_t *list, void *data)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL) {
		return (NULL);
	}
	memset(elem, 0, sizeof(*elem));
	elem->data = data;
	if (list->size == 0) {
		list->front = elem;
		list->back = elem;
	} else {
		list->front->prev = elem;
		elem->next = list->front;
		list->front = elem;
	}
	++list->size;
	return (elem);
}

void	*push_back(list_t *list, void *data)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL) {
		return (NULL);
	}
	memset(elem, 0, sizeof(*elem));
	elem->data = data;
	if (list->size == 0) {
		list->front = elem;
		list->back = elem;
	} else {
		list->back->next = elem;
		elem->prev = list->back;
		list->back = elem;
	}
	++list->size;
	return (elem);
}

void	pop_front(list_t *list)
{
	if (list->size == 0) {
		return;
	}

	elem_t *elem = list->front;

	list->front = list->front->next;
	--list->size;
	if (list->size != 0) {
		list->front->prev = NULL;
	} else {
		list->back = NULL;
	}
	free(elem);
}

void	pop_back(list_t *list)
{
	if (list->size == 0) {
		return;
	}

	elem_t *elem = list->back;

	list->back = list->back->prev;
	--list->size;
	if (list->size != 0) {
		list->front->prev = NULL;
	} else {
		list->front = NULL;
	}
	free(elem);
}

void	clear(list_t *list)
{
	while (list->size != 0) {
		pop_front(list);
	}
}
