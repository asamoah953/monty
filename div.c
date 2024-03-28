#include "monty.h"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    while (h->next)
    {
        h = h->next;
        len++;
    }

    if (len < 1)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = h->prev->n / h->n;
    h->prev->n = aux;
    h->prev->next = NULL;
    free(h);
}
