#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

int nb_error = 0;

size_t ft_strlen(const char *s);

void test_str_strlen(const char *s)
{
    if (strlen(s) != ft_strlen(s)) {
        nb_error++;
        printf("\033[31m   strlen(\"%s\") = %ld \n", s, strlen(s));
        printf("ft_strlen(\"%s\") = %ld \033[0m \n\n", s, ft_strlen(s));
    } else if (strlen(s) < 40) {
        printf("   strlen(\"%s\") = %ld\n", s, strlen(s));
        printf("ft_strlen(\"%s\") = %ld\n\n", s, ft_strlen(s));
    } else {
        printf("   strlen(\"...\") = %ld\n", strlen(s));
        printf("ft_strlen(\"...\") = %ld\n\n", ft_strlen(s));
    }
}

void test_strlen()
{
    printf("#################### strlen ####################\n");
    {
        const char *s = "Hello World!";
        test_str_strlen(s);
    } {
        test_str_strlen("");
    } {
        char *s = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        test_str_strlen(s);
    } {
        char s[255];
        for (int i = 0; i!= 255; ++i)
            s[i] = 'A';
        s[255] = '\0';
        test_str_strlen((const char *)s);
    } {
        // test_str_strlen((const char *)0); // segfault
    }
}


char *ft_strcpy(char *dest, const char *src);

void test_str_strcpy(char *dest, const char *src)
{
    char *strA = strcpy(dest, src);
    char *strB = ft_strcpy(dest, src);
    if (strcmp(strA, strB) == 0)
        printf("strcmp(strcpy, ft_strcpy) = %d\n\n", strcmp(strA, strB));
    else {
        nb_error++;
        printf("\033[31m strcmp(strcpy, ft_strcpy) = %d \033[0m\n\n", strcmp(strA, strB));
        printf("   strcpy = \"%s\"\n", strA);
        printf("ft_strcpy = \"%s\"\n", strB);
    }
}

void test_strcpy()
{
    printf("#################### strcpy ####################\n");
    {
        char dest[100];
        const char *src = "Hello World!";

        test_str_strcpy((char *)dest, src);
    } {
        char dest[0];
        test_str_strcpy((char *)dest, "");
    } {
        const char *src = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        char *dest = malloc((strlen(src) + 1) * sizeof(char));
        if (dest) {
            test_str_strcpy(dest, src);
            free(dest);
        }
    } {
        char dest[100] = "The strings may not overlap\0";
        const char *src = dest + 5;

        test_str_strcpy(dest, src);
    } {
        // char src[100] = "The strings may not overlap\0"; // segfault

        // test_str_strcpy(src + 2, src);
    } {
        // const char *src = "Hey"; // segfault
        // char *dest;

        // test_str_strcpy(dest, src);
    } {
        // test_str_strcpy((const char *)0, (const char *)0); // segfault
    }
}


int ft_strcmp(const char *s1, const char *s2);

void test_str_strcmp(const char *s1, const char *s2)
{
    if (strcmp(s1, s2) != ft_strcmp(s1, s2)) {
        nb_error++;
        printf("\033[31m   strcmp(\"%s\", \"%s\") = %d \n", s1, s2, strcmp(s1, s2));
        printf("ft_strcmp(\"%s\", \"%s\") = %d \033[0m \n\n", s1, s2, ft_strcmp(s1, s2));
    } else if (strlen(s1) < 20 || strlen(s2) < 20) {
        printf("   strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
        printf("ft_strcmp(\"%s\", \"%s\") = %d\n\n", s1, s2, ft_strcmp(s1, s2));
    } else {
        printf("   strcmp(\"...\", \"...\") = %d\n", strcmp(s1, s2));
        printf("ft_strcmp(\"...\", \"...\") = %d\n\n", ft_strcmp(s1, s2));
    }
}

void test_strcmp()
{
    printf("#################### strcmp ####################\n");
    {
        const char *s1 = "Hello World!";
        const char *s2 = "Hello World!";
        test_str_strcmp(s1, s2);
    } {
        test_str_strcmp("", "");
    } {
        char *s1 = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        test_str_strcmp(s1, s1);
    } {
        const char *s1 = "Hello World!";
        const char *s2 = "Helll World!";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    } {
        char dest[100] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\0";
        const char *src = dest + 5;

        test_str_strcmp(dest, src);
    } {
        const char *s1 = "\x0";
        const char *s2 = "\x7f";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    } {
        const char *s1 = "\x0";
        const char *s2 = "\xff";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    } {
        // test_str_strcmp((const char *)0, (const char *)0); // segfault
    }
}


ssize_t ft_write(int fd, const void *buf, size_t count);

void print_test_str_write(int fd, const void *buf, size_t count)
{
    ssize_t res;
    int ft_write_errno;
    int write_errno;

    printf("write(%d, %s, %ld)\n", fd, (const char *)buf, count);

    printf("\"");

    res = ft_write(fd, buf, count);
    ft_write_errno = errno;

    printf("\" = %ld (errno = %d)\n", res, ft_write_errno);
    if (ft_write_errno)
        perror("errno");


    printf("\"");

    res = write(fd, buf, count);
    write_errno = errno;

    printf("\" = %ld (errno = %d)\n", res, write_errno);
    if (write_errno)
        perror("errno");
        
    if (ft_write_errno != write_errno) {
        nb_error++;
        printf("\033[31m Not Same Errno \033[0m\n");
    }
    if (errno)
        errno = 0;
    printf("\n");
}

void test_str_write(int fd, const void *buf, size_t count, int garbage_fd)
{
    ssize_t res;

    if (write(garbage_fd, buf, count) != ft_write(garbage_fd, buf, count)) {
        nb_error++;
        printf("\033[31m");
    }
    print_test_str_write(fd, buf, count);

    printf("\033[0m");
}

void test_write()
{
    printf("#################### ft_write ####################\n");
    int garbage_fd = open("/dev/null", O_WRONLY);
    {
        test_str_write(1, "ABCD OH NO", 4, garbage_fd);
    } {
        test_str_write(2, "Hey", 3, garbage_fd);
    } {
        test_str_write(-1, "ABCD OH NO", 4, garbage_fd);
    } {
        test_str_write(1, "ABCD\0", 10, garbage_fd);
    } {
        test_str_write(1, (const void *)0, 10, garbage_fd);
    }
    close(garbage_fd);
}

ssize_t ft_read(int fd, void *buf, size_t count);

/*
read and ft_read successively advances in file
It is therefore normal that the results are different or not
*/
void test_str_read(int fd, void *buf, size_t count)
{
    ssize_t nb_read = read(fd, buf, count);
    int read_errno = errno;
    if (nb_read && !read_errno)
        ((char *)buf)[nb_read] = '\0';
    errno = 0;
    
    ssize_t nb_ft_read = ft_read(fd, buf, count);
    int ft_read_errno = errno;
    if (nb_ft_read && !ft_read_errno)
        ((char *)buf)[nb_ft_read] = '\0';
    errno = 0;

    if (nb_read != nb_ft_read || read_errno != ft_read_errno) {
        nb_error++;
        printf("\033[31m");
    }
    printf("read(%d, %p, %ld)\n", fd, (const void *)buf, count);
    if (nb_ft_read && !ft_read_errno)
        printf("\"%s\"\n", (const char *)buf);
    printf("nb_read: %ld == %ld\n", nb_read, nb_ft_read);
    printf("errno: %d == %d\n", read_errno, ft_read_errno);
    perror("errno");
    if (errno)
        errno = 0;
    printf("\n\033[0m");
    
}

void test_read()
{
    printf("#################### ft_read ####################\n");
    {
        int fd = open("./Makefile", O_RDONLY);
        char buf[100];
        test_str_read(fd, (void *)buf, 20);

        close(fd);
    } {
        int fd = open("./Makefile", O_RDONLY);
        char *buf = malloc(101 * sizeof(char));

        test_str_read(fd, (void *)buf, 100);

        free(buf);
        close(fd);
    } {
        char *buf = malloc(101 * sizeof(char));
        
        test_str_read(-1, (void *)buf, 100);
        
        free(buf);
    } {
        // char *buf = malloc(101 * sizeof(char)); // waiting input
        
        // test_str_read(0, (void *)buf, 100);
        
        // free(buf);
    } {
        // test_str_read(2, "Hey", 3); // segfault
    } {
        // test_str_read(2, (void *)0, 3); // segfault
    }
}

char *ft_strdup(const char *s);

void test_str_strdup(const char *s)
{
    char *sdup = ft_strdup(s);

    if (strcmp(s, sdup) != 0) {
        nb_error++;
        printf("\033[31m");
    }
    printf("strdup(%s)\n", s);
    printf("\"%s\"\n", sdup);
    printf("errno: %d\n", errno);
    if (errno)
        errno = 0;
    printf("\n\033[0m");

    free(sdup);
}

void test_strdup()
{
    printf("#################### ft_strdup ####################\n");
    {
        char str[100] = "Hello World!\0";
        test_str_strdup(str);
    } {
        test_str_strdup("");
    } {
        // Uncomment main at bottom file; test if malloc crash
    } {
        // test_str_strdup((const char *)0); // segfault
    }
}

int main()
{
    test_strlen();
    test_strcpy();
    test_strcmp();
    setbuf(stdout, NULL);
    test_write();
    test_read();
    setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
    test_strdup();
    
    if (nb_error != 0) {
        printf("\033[31m ##### ##### ##### ##### ##### \n");
        printf(" #####      ERROR: %d \t ##### \n", nb_error);
        printf(" ##### ##### ##### ##### ##### \033[0m \n");
    }

    return 0;
}



// // TEST FOR STRDUP ERROR HANDLER

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// #include <stdlib.h>
// #include <sys/resource.h>

// char	*ft_strdup(const char *s);

// int	main()
// {
// 	struct rlimit	rl;
// 	rl.rlim_cur = 100000; 
// 	rl.rlim_max = 100000;

// 	setrlimit(RLIMIT_AS, &rl);

// 	char	*str = "Hello";

// 	errno = 0;
// 	char	*real_ret = strdup(str);
// 	if (real_ret)
// 		free(real_ret);

// 	int		real_err = errno;

// 	errno = 0;
// 	char	*ret = ft_strdup(str);

// 	if (ret == NULL)
// 		printf("Succès du test : ft_strdup a renvoyé NULL et errno = %d || %d\n", errno, real_err);
// 	else
// 	{
// 		printf("Échec du test : ft_strdup a réussi (il y a trop de RAM) ou a crashé.\n");
// 		free(ret);
// 	}
// 	return 0;
// }