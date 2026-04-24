/*
================================================================
Programa: Reproducao de audio com SDL2 e SDL_mixer
Autor: [colocar nome do professor ou do aluno]
Arquivo: audio_sdl.cpp

Descricao:
Este programa demonstra a reproducao de um arquivo WAV usando
as bibliotecas SDL2 e SDL2_mixer.

O programa:
1) inicializa o subsistema de audio do SDL;
2) inicializa o mixer de audio;
3) carrega o arquivo audio.wav;
4) reproduz o som;
5) espera o termino da reproducao;
6) libera os recursos utilizados.

Observacao:
Em Linux nativo, este exemplo costuma funcionar bem quando as
bibliotecas e o dispositivo de audio estao corretamente configurados.

No WSL, o funcionamento depende da integracao de audio do ambiente.
================================================================
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main() {
    // Inicializa apenas o subsistema de audio do SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "Erro ao inicializar o SDL: "
                  << SDL_GetError() << std::endl;
        return -1;
    }

    // Inicializa o mixer de audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Erro ao inicializar o mixer de audio: "
                  << Mix_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Nome do arquivo de audio
    const char* audioFile = "audio.wav";

    // Carrega o arquivo WAV na memoria
    Mix_Chunk* sound = Mix_LoadWAV(audioFile);
    if (!sound) {
        std::cout << "Erro ao carregar o arquivo de audio: "
                  << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }

    std::cout << "Reproduzindo o arquivo de audio: "
              << audioFile << std::endl;

    // Reproduz o audio em um canal livre
    int channel = Mix_PlayChannel(-1, sound, 0);
    if (channel == -1) {
        std::cout << "Erro ao reproduzir o audio: "
                  << Mix_GetError() << std::endl;
        Mix_FreeChunk(sound);
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }

    // Aguarda ate o termino da reproducao
    while (Mix_Playing(channel) != 0) {
        SDL_Delay(100);
    }

    // Libera recursos
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();

    std::cout << "Reproducao finalizada." << std::endl;
    return 0;
}