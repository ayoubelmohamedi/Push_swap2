/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:49 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:49:43 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void) {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
     return stack;
}

void push(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}


int is_empty(t_stack *stack) {
    return stack->top == NULL;
}

int pop(t_stack *stack) {
    if (is_empty(stack))
        return -1; // Or some error value
    t_node *top_node = stack->top;
    int value = top_node->value;
    stack->top = top_node->next;
    free(top_node);
    return value;
}

void free_stack(t_stack *stack) {
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}
