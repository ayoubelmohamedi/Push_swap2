/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 06:25:59 by asodor            #+#    #+#             */
/*   Updated: 2024/08/02 06:34:41 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort(t_stack **stack_a)
{
    t_stack *stack_b;
    int i;
    int min;

    stack_b = NULL;
    if (ft_lstsize(*stack_a) == 2)
        ft_sa(stack_a, 0);
    else
    {
        stack_b = ft_sort_b(stack_a);
        ft_sort_a(stack_a, &stack_b);
        min = ft_min(*stack_a);
        i = ft_find_index(*stack_a, min);
        if (i < ft_lstsize(*stack_a) - i)
        {
            while ((*stack_a)->top->value != min)
                ft_ra(stack_a, 0);
        }
        else
        {
            while ((*stack_a)->top->value != min)
                ft_rra(stack_a, 0);
        }
    }
}
