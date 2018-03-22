/*
** EPITECH PROJECT, 2017
** list.c for lists
** File description:
** description
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

void init_list(list_t *list)
{
	memset(list, 0, sizeof(*list));
}

elem_t *create_new_elem(int nb)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL) {
		return (false);
	}
	memset(elem, 0, sizeof(*elem));
	elem->data = nb;
	return (elem);
}

bool	push_front(list_t *list, int data)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL) {
		return (false);
	}
	if (list->size == 0) {
		list->front = elem;
		list->back = elem;
	} else {
		list->front->prev = elem;
		elem->next = list->front;
		list->front = elem;
	}
	++list->size;
	return (true);
}

bool	push_back(list_t *list, int data)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL) {
		return (false);
	}
	if (list->size == 0) {
		list->front = elem;
		list->back = elem;
	} else {
		list->back->next = elem;
		elem->prev = list->back;
		list->back = elem;
	}
	++list->size;
	return (true);
}

bool	insert_at(list_t *list, size_t at, int data)
{
	elem_t *elem = list->front;
	elem_t *new_elem = create_new_elem(data);

	if (new_elem == NULL) {
		return (false);
	}
	if (list->size == 0) {
		list->front = new_elem;
		list->back = new_elem;
		++list->size;
	} else if (at >= list->size) {
		push_back(list, data);
	} else if (at == 0){
		push_front(list, data);
	} else {
		for (size_t i = 0; i < at; i++) {
			elem = NEXT(elem);
		}
		if (elem != NULL) {
			new_elem->prev = elem->prev;
			new_elem->next = elem;
			elem->prev->next = new_elem;
			elem->prev = new_elem;
			++list->size;
		}
	}
	return (true);
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
		list->back->next = NULL;
	} else {
		list->front = NULL;
	}
	free(elem);
}

void	remove_at(list_t *list, size_t at)
{
	if (at >= list->size) {
		return;
	}

	elem_t *elem = list->front;

	for (size_t i = 0; i < at; i++) {
		elem = NEXT(elem);
	}
	if (elem != list->front) {
		elem->prev->next = elem->next;
	} else {
		list->front = elem->next;
	}
	if (elem != list->back) {
		elem->next->prev = elem->prev;
	} else {
		list->back = elem->prev;
	}
	--list->size;
	free(elem);
}

void	clear_list(list_t *list)
{
	while (list->size != 0) {
		pop_front(list);
	}
}

void foreach(list_t *list, void (*func)(int *))
{
	for (elem_t *elem = list->front; elem != NULL; elem = NEXT(elem)) {
		func(&elem->data);
	}
}

static elem_t *remove_elem(list_t *list, elem_t *elem)
{
	elem_t *to_free = elem;
	elem_t *next = elem->next ? elem->next : elem->prev;

	--list->size;
	if (elem->prev != NULL) {
		elem->prev->next = elem->next;
	}
	if (elem->next != NULL) {
		elem->next->prev = elem->prev;
	}
	if (list->front == elem) {
		list->front = list->front->next;
	}
	if (list->back == elem) {
		list->back = list->back->prev;
	}
	free(to_free);
	return (next);
}

void remove_if(list_t *list, bool (*func)(int))
{
	elem_t *elem = list->front;

	while (elem != NULL) {
		if (func(elem->data) == true) {
			elem = remove_elem(list, elem);
		} else {
			elem = NEXT(elem);
		}
	}
}

void sort_list(list_t *list, int (*func)(int, int))
{
	elem_t *elem = NULL;
	bool sorted = false;
	int swap;

	if (list->size <= 1) {
		return;
	}
	while (sorted == false) {
		sorted = true;
		elem = list->front;
		while (elem->next != NULL) {
			if (func(elem->data, elem->next->data) > 0) {
				swap = elem->data;
				elem->data = elem->next->data;
				elem->next->data = swap;
				sorted = false;
			}
			elem = NEXT(elem);
		}
	}
}

void reverse_list(list_t *list)
{
	elem_t *first_elem = list->front;
	elem_t *second_elem = list->back;
	int swap;

	if (list->size <= 1) {
		return;
	}
	while (first_elem != second_elem) {
		swap = first_elem->data;
		first_elem->data = second_elem->data;
		second_elem->data = swap;
		first_elem = NEXT(first_elem);
		if (first_elem == second_elem) {
			break;
		}
		second_elem = PREV(second_elem);
	}
}
