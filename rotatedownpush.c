/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatedownpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:11:03 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/23 14:15:33 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_rotatedown(t_list **list)
{
	t_list	*aux;

	aux = *list;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next->next = *list;
	*list = aux->next;
	aux->next = NULL;
}

void	ft_rotatedcontrol(t_control *control, char c)
{
	if (c == 'a')
	{
		//write(1, "rra", 3);
		ft_rotatedown(&control->stack_a);
	}
	else if (c == 'b')
	{
		//write(1, "rrb", 3);
		ft_rotatedown(&control->stack_b);
	}
	control->total_moves++;
}

void	ft_pushstack(t_control *control, char c)
{
	t_list	*aux;

	if (c == 'b')
	{
		//write(1, "pb", 3);
		aux = control->stack_a;
		control->stack_a = control->stack_a->next;
		ft_addlistf(&(control->stack_b), &aux);
		control->a_size--;
		control->b_size++;
	}
	else if (c == 'a')
	{
		//write(1, "pa", 3);
		aux = control->stack_b;
		control->stack_b = control->stack_b->next;
		ft_addlistf(&control->stack_a, &aux);
		control->b_size--;
		control->a_size++;
	}
	control->total_moves++;
	//printf("%d \n", control->b_size);
}