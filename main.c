/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:16:51 by asodor            #+#    #+#             */
/*   Updated: 2024/08/21 09:33:32 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int ft_isvalid(char **argv)
{
	size_t i;
	size_t j;
	char **spt;

	i = 0;
	argv++;
	while (argv[i])
	{
		spt = ft_split(argv[i],' ');
		printf("current argv[%zu] => %s\n", i, argv[i]);
		if (spt == NULL)
			return (0);
		j = 0;
		while (spt[j])	
		{
			printf("spt[%zu] ===> %s\n", j, spt[j]);
			if (error_syntax(spt[j]))
			{
				printf("error here where spt[j] == %s\n", spt[j]);
				// free_matrix(spt);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || !ft_isvalid(argv))
	{
		printf("unvalid syntax\n");
		return (1);
	}
	printf("valid syntax");
	exit(0);
	stack_init(&a, argv + 1 , 2 == argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
