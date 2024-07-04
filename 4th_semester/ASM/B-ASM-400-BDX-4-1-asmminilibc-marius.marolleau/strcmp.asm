BITS 64 ; Achitecure
%define NULL_BYTE 0x0
section .text
    global strcmp
    strcmp:
        xor rax, rax
        xor r8, r8
        xor r9, r9
        .loop_compare:
            cmp byte [rdi + rax], NULL_BYTE     ; Compare if the value in bl is a null byte
            je .exit_process     ; Jump to the end of the function
            cmp byte [rsi + rax], NULL_BYTE      ; ''
            je .exit_process     ; ''
            mov r8b, byte [rsi + rax]
            cmp r8b, byte [rdi + rax]          ; 
            jne .exit_process       ; If it's not equal, go to exit_loop
            inc rax             ; else, incremente the pointer of rsi
            jmp .loop_compare    ; go back to the start of the label

        .exit_process:
            mov r9b, byte [rsi + rax]
            mov r8b, byte [rdi + rax]
            sub r8, r9
            mov rax, r8
            ret
