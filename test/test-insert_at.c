/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
static int arr_to_insert[] = {5, 7, 2, 0, 4, 9, 8, 6, 1, 3, -1};

int main(void)
{
	list_t list = LIST_INITIALIZER;
	size_t i = 10;
	size_t size_array = 10;


	printf("insert %d at %d\n", arr_to_insert[0], 5);
	insert_at(&list, 5, arr_to_insert[0]);
	printf("insert %d at %d\n", arr_to_insert[1], 1);
	insert_at(&list, 1, arr_to_insert[1]);
	printf("insert %d at %d\n", arr_to_insert[2], 0);
	insert_at(&list, 0, arr_to_insert[2]);
	printf("insert %d at %d\n", arr_to_insert[3], 0);
	insert_at(&list, 0, arr_to_insert[3]);
	printf("insert %d at %d\n", arr_to_insert[4], 2);
	insert_at(&list, 2, arr_to_insert[4]);
	printf("insert %d at %d\n", arr_to_insert[5], 9);
	insert_at(&list, 9, arr_to_insert[5]);
	printf("insert %d at %d\n", arr_to_insert[6], 5);
	insert_at(&list, 5, arr_to_insert[6]);
	printf("insert %d at %d\n", arr_to_insert[7], 4);
	insert_at(&list, 4, arr_to_insert[7]);
	printf("insert %d at %d\n", arr_to_insert[8], 1);
	insert_at(&list, 1, arr_to_insert[8]);
	printf("insert %d at %d\n", arr_to_insert[9], 3);
	insert_at(&list, 3, arr_to_insert[9]);

	assert(list.size == i);
	elem_t *elem = list.front;
	puts("\nfront -> back:");
	for (; i > 0; --i) {
		printf("access elem n°%ld\n", size_array - i);
		printf("expected: %d\n", arr[size_array - i]);
		printf("result: %d\n", elem->data);
		assert(elem != NULL);
		assert(elem->data == arr[size_array - i]);
		assert(elem->data == arr[size_array - i]);
		elem = NEXT(elem);
	}
	elem = list.back;
	puts("\nback -> front:");
	for (size_t i = 0; arr[i] != -1; ++i) {
		printf("access elem n°%ld\n", i);
		printf("expected: %d\n", arr[size_array - i - 1]);
		printf("result: %d\n", elem->data);
		assert(elem != NULL);
		assert(elem->data == arr[size_array - i - 1]);
		assert(elem->data == arr[size_array - i - 1]);
		elem = PREV(elem);
	}
	return (0);
}
