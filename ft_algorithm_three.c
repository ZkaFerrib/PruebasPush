/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:04:01 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/22 14:39:44 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_algorithm_three(t_control *control)
{
    printf("stack_a %d\n", control->stack_a->contenido);
    printf("stack_a %d\n", control->stack_a->next->contenido);
    printf("stack_a %d\n", control->stack_a->next->next->contenido);
    if (control->stack_a->contenido < control->stack_a->next->contenido)
    {
        if(control->stack_a->contenido > control->stack_a->next->next->contenido)
        {
            ft_rotatedcontrol(control, 'a');
        }
    }

    if(control->stack_a->contenido < control->stack_a->next->contenido)
    {
        if(control->stack_a->contenido < control->stack_a->next->next->contenido)
        {
            if(control->stack_a->next->contenido > control->stack_a->next->next->contenido)
            {
                ft_swapcontrol(control, 'a');
                ft_rotatecontrol(control, 'a');
            }
        }
    }
    if(control->stack_a->contenido > control->stack_a->next->contenido)
    {
        if(control->stack_a->contenido > control->stack_a->next->next->contenido)
        {
            if(control->stack_a->next->contenido > control->stack_a->next->next->contenido)
            {
                ft_swapcontrol(control, 'a');
                ft_rotatedcontrol(control, 'a');
            }
        }
    }
    if(control->stack_a->contenido > control->stack_a->next->contenido)
    {
        if(control->stack_a->contenido > control->stack_a->next->next->contenido)
            if(control->stack_a->next->contenido < control->stack_a->next->next->contenido)
                    ft_rotatecontrol(control, 'a');
    }
    if(control->stack_a->contenido > control->stack_a->next->contenido)
    {
        if(control->stack_a->contenido < control->stack_a->next->next->contenido)
            if(control->stack_a->next->contenido < control->stack_a->next->next->contenido)
                ft_swapcontrol(control, 'a');
    }
}
