/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaizkafernandezribeiro <gaizkafernandez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/16 14:45:25 by gaizkaferna      ###   ########.fr       */
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
    printf("%d \n", ft_listsize);
    ft_printlist(list);
}

void    ft_movestack(t_control *control)
{
    while(control->ra--)
        ft_rotatecontrol(control, 'a');
    while(control->rb--)
        ft_rotatecontrol(control, 'b');
    while(control->rra--)
        ft_rotatedcontrol(control, 'a');
    while(control->rrb--)
        ft_rotatedcontrol(control, 'b');
    while(control->rr--)
        ft_simplify_moveset(control, 'a' && 'b');
    while(control->rrr--)
        ft_simplify_moveset(control, 'a' && 'b');
}

void    ft_initiatevalues(int   c, t_control *control)
{
    if (c == 0)
    {
        control->stack_a = NULL;
        control->stack_b = NULL;
        control->a_size = 0;
        control->b_size = 0;
    }
}
