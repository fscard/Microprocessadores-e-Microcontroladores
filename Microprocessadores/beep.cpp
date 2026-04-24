/**
 * Exemplo de programa em C++ para Linux
 * Com reprodução de som usando aplay
 * 
 * Compilação: g++ -o beep beep.cpp
 * Requer pacote alsa-utils: sudo apt-get install alsa-utils
 */

#include <iostream>
#include <cstdlib>

int main() {
    // Tenta reproduzir som usando aplay
    system("speaker-test -t sine -f 1000 -l 1 > /dev/null 2>&1");

    // Entrada de dados
    std::string input;
    std::cout << "Digite algo: ";
    std::cin >> input;

    // Exibe entrada
    std::cout << "Voce digitou: " << input << std::endl;

    return 0;
}