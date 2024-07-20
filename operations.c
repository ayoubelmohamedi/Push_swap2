/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:49:53 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:34:13 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void sa(t_stack *a) {
    if (a->top && a->top->next) {
        int temp = a->top->value;
        a->top->value = a->top->next->value;
        a->top->next->value = temp;
        printf("sa\n");
    }
}

void sb(t_stack *b) {
    sa(b);
    printf("sb\n");
}

void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
    printf("ss\n");
}

void pa(t_stack *a, t_stack *b) {
    if (!is_empty(b)) {
        push(a, pop(b));
        printf("pa\n");
    }
}

void pb(t_stack *a, t_stack *b) {
    if (!is_empty(a)) {
        push(b, pop(a));
        printf("pb\n");
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
        printf("ra\n");
    }
}

void rb(t_stack *b) {
    ra(b);
    printf("rb\n");
}

void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
    printf("rr\n");
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
        printf("rra\n");
    }
}

void rrb(t_stack *b) {
    rra(b);
    printf("pb\n");
}

void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
    printf("rra\n");
}
