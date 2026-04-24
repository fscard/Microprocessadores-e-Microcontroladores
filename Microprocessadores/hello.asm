; ================================================================
; Programa: Hello World em Assembly x86 para Linux 32 bits
; Autor: Prof. Fábio de Sousa Cardoso
; Arquivo: hello32.asm
;
; Descrição:
; Este programa apresenta um exemplo básico de escrita em Assembly
; para arquitetura x86 (32 bits) no sistema operacional Linux.
;
; O programa executa duas ações principais:
; 1) escreve a mensagem "Hello, World!" na saída padrão (terminal);
; 2) encerra o processo com código de retorno 0.
;
; Conceitos ilustrados:
; - organização do programa em seções (.data e .text)
; - definição de string em memória
; - uso do ponto de entrada _start
; - chamadas de sistema no Linux 32 bits com int 0x80
; - uso dos registradores eax, ebx, ecx e edx
;
; Chamada de sistema usada para escrita:
;   write(1, hello, 14)
; onde:
;   1      -> descritor da saída padrão (stdout)
;   hello  -> endereço inicial da string
;   14     -> número de bytes a escrever
;
; Observação:
; A string possui quebra de linha no final (ASCII 10), por isso
; o total de bytes escritos é 14.
;
; Chamada de sistema usada para encerramento:
;   exit(0)
;
; ----------------------------------------------------------------
; Como compilar e executar este programa
; ----------------------------------------------------------------
; 1. Montar o código-fonte com o NASM:
;    nasm -f elf32 hello32.asm -o hello32.o
;
; 2. Fazer a linkedição com o ld:
;    ld -m elf_i386 hello32.o -o hello32
;
; 3. Executar o programa:
;    ./hello32
;
; ----------------------------------------------------------------
; Requisitos
; ----------------------------------------------------------------
; - Linux com suporte a binários 32 bits
; - NASM instalado
; - ld (linker) disponível no sistema
;
; Exemplo de instalação no Ubuntu/Debian:
;    sudo apt update
;    sudo apt install nasm
;
; Em alguns sistemas 64 bits, pode ser necessário suporte adicional
; para executar programas 32 bits.
; ================================================================

section .data
    ; Define uma string na memória com o texto "Hello, World!"
    ; O valor 10 ao final representa a quebra de linha (\n).
    hello db 'Hello, World!', 10

section .text
    ; Torna o rótulo _start visível para o linker.
    ; Esse rótulo será o ponto de entrada do programa.
    global _start

_start:
    ; ============================================================
    ; Chamada de sistema sys_write
    ; Objetivo: escrever "Hello, World!" na saída padrão
    ;
    ; Assinatura lógica:
    ;   write(fd, buffer, tamanho)
    ;
    ; Neste exemplo:
    ;   fd      = 1       -> stdout
    ;   buffer  = hello   -> endereço da string
    ;   tamanho = 14      -> 13 caracteres + quebra de linha
    ;
    ; Convenção de chamadas de sistema no Linux x86 32 bits:
    ;   eax -> número da syscall
    ;   ebx -> 1º argumento
    ;   ecx -> 2º argumento
    ;   edx -> 3º argumento
    ; ============================================================

    mov eax, 4         ; eax = número da syscall sys_write
    mov ebx, 1         ; ebx = descritor de arquivo 1 (stdout)
    mov ecx, hello     ; ecx = endereço inicial da string
    mov edx, 14        ; edx = quantidade de bytes a escrever
    int 0x80           ; chama o kernel

    ; ============================================================
    ; Chamada de sistema sys_exit
    ; Objetivo: encerrar o programa
    ;
    ; Assinatura lógica:
    ;   exit(codigo)
    ;
    ; Neste exemplo:
    ;   codigo = 0 -> término normal, sem erro
    ; ============================================================

    mov eax, 1         ; eax = número da syscall sys_exit
    xor ebx, ebx       ; ebx = 0, código de retorno
    int 0x80           ; chama o kernel e finaliza o programa
