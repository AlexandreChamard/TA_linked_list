/*
** EPITECH PROJECT, 2017
** list.h for lists
** File description:
** description
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#define LIST_INITIALIZER {NULL, NULL, 0}
#define NEXT(elem) (elem != NULL ? elem->next : NULL)
#define PREV(elem) (elem != NULL ? elem->prev : NULL)

typedef struct list_elem {
	int			data;
	struct list_elem	*prev;
	struct list_elem	*next;
}	elem_t;

typedef struct {
	elem_t *front;
	elem_t *back;
	size_t size;
}	list_t;

bool	push_front(list_t list[static 1], int data);
bool	push_back(list_t list[static 1], int data);
void	pop_front(list_t list[static 1]);
void	pop_back(list_t list[static 1]);
void	clear(list_t list[static 1]);

void foreach(list_t list[static 1], void (*)(elem_t *));
void remove_if(list_t list[static 1], bool (*)(int));
void sort(list_t list[static 1], int (*)(int, int));
