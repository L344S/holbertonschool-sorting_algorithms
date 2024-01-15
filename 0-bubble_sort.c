#include "sort.h"

/**
* bubble_sort - entry point
* @array: array to sort
* @size: size of array
*
* ------------- Description --------------
* Sorts an array of integers in ascending order
*
* Return: nothing (void)
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b, store_temporary;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				store_temporary = array[b];
				array[b] = array[b + 1];
				array[b + 1] = store_temporary;
				print_array(array, size);
			}
		}
	}
}
