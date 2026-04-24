# -*- coding: utf-8 -*-
"""
================================================================
Programa: Criação dinâmica de array em Python
Autor: Prof. Fábio de Sousa Cardoso
Arquivo: array_dinamico.py

Descrição:
Este programa demonstra a criação de uma lista em Python com
tamanho definido pelo usuário.

O programa realiza as seguintes etapas:
1) solicita ao usuário o tamanho do array;
2) cria uma lista com esse tamanho;
3) preenche a lista com valores sequenciais;
4) exibe os elementos armazenados.

Conceitos ilustrados:
- entrada de dados com input()
- conversão de tipos com int()
- criação de lista com tamanho inicial
- uso de laço for com range()
- acesso a elementos por índice
- exibição de elementos na tela

----------------------------------------------------------------
Como executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   array_dinamico.py

2. Executar no terminal:
   python array_dinamico.py

   ou, em alguns sistemas:
   python3 array_dinamico.py

----------------------------------------------------------------
Exemplo de execução
----------------------------------------------------------------
Digite o tamanho do array: 5
Array:
1 2 3 4 5

----------------------------------------------------------------
Observação
----------------------------------------------------------------
Em Python, a alocação de memória é gerenciada automaticamente.
Diferente de C e C++, não é necessário liberar memória manualmente.
================================================================
"""

def main():
    size = int(input("Digite o tamanho do array: "))

    array = [0] * size

    for i in range(size):
        array[i] = i + 1

    print("Array:")
    for element in array:
        print(element, end=" ")
    print()

main()