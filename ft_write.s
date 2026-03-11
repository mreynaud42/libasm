
; ssize_t ft_write(int fd, const void *buf, size_t count);
; rax ft_write rdi rsi rdx

; rdi rsi rdx rcx r8 r9

%define SYS_WRITE 1

extern __errno_location

section .text
    global ft_write

ft_write:
    mov rax, SYS_WRITE
    syscall

    test rax, rax   ; set flags
    jns .ok         ; Jump if SignFlag=1 

    .error:
        neg rax
        mov rdi, rax

        call __errno_location wrt ..plt ; = __errno_location's address relative to Procedure Linkage Table

        mov [rax], edi
        mov rax, -1
        ret

    .ok:
        ret
