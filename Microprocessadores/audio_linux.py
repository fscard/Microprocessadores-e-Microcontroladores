# -*- coding: utf-8 -*-
"""
================================================================
Programa: Reprodução de arquivo de áudio em Linux nativo
Autor: [colocar nome do professor ou do aluno]
Arquivo: audio_linux.py

Descrição:
Este programa demonstra como reproduzir um arquivo de áudio
em Linux nativo utilizando um utilitário externo do sistema.

Neste exemplo, o programa:
1) define o nome do arquivo de áudio;
2) informa ao usuário que a reprodução será iniciada;
3) chama o utilitário "aplay" do Linux;
4) reproduz o arquivo de áudio;
5) informa se a reprodução terminou com sucesso.

Conceitos ilustrados:
- uso de strings em Python
- execução de comandos externos com subprocess.run()
- integração com utilitários do sistema operacional
- reprodução de áudio em Linux
- tratamento simples de erros

----------------------------------------------------------------
Como executar
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   audio_linux.py

2. Certifique-se de que o arquivo de áudio esteja no mesmo diretório:
   audio.wav

3. Executar no terminal:
   python3 audio_linux.py

----------------------------------------------------------------
Pré-requisitos
----------------------------------------------------------------
Este exemplo utiliza o utilitário "aplay", comum em sistemas Linux.

Em distribuições Debian/Ubuntu, ele pode ser instalado com:
   sudo apt update
   sudo apt install alsa-utils

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. Este exemplo foi pensado para Linux nativo.
2. O arquivo de áudio deve estar no formato .wav.
3. A reprodução é sincronizada, ou seja, o programa espera o
   áudio terminar antes de continuar.
4. Se o sistema não tiver dispositivo de áudio configurado,
   a reprodução pode falhar.
================================================================
"""

import subprocess


def main():
    # Nome do arquivo de áudio que será reproduzido
    audio_file = "audio.wav"

    # Informa ao usuário qual arquivo será reproduzido
    print(f"Tentando reproduzir o arquivo de áudio: {audio_file}")

    try:
        # Executa o utilitário aplay para reproduzir o arquivo WAV
        result = subprocess.run(
            ["aplay", audio_file],
            capture_output=True,
            text=True
        )

        # Verifica se o comando foi executado com sucesso
        if result.returncode == 0:
            print("Reprodução finalizada.")
        else:
            print(f"Erro ao reproduzir o arquivo de áudio: {audio_file}")
            if result.stderr:
                print("Detalhes do erro:")
                print(result.stderr)

    except FileNotFoundError:
        print("Erro: o comando 'aplay' não foi encontrado.")
        print("Instale o pacote alsa-utils no sistema.")
    except Exception as e:
        print("Ocorreu um erro inesperado:")
        print(e)


if __name__ == "__main__":
    main()