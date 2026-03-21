
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

int ft_strcmp(const char *s1, const char *s2);

void    ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*cmp)());

void	ft_lstiter(t_list *lst)
{
    t_list *save_lst = lst;
    int i = 0;
	while (lst)
	{
		printf("[%d] \"%s\";\n", i, (char *)lst->data);
		lst = lst->next;
        i++;
	}
    printf("size = [%d]\n", ft_list_size(save_lst));
    printf("\n");
}

void test_push_front()
{
    {
        t_list *begin_list = NULL;
        void *data1 = "Hello\0";
        void *data2 = "World\0";
        void *data3 = "~\0";
        void *data4 = "!\0";
        void *data5 = "ABCD\0";

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

        printf("size = [%d]\n\n", size);
        
        ft_list_push_front(&begin_list, data3);
        ft_list_push_front(&begin_list, data4);
        ft_list_push_front(&begin_list, data5);
        

        ft_lstiter(begin_list);

        ft_list_sort(&begin_list, &ft_strcmp);

        ft_lstiter(begin_list);

        free(begin_list->next);
        free(begin_list);
    }
}

int main()
{
    test_push_front();

    return 0;
}
