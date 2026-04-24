/**
 * Programa de reprodução de áudio usando SDL2 e SDL2_mixer
 * 
 * Este programa demonstra como carregar e reproduzir um arquivo de áudio WAV
 * utilizando a biblioteca SDL2 com a extensão SDL2_mixer.
 */

#include <iostream>          // Para saída no console (std::cout)
#include <SDL2/SDL.h>        // Biblioteca SDL2 principal
#include <SDL2/SDL_mixer.h>  // Extensão SDL2 para áudio

int main() {
    // 1. Inicialização do SDL (subsistema de áudio)
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "Erro ao inicializar o SDL: " << SDL_GetError() << std::endl;
        return -1;  // Encerra com código de erro
    }

    // 2. Inicialização do sistema de áudio do mixer
    // Parâmetros: frequência (44.1kHz), formato padrão, canais (estéreo), tamanho do chunk (2048 bytes)
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Erro ao inicializar o mixer de áudio: " << Mix_GetError() << std::endl;
        SDL_Quit();  // Limpa o SDL antes de sair
        return -1;
    }

    // 3. Carregamento do arquivo de áudio
    const char* audioFile = "audio.wav";  // Nome do arquivo a ser carregado
    Mix_Chunk* sound = Mix_LoadWAV(audioFile);  // Carrega o arquivo WAV
    
    // Verifica se o carregamento foi bem-sucedido
    if (!sound) {
        std::cout << "Erro ao carregar o arquivo de áudio: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();  // Fecha o mixer
        SDL_Quit();        // Finaliza o SDL
        return -1;
    }

    // 4. Reprodução do áudio
    std::cout << "Reproduzindo o arquivo de audio: " << audioFile << std::endl;
    // Parâmetros: canal (-1 = primeiro canal livre), som, loops (0 = sem repetição)
    Mix_PlayChannel(-1, sound, 0);

    // 5. Aguarda 5 segundos enquanto o áudio toca
    SDL_Delay(5000);  // Pausa de 5000 milissegundos (5 segundos)

    // 6. Limpeza dos recursos
    Mix_FreeChunk(sound);  // Libera a memória do som carregado
    Mix_CloseAudio();      // Fecha o sistema de áudio do mixer
    SDL_Quit();           // Finaliza todos os subsistemas do SDL

    std::cout << "Reproducao finalizada." << std::endl;
    return 0;  // Encerra com sucesso
}