# coding: iso-8859-1 -*-
import tkinter as tk

# Função para exibir uma mensagem quando o botão for clicado
def exibir_mensagem():
    label["text"] = "Ola, mundo!"

# Cria a janela principal
janela = tk.Tk()

# Cria um rótulo na janela
label = tk.Label(janela, text="Clique no botao para exibir uma mensagem")
label.pack(pady=10)

# Cria um botão na janela
botao = tk.Button(janela, text="Clique aqui", command=exibir_mensagem)
botao.pack()

# Executa o loop principal da janela
janela.mainloop()
