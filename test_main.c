#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

void test_str_strlen(const char *s)
{
    if (strlen(s) < 80) {
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
        char *s = "Hello World!";
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

int main()
{
    test_strlen();
    
    return 0;
}
