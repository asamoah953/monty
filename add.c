#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *current_node;
    int stack_length = 0;
    int result;

    current_node = *head;
    while (current_node->next)
    {
        current_node = current_node->next;
        stack_length++;
    }

    if (stack_length < 1)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    result = current_node->n + current_node->prev->n;
    current_node->prev->n = result;
    current_node->prev->next = NULL;
    free(current_node);
}

