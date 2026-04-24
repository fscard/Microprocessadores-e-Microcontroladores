/*
================================================================
Programa: Reproducao de arquivo de audio no WSL usando PowerShell
Autor: [colocar nome do professor ou do aluno]
Arquivo: audio_wsl.cpp

Descricao:
Este programa demonstra como reproduzir um arquivo de audio
em ambiente WSL (Windows Subsystem for Linux) utilizando um
recurso do proprio Windows, chamado a partir de um programa C++.

Em vez de usar bibliotecas do Windows diretamente, como
windows.h e PlaySoundA(), o programa executa um comando
PowerShell por meio da funcao system().

O programa realiza as seguintes etapas:
1) define o nome do arquivo de audio;
2) informa na tela que a reproducao sera iniciada;
3) chama o PowerShell do Windows;
4) cria um objeto SoundPlayer para o arquivo WAV;
5) reproduz o audio de forma sincronizada;
6) informa se a reproducao foi concluida com sucesso.

Conceitos ilustrados:
- uso de string em C++
- chamada de comandos do sistema com system()
- integracao entre WSL e Windows
- reproducao de audio com PowerShell
- tratamento simples de retorno da execucao

----------------------------------------------------------------
Por que este exemplo foi adaptado para WSL?
----------------------------------------------------------------
Em Linux nativo, a reproducao de audio geralmente pode ser feita
com ferramentas como aplay, paplay ou outros players.

No entanto, em WSL, o acesso direto ao subsistema de audio Linux
nem sempre funciona corretamente. Por isso, uma alternativa
pratica e usar o PowerShell do Windows para tocar o arquivo.

----------------------------------------------------------------
Como compilar
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   audio_wsl.cpp

2. Compilar com:
   g++ audio_wsl.cpp -o audio_wsl

----------------------------------------------------------------
Como executar
----------------------------------------------------------------
1. Certifique-se de que o arquivo de audio esteja no mesmo diretorio:
   audio.wav

2. Execute:
   ./audio_wsl

----------------------------------------------------------------
Observacoes importantes
----------------------------------------------------------------
1. Este exemplo funciona melhor com arquivos .wav
2. O PowerShell precisa estar acessivel a partir do WSL
3. O arquivo de audio deve estar no diretorio atual
4. A reproducao e sincronizada, isto e, o programa espera o audio
   terminar antes de continuar

----------------------------------------------------------------
Exemplo de execucao
----------------------------------------------------------------
Tentando reproduzir o arquivo de audio: audio.wav
Reproducao finalizada.
================================================================
*/

#include <iostream>   // std::cout, std::endl
#include <cstdlib>    // system()

int main() {
    // Nome do arquivo de audio que sera reproduzido
    const char* audioFile = "audio.wav";

    // Mensagem informando o inicio da operacao
    std::cout << "Tentando reproduzir o arquivo de audio: "
              << audioFile << std::endl;

    /*
    Monta um comando para chamar o PowerShell do Windows.

    O comando cria um objeto SoundPlayer associado ao arquivo
    audio.wav e depois executa o metodo PlaySync(), que toca
    o arquivo de forma sincronizada.

    O caractere '\' antes de $player e necessario para evitar
    que o shell do Linux tente interpretar $player antes que o
    comando chegue ao PowerShell.
    */
    std::string command =
        "powershell.exe -Command \""
        "\\$player = New-Object System.Media.SoundPlayer 'audio.wav'; "
        "\\$player.PlaySync();"
        "\"";

    // Executa o comando no sistema operacional
    int result = system(command.c_str());

    // Verifica se o comando foi executado com sucesso
    if (result == 0) {
        std::cout << "Reproducao finalizada." << std::endl;
    } else {
        std::cout << "Erro ao reproduzir o arquivo de audio: "
                  << audioFile << std::endl;
    }

    return 0;
}