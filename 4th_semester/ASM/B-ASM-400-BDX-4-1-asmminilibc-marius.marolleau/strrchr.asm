BITS 64

extern strlen

rindex:
section .text
    global strrchr
    strrchr:
            xor rax, rax
            call strlen wrt ..plt
        .loop:
            cmp sil, byte [rdi + rax]
            je .go_end
            cmp rax, 0x0
            je .null
            sub rax, 1
            jmp .loop

        .go_end:
            add rdi, rax
            mov rax, rdi
            ret
        .null:
            mov rax, 0x0
            ret