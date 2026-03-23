
; Prototype:
; ssize_t ft_read(int fd, void *buf, size_t count);
; rax ft_read rdi rsi rdx

; rdi rsi rdx rcx r8 r9

%define SYS_READ 0

extern __errno_location

section .text
    global ft_read

ft_read:
    ; rdi = int fd
    ; rsi = void *buf
    ; rdx = size_t count

    mov rax, SYS_READ
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
