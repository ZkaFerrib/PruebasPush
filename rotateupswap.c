/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateupswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:43:32 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/23 14:29:10 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_rotateup(t_list **list)
{
	t_list	*last;
	t_list	*aux;

	aux = *list;
	last = ft_lstlast(*list);
	*list = (*list)->next;
	last->next = aux;
	aux->next = NULL;
}

void	ft_rotatecontrol(t_control *control, char c)
{
	if (c == 'a')
	{
		//write(1, "ra\n", 3);
		ft_rotateup(&control->stack_a);
	}
	else if (c == 'b')
	{
		//write(1, "rb\n", 3);
		ft_rotateup(&control->stack_b);
	}
	control->total_moves++;
}

void	ft_swap(t_list **list)
{
	t_list	*aux;

	aux = *list;
	*list = aux->next;
	aux->next = (*list)->next;
	(*list)->next = aux;
}

void	ft_swapcontrol(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "sa\n", 3);
		ft_swap(&control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "sb\n", 3);
		ft_swap(&control->stack_b);
	}
	control->total_moves++;
}
