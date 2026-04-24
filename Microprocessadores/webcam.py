import cv2
def capture_webcam():
    # Inicializa o objeto de captura de vídeo
    cap = cv2.VideoCapture(0)
    if not cap.isOpened(): # Verifica se a webcam foi aberta
        print("Erro ao abrir a webcam")
        return
    # Loop para capturar e exibir as imagens da webcam
    while True:
        # Captura um frame da webcam
        ret, frame = cap.read()
        # Verifica se o frame foi capturado corretamente
        if not ret:
            print("Erro ao capturar o frame")
            break
        # Exibe o frame capturado
        cv2.imshow("Webcam", frame)
        # Verifica se a tecla 'q' foi pressionada para sair do loop
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    # Libera o objeto de captura e fecha as janelas
    cap.release()
    cv2.destroyAllWindows()
capture_webcam() # Chama a função para capturar webcam