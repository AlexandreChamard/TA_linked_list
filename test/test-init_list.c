/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

int main(void)
{
	list_t list;

	init_list(&list);
	assert(list.front == NULL);
	assert(list.back == NULL);
	assert(list.size == 0);
	return (0);
}
