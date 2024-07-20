/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:12 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:49:22 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to check if a string is a valid integer
int is_integer(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

// Function to check for duplicates in the stack
int has_duplicates(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        t_node *runner = current->next;
        while (runner) {
            if (current->value == runner->value)
                return 1;
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }

    t_stack *a = init_stack();
    t_stack *b = init_stack();

    for (int i = 1; i < argc; i++) {
        if (!is_integer(argv[i])) {
            fprintf(stderr, "Error\n");
            free_stack(a);
            free_stack(b);
            return 1;
        }
        push(a, atoi(argv[i]));
    }

    if (has_duplicates(a)) {
        fprintf(stderr, "Error\n");
        free_stack(a);
        free_stack(b);
        return 1;
    }

    // Implement sorting logic here

    free_stack(a);
    free_stack(b);
    return 0;
}
