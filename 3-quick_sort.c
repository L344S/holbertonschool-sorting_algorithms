#include "sort.h"

/**
 * swap - Swaps two elements in an integer array.
 * @array: Pointer to the integer array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @size: Size of the array.
 *
 * Description: This function swaps two elements in the given integer array
 *              and prints the updated array after the swap.
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * partition_array - Partitions an integer array for Quick Sort.
 * @array: Pointer to the integer array to be partitioned.
 * @start: Starting index of the range to be partitioned.
 * @end: Ending index of the range to be partitioned.
 * @size: Size of the array.
 *
 * Return: The final index of the pivot.
 *
 * Description: This function partitions the given array using the Quick Sort
 *              algorithm. It selects the last element as the pivot, places it
 *              at its correct position in the sorted array, and places all
 *              smaller elements to the left and larger elements to the right.
 */
int partition_array(int *array, int start, int end, size_t size)
{
	int i, pivot = array[end];

	for (i = start; i <= end; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, start, i, size);
			start++;
		}
	}

	swap(array, start, end, size);
	return (start);
}

/**
 * recursive_quick_sort - Recursively sorts an integer array using Quick Sort.
 * @array: Pointer to the integer array to be sorted.
 * @start: Starting index of the array or partition to be sorted.
 * @end: Ending index of the array or partition to be sorted.
 * @size: Size of the array.
 *
 * Description: This function recursively applies the Quick Sort algorithm to
 *              sort the array or partition. It selects a pivot, partitions the
 *              array, and recursively sorts the sub-arrays on both sides of
 *              the pivot until the entire array is sorted.
 */
void recursive_quick_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
		return;

	pivot = partition_array(array, start, end, size);
	recursive_quick_sort(array, start, pivot - 1, size);
	recursive_quick_sort(array, pivot + 1, end, size);
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Quick Sort algorithm. If the array is empty or has
 *              only one element, no action is taken.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}
