#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nb_error = 0;

size_t ft_strlen(const char *s);

void test_str_strlen(const char *s)
{
    if (strlen(s) != ft_strlen(s)) {
        nb_error++;
        printf("\033[31m   strlen(\"%s\") = %ld \n", s, strlen(s));
        printf("ft_strlen(\"%s\") = %ld \033[0m \n\n", s, ft_strlen(s));
    }
    else if (strlen(s) < 40) {
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
    }
    {
        test_str_strlen("");
    }
    {
        char *s = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        test_str_strlen(s);
    }
    {
        char s[255];
        for (int i = 0; i!= 255; ++i)
            s[i] = 'A';
        s[255] = '\0';
        test_str_strlen((const char *)s);
    }
    {
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
    else
    {
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
    }
    {
        char dest[0];
        test_str_strcpy((char *)dest, "");
    }
    {
        const char *src = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        char *dest = malloc((strlen(src) + 1) * sizeof(char));
        if (dest)
        {
            test_str_strcpy(dest, src);
            free(dest);
        }
    }
    {
        char dest[100] = "The strings may not overlap\0";
        const char *src = dest + 5;

        test_str_strcpy(dest, src);
    }
    {
        // char src[100] = "The strings may not overlap\0"; // segfault

        // test_str_strcpy(src + 2, src);
    }
    {
        // const char *src = "Hey"; // segfault
        // char *dest;

        // test_str_strcpy(dest, src);
    }
    {
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
    }
    else if (strlen(s1) < 20 || strlen(s2) < 20) {
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
    }
    {
        test_str_strcmp("", "");
    }
    {
        char *s1 = "ijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgreaijwgbwjhbgjwnljgbrjgbrkjgbabrgbakjrgbrkgbkjaerbjgbrajbgrbekagjkrbejkeaberkjblkgarjebagjbakjjgrkbgekjabrgajkbgkjbgarjjkbbrklbgrerjgbaekjabgabrjgrea";
        test_str_strcmp(s1, s1);
    }
    {
        const char *s1 = "Hello World!";
        const char *s2 = "Helll World!";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    }
    {
        char dest[100] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\0";
        const char *src = dest + 5;

        test_str_strcmp(dest, src);
    }
    {
        const char *s1 = "\x0";
        const char *s2 = "\x7f";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    }
    {
        const char *s1 = "\x0";
        const char *s2 = "\xff";
        test_str_strcmp(s1, s2);
        test_str_strcmp(s2, s1);
    }
    {
        // test_str_strcmp((const char *)0, (const char *)0); // segfault
    }
}

int main()
{
    test_strlen();
    test_strcpy();
    test_strcmp();
    
    if (nb_error != 0) {
        printf("\033[31m ##### ##### ##### ##### ##### \n");
        printf(" #####      ERROR: %d \t ##### \n", nb_error);
        printf(" ##### ##### ##### ##### ##### \033[0m \n");
    }
    return 0;
}
