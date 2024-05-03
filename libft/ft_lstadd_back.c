#include "libft.h"

void ft_listadd_back(t_list **list, t_list *new)
{
    t_list *last = ft_listlast(*list);
    last -> next = new;
}
/*
int main()
{
    t_list *head = ft_listnew("wqwq");
    t_list *new1 = ft_listnew("asas");
    t_list *new2 = ft_listnew("asasa");
    t_list *new3 = ft_listnew("asasaaaaaaa");
    t_list *new4 = ft_listnew("tolast");
    ft_listadd_front(&head, new1);
    ft_listadd_front(&head, new2);
    ft_listadd_front(&head, new3);
    ft_listadd_back(&head, new4);
    int i = ft_listsize(head);

    printf("last's content = %s\n", (char *)head -> next -> next -> next -> next -> content);
    //head -> next -> next = NULL;
    //t_list *last = ft_listlast(head);
    printf("i = %d\n", i);
}
*/
