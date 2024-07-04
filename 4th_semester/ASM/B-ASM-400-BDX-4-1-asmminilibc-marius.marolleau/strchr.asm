BITS 64
%define NULL_BYTE 0x0

index:
section .text
    global strchr
    strchr:
        xor rax, rax
        .loop:
            cmp byte [rdi], NULL_BYTE
            je .go_check_null
            cmp byte [rdi], sil
            je .go_end
            inc rdi
            jmp .loop
            
        .go_end:
            lea rax, [rdi]
            ret

        .go_check_null:
            cmp byte sil, 0
            je .go_end
            ret

        .go_null:
            mov rax, NULL_BYTE
            ret

