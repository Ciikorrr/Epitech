BITS 64
%define NULL_BYTE 0x0

section .text
    global memcpy
    memcpy:
        xor rcx, rcx
        .loop:
            cmp rdx, 0
            je .go_end
            mov r8b, byte [rsi + rcx]
            mov byte [rdi + rcx ], r8b
            inc rcx
            dec rdx
            jmp .loop
        .go_end:
            mov rax, rdi
            ret