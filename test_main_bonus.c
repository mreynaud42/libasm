
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

void    ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);

void test_push_front()
{
    {
        t_list *begin_list = NULL;
        void *data1 = (void *)42U;
        void *data2 = NULL;

        ft_list_push_front(&begin_list, data1);
        if (errno)
            return;
        
        printf("data = [%p]\n", begin_list->data);
        printf("next = [%p]\n", begin_list->next);

        ft_list_push_front(&begin_list, data2);
        if (errno) {
            free(begin_list);
            return;
        }

        printf("data = [%p]\n", begin_list->data);
        printf("next = [%p]\n", begin_list->next);
        
        int size = ft_list_size(begin_list);

        printf("size = [%d]\n", size);

        free(begin_list->next);
        free(begin_list);
    }
}

int main()
{
    test_push_front();

    return 0;
}
