/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:38 by asodor            #+#    #+#             */
/*   Updated: 2024/07/18 13:50:40 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack_node {
    int value;
    struct s_stack_node *next;
} t_stack_node;

typedef struct s_stack {
    t_stack_node *top;
    int size;
} t_stack;

// Stack operations
void stack_push(t_stack *stack, int value);
int stack_pop(t_stack *stack);
void stack_init(t_stack *stack);

// Parsing
int parse_arguments(int argc, char **argv, t_stack *stack_a);

// Push swap operations
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

#endif

