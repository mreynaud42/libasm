
; int ft_strcmp(const char *s1, const char *s2);
; rax ft_strcmp rdi rsi

; rdi rsi rdx rcx r8 r9

section .text
    global ft_strcmp

ft_strcmp:
    .loop:
        mov al, [rdi]
        mov dl, [rsi]

        cmp al, dl
        jne .diff

        test al, al     ; if end string
        je .end_string  ; return 0

        inc rsi
        inc rdi
        jmp .loop
   
    .diff:
        movzx rax, al   ; Move With Zero-Extend
        movzx rdx, dl   ; Move With Zero-Extend
        sub rax, rdx
        ret
    
    .end_string:
        xor rax, rdx    ; set 0
        ret
