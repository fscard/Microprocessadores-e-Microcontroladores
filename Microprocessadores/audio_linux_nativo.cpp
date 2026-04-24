/*
================================================================
Programa: Reproducao de arquivo de audio em Linux nativo
Autor: [colocar nome do professor ou do aluno]
Arquivo: audio_linux_nativo.cpp

Descricao:
Este programa demonstra como reproduzir um arquivo de audio
em Linux nativo utilizando um utilitario externo do sistema.

Neste exemplo, o programa:
1) define o nome do arquivo de audio;
2) informa ao usuario que a reproducao sera iniciada;
3) chama o utilitario "aplay" do Linux;
4) reproduz o arquivo de audio;
5) informa se a reproducao terminou com sucesso.

Conceitos ilustrados:
- uso de strings em C++
- chamada de comandos do sistema com system()
- reproducao de audio em Linux por utilitario externo
- verificacao simples do resultado da execucao

----------------------------------------------------------------
Como compilar
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   audio_linux_nativo.cpp

2. Compilar com:
   g++ audio_linux_nativo.cpp -o audio_linux_nativo

----------------------------------------------------------------
Como executar
----------------------------------------------------------------
1. Certifique-se de que o arquivo de audio esteja no mesmo diretorio:
   audio.wav

2. Execute:
   ./audio_linux_nativo

----------------------------------------------------------------
Pre-requisitos
----------------------------------------------------------------
Este exemplo utiliza o utilitario "aplay", comum em sistemas Linux.

Em distribuicoes Debian/Ubuntu, ele pode ser instalado com:
   sudo apt update
   sudo apt install alsa-utils

----------------------------------------------------------------
Observacoes importantes
----------------------------------------------------------------
1. Este exemplo foi pensado para Linux nativo.
2. O arquivo de audio deve estar no formato .wav.
3. A reproducao e sincronizada: o programa espera o som terminar.
4. Se o sistema nao tiver dispositivo de audio configurado,
   a reproducao pode falhar.
================================================================
*/

#include <iostream>   // std::cout, std::endl
#include <cstdlib>    // system()

int main() {
    // Nome do arquivo de audio a ser reproduzido
    const char* audioFile = "audio.wav";

    // Informa ao usuario qual arquivo sera reproduzido
    std::cout << "Tentando reproduzir o arquivo de audio: "
              << audioFile << std::endl;

    /*
    Monta o comando do sistema operacional.

    O utilitario "aplay" e usado para reproduzir arquivos WAV
    em sistemas Linux. O comando sera equivalente a:

        aplay audio.wav
    */
    std::string command = "aplay ";
    command += audioFile;

    // Executa o comando no sistema operacional
    int result = system(command.c_str());

    // Verifica o resultado da execucao
    if (result == 0) {
        std::cout << "Reproducao finalizada." << std::endl;
    } else {
        std::cout << "Erro ao reproduzir o arquivo de audio: "
                  << audioFile << std::endl;
        std::cout << "Verifique se o arquivo existe, se esta em formato WAV"
                  << " e se o utilitario aplay esta instalado." << std::endl;
    }

    return 0;
}