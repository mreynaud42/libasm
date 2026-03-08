
; char *ft_strcpy(char *dest, const char *src);
; rax ft_strcpy rdi rsi

; rdi rsi rdx rcx r8 r9

section .text
    global ft_strcpy   

ft_strcpy:
    mov rax, rdi
    cld ; Clear Direction Flag

    _loop:
        cmp byte [rsi], 0
        je return
        movsb   ; Move Data From String to String (and inc)
        jmp _loop
   
    return:
        mov byte [rdi], 0
        ret
