BITS 64

global memmove

memmove:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    mov r8, rdi
    sub r8, rsi
    cmp r8, 0
    jge overlap_right

    loop_left:
        xor rcx, rcx
    
    loop_left_inner:
        cmp rcx, rdx
        je end
        mov r8b, [rsi + rcx]
        mov [rdi + rcx], r8b
        inc rcx
        jmp loop_left_inner
    
    overlap_right:
        dec rdx
    
    loop_right:
        cmp rdx, 0
        jl end
        mov r8b, [rsi + rdx]
        mov [rdi + rdx], r8b
        dec rdx
        jmp loop_right
    
    end:
        mov rsp, rbp
        pop rbp
        ret