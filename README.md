# libasm
## function

### mandatory
#### ft_strlen
```c
size_t   ft_strlen(const char *s);
```
#### ft_strcpy
```c
char    *ft_strcpy(char *dest, const char *src);
```
#### ft_strcmp
```c
int ft_strcmp(const char *s1, const char *s2);
```
#### ft_write
```c
ssize_t ft_write(int fd, const void *buf, size_t count);
```
#### ft_read
```c
ssize_t ft_read(int fd, void *buf, size_t count);
```
#### ft_strdup
```c
char    *ft_strdup(const char *s);
```

### bonus
#### preamble
```c
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;
```
#### ft_atoi_base
```c
int ft_atoi_base(char *str, char *base);
```
#### ft_list_push_front
```c
void    ft_list_push_front(t_list **begin_list, void *data);
```
#### ft_list_size
```c
int ft_list_size(t_list *begin_list);
```
#### ft_list_sort
```c
void    ft_list_sort(t_list **begin_list, int (*cmp)());
```
#### ft_list_remove_if
```c
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
```
