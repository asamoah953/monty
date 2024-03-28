#include "monty.h"
/**
 * addnode - add node to the head of the stack
 * @head: pointer to the head of the stack
 * @n: value to be stored in the new node
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

