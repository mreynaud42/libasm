
; size_t ft_strlen(const char *s);
; rax ft_strlen rdi ; rax = size_t = 64 bits

; rdi rsi rdx rcx r8 r9

section .text
    global ft_strlen   

ft_strlen:
    mov rax, rdi

    _loop:
        cmp byte [rax], 0
        je return
        inc rax
        jmp _loop

    return:
        sub rax, rdi
        ret
