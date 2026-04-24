# Exemplo 3: escrever o conteúdo linha por linha

nome_arquivo = "resumo_disciplina.txt"

with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
    arquivo.write("Resumo da Disciplina: Técnicas de Programação em Engenharia Eletrônica I\n")
    arquivo.write("\n")
    arquivo.write("Conteúdos abordados:\n")
    arquivo.write("- Conceitos básicos de computação\n")
    arquivo.write("- Algoritmos e programas\n")
    arquivo.write("- Linguagens de programação\n")
    arquivo.write("- Sistemas de numeração\n")
    arquivo.write("- Aritmética binária\n")
    arquivo.write("- Operações lógicas\n")
    arquivo.write("- Estruturas condicionais\n")
    arquivo.write("- Estruturas de repetição\n")
    arquivo.write("- Desenvolvimento de algoritmos\n")

print(f"Arquivo '{nome_arquivo}' criado com conteúdo linha por linha.")