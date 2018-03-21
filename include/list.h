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

bool	push_front(list_t *list, int data);
bool	push_back(list_t *list, int data);
void	pop_front(list_t *list);
void	pop_back(list_t *list);
void	clear(list_t *list);

void foreach(list_t *list, void (*)(int *));
void remove_if(list_t *list, bool (*)(int));
void sort(list_t *list, int (*)(int, int));
void reverse(list_t *list);
