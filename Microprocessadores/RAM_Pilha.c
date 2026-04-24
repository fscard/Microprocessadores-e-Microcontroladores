/**
 * Benchmark de comparação de desempenho entre acesso à memória Heap e Stack
 * 
 * Este programa mede e compara o tempo de acesso a arrays alocados:
 * 1. Dinamicamente na Heap (usando malloc)
 * 2. Estaticamente na Stack (alocação automática)
 */

#include <stdio.h>   // Para funções de entrada/saída (printf)
#include <stdlib.h>  // Para alocação dinâmica (malloc, free)
#include <time.h>    // Para medição precisa de tempo (clock_gettime)

#define SIZE 500000  // Tamanho do array para os testes

/**
 * Teste de acesso à memória Heap (alocação dinâmica)
 * 
 * Aloca um array na heap, percorre incrementando valores,
 * mede o tempo gasto e libera a memória.
 */
void ramAccess() {
    // 1. Alocação dinâmica na Heap
    int* array = malloc(SIZE * sizeof(int));
    
    // Estruturas para armazenar tempos inicial/final
    struct timespec start, end;
    
    // 2. Marca tempo inicial
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // 3. Percorre array incrementando valores
    for (int i = 0; i < SIZE; i++) {
        array[i]++;  // Acesso + operação
    }
    
    // 4. Marca tempo final
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // 5. Calcula tempo decorrido (segundos com precisão nanossegundos)
    double time_taken = (end.tv_sec - start.tv_sec) + 
                       (end.tv_nsec - start.tv_nsec) / 1e9;
    
    printf("Tempo de acesso à Heap: %.6f segundos\n", time_taken);
    
    // 6. Libera memória alocada
    free(array);
}

/**
 * Teste de acesso à memória Stack (alocação estática)
 * 
 * Declara um array na stack, percorre incrementando valores
 * e mede o tempo gasto.
 */
void stackAccess() {
    // 1. Alocação automática na Stack
    int array[SIZE];
    
    struct timespec start, end;
    
    // 2. Marca tempo inicial
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // 3. Percorre array incrementando valores
    for (int i = 0; i < SIZE; i++) {
        array[i]++;
    }
    
    // 4. Marca tempo final
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // 5. Calcula tempo decorrido
    double time_taken = (end.tv_sec - start.tv_sec) + 
                       (end.tv_nsec - start.tv_nsec) / 1e9;
    
    printf("Tempo de acesso à Stack: %.6f segundos\n", time_taken);
}

/**
 * Função principal
 * 
 * Executa os testes de acesso à Heap e Stack
 * e exibe os resultados comparativos.
 */
int main() {
    printf("\nBenchmark de Acesso à Memória (Size: %d elementos)\n", SIZE);
    printf("==========================================\n");
    
    printf("\n[TESTE HEAP - Alocação Dinâmica]\n");
    ramAccess();
    
    printf("\n[TESTE STACK - Alocação Estática]\n");
    stackAccess();
    
    printf("\n==========================================\n");
    return 0;
}