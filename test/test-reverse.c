/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static const int ref_arr[] = {6, 1, 2, 5, 4, 3, 6, 97, 8, 9, -1};
static const int ref_rev_arr[] = {9, 8, 97, 6, 3, 4, 5, 2, 1, 6, -1};
static int arr[] = {6, 1, 2, 5, 4, 3, 6, 97, 8, 9, -1};

static void verif_reverse(list_t *list, const int *arr)
{
	assert(list->size == 10);
	assert(list->front != NULL);
	assert(list->back != NULL);

	size_t i = 0;
	elem_t *elem = list->front;
	while (elem != NULL) {
		printf("elem n°%ld: expected: %d\tget: %d\n", i, arr[i], elem->data);
		assert(elem->data == arr[i]);
		elem = NEXT(elem);
		i++;
	}
}

int main(void)
{
	list_t list = LIST_INITIALIZER;
	size_t i = 0;

	for (; arr[i] != -1; ++i) {
		printf("push elem: %d\n", arr[i]);
		push_back(&list, arr[i]);
	}
	assert(list.size == i);

	puts("\nverif list");
	verif_reverse(&list, ref_arr);

	puts("\nreverse list");
	reverse(&list);
	verif_reverse(&list, ref_rev_arr);

	puts("\nre-reverse list");
	reverse(&list);
	verif_reverse(&list, ref_arr);

	puts("\nre-reverse another time");
	reverse(&list);
	verif_reverse(&list, ref_rev_arr);

	puts("\nclear");
	clear(&list);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);

	puts("\nreverse empty list");
	reverse(&list);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);

	return (0);
}
