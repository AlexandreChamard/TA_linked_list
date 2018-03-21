/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

int main(void)
{
	list_t list = LIST_INITIALIZER;
	size_t i = 0;

	for (; arr[i] != -1; ++i) {
		push_back(&list, arr[i]);
	}
	assert(list.size == i);
	i = 0;
	while (list.size != 0) {
		printf("access node n°%ld\n", i);
		assert(list.front->data == arr[i++]);
		assert(list.front->prev == NULL);
		pop_front(&list);
	}
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);
	return (0);
}
