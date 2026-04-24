/*
================================================================
Programa: Entrada e saída com periféricos no Linux
Autor: [colocar nome do professor ou do aluno]
Arquivo: perifericos_linux.cpp

Descrição:
Este programa demonstra um exemplo simples de uso de periféricos
em ambiente Linux por meio do terminal.

O programa realiza as seguintes ações:
1) emite um aviso sonoro no terminal;
2) exibe a mensagem "Digite algo: ";
3) lê um texto digitado pelo usuário no teclado;
4) exibe na tela o texto informado.

Periféricos envolvidos:
- monitor: exibição das mensagens no terminal
- teclado: entrada de dados do usuário
- alto-falante/terminal: tentativa de aviso sonoro com '\a'

Observação:
O caractere '\a' solicita um beep no terminal, mas o som pode
depender das configurações do sistema, do emulador de terminal
e do ambiente gráfico.

----------------------------------------------------------------
Como compilar e executar
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   perifericos_linux.cpp

2. Compilar com:
   g++ perifericos_linux.cpp -o perifericos_linux

3. Executar com:
   ./perifericos_linux
================================================================
*/

#include <iostream>
#include <string>

int main() {
    // Emite um aviso sonoro no terminal
    std::cout << '\a';

   // Emite um beep usando o PowerShell do Windows
    system("powershell.exe -c \"[console]::beep(1000,500)\"");

    // Exibe a mensagem no monitor
    std::cout << "Digite algo: ";

    // Lê uma linha completa digitada no teclado
    std::string input;
    std::getline(std::cin, input);

    // Exibe o texto digitado
    std::cout << "Voce digitou: " << input << std::endl;

    return 0;
}