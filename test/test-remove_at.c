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
	assert(list.back != NULL);
	assert(list.back->data == 9);
	printf("remove elem n°9\n");
	remove_at(&list, 9);
	assert(list.size == i - 1);
	assert(list.back != NULL);
	assert(list.back->data == 8);
	assert(list.front != NULL);
	assert(list.front->data == 0);
	printf("remove elem n°0\n");
	remove_at(&list, 0);
	assert(list.size == i - 2);
	assert(list.front != NULL);
	assert(list.front->data == 1);

	while (list.size != 3) {
		printf("remove elem n°3\n");
		remove_at(&list, 3);
	}
	assert(list.size == 3);
	assert(list.front != NULL);
	assert(list.back != NULL);

	printf("remove elem n°9\n");
	remove_at(&list, 9);
	printf("remove elem n°9\n");
	remove_at(&list, 9);
	printf("remove elem n°9\n");
	remove_at(&list, 9);
	assert(list.size == 3);
	assert(list.front != NULL);
	assert(list.back != NULL);

	printf("remove elem n°0\n");
	remove_at(&list, 0);
	printf("remove elem n°0\n");
	remove_at(&list, 0);
	printf("remove elem n°0\n");
	remove_at(&list, 0);

	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);
	return (0);
}
