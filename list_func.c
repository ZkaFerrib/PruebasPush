/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:11:35 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/22 12:51:48 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_list  *ft_lstlast(t_list *list)
{
    while(list)
    {
        if(list->next == NULL)
            return(list);
        list = list->next;
    }
    return(list);
}

void    ft_addlistb(t_list **list, t_list *nodo)
{
    t_list      *last;

    if (!(*list))
        *list = nodo;
    else
    {
        last = ft_lstlast(*list);
        last->next = nodo;
    }
}

void    ft_addlistf(t_list **list, t_list **nodo)
{
    t_list  *aux;

    if(*nodo)
    {
        aux = *list;
        *list = *nodo;
        (*nodo)->next = aux;
    }
}

t_list  *ft_lstnew(int content)
{
    t_list  *list;
    
    list = malloc(sizeof(*list));
    if (list == NULL)
        return (NULL);
    list->contenido = content;
    return(list);
}


void ft_printlist(t_list *list)
{
    while(list)
    {
        printf("%d, \n", list->contenido);
        list = list->next; 
    }
}

t_list *ft_getlist(char **argv, t_control *control)
{
    int n;
    int num;
    t_list *list;
    
    list = NULL;
    n = 0;
    num = 0;
    while(argv[n])
    {
        num = ft_atoi(argv[n]);
        ft_addlistb(&list, ft_lstnew(num));
        control->a_size++;
        n++;
    }
    return(list);
}

int ft_listsize(t_list *list)
{
    int i;

    i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return(i);
}