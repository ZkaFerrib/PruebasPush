/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:11:03 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/09 15:46:23 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_rotateup(t_list **list)
{
    t_list      *last;
    t_list      *aux;

    aux = *list;
    last = ft_lstlast(*list);
    *list = (*list)->next;
    last->next = aux;
    aux->next = NULL;
} 

void    ft_swap(t_list **list)
{
    t_list      *aux;

    aux = *list;
    *list = aux->next;
    aux->next = (*list)->next;
    (*list)->next = aux;
}

void    ft_rotatedown(t_list **list)
{
    t_list      *aux;

    aux = *list;
    while(aux->next->next != NULL)
            aux = aux->next;
    aux->next->next = *list;
    *list = aux->next;
    aux->next = NULL;
}