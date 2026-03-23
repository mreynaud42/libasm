
; Prototype:
; int ft_atoi_base(char *str, char *base);

section .text
    global ft_atoi_base

ft_atoi_base:
    ; rdi = char *str
    ; rsi = char *base