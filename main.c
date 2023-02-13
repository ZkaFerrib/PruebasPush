/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/13 14:12:42 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_simplify_moveset(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while(aux)
	{
		while (aux->ra && aux->rb)
		{
			aux->ra--;
			aux->rb--;
			aux->rr++;
		}
		while (aux->rra && aux->rrb)
		{
			aux->rra--;
			aux->rrb--;
			aux->rrr++;
		}
		aux = aux->next;
	}
}

int main(int argc, char** argv)
{
    t_list      *list;

    list = NULL;
    (void)argc;
    list = ft_getlist(&argv[1]);
    // ft_printlist(list);
    // ft_rotatedown(&list);
    // ft_printlist(list);
    t_control control;
    control.stack_a = list;
    control.stack_b = NULL;
    ft_pushstack(&control, 'b');
    ft_rotatedown(&control.stack_a);
    ft_pushstack(&control, 'b');
    ft_rotateup(&control.stack_b);
    printf("stack_a\n");
    ft_printlist(control.stack_a);
    printf("stack_b\n");
    ft_printlist(control.stack_b);
    ft_printlist(list);
}
