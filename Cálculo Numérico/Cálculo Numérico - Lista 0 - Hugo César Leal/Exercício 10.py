
soma_notas_finais = 0
alunos_aprovados = 0

for aluno in range(1, 11):
    print(f"Aluno {aluno}:")
    
    nota1 = float(input("Digite a nota 1: "))
    nota2 = float(input("Digite a nota 2: "))
    nota3 = float(input("Digite a nota 3: "))
    
    nota_final = nota1 * 0.3 + nota2 * 0.3 + nota3 * 0.4
    
    soma_notas_finais += nota_final
    
    if nota_final >= 60:
        print(f"Nota final: {nota_final} - Aprovado")
        alunos_aprovados += 1
    else:
        print(f"Nota final: {nota_final} - Reprovado")

media_final = soma_notas_finais / 10

print(f"\nMédia final das notas finais: {media_final}")
print(f"Número de alunos aprovados: {alunos_aprovados}")