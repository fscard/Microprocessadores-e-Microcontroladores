/*
================================================================
Programa: Alocação dinâmica de array em C
Autor: Prof. Fábio de Sousa Cardoso
Arquivo: array_dinamico.c

Descrição:
Este programa demonstra o uso de alocação dinâmica de memória
na linguagem C utilizando a função malloc().

O programa realiza as seguintes etapas:
1) solicita ao usuário o tamanho do array;
2) aloca dinamicamente memória para esse array;
3) preenche o array com valores sequenciais;
4) exibe os elementos armazenados;
5) libera a memória alocada ao final.

Conceitos ilustrados:
- uso de ponteiros
- alocação dinâmica com malloc()
- verificação de erro de alocação
- uso de sizeof()
- preenchimento e leitura de arrays
- liberação de memória com free()

----------------------------------------------------------------
Como compilar e executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   array_dinamico.c

2. Compilar com GCC:
   gcc array_dinamico.c -o array_dinamico

3. Executar o programa:
   ./array_dinamico

----------------------------------------------------------------
Exemplo de execução
----------------------------------------------------------------
Digite o tamanho do array: 5
Array:
1 2 3 4 5

----------------------------------------------------------------
Observação
----------------------------------------------------------------
A memória alocada com malloc() deve ser liberada com free()
para evitar vazamentos de memória.
================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array;
    int size;
    int i;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    array = (int*)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    printf("Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}