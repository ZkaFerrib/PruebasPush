/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/22 15:17:18 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void    ft_pushmin(t_control *control)
{
        if (control->a_moves < 3)
            while(control->a_moves--)
                ft_rotatecontrol(control, 'a');
        else
        {
            if(control->a_moves == control->a_size -2)
            {
                ft_rotatedcontrol(control, 'a');
                ft_rotatedcontrol(control, 'a');
            }
            if(control->a_moves == control->a_size -1)
                ft_rotatedcontrol(control, 'a');
        }
        control->a_moves  = 0;
        ft_pushstack(control, 'b');
}

void    ft_minvalue(t_control *control)
{
    t_list *aux;
    t_list *stack;

    int moves;
    int check;

    stack = control->stack_a;
    moves = 0;
    while(stack)
    {
        check = 0;
        aux = control->stack_a;
        while (aux)
        {
            if(stack->contenido > aux->contenido)
                check = 1;
                aux = aux->next;
        }
        if (check == 0)
        {
            control->a_moves = moves;
            break;
        }
        stack = stack->next;
        moves++;
    }

    
}

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
    /* while(control->rr--)
        ft_simplify_moveset(control, 'a' && 'b');
    while(control->rrr--)
        ft_simplify_moveset(control, 'a' && 'b'); */
}

void    ft_initiatevalues(t_control *control)
{
        control->stack_a = NULL;
        control->stack_b = NULL;
        control->a_size = 0;
        control->b_size = 0;
}

int main(int argc, char** argv)
{
    t_list      *list;
    t_control   control;

    list = NULL;
    (void)argc;
    ft_initiatevalues(&control);
    list = ft_getlist(&argv[1], &control);
    printf("a_size = %d\n", control.a_size);
    // ft_printlist(list);
    // ft_rotatedown(&list);
    // ft_printlist(list);
    control.stack_a = list;
    control.stack_b = NULL;
    if (control.a_size == 3)
        ft_algorithm_three(&control);
    else if (control.a_size == 5)
        ft_algorithm_five(&control);
    //else
    //    ft_algorithm_final();
    /* ft_rotatedown(&control.stack_a);
    ft_pushstack(&control, 'b');
    ft_pushstack(&control, 'b');
    ft_rotateup(&control.stack_b);
    printf("stack_a\n");
    ft_printlist(control.stack_a);
    printf("stack_b\n");
    ft_printlist(control.stack_b);
    ft_pushstack(&control, 'a');
    ft_pushstack(&control, 'a');*/
    printf("stack_a\n");
    ft_printlist(control.stack_a);
    printf("stack_b\n");
    ft_printlist(control.stack_b);
    //ft_printlist(list);
}