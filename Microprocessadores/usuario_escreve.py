# Exemplo 4: o usuário digita o resumo e o programa salva no arquivo

nome_arquivo = "resumo_disciplina.txt"

print("Digite o resumo da disciplina:")
conteudo = input()

with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
    arquivo.write(conteudo)

print(f"Resumo salvo no arquivo '{nome_arquivo}'.")
