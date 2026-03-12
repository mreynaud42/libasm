
; size_t ft_strlen(const char *s);
; rax ft_strlen rdi ; rax = size_t = 64 bits

; rdi rsi rdx rcx r8 r9

section .text
    global ft_strlen

ft_strlen:
    mov rax, rdi

    .loop_:
        cmp BYTE [rax], 0
        je .end_string
        inc rax
        jmp .loop_

    .end_string:
        sub rax, rdi
        ret
