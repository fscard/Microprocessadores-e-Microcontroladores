# Exemplo 1: criar um arquivo, escrever conteúdo e fechar o arquivo

# Nome do arquivo que será criado
nome_arquivo = "resumo_disciplina.txt"

# Conteúdo que será gravado no arquivo
conteudo = """Resumo da Disciplina: Técnicas de Programação em Engenharia Eletrônica I

A disciplina apresenta os conceitos básicos de computação,
algoritmos, programas e linguagens de programação.

Também aborda:
- sistemas de numeração;
- aritmética binária;
- operações lógicas;
- estruturas condicionais;
- estruturas de repetição;
- desenvolvimento de algoritmos;
- exemplos em C, C++ e Python.
"""

# Abre o arquivo no modo de escrita ("w")
# Se o arquivo não existir, ele será criado
# Se já existir, seu conteúdo será sobrescrito
arquivo = open(nome_arquivo, "w", encoding="utf-8")

# Escreve o conteúdo no arquivo
arquivo.write(conteudo)

# Fecha o arquivo para garantir o salvamento correto
arquivo.close()

print(f"Arquivo '{nome_arquivo}' criado e salvo com sucesso.")