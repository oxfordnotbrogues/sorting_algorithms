#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int largest, j;

	for (largest = array[0], j = 1; j < size; j++)
	{
		if (array[j] > largest)
			largest = array[j];
	}

	return (largest);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *increase, *sorted, largest, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	largest = get_max(array, size);
	increase = malloc(sizeof(int) * (largest + 1));
	if (increase == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (largest + 1); j++)
		increase[j] = 0;
	for (j = 0; j < (int)size; j++)
		increase[array[j]] += 1;
	for (j = 0; j < (largest + 1); j++)
		increase[j] += increase[j - 1];
	print_array(increase, largest + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[increase[array[j]] - 1] = array[j];
		increase[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(increase);
}
