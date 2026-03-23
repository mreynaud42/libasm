
; Prototype:
; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

struc   node
    .data:  resq 1
    .next:  resq 1
endstruc

section .text
    global ft_list_remove_if

; The functions pointed to by cmp and free_fct will be used as:
; (*cmp)(list_ptr->data, data_ref);
; (*free_fct)(list_ptr->data);
ft_list_remove_if:
    ; rdi = t_list **begin_list
    ; rsi = void *data_ref
    ; rdx = int (*cmp)()
    ; rcx = void (*free_fct)(void *)

    test rdi, rdi   ; if begin_list is null
    je .return

    test rsi, rsi   ; if data_ref is null
    je .return

    test rdx, rdx   ; if cmp is null
    je .return

    test rcx, rcx   ; if free_fct is null
    je .return

    mov rax, [rdi]  ; rax = head

    test rax, rax   ; if head is null
    je .return

    push rdi    ; save rdi
    push r12
    push r13
    push r14
    push r15

    sub rsp, 8  ; align stack

    ; create dummy node
    sub rsp, node_size          ; prepare rsp for dummy node

    mov [rsp + node.next], rax  ; dummy.next = head = rax

    mov r12, rdx    ; r12 is function cmp
    mov r13, rcx    ; r13 is function free_fct
    mov r14, rsi    ; r14 is data_ref
    mov r15, rsp    ; r15 = dummy node = prev

    ._loop:
        mov r8, [r15 + node.next]   ; r8 = a
        
        test r8, r8
        jz .end

        mov rdi, [r8 + node.data]   ; rdi = a.data
        mov rsi, r14                ; rsi = data_ref
        call r12                    ; cmp

        test rax, rax
        je .free

        mov r15, [r15 + node.next]  ; prev = prev->next

        jmp .endfree
        .free:
            mov r9, [r8 + node.next]    ; r9 = b
            mov [r15 + node.next], r9   ; prev->next = b

            mov rdi, [r8 + node.data]   ; rdi a.data
            call r13                    ; free_fct

            ; free a ?

        .endfree:

        jmp ._loop

    .end:

        mov rax, [rsp + node.next]  ; get head

        add rsp, node_size

        add rsp, 8  ; restore stack

        pop r15
        pop r14
        pop r13
        pop r12
        pop rdi

        mov [rdi], rax              ; update head

    .return:
        ret
