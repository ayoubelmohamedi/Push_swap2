/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:12 by asodor            #+#    #+#             */
/*   Updated: 2024/07/28 21:55:10 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
