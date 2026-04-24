# -*- coding: utf-8 -*-
"""
================================================================
Programa: Captura e exibição de imagens da webcam com OpenCV
Autor: Fábio de Sousa Cardoso
Arquivo: webcam.py

Descrição:
Este programa demonstra como capturar imagens de uma webcam
utilizando a biblioteca OpenCV em Python.

O programa realiza as seguintes etapas:
1) inicializa o dispositivo de captura de vídeo da webcam;
2) verifica se a câmera foi aberta corretamente;
3) entra em um laço de captura contínua de frames;
4) exibe cada frame em uma janela;
5) permite encerrar a execução quando a tecla 'q' for pressionada;
6) libera a câmera e fecha as janelas ao final.

Conceitos ilustrados:
- uso da biblioteca OpenCV
- captura de vídeo em tempo real
- leitura de frames da webcam
- exibição de imagens em janela gráfica
- controle de laço com teclado
- liberação de recursos do sistema

----------------------------------------------------------------
Como executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   webcam.py

2. Certifique-se de que o OpenCV esteja instalado:
   pip install opencv-python

3. Executar no terminal:
   python webcam.py

   ou, em alguns sistemas:
   python3 webcam.py

----------------------------------------------------------------
Como usar
----------------------------------------------------------------
1. O programa tentará abrir a webcam padrão do sistema.
2. Uma janela com o vídeo capturado será exibida.
3. Para encerrar o programa, pressione a tecla:
   q

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. Este exemplo funciona melhor em Windows ou Linux nativo.
2. Em WSL, a webcam pode não estar acessível como /dev/video0.
3. O índice 0 em VideoCapture(0) indica a câmera padrão.
4. Caso haja mais de uma câmera, pode ser necessário testar outros
   índices, como 1 ou 2.
================================================================
"""

import cv2   # Biblioteca OpenCV para visão computacional e captura de vídeo


def capture_webcam():
    """
    Função responsável por abrir a webcam, capturar os frames
    e exibi-los em tempo real na tela.
    """

    # Inicializa o objeto de captura de vídeo
    # O índice 0 normalmente representa a webcam padrão do sistema
    cap = cv2.VideoCapture(0)

    # Verifica se a webcam foi aberta corretamente
    if not cap.isOpened():
        print("Erro ao abrir a webcam")
        return

    # Loop principal para capturar e exibir os frames continuamente
    while True:
        # Captura um frame da webcam
        ret, frame = cap.read()

        # Verifica se o frame foi capturado corretamente
        # ret = True indica sucesso na captura
        if not ret:
            print("Erro ao capturar o frame")
            break

        # Exibe o frame capturado em uma janela chamada "Webcam"
        cv2.imshow("Webcam", frame)

        # Aguarda 1 ms por uma tecla pressionada
        # Se a tecla 'q' for pressionada, o loop será encerrado
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Libera a webcam para que o sistema possa usá-la novamente
    cap.release()

    # Fecha todas as janelas abertas pelo OpenCV
    cv2.destroyAllWindows()


# Chama a função principal de captura da webcam
capture_webcam()