/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/09 15:07:36 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int     ft_listsize(t_list *list);
void    ft_printlist(t_list *list);
t_list  *ft_getlist(char **argv);

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

void    ft_addlistf(t_list **list, t_list *nodo)
{
    if(list && nodo)
    {
        nodo->next = *list;
        list = &nodo;
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

int main(int argc, char** argv)
{
    t_list      *list;

    list = NULL;
    (void)argc;
    list = ft_getlist(&argv[1]);
    ft_printlist(list);
    ft_rotatedown(&list);
    ft_printlist(list);
}

void ft_printlist(t_list *list)
{
    while(list)
    {
        printf("%d, \n", list->contenido);
        list = list->next; 
    }
}

t_list *ft_getlist(char **argv)
{
    int n;
    int num;
    t_list *list;
    
    n = 0;
    num = 0;
    while(argv[n])
    {
        num = ft_atoi(argv[n]);
        ft_addlistb(&list, ft_lstnew(num));
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

/* void ft_pushstack(t_control  *control, char c)
{
    t_list     *aux;

    if (c == 'b')
    {
        write(1, "pb", 3);
        aux = control->stack_a;
        control->stack_a = control->stack_a->next;
        ft_addlistf(&control->stack_b, aux);
        control->a_size--;
        control->b_size++;
    }
    else if (c == 'a')
    {
        write(1, "pa", 3);
        aux = control->stack_b;
        control->stack_b = control->stack_b->next;
        ft_addlistf(&control->stack_b->next, aux);
        control->b_size--;
        control->a_size++;
    }
    control->total_moves++;
    printf("%d \n", control->b_size);
} */
