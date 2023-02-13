/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:06:04 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/13 14:45:31 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H



typedef struct s_list
{
    int         contenido;
    int         rb;
    int         ra;
    int         rr;
    int         rra;
    int         rrb;
    int         rrr;
    int         moves;
   struct s_list     *next;
}                       t_list;

typedef struct s_control
{
    struct s_list       *stack_a;
    struct s_list       *stack_b;
    int         a_size;
    int         b_size;
    int         total_moves;
    int         ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;

}                       t_control;

/* Utils */

void	ft_simplify_moveset(t_list *stack);
int		ft_atoi(const char *str);
void    ft_addlistf(t_list **list, t_list **nodo);
void    ft_addlistb(t_list **list, t_list *nodo);
t_list  *ft_lstnew(int content);
t_list  *ft_lstlast(t_list *list);
t_list *ft_getlist(char **argv);
void 	ft_printlist(t_list *list);
int 	ft_listsize(t_list *list);
int 	main(int argc, char** argv);


/* movimientos */

void    ft_rotateup(t_list **list);
void    ft_swap(t_list **list);
void    ft_rotatedown(t_list **list);
void    ft_pushstack(t_control  *control, char c);
void    ft_swapcontrol(t_control *control, char c);
void    ft_rotatedcontrol(t_control *control, char c);
void    ft_rotatecontrol(t_control *control, char c);

#endif