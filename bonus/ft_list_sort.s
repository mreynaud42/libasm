
; void ft_list_sort(t_list **begin_list, int (*cmp)());

struc   node
    .data:  resq 1
    .next:  resq 1
endstruc

section .text
    global ft_list_sort

; use Bubble Sort
ft_list_sort:
    ; rdi = t_list **begin_list
    ; rsi = int (*cmp)()

    test rdi, rdi   ; if begin_list is null
    je .return

    test rsi, rsi   ; if cmp is null
    je .return

    mov rax, [rdi]  ; rax = head

    test rax, rax   ; if head is null
    je .return

    push r12
    push r13
    push r14
    push r15
    push rbx

    mov r13, rdi    ; save **begin_list in r13
    mov r14, rax  ; r14 = head

    ; create dummy node
    sub rsp, node_size          ; prepare rsp for dummy node

    mov [rsp + node.next], r14  ; dummy.next = head = r14
    mov r14, rsp                ; r14 = dummy node = prev

    mov r15, r14                ; save dummy node in r15

    mov r8, [r14 + node.next]   ; r8 = current node = a

    mov r12, rsi                ; save int (*cmp)() in r12

    mov rbx, 0                  ; rbx = null = last node list

    ._loop1:
        ._loop2:

            mov r9, [r8 + node.next]    ; r9 = b = a.next
        
            cmp r9, rbx     ; if last node list not sort
            je .endloop2
    
            ; int cmp(a.data, b.data)
            ; call cmp function
            mov rdi, [r8 + node.data]   ; rdi = a.data
            mov rsi, [r9 + node.data]   ; rsi = b.data
            call r12                    ; call cmp

            test rax, rax   ; if a.data > b.data
            jg .swap

            jmp .endswap
            .swap:   ; swap node a and b
                                            ; r14 = prev
                mov r8, [r14 + node.next]   ; r8 = a
                mov r9, [r8 + node.next]    ; r9 = b
                mov r10, [r9 + node.next]   ; r10 = c

                mov [r14 + node.next], r9   ; prev.next = b
                mov [r9 + node.next], r8    ; b.next = a
                mov [r8 + node.next], r10   ; a.next = c

            .endswap:

            mov r14, [r14 + node.next]      ; inc r14

            mov r8, [r14 + node.next]       ; r8 = a

            jmp ._loop2
        .endloop2:

        cmp r8, [r15 + node.next]  ; if list sort
        je .end

        mov rbx, r8                 ; last node list
        mov r14, r15                ; r14 = dummy node = prev
        mov r8, [r14 + node.next]   ; r8 = a

        jmp ._loop1


    .end:
        mov r14, [r15 + node.next]  ; r14 = dummy_node.next
        mov [r13], r14  ; [r13] = *begin_list = r14 = new_head

        add rsp, node_size

        pop rbx
        pop r15
        pop r14
        pop r13
        pop r12

    .return:
        ret
