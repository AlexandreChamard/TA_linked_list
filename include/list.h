/*
** EPITECH PROJECT, 2017
** list.h for lists
** File description:
** description
*/

#pragma once

#include <stddef.h>

#define LIST_INITIALIZER {NULL, NULL, 0}
#define NEXT(elem) (elem != NULL ? elem->next : NULL)
#define PREV(elem) (elem != NULL ? elem->prev : NULL)

typedef struct list_elem {
	void			*data;
	struct list_elem	*prev;
	struct list_elem	*next;
}	elem_t;

typedef struct {
	elem_t *front;
	elem_t *back;
	size_t size;
}	list_t;

void	*push_front(list_t list[static 1], void *data);
void	*push_back(list_t list[static 1], void *data);
void	pop_front(list_t list[static 1]);
void	pop_back(list_t list[static 1]);
void	clear(list_t list[static 1]);
