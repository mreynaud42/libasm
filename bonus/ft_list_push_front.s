
; void ft_list_push_front(t_list **begin_list, void *data);

extern malloc

struc   node
    .data:  resq 1 ; resq 1 = 8 bytes = 64 bits
    .next:  resq 1
endstruc

section .text
    global ft_list_push_front

ft_list_push_front:
    ; rdi = t_list **begin_list
    ; rsi = void *data

    .create_node:
        push rdi
        push rsi

        ; call malloc
        sub rsp, 8              ; align stack to 16 bytes before call
        mov rdi, node_size      ; node_size generate with NASM
        call malloc wrt ..plt   ; with respect to Procedure Linkage Table
        add rsp, 8              ; restore stack

        pop rsi
        pop rdi
    
        test rax, rax
        jnz .ok

    .error:     ; malloc failed
        ret

    .ok:
        ; new->data = data
        mov [rax + node.data], rsi  

        ; new->next = old head (*begin_list)
        mov r10, [rdi]
        mov [rax + node.next], r10

        mov [rdi], rax

        ret
