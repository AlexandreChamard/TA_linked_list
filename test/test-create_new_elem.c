/*
** EPITECH PROJECT, 2017
** test-init_new_page.c for PSU_2017_malloc
** File description:
** description
*/

#include <stdlib.h>
#include "test.h"

static int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

int main(void)
{
	for (size_t i = 0; arr[i] != -1; i++) {
		elem_t *elem = create_new_elem(arr[i]);
		assert(elem != NULL);
		assert(elem->next == NULL);
		assert(elem->prev == NULL);
		assert(elem->data == arr[i]);
		free(elem);
	}
	return (0);
}
