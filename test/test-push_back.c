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
	size_t size_array;

	for (; arr[i] != -1; ++i) {
		printf("push_back: %d\n", arr[i]);
		push_back(&list, arr[i]);
	}
	size_array = i;
	assert(list.size == i);
	elem_t *elem = list.front;
	puts("\nfront -> back:");
	for (size_t i = 0; arr[i] != -1; ++i) {
		printf("access elem n°%ld\n", i);
		printf("expected: %d\n", arr[i]);
		assert(elem != NULL);
		assert(elem->data == arr[i]);
		assert(elem->data == arr[i]);
		printf("result: %d\n", elem->data);
		elem = NEXT(elem);
	}
	elem = list.back;
	puts("\nback -> front:");
	for (size_t i = size_array - 1; (long)i >= 0; --i) {
		printf("access elem n°%ld\n", i);
		printf("expected: %d\n", arr[i]);
		assert(elem != NULL);
		assert(elem->data == arr[i]);
		assert(elem->data == arr[i]);
		printf("result: %d\n", elem->data);
		elem = PREV(elem);
	}
	return (0);
}
