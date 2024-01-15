#include "sort.h"
#include <stddef.h>
#include <stdio.h>

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
	size_t a, b;
	int store_temporary;

	/* check if array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return; /* stop cuz there's nothing to sort */

	/* go through array from 0 to size - 1 (before '\0') */
	for (a = 0; a < size - 1; a++)
		/* go through array again from 0 to size - 1 (before '\0') */
		for (b = 0; b < size - 1; b++)
			/* if current element is greater than next element */
			if (array[b] > array[b + 1])
			{
				store_temporary = array[b + 1];
				array[b + 1] = array[b];
				array[b] = store_temporary;
				/* print array every time we swap */
				print_array(array, size);
			}
    /* ----------- Example ------------ */
    /* array[0] > array[1] */
    /* array[0] = 13, array[1] = 7 */
    /* store_temporary = 13 */
    /* array[0] = 7 */
    /* array[1] = 13 */
}
