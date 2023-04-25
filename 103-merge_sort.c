#include "sort.h"

/**
 * merge_subarray - Merge two subarrays of an array of integers.
 * @array: The array containing the two subarrays to merge.
 * @buffer: A buffer to store the sorted subarray.
 * @front: The index of the first element of the first subarray.
 * @mid: The index of the last element of the first subarray.
 * @back: The index of the last element of the second subarray.
 */

void merge_subarray(int *array, int *buffer, size_t front, size_t mid,
size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(array + front, mid - front);

printf("[right]: ");
print_array(array + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
	buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];

for (; i < mid; i++)
	buffer[k++] = array[i];

for (; j < back; j++)
	buffer[k++] = array[j];

for (i = front, k = 0; i < back; i++)
	array[i] = buffer[k++];

printf("[Done]: ");
print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm recursively.
 * @array: The array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The index of the first element in the array to sort.
 * @back: The index of the last element in the array to sort.
 */

void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(array, buffer, front, mid);
merge_sort_recursive(array, buffer, mid, back);
merge_subarray(array, buffer, front, mid, back);
}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
int *buffer;

if (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);

if (buffer == NULL)
return;

merge_sort_recursive(array, buffer, 0, size);

free(buffer);
}
