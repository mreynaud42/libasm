
; char *ft_strdup(const char *s);
; rax ft_strdup rdi

; rdi rsi rdx rcx r8 r9

extern malloc
extern ft_strlen
extern ft_strcpy

section .text
    global ft_strdup

ft_strdup:
    call ft_strlen

    inc rax         ; add 1 for \0
    mov r12, rdi    ; save rdi in r12
    mov rdi, rax
    call malloc wrt ..plt
    test rax, rax   ; set flags
    jnz .ok

    
    .error:         ; if errno=ENOMEM
        ret

    .ok:
        mov rdi, rax
        mov rsi, r12
        call ft_strcpy

        ret
