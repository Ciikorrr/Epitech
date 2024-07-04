BITS 64 ; Achitecure
%define NULL_BYTE 0x0

section .text
    global strncmp
    strncmp:
        xor rax, rax
        cmp rdx, 0
        je .go_special_end
        dec rdx
        .loop:
            cmp byte [rdi + rax], NULL_BYTE
            je .go_end
            cmp byte [rsi + rax], NULL_BYTE
            je .go_end
            cmp rax, rdx
            je .go_end
            mov r8b, byte [rsi + rax]
            cmp r8b, byte [rdi + rax]
            jne .go_end
            inc rax
            jmp .loop

        .go_end:
            mov r9b, byte [rsi + rax]
            mov r8b, byte [rdi + rax]
            sub r8, r9
            lea rax, [r8]
            ret
        
        .go_special_end:
            ret
