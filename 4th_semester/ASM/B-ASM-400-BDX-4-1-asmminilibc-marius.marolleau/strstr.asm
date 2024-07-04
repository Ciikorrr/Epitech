BITS 64
%define NULL_BYTE 0x0

extern strncmp, strlen

section .text
    global strstr
    strstr:
        xor rbx, rbx

        .loop:
            mov r8, rbx
            xor rcx, rcx

        .sub_loop:
            mov al, byte [rsi + rcx]
            cmp al, 0x0
            je .end_found
            mov dl, byte [rdi + r8]
            cmp dl, 0x0
            je .end_null
            cmp dl, al
            je .inc_idx
            inc rbx
            jmp .loop

        .inc_idx:
            inc rcx
            inc r8
            jmp .sub_loop

        .end_null:
            xor rax, rax
            ret
        
        .end_found:
            mov rax, rdi
            add rax, rbx
            ret