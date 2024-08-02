/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:29:11 by asodor            #+#    #+#             */
/*   Updated: 2024/08/02 04:23:09 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **arr)
{
	char	*n;

	if (!arr)
		return ;
	while (*arr)
	{
		n = *arr;
		arr++;
		free(n);
	}
	*arr = NULL;
}

void	list_args(char **av, t_stack **a, long i)
{
	while (av[i] != NULL)
	{
		ft_add_back(a, ft_stack_new(ft_atoi(av[i])));
		i++;
	}
}

t_stack	*ft_parse_args_quoted(char **av)
{
	t_stack	*a;
	char	**tmp;

	a = NULL;
	tmp = ft_split(av[1], 32);
	list_args(tmp, &a, 0);
	ft_free(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack		*a;

	a = NULL;
	if (ac < 2)
		ft_error();
	else if (ac == 2)
		a = ft_parse_args_quoted(av);
	else
	{
		list_args(av, &a, 1);
	}
	return (a);
}
