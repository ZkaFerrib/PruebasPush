/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:21 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/23 14:42:25 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

static	void	ft_index(t_control *control)
{
	int			check;
	t_list		*aux;
	t_list		*stack;

	stack->control = control->stack_a;
	while (stack)
	{
		check = 0;
		aux = control->stack_a;
		while (aux)
		{
			if (stack->contenido > aux->contenido && aux->index == 0)
				check = 1;
			aux = aux->next;
		}
	}
	
}