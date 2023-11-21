#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swap a node with its previous one
 * @node: node to be swapped
 * @list: pointer to the list
 *
 * Return: pointer to the node that was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev, *current = node;

    if (back)
        back->next = current->next;
    if (current->next)
        current->next->prev = back;
    current->next = back;
    current->prev = back->prev;
    back->prev = current;
    if (current->prev)
        current->prev->next = current;
    else
        *list = current;
    return (current);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using the cocktail sort
 *                      algorithm
 * @list: double pointer to the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *node;
    int swap_done = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    node = *list;
    while (swap_done)
    {
        swap_done = 0;
        while (node->next != NULL)
        {
            if (node->n > node->next->n)
            {
                node = swap_node(node->next, list);
                swap_done = 1;
                print_list(*list);
            }
            else
                node = node->next;
        }

        if (!swap_done)
            break;

        swap_done = 0;
        while (node->prev != NULL)
        {
            if (node->n < node->prev->n)
            {
                node = swap_node(node, list);
                swap_done = 1;
                print_list(*list);
            }
            else
                node = node->prev;
        }
    }
}
