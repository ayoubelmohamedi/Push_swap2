/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:49:53 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:48:17 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a) {
    if (a->top && a->top->next) {
        int temp = a->top->value;
        a->top->value = a->top->next->value;
        a->top->next->value = temp;
    }
}

void sb(t_stack *b) {
    sa(b);
}

void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
}

void pa(t_stack *a, t_stack *b) {
    if (!is_empty(b)) {
        push(a, pop(b));
    }
}

void pb(t_stack *a, t_stack *b) {
    if (!is_empty(a)) {
        push(b, pop(a));
    }
}

void ra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *first = a->top;
        a->top = a->top->next;
        t_node *current = a->top;
        while (current->next) {
            current = current->next;
        }
        current->next = first;
        first->next = NULL;
    }
}

void rb(t_stack *b) {
    ra(b);
}

void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
}

void rra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *current = a->top;
        t_node *prev = NULL;
        while (current->next) {
            prev = current;
            current = current->next;
        }
        current->next = a->top;
        a->top = current;
        prev->next = NULL;
    }
}

void rrb(t_stack *b) {
    rra(b);
}

void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
}
