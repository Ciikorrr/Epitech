BITS 64
%define NULL_BYTE 0x0

section .text
    global strcspn
    strcspn:
        xor rax, rax
        xor r8, r8
        xor r9, r9
        xor rcx, rcx
        .loop:
            xor r8, r8
            cmp byte [rdi + rax], NULL_BYTE
            je .go_end
            jmp .verif_substr

        .verif_substr:
            cmp byte [rsi + r8], NULL_BYTE
            je .not_in
            mov r9b, byte [rsi + r8]
            cmp r9b, byte [rdi + rax]
            je .go_end
            inc r8
            jmp .verif_substr

        .not_in:
            inc rax
            jmp .loop

        .go_end:
            ret