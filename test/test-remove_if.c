/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

static int nb_call = 0;
static int nb_match = 0;

static bool sup_5(int nb)
{
	++nb_call;
	if (nb > 5) {
		++nb_match;
		printf("elem %d match.\n", nb);
	} else {
		printf("elem %d doesn't match.\n", nb);
	}
	return (nb > 5);
}

static bool egal_8(int nb)
{
	++nb_call;
	if (nb == 8) {
		++nb_match;
		printf("elem %d match.\n", nb);
	} else {
		printf("elem %d doesn't match.\n", nb);
	}
	return (nb == 8);
}

static bool match_all(int __attribute((unused)) nb)
{
	++nb_call;
	++nb_match;
	printf("elem %d match.\n", nb);
	return (true);
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

	puts("\nremove_if == 8");
	nb_call = 0;
	nb_match = 0;
	remove_if(&list, egal_8);
	assert(nb_call >= 10);
	assert(nb_match == 1);
	assert(list.size == 9);

	puts("\nremove_if > 5");
	nb_call = 0;
	nb_match = 0;
	remove_if(&list, sup_5);
	assert(nb_call >= 9);
	assert(nb_match == 3);
	assert(list.size == 6);

	puts("\nremove_if == 8");
	nb_call = 0;
	nb_match = 0;
	remove_if(&list, egal_8);
	assert(nb_call >= 6);
	assert(nb_match == 0);
	assert(list.size == 6);

	puts("\nremove_if all");
	nb_call = 0;
	nb_match = 0;
	remove_if(&list, match_all);
	assert(nb_call >= 6);
	assert(nb_match == 6);
	assert(list.size == 0);

	puts("\nremove_if == 8");
	nb_call = 0;
	nb_match = 0;
	remove_if(&list, egal_8);
	assert(nb_call == 0);
	assert(nb_match == 0);
	assert(list.size == 0);

	puts("\nclear");
	clear_list(&list);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);
	return (0);
}
