#include "sort.h"

/**
* selection_sort - entry point
* @array: array to sort
* @size: size of array
*
* ------------- Description --------------
* Sorts an array of integers in ascending order
*
* Return: nothing (void)
*/
void selection_sort(int *array, size_t size)
{
	size_t current, next, smallest;
	int store_temporary; /* store temporary value */

	/* check if array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return; /* stop cuz there's nothing to sort */

	/* go through array from 0 to end of array */
	for (current = 0; current < size - 1; current++) /* ex : 19, 48 .. */
	{
		/* smallest will be use to store the smallest element, init to current */
		smallest = current;
		/* iterate through array from current + 1 (le reste du tableau) */
		for (next = current + 1; next < size; next++)
			/* if next element is smaller than smallest element */
			if (array[next] < array[smallest]) /* ex : if 7 < 19 */
				smallest = next; /* update small index to next element cuz it's smaller*/
		/* if the current element is not the smallest element */
		if (current != smallest)
		{
			store_temporary = array[current]; /* store current element */
			array[current] = array[smallest]; /* swap current element with smallest */
			array[smallest] = store_temporary; /* swap smallest element with current */
			print_array(array, size); /* print array every time we swap */
		}
	}
	/* ----------- Example ------------ */
	/* array = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7} */
	/* smallest = 0 cuz array[0] = 19 and his index is 0 */
	/* next = 1 */
	/* until array[next] is smaller than array[smallest] */
	/* if array[next] : 7 < array[smallest] : 19 */
	/* smallest was 0, now smallest = 9 cuz index of 7 is 9 */
    /* if current != smallest -> 0 != 9 */
    /* ---------------- swap ---------------- */
    /* store_temporary = array[current] = 19 */
    /* array[current] = array[smallest] = 7 */
    /* array[smallest] = store_temporary = 19 */
    /* print : array = {7, 48, 99, 71, 13, 52, 96, 73, 86, 19} */
}
