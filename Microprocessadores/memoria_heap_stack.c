/*
================================================================
Programa: Comparação de acesso à memória RAM (heap) e pilha (stack) em C
Autor: Prof. Fábio de Sousa Cardoso
Arquivo: memoria_heap_stack.c

Descrição:
Este programa mede, de forma simples, o tempo gasto para acessar
elementos armazenados em duas regiões diferentes de memória:

1) Heap (memória alocada dinamicamente com malloc)
2) Stack (memória local alocada dentro da função)

O objetivo é demonstrar:
- diferença conceitual entre heap e stack;
- alocação dinâmica e automática de memória;
- acesso sequencial a vetores;
- medição de tempo com clock_gettime().

O programa executa duas funções:
- ramAccess()   -> mede acesso a um vetor alocado na heap
- stackAccess() -> mede acesso a um vetor alocado na stack

Depois, a função main() chama as duas funções e exibe os tempos.

----------------------------------------------------------------
Como compilar e executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   memoria_heap_stack.c

2. Compilar com GCC:
   gcc memoria_heap_stack.c -o memoria_heap_stack

   Em alguns sistemas, pode ser necessário:
   gcc memoria_heap_stack.c -o memoria_heap_stack -lrt

3. Executar o programa:
   ./memoria_heap_stack

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. O tempo medido pode variar bastante conforme:
   - carga do sistema
   - processador
   - cache
   - otimização do compilador
   - sistema operacional

2. O acesso é sequencial, o que favorece cache.

3. Em alguns sistemas, um vetor muito grande na stack pode causar
   erro de execução por excesso de uso da pilha (stack overflow).

4. A instrução array[i]++ realiza leitura e escrita em cada posição,
   forçando acesso real à memória.
================================================================
*/

#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc(), free()
#include <time.h>    // clock_gettime(), struct timespec

#define SIZE 500000  // quantidade de elementos do vetor

void ramAccess() {
    // Aloca dinamicamente um vetor de inteiros na heap
    int* array = malloc(SIZE * sizeof(int));

    // Verifica se a alocação foi realizada com sucesso
    if (array == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return;
    }

    // Estruturas para armazenar o tempo inicial e final
    struct timespec start, end;

    // Registra o instante inicial
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Variável de controle do laço
    int i;

    // Percorre o vetor e acessa cada posição
    // A operação ++ força leitura e escrita
    for (i = 0; i < SIZE; i++) {
        array[i]++;
    }

    // Registra o instante final
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calcula o tempo decorrido em segundos
    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    // Exibe o resultado
    printf("Tempo para acessar a memoria RAM: %f segundos\n", time_taken);

    // Libera a memória alocada na heap
    free(array);
}

void stackAccess() {
    // Declara um vetor local na stack
    int array[SIZE];

    // Estruturas para armazenar o tempo inicial e final
    struct timespec start, end;

    // Registra o instante inicial
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Variável de controle do laço
    int i;

    // Percorre o vetor e acessa cada posição
    // A operação ++ força leitura e escrita
    for (i = 0; i < SIZE; i++) {
        array[i]++;
    }

    // Registra o instante final
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calcula o tempo decorrido em segundos
    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    // Exibe o resultado
    printf("Tempo para acessar a pilha: %f segundos\n", time_taken);
}

int main() {
    // Mede o tempo de acesso a um vetor na heap
    printf("Acesso a memoria RAM:\n");
    ramAccess();

    // Mede o tempo de acesso a um vetor na stack
    printf("\nAcesso a pilha:\n");
    stackAccess();

    return 0;
}