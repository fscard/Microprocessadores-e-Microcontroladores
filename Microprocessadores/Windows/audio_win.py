# -*- coding: utf-8 -*-
"""
================================================================
Programa: Reprodução de arquivo de áudio no Windows com Python
Autor: Fábio de Sousa Cardoso
Arquivo: audio_win.py

Descrição:
Este programa demonstra como reproduzir um arquivo de áudio no
Windows utilizando o módulo winsound da linguagem Python.

O programa realiza as seguintes etapas:
1) define o nome do arquivo de áudio;
2) inicia a reprodução do arquivo em modo assíncrono;
3) informa ao usuário que o áudio está sendo reproduzido;
4) aguarda 5 segundos;
5) interrompe a reprodução do áudio;
6) informa que a reprodução foi finalizada.

Conceitos ilustrados:
- importação de módulos em Python
- uso do módulo winsound
- reprodução de arquivos WAV
- uso de flags para controle da reprodução
- pausa de execução com time.sleep()
- organização do código em função

----------------------------------------------------------------
Como executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   audio_win.py

2. Certifique-se de que o arquivo de áudio esteja no mesmo diretório:
   audio.wav

3. Executar no terminal do Windows:
   python audio_win.py

   ou, em alguns ambientes:
   python3 audio_win.py

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. Este exemplo foi pensado para Windows nativo.
2. O módulo winsound é específico do Windows.
3. O arquivo de áudio deve estar no formato .wav.
4. A reprodução é iniciada em modo assíncrono, ou seja, o programa
   continua executando enquanto o som toca.
5. Neste exemplo, o programa espera 5 segundos e depois interrompe
   a reprodução do áudio.
================================================================
"""

import winsound   # Módulo do Windows para emitir sons e reproduzir arquivos WAV
import time       # Módulo usado para inserir pausas no programa


def play_audio(file_path):
    """
    Função responsável por reproduzir um arquivo de áudio WAV.

    Parâmetro:
    file_path -> caminho ou nome do arquivo de áudio
    """

    # Inicia a reprodução do arquivo de áudio
    # SND_FILENAME indica que será usado o nome de um arquivo
    # SND_ASYNC indica reprodução assíncrona, ou seja, sem bloquear o programa
    winsound.PlaySound(file_path, winsound.SND_FILENAME | winsound.SND_ASYNC)

    # Exibe mensagem informando que o áudio está sendo reproduzido
    print("Reproduzindo o arquivo de áudio:", file_path)

    # Aguarda 5 segundos antes de interromper a reprodução
    time.sleep(5)

    # Interrompe qualquer som em reprodução iniciado por PlaySound
    winsound.PlaySound(None, winsound.SND_PURGE)

    # Exibe mensagem indicando o fim da reprodução
    print("Reprodução finalizada.")


# Nome do arquivo de áudio que será reproduzido
audio_file = "audio.wav"

# Chama a função para tocar o áudio
play_audio(audio_file)
