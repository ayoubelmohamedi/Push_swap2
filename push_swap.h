/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:38 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:33:54 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

// utils.c
t_stack *init_stack(void);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int is_empty(t_stack *stack);
void free_stack(t_stack *stack);

//operations.c
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

#endif

