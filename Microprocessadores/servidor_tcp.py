# -*- coding: utf-8 -*-
"""
================================================================
Programa: Servidor TCP em Python
Autor: Fábio de Sousa Cardoso
Arquivo: servidor_tcp.py

Descrição:
Este programa demonstra o funcionamento básico de um servidor
TCP utilizando a biblioteca socket da linguagem Python.

O servidor realiza as seguintes etapas:
1) cria um socket TCP;
2) associa o socket a um endereço IP e a uma porta;
3) entra em modo de escuta;
4) aguarda a conexão de um cliente;
5) recebe uma mensagem enviada pelo cliente;
6) exibe a mensagem recebida;
7) envia uma resposta ao cliente;
8) encerra a conexão.

Conceitos ilustrados:
- programação de rede com sockets
- modelo cliente-servidor
- protocolo TCP
- endereço IP e porta
- envio e recebimento de dados
- codificação e decodificação de mensagens

----------------------------------------------------------------
Como executar este programa
----------------------------------------------------------------
1. Salvar o arquivo com o nome:
   servidor_tcp.py

2. Executar no terminal:
   python3 servidor_tcp.py

----------------------------------------------------------------
Como usar
----------------------------------------------------------------
1. Primeiro, execute o servidor.
2. Depois, em outro terminal, execute o cliente.
3. O servidor aguardará uma conexão na porta definida.
4. Quando o cliente se conectar, a mensagem será recebida e uma
   resposta será enviada.

----------------------------------------------------------------
Observações importantes
----------------------------------------------------------------
1. O endereço 127.0.0.1 representa o próprio computador.
2. A porta 5000 foi usada apenas como exemplo.
3. Este programa foi pensado para fins didáticos.
4. O servidor atende uma única conexão e depois encerra.
================================================================
"""

import socket


def main():
    # Endereço IP local
    host = "127.0.0.1"

    # Porta usada pelo servidor
    port = 5000

    # Cria um socket TCP
    # AF_INET  -> usa endereços IPv4
    # SOCK_STREAM -> usa o protocolo TCP
    servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Associa o socket ao endereço e à porta
    servidor.bind((host, port))

    # Coloca o socket em modo de escuta
    # O valor 1 indica o número máximo de conexões pendentes
    servidor.listen(1)

    print(f"Servidor aguardando conexão em {host}:{port}...")

    # Aceita uma conexão de cliente
    conexao, endereco = servidor.accept()
    print(f"Conexão estabelecida com: {endereco}")

    # Recebe até 1024 bytes enviados pelo cliente
    dados = conexao.recv(1024)

    # Decodifica os bytes recebidos para string
    mensagem = dados.decode("utf-8")
    print("Mensagem recebida do cliente:", mensagem)

    # Define a resposta que será enviada ao cliente
    resposta = "Olá, cliente! Mensagem recebida com sucesso."

    # Codifica a string para bytes e envia ao cliente
    conexao.send(resposta.encode("utf-8"))

    # Encerra a conexão com o cliente
    conexao.close()

    # Encerra o socket do servidor
    servidor.close()

    print("Servidor encerrado.")


if __name__ == "__main__":
    main()