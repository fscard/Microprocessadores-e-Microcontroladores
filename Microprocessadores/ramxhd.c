/*
 * Título do Programa: Benchmark de Acesso à Memória RAM e Disco Rígido
 * 
 * Descrição: 
 * Programa que compara o tempo de acesso e operações em memória RAM 
 * e em disco rígido. Realiza operações de escrita e leitura em um 
 * buffer de tamanho predefinido, medindo o tempo de execução para 
 * cada tipo de armazenamento.
 * 
 * Funcionalidades principais:
 * - Alocação de buffer em memória RAM
 * - Medição de tempo de escrita em memória RAM
 * - Criação de arquivo para operações em disco
 * - Medição de tempo de escrita e leitura em disco rígido
 * - Comparação de desempenho entre RAM e disco
 * 
 * Conceitos demonstrados:
 * - Alocação dinâmica de memória
 * - Medição de tempo com clock_gettime()
 * - Operações de arquivo
 * - Comparação de performance de armazenamento
 * 
 * Autor: Fabio Cardoso
 * Data de criação: 23/11/2024
 * 
 * Como compilar:
 * No terminal, execute:
 * gcc -Wall -Wextra -o ramxhd ramxhd.c -lrt
 * 
 * Como executar:
 * - No Linux/Mac: ./ramxhd
 * - No Windows: ramxhd.exe
 * 
 * Pré-requisitos:
 * - Sistema Linux (para clock_gettime())
 * - Biblioteca librt
 * 
 * Observações:
 * - A flag -lrt é necessária para linkar a biblioteca de tempo real
 * - Resultados podem variar dependendo do hardware
 * - Sempre libere memória alocada dinamicamente
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE (1024 * 1024)  // 1 MB
#define FILE_SIZE (1024 * 1024 * 10)  // 10 MB

// Função para acessos na RAM
void ramAccess() {
    // Aloca um buffer na memoria RAM
    char* buffer = (char*)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Erro na alocação de memória RAM\n");
        return;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Operacoes de escrita na memoria RAM
    memset(buffer, 'A', BUFFER_SIZE);
    
    // Operacoes com os dados escritos na memoria RAM
    for (int j = 0; j < BUFFER_SIZE; j++) {
        char data = buffer[j];  // Exemplo de operação de leitura
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Tempo para acesso a memoria RAM: %f segundos\n", time_taken);
    
    free(buffer); 
}

// Função para acessos em disco
void diskAccess() {
    // Abre o arquivo para escrita e leitura
    FILE* file = fopen("data.bin", "wb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }

    // Aloca um buffer para escrever dados no disco rígido
    char* write_buffer = (char*)malloc(BUFFER_SIZE);
    char* read_buffer = (char*)malloc(BUFFER_SIZE);
    
    if (write_buffer == NULL || read_buffer == NULL) {
        printf("Erro na alocação de memória para disco\n");
        free(write_buffer);
        free(read_buffer);
        fclose(file);
        return;
    }

    // Preenche o buffer com dados
    memset(write_buffer, 'B', BUFFER_SIZE);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Escreve os dados no arquivo (disco rígido)
    size_t total_written = 0;
    size_t chunks = FILE_SIZE / BUFFER_SIZE;

    for (size_t i = 0; i < chunks; i++) {
        size_t written = fwrite(write_buffer, 1, BUFFER_SIZE, file);
        if (written != BUFFER_SIZE) {
            printf("Erro na escrita do arquivo no bloco %zu\n", i);
            fclose(file);
            free(write_buffer);
            free(read_buffer);
            return;
        }
        total_written += written;
    }

    // Força a gravação dos dados no disco
    fflush(file);

    // Volta para o início do arquivo
    rewind(file);

    // Operações de leitura no disco rígido
    size_t total_read = 0;
    for (size_t i = 0; i < chunks; i++) {
        // Lê os dados do arquivo (disco rígido) para o buffer
        size_t read = fread(read_buffer, 1, BUFFER_SIZE, file);
        
        if (read != BUFFER_SIZE) {
            printf("Erro na leitura do arquivo no bloco %zu\n", i);
            printf("Bytes lidos: %zu, Bytes esperados: %d\n", read, BUFFER_SIZE);
            break;
        }

        // Verifica os dados lidos
        for (int j = 0; j < BUFFER_SIZE; j++) {
            if (read_buffer[j] != 'B') {
                printf("Dado incorreto lido no bloco %zu\n", i);
                break;
            }
        }
        
        total_read += read;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Total de bytes escritos: %zu\n", total_written);
    printf("Total de bytes lidos: %zu\n", total_read);
    printf("Tempo para acesso ao HD: %f segundos\n", time_taken);
    
    fclose(file);
    free(write_buffer);
    free(read_buffer);

    // Remove o arquivo temporário
    remove("data.bin");
}

// Função principal
int main() {
    printf("Operacoes na memoria RAM:\n");
    ramAccess();
    
    printf("\nOperacoes no HD:\n");
    diskAccess();
    
    return 0;
}