#include <stdio.h>
#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array
 *                  of integers using binary search.
 * @array: A pointer to the first element of the array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
    size_t i;

    if (array == NULL)
        return -1;

    while (right >= left)
    {
        printf("Searching in array: ");
        for (i = left; i < right; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[i]);

        i = left + (right - left) / 2;
        if (array[i] == value)
            return i;
        if (array[i] > value)
            right = i - 1;
        else
            left = i + 1;
    }

    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t i = 1;

    if (array == NULL || size == 0)
        return -1;

    /* Find the range where the value may exist */
    while (i < size && array[i] <= value)
    {
        printf("Value checked array[%ld] = [%d]\n", i, array[i]);
        i *= 2;
    }

    /* Perform binary search in the found range */
    printf("Value found between indexes [%ld] and [%ld]\n", i / 2, (i < size ? i : size) - 1);
    return _binary_search(array, i / 2, (i < size ? i : size) - 1, value);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));

    return 0;
}
