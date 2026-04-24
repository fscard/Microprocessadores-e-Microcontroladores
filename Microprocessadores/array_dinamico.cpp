/*
================================================================
Programa: Alocação dinâmica de array em C++
Autor: Prof. Fábio de Sousa Cardoso
Arquivo: array_dinamico.cpp

Descrição:
Este programa demonstra o uso de alocação dinâmica de memória
na linguagem C++ utilizando o operador new.

O programa realiza as seguintes etapas:
1) solicita ao usuário o tamanho do array;
2) aloca dinamicamente memória para esse array;
3) preenche o array com valores sequenciais;
4) exibe os elementos armazenados;
5) libera a memória alocada ao final com delete[].

Conceitos ilustrados:
- uso de ponteiros
- alocação dinâmica com new
- acesso a elementos de array por índice
- entrada e saída com std::cin e std::cout
- liberação de memória com delete[]

----------------------------------------------------------------
Como compilar e executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   array_dinamico.cpp

2. Compilar com G++:
   g++ array_dinamico.cpp -o array_dinamico

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
Quando a memória é alocada com new[],
ela deve ser liberada com delete[].
================================================================
*/

#include <iostream>

int main() {
    int* array;
    int size;

    std::cout << "Digite o tamanho do array: ";
    std::cin >> size;

    array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    std::cout << "Array:\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}