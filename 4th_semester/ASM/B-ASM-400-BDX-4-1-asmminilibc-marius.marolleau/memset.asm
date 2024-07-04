BITS 64
%define NULL_BYTE 0x0

section .text
    global memset
    memset:
        xor rax, rax
        .loop:
            cmp rdx, 0
            je .go_end
            mov byte [rdi + rdx - 1], sil
            dec rdx
            jmp .loop
        .go_end:
            mov rax, rdi
            ret