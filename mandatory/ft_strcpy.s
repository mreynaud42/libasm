
; Prototype:
; char *ft_strcpy(char *dest, const char *src);
; rax ft_strcpy rdi rsi

; rdi rsi rdx rcx r8 r9

section .text
    global ft_strcpy

ft_strcpy:
    ; rdi = char *dest
    ; rsi = const char *src

    mov rax, rdi
    cld                     ; Clear Direction Flag

    .loop_:
        cmp BYTE [rsi], 0
        je .end_string
        movsb               ; Move Data From String to String (and inc)
        jmp .loop_
   
    .end_string:
        mov BYTE [rdi], 0
        ret
