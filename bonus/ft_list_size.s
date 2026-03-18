
; int ft_list_size(t_list *begin_list);

struc   node
    .data:  resq 1
    .next:  resq 1
endstruc

section .text
    global ft_list_size

ft_list_size:
    ; rdi = t_list *begin_list

    mov rax, 0

    ._loop:
        test rdi, rdi
        jz .end

        inc rax
        mov rdi, [rdi + node.next]
        jmp ._loop

    .end:
        ret
