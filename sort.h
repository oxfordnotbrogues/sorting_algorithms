#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;
/* function to print list*/
void print_list(const listint_t *list);
/*function to print array*/
void print_array(const int *array, size_t size);
/* bubble sort function*/
void bubble_sort(int *array, size_t size);
/*insertion list*/
void insertion_sort_list(listint_t **list);
/*selection sort*/
void selection_sort(int *array, size_t size);
/*quick sort*/
void quick_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
/*shell sort_knuth sequence*/
void shell_sort(int *array, size_t size);
/*cocktail shaker sort*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
#endif
