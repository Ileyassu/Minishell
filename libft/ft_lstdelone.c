/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:27:16 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/13 20:33:54 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_listdelone(t_list *list, void (*del)(void*))
{
    if(list)
    {
        (*del)(list -> content);
        free(list);
    }
}
/*
void deletecontent(void *content)
{
    free(content);
}
int main()
{
    t_list *head = ft_listnew(strdup("0"));
    t_list *new1 = ft_listnew(strdup("1"));
    t_list *new2 = ft_listnew(strdup("2"));
    t_list *new3 = ft_listnew(strdup("3"));
    ft_listadd_front(&head, new1);
    ft_listadd_front(&head, new2);
    ft_listadd_front(&head, new3);
    int i = ft_listsize(head);

    ft_listdelone(new1, deletecontent);
    printf("%s\n", (char *)head -> content);
    //printf("i = %d\n", i);
}
*/