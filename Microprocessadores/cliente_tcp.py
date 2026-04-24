# -*- coding: utf-8 -*-
"""
================================================================
Programa: Cliente TCP em Python
Autor: Fábio de Sousa Cardoso
Arquivo: cliente_tcp.py

Descrição:
Este programa demonstra o funcionamento básico de um cliente
TCP utilizando a biblioteca socket da linguagem Python.

O cliente realiza as seguintes etapas:
1) cria um socket TCP;
2) conecta-se ao servidor usando endereço IP e porta;
3) envia uma mensagem ao servidor;
4) recebe a resposta enviada pelo servidor;
5) exibe a resposta recebida;
6) encerra a conexão.

Conceitos ilustrados:
- programação de rede com sockets
- modelo cliente-servidor
- protocolo TCP
- conexão com servidor
- envio e recebimento de dados
- codificação e decodificação de mensagens

----------------------------------------------------------------
Como executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   cliente_tcp.py

2. Executar no terminal:
   python3 cliente_tcp.py

----------------------------------------------------------------
Como usar
----------------------------------------------------------------
1. Primeiro, execute o servidor:
   python3 servidor_tcp.py

2. Depois, em outro terminal, execute o cliente:
   python3 cliente_tcp.py

3. O cliente enviará uma mensagem ao servidor e aguardará a resposta.

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. O endereço 127.0.0.1 representa o próprio computador.
2. A porta deve ser a mesma usada no servidor.
3. Este programa foi pensado para fins didáticos.
================================================================
"""

import socket


def main():
    # Endereço IP do servidor
    host = "127.0.0.1"

    # Porta usada pelo servidor
    port = 5000

    # Cria um socket TCP
    cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Conecta o cliente ao servidor
    cliente.connect((host, port))

    # Define a mensagem que será enviada
    mensagem = "Olá, servidor! Aqui é o cliente."

    # Envia a mensagem ao servidor
    cliente.send(mensagem.encode("utf-8"))

    # Recebe a resposta do servidor
    resposta = cliente.recv(1024).decode("utf-8")

    # Exibe a resposta recebida
    print("Resposta do servidor:", resposta)

    # Encerra o socket do cliente
    cliente.close()


if __name__ == "__main__":
    main()