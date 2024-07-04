%define NULL_BYTE  0x0

section .text

global strlen
    strlen:
        xor rax, rax
        .loop:
            cmp byte [rdi + rax], NULL_BYTE
            je .go_ret
            inc rax
            jmp .loop

        .go_ret:
            ret
        