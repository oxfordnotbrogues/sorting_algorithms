#include <stdio.h>
#include "sort.h"
#include <stdbool.h>
/**
 * swap_ints - a function that swaps integers
 * @a: the first integer
 * @b: the second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: an array of integers to sort
 * @size: the size of the array
 * Description: prints the array after eachswap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;
	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}

		}
		len--;
	}
}
