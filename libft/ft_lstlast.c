#include "libft.h"

t_list *ft_listlast(t_list *list)
{
    int i = ft_listsize(list) - 1;
    while(i > 0)
    {
        //printf("i = %d\n", i);
        list = list -> next;
        i--;
    }
    return (list);
}
/*
int main()
{
    t_list *head = ft_listnew("wqwq");
    t_list *new1 = ft_listnew("asas");
    t_list *new2 = ft_listnew("asasa");
    t_list *new3 = ft_listnew("asasaaaaaaa");

    ft_listadd_front(&head, new1);
    ft_listadd_front(&head, new2);
    ft_listadd_front(&head, new3);

    int i = ft_listsize(head);

    //head -> next -> next = NULL;
    t_list *last = ft_listlast(head);
    printf("last one = %s\n", (char *)last -> content);
}
*/