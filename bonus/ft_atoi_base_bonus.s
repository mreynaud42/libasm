
; Prototype:
; int ft_atoi_base(char *str, char *base);

section .text
    global ft_atoi_base


; fuction isspace
; rdi = char c
isspace:
    cmp dil, ' '
    je .isspace_true

    cmp dil, 9          ; '\t' (horizontal tab)
    je .isspace_true

    cmp dil, 10         ; '\n' (new line)
    je .isspace_true

    cmp dil, 11         ; '\v' (vertical tab)
    je .isspace_true

    cmp dil, 12         ; '\f' (form feed)
    je .isspace_true

    cmp dil, 13         ; '\r' (carriage ret)
    je .isspace_true

    mov rax, 0
    ret

.isspace_true:
    mov rax, 1
    ret


; fuction check_base
; rdi = char *base
check_base:
    mov rsi, rdi    ; init ptr
    mov r11, rdi    ; save rdi

    .check_base_loop:
        mov dl, [rsi]

        test dl, dl
        jz .end_check_base_loop

        cmp dl, '+'
        je .end_check_base_false

        cmp dl, '-'
        je .end_check_base_false

        mov dil, dl
        call isspace

        test rax, rax
        jnz .end_check_base_false

        mov r8, rsi
        .check_base_loop2:
            inc r8

            mov r9b, [r8]

            test r9b, r9b
            jz .end_check_base_loop2

            cmp r9b, dl
            je .end_check_base_false

            jmp .check_base_loop2
        .end_check_base_loop2:

        inc rsi
        jmp .check_base_loop

    .end_check_base_loop:
        sub rsi, r11
        mov rax, rsi
        ret

    .end_check_base_false:
        mov rax, 0
        ret


; fuction ft_atoi_base
; rdi = char *str
; rsi = char c
strfind:
    mov rax, rdi

    .strfind_loop:
        mov r8b, [rax]

        test r8b, r8b
        je .end_strfind_false

        cmp r8b, sil            ; *str == c
        je .end_strfind_loop

        inc rax
        jmp .strfind_loop

    .end_strfind_loop:
    sub rax, rdi
    ret

    .end_strfind_false:
    mov rax, -1
    ret


; fuction ft_atoi_base
; rdi = char *str
; rsi = char *base
ft_atoi_base:
    test rdi, rdi   ; if str is null
    je .return_false

    test rsi, rsi   ; if base is null
    je .return_false

    push r12
    push r13
    push r14
    push r15
    push rbx

    mov r12, rdi    ; r12 is str
    mov r13, rsi    ; r13 is base
    mov r14, 0      ; r14 is result
    mov rbx, 1      ; rbx is sign result

    mov rdi, r13
    call check_base

    cmp rax, 2
    jl .end_false

    mov r15, rax      ; r15 is base_len

    .skip_whitespace_loop:
        mov dil, [r12]
        call isspace

        test al, al
        jz .end_skip_whitespace_loop
    
        inc r12
        jmp .skip_whitespace_loop
    .end_skip_whitespace_loop:

    mov r8b, [r12]
    .check_sign:
    cmp r8b, '+'
    jne .check_minus

    inc r12

    jmp .end_check_sign
    .check_minus:
    cmp r8b, '-'
    jne .end_check_sign

    neg rbx
    inc r12
    .end_check_sign:

    .ft_atoi_base_loop:
        mov rdi, r13
        mov sil, [r12]
        call strfind

        cmp eax, -1
        je .end_ft_atoi_base_loop

        mov r8d, eax
        mov eax, r14d

        mul r15d    ; result * base_len

        add eax, r8d

        mov r14d, eax

        inc r12

        jmp .ft_atoi_base_loop
    .end_ft_atoi_base_loop:

.end:
    mov eax, r14d
    imul ebx

    pop rbx
    pop r15
    pop r14
    pop r13
    pop r12

    ret

.end_false:
    pop rbx
    pop r15
    pop r14
    pop r13
    pop r12

.return_false:
    mov rax, 0
    ret
