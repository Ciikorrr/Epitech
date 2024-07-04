BITS 64

global strcasecmp

strcasecmp:
    push rbp
    mov rbp, rsp

    xor rax, rax
    jmp check_first_string

lower_first_string:
    add r8b, 32
    jmp check_second_string

lower_second_string:
    add r9b, 32
    jmp compare

check_first_string:
    mov r8b, [rdi + rax]
    cmp r8b, 65
    jl check_second_string
    cmp r8b, 90
    jl lower_first_string

check_second_string:
    mov r9b, [rsi + rax]
    cmp r9b, 65
    jl compare
    cmp r9b, 90
    jl lower_second_string

compare:
    cmp r8b, 0
    je end
    cmp r9b, 0
    je end

    cmp r8b, r9b
    jne end

    inc rax
    jmp check_first_string

end:
    sub r8b, r9b
    movsx rax, r8b

    mov rsp, rbp
    pop rbp

    ret