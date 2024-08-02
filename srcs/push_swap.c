/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:12 by asodor            #+#    #+#             */
/*   Updated: 2024/08/02 06:07:45 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_duplicate(t_stack *a)
{
    t_node *current;
    t_node *runner;

    if (!a || !a->top)
        return (0);

    current = a->top;
    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (current->value == runner->value)
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}

// This function checks if the stack is sorted.
int ft_check(t_stack *a)
{
    t_node *current;

    current = a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int main(int ac, char **av)
{
	t_stack	*a;

	a = ft_parse(ac, av);
	if (!a || ft_check_duplicate(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_check(a))
		ft_sort(&a);
	ft_free(&a);
}
