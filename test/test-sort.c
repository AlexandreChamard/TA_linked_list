/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static const int ref_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
static const int ref_rev_arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

static int nb_call = 0;

static int sort_int(int a, int b)
{
	++nb_call;
	return a - b;
}

static int rev_sort_int(int a, int b)
{
	++nb_call;
	return b - a;
}

static void verif_sorted(list_t *list, const int *arr)
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

	puts("\nsort an sorted list");
	sort(&list, sort_int);
	verif_sorted(&list, ref_arr);

	puts("\nreverse sort");
	sort(&list, rev_sort_int);
	verif_sorted(&list, ref_rev_arr);

	puts("\nsort");
	sort(&list, sort_int);
	verif_sorted(&list, ref_arr);

	puts("\nclear");
	clear(&list);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);

	puts("\nsort empty list");
	sort(&list, sort_int);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);

	return (0);
}
