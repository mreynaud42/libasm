*This project has been created as part of the 42 curriculum by **mreynaud**.*

# libasm

## Description
The libasm project consists of re-implementing several standard C library functions using x86-64 assembly. The goal is to understand low-level system calls, memory management, and string operations while gaining proficiency in assembly language. This project covers both mandatory and bonus functions, including string manipulation, file I/O, memory allocation, and linked list operations.

By completing this project, you will deepen your understanding of:
- Writing functions in assembly with proper calling conventions.
- Using Linux syscalls directly for I/O operations.
- Implementing data structures like linked lists in low-level code.
- Debugging and optimizing assembly routines for efficiency.

## Registers

| Register | Low/High byte | 16-bit | 32-bit | 64-bit | Description |
|----------|---------------|--------|--------|--------|-------------|
| **Caller-saved registers** |
| RAX      | AL / AH       | AX     | EAX    | RAX    | Accumulator, return value, temporary |
| RDI      | DIL           | DI     | EDI    | RDI    | 1st argument, destination index for string ops |
| RSI      | SIL           | SI     | ESI    | RSI    | 2nd argument, source index for string ops |
| RDX      | DL / DH       | DX     | EDX    | RDX    | 3rd argument, data register, temporary |
| RCX      | CL / CH       | CX     | ECX    | RCX    | 4th argument, counter, temporary |
| R8       | R8B           | R8W    | R8D    | R8     | 5th argument, temporary |
| R9       | R9B           | R9W    | R9D    | R9     | 6th argument, temporary |
| R10      | R10B          | R10W   | R10D   | R10    | Temporary register, scratch |
| R11      | R11B          | R11W   | R11D   | R11    | Temporary register, scratch |
| **Callee-saved registers** |
| RBX      | BL / BH       | BX     | EBX    | RBX    | Base register, preserved across calls |
| RBP      | BPL           | BP     | EBP    | RBP    | Base pointer, stack frame pointer |
| RSP      | SPL           | SP     | ESP    | RSP    | Stack pointer, points to top of stack |
| R12      | R12B          | R12W   | R12D   | R12    | Preserved register, can hold pointers |
| R13      | R13B          | R13W   | R13D   | R13    | Preserved register, can hold pointers |
| R14      | R14B          | R14W   | R14D   | R14    | Preserved register, can hold pointers |
| R15      | R15B          | R15W   | R15D   | R15    | Preserved register, can hold pointers |
| **Special / System registers** |
| RIP      | —             | —      | —      | RIP    | Instruction pointer, holds address of next instruction |
| RFLAGS   | —             | —      | —      | RFLAGS | CPU status flags, condition codes |
| CS       | —             | CS     | CS     | CS     | Code segment selector |
| DS       | —             | DS     | DS     | DS     | Data segment selector |
| ES       | —             | ES     | ES     | ES     | Extra segment selector |
| FS       | —             | FS     | FS     | FS     | Thread-local storage / extra data |
| GS       | —             | GS     | GS     | GS     | Thread-local storage / extra data |
| SS       | —             | SS     | SS     | SS     | Stack segment selector |


## Function

### Mandatory
#### ft_strlen
```c
size_t   ft_strlen(const char *s);
```
Returns the length of a string ```s``` (number of characters before the null terminator).
Equivalent to the standard ```strlen``` function.

#### ft_strcpy
```c
char    *ft_strcpy(char *dest, const char *src);
```
Copies the string pointed to by ```src``` (including the terminating null byte) into the buffer dest.
Equivalent to the standard ```strcpy```.

#### ft_strcmp
```c
int ft_strcmp(const char *s1, const char *s2);
```
Compares two strings ```s1``` and ```s2``` lexicographically.
Returns ```0``` if they are equal, a negative value if ```s1 < s2```, and a positive value if ```s1 > s2```.
Equivalent to the standard ```strcmp```.

#### ft_write
```c
ssize_t ft_write(int fd, const void *buf, size_t count);
```
Writes ```count``` bytes from the buffer ```buf``` to the file descriptor ```fd```.
Directly uses the Linux ```write``` syscall. Returns the number of bytes written or ```-1``` on error.

#### ft_read
```c
ssize_t ft_read(int fd, void *buf, size_t count);
```
Reads up to ```count``` bytes from the file descriptor ```fd``` into the buffer ```buf```.
Directly uses the Linux ```read``` syscall. Returns the number of bytes read or ```-1``` on error.


#### ft_strdup
```c
char    *ft_strdup(const char *s);
```
Allocates sufficient memory for a copy of the string ```s``` and returns a pointer to it.
Equivalent to the standard ```strdup```.

### Bonus
#### Preamble
```c
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;
```
Defines a basic singly linked list structure for bonus functions. Each node contains a pointer to data and the next node in the list.

#### ft_atoi_base
```c
int ft_atoi_base(char *str, char *base);
```
Converts the string ```str``` to an integer using the numeral system defined by ```base```.
Supports bases of arbitrary length (e.g., binary, decimal, hexadecimal).

#### ft_list_push_front
```c
void    ft_list_push_front(t_list **begin_list, void *data);
```
Creates a new list node with ```data``` and inserts it at the beginning of the linked list pointed to by ```begin_list```.

#### ft_list_size
```c
int ft_list_size(t_list *begin_list);
```
Returns the number of elements in the linked list starting at ```begin_list```.

#### ft_list_sort
```c
void    ft_list_sort(t_list **begin_list, int (*cmp)());
```
Sorts the linked list in ascending order according to the comparison function ```cmp```.
```cmp``` should return negative, zero, or positive depending on the comparison.

#### ft_list_remove_if
```c
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
```
Removes from the list all nodes whose ```data``` matches ```data_ref``` according to the comparison function ```cmp```.
Frees the removed nodes using ```free_fct```.

## Resources
- [Intel 64 and IA-32 Architectures Software Developer’s Manual](https://www.intel.fr/content/www/fr/fr/content-details/782158/intel-64-and-ia-32-architectures-software-developer-s-manual-combined-volumes-1-2a-2b-2c-2d-3a-3b-3c-3d-and-4.html) - Reference for assembly instructions and conventions.

- [NASM manual](https://www.nasm.us/doc/nasm00.html) - Documentation for the Netwide Assembler.

- [syscalls linux source](https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/tree/arch/x86/entry/syscalls/syscall_64.tbl?h=v5.15.202) - Table of Linux system call numbers.
