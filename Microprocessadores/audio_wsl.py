# -*- coding: utf-8 -*-
"""
================================================================
Programa: Reprodução de arquivo de áudio no WSL usando PowerShell
Autor: [colocar nome do professor ou do aluno]
Arquivo: audio_wsl.py

Descrição:
Este programa demonstra como reproduzir um arquivo de áudio
em ambiente WSL (Windows Subsystem for Linux) utilizando o
PowerShell do Windows.

Como o áudio no Linux dentro do WSL pode não estar configurado
corretamente, uma alternativa prática é chamar um recurso do
próprio Windows para tocar o arquivo.

O programa realiza as seguintes etapas:
1) define o nome do arquivo de áudio;
2) informa na tela que a reprodução será iniciada;
3) chama o PowerShell do Windows por meio do módulo subprocess;
4) cria um objeto SoundPlayer para o arquivo WAV;
5) reproduz o áudio de forma sincronizada;
6) informa se a reprodução foi concluída com sucesso.

Conceitos ilustrados:
- uso de strings em Python
- execução de comandos externos com subprocess.run()
- integração entre WSL e Windows
- reprodução de áudio via PowerShell
- tratamento simples de erros

----------------------------------------------------------------
Como executar
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   audio_wsl.py

2. Certifique-se de que o arquivo de áudio esteja no mesmo diretório:
   audio.wav

3. Executar no terminal:
   python3 audio_wsl.py

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. Este exemplo foi pensado para WSL.
2. O arquivo deve estar no formato .wav.
3. O PowerShell do Windows precisa estar acessível no WSL.
4. A reprodução é sincronizada, ou seja, o programa espera o
   som terminar antes de continuar.
================================================================
"""

import subprocess


def main():
    # Nome do arquivo de áudio
    audio_file = "audio.wav"

    # Mensagem inicial para o usuário
    print(f"Tentando reproduzir o arquivo de áudio: {audio_file}")

    # Script PowerShell que cria o player e toca o áudio
    ps_script = (
        "$player = New-Object System.Media.SoundPlayer 'audio.wav'; "
        "$player.PlaySync();"
    )

    try:
        # Executa o PowerShell do Windows a partir do WSL
        result = subprocess.run(
            ["powershell.exe", "-Command", ps_script],
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
        print("Erro: powershell.exe não foi encontrado.")
        print("Verifique se o programa está sendo executado no WSL.")
    except Exception as e:
        print("Ocorreu um erro inesperado:")
        print(e)


if __name__ == "__main__":
    main()