/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include "test.h"

static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

static int nb_call = 0;
static int res = 0;

static void print_int(int *nb)
{
	++nb_call;
	printf("%i\n", *nb);
	res += *nb;
}

static void double_int(int *nb)
{
	++nb_call;
	printf("%d -> %d\n", *nb, (*nb) * 2);
	*nb *= 2;
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

	puts("\nprint foreach");
	foreach(&list, print_int);
	assert(nb_call == 10);
	assert(res == 1+2+3+4+5+6+7+8+9);

	puts("\ndouble int foreach");
	foreach(&list, double_int);
	assert(nb_call == 20);

	puts("\nprint foreach");
	res = 0;
	foreach(&list, print_int);
	assert(nb_call == 30);
	assert(res == (1+2+3+4+5+6+7+8+9) * 2);

	puts("\npop front");
	pop_front(&list);
	puts("pop back");
	pop_back(&list);

	puts("\nprint foreach");
	res = 0;
	foreach(&list, print_int);
	assert(nb_call == 38);
	assert(res == (1+2+3+4+5+6+7+8) * 2);

	puts("clear");
	clear_list(&list);
	assert(list.size == 0);
	assert(list.front == NULL);
	assert(list.back == NULL);
	return (0);
}
