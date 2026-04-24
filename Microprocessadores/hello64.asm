; ================================================================
; Programa: Hello World em Assembly x86-64 para Linux
; Autor: Prof. Fábio de Sousa Cardoso
; Arquivo: hello64.asm
;
; Descrição:
; Este programa demonstra um exemplo mínimo de escrita em Assembly
; para arquitetura x86-64 no sistema operacional Linux.
;
; O programa realiza duas operações principais:
; 1) escreve a mensagem "Hello, World!" na saída padrão (terminal);
; 2) encerra o processo com código de retorno 0.
;
; Conceitos ilustrados:
; - organização do código em seções (.data e .text)
; - declaração de dados em memória
; - cálculo automático do tamanho da string
; - uso do ponto de entrada _start
; - chamadas de sistema no Linux x86-64 com a instrução syscall
; - uso dos registradores rax, rdi, rsi e rdx
;
; Chamada de sistema usada para escrita:
;   write(1, hello, len)
; onde:
;   1     -> descritor da saída padrão (stdout)
;   hello -> endereço da string
;   len   -> quantidade de bytes a escrever
;
; Chamada de sistema usada para encerramento:
;   exit(0)
;
; ----------------------------------------------------------------
; Como compilar e executar este programa
; ----------------------------------------------------------------
; 1. Montar o código-fonte com o NASM:
;    nasm -f elf64 hello64.asm -o hello64.o
;
; 2. Fazer a linkedição com o ld:
;    ld hello64.o -o hello64
;
; 3. Executar o programa:
;    ./hello64
;
; ----------------------------------------------------------------
; Requisitos
; ----------------------------------------------------------------
; - Linux 64 bits
; - NASM instalado
; - ld (linker) disponível no sistema
;
; Exemplo de instalação no Ubuntu/Debian:
;    sudo apt update
;    sudo apt install nasm
;
; ================================================================

section .data
    ; String que será exibida no terminal.
    ; O valor 10 representa o caractere de quebra de linha (\n).
    hello db 'Hello, World!', 10

    ; Calcula automaticamente o tamanho da string.
    ; O símbolo $ representa a posição atual na montagem.
    ; Assim, len = endereço atual - endereço inicial de hello.
    len equ $ - hello

section .text
    ; Torna o rótulo _start visível ao linker.
    ; Esse será o ponto de entrada do programa.
    global _start

_start:
    ; ============================================================
    ; syscall write
    ; Objetivo: escrever a mensagem no terminal
    ;
    ; Assinatura lógica:
    ;   write(fd, buffer, tamanho)
    ;
    ; Neste exemplo:
    ;   fd      = 1       -> stdout
    ;   buffer  = hello   -> endereço da string
    ;   tamanho = len     -> número de bytes
    ;
    ; Convenção de chamadas de sistema no Linux x86-64:
    ;   rax -> número da syscall
    ;   rdi -> 1º argumento
    ;   rsi -> 2º argumento
    ;   rdx -> 3º argumento
    ; ============================================================
    mov rax, 1          ; syscall 1 = write
    mov rdi, 1          ; descritor 1 = saída padrão (stdout)
    mov rsi, hello      ; endereço inicial da mensagem
    mov rdx, len        ; quantidade de bytes a escrever
    syscall             ; chama o kernel

    ; ============================================================
    ; syscall exit
    ; Objetivo: encerrar o programa
    ;
    ; Assinatura lógica:
    ;   exit(codigo)
    ;
    ; Neste exemplo:
    ;   codigo = 0 -> término normal, sem erro
    ; ============================================================
    mov rax, 60         ; syscall 60 = exit
    xor rdi, rdi        ; rdi = 0, código de retorno
    syscall             ; encerra o processo