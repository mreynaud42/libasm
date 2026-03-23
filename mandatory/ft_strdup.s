
; Prototype:
; char *ft_strdup(const char *s);
; rax ft_strdup rdi

; rdi rsi rdx rcx r8 r9

extern malloc
extern ft_strlen
extern ft_strcpy

section .text
    global ft_strdup

ft_strdup:
    ; rdi = const char *s

    push rdi    ; save rdi
    sub rsp, 8  ; align stack

    call ft_strlen

    inc rax         ; add 1 for \0
    mov rdi, rax
    call malloc wrt ..plt

    add rsp, 8      ; restore align stack

    test rax, rax   ; set flags
    jnz .ok

    
    .error:         ; if errno=ENOMEM
        pop rdi
        ret

    .ok:
        mov rdi, rax
        pop rsi
        call ft_strcpy

        ret
