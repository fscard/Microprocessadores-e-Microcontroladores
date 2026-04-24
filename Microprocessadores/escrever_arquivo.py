# Exemplo 2: criar um arquivo com fechamento automático usando with

nome_arquivo = "resumo_disciplina.txt"

conteudo = """Resumo da Disciplina: Técnicas de Programação em Engenharia Eletrônica I

A disciplina desenvolve a base da programação aplicada à engenharia,
incluindo lógica, algoritmos, representação da informação e estruturas
fundamentais de uma linguagem procedimental.
"""

# O bloco with abre o arquivo e garante o fechamento automático ao final
with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
    arquivo.write(conteudo)

print(f"Arquivo '{nome_arquivo}' criado, salvo e fechado automaticamente.")