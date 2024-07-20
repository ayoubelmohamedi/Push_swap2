/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:49:53 by asodor            #+#    #+#             */
/*   Updated: 2024/07/18 13:49:56 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
//Helper functions
void swap(t_stack *stack) {
    if (stack->size < 2)
        return;
    int temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}

void push(t_stack *source, t_stack *destination) {
    if (source->size == 0)
        return;
    int value = stack_pop(source);
    stack_push(destination, value);
}

void rotate(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_stack_node *last = stack->top;
    while (last->next)
        last = last->next;
    last->next = stack->top;
    stack->top = stack->top->next;
    last->next->next = NULL;
}

void reverse_rotate(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_stack_node *second_last = stack->top;
    while (second_last->next->next)
        second_last = second_last->next;
    second_last->next->next = stack->top;
    stack->top = second_last->next;
    second_last->next = NULL;
}

//required push_swap operations
void sa(t_stack *stack_a) {
    swap(stack_a);
    printf("sa\n");
}

void sb(t_stack *stack_b) {
    swap(stack_b);
    printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b) {
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}

void pa(t_stack *stack_a, t_stack *stack_b) {
    push(stack_b, stack_a);
    printf("pa\n");
}

void pb(t_stack *stack_a, t_stack *stack_b) {
    push(stack_a, stack_b);
    printf("pb\n");
}

void ra(t_stack *stack_a) {
    rotate(stack_a);
    printf("ra\n");
}

void rb(t_stack *stack_b) {
    rotate(stack_b);
    printf("rb\n");
}

void rr(t_stack *stack_a, t_stack *stack_b) {
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}

void rra(t_stack *stack_a) {
    reverse_rotate(stack_a);
    printf("rra\n");
}

void rrb(t_stack *stack_b) {
    reverse_rotate(stack_b);
    printf("rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b) {
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}