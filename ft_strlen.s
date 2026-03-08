
default rel

section .data
   hello: db "Hello world!\n", 0
	helloLen: equ $-hello

section .bss

section .text
   global main
main:
   lea rdi, hello
   call ft_strlen
   xor rax, rax
   ret

   global ft_strlen   
ft_strlen:
   ; size_t strlen(const char *s);
   ; rdi rsi rdx rcx r8 r9
   mov rcx, 0

   _loop:
      cmp byte [rdi+rcx], 0
      je return
      cmp rcx, 20
      je return_error
      inc rcx
      jmp _loop
   
   return_error:
      mov rax, -1
      ret

   return:
      mov rax, rcx
      ret
