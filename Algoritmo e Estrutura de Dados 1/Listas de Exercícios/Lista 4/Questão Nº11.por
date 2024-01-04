programa
{
	
	funcao inicio()
	{
		
		cadeia vetAlunos[10], vetMaterias[5], infoAluno, controleMaiorNome, controleMenorNome, situacaoAluno[10]
		real matNotas[10][5], somaGeral, mediaGeral, mediaMaterias[5], somaTemp, mediaAlunos[10], controleMaior, controleMenor
		inteiro cont, cont2, controleEncontro

		vetMaterias[0]="Português"
		vetMaterias[1]="Matemática"
		vetMaterias[2]="Biologia"
		vetMaterias[3]="Física"
		vetMaterias[4]="Química"

		para(cont=0;cont<10;cont++)
		{
			escreva("Informe o nome do ",cont+1,"º aluno: ")
			leia(vetAlunos[cont])

			para(cont2=0;cont2<5;cont2++)
			{
				escreva("Informe a nota do(a) aluno(a) ",vetAlunos[cont]," na disciplina ",vetMaterias[cont2],": ")
				leia(matNotas[cont][cont2])
			}
		}

		somaGeral=0
	
		para(cont=0;cont<10;cont++)
		{
			para(cont2=0;cont2<5;cont2++)
			{
				somaGeral=somaGeral+matNotas[cont][cont2]
			}
		}

		mediaGeral=somaGeral/50

		escreva("A média geral da turma é: ",mediaGeral,"\n")

		para(cont=0;cont<5;cont++)
		{
			somaTemp=0
			
			para(cont2=0;cont2<10;cont2++)
			{
				somaTemp=somaTemp+matNotas[cont2][cont]	
			}

			mediaMaterias[cont]=somaTemp/10
		}

		para(cont=0;cont<5;cont++)
		{
			escreva("A média de notas da turma na matéria ",vetMaterias[cont]," é: ",mediaMaterias[cont],".\n")
		}

		para(cont=0;cont<10;cont++)
		{
			somaTemp=0
			
			para(cont2=0;cont2<5;cont2++)
			{
				somaTemp=somaTemp+matNotas[cont][cont2]	
			}

			mediaAlunos[cont]=somaTemp/5
		}

		para(cont=0;cont<10;cont++)
		{
			escreva("A média de notas do(a) aluno(a) ",vetAlunos[cont]," é: ",mediaAlunos[cont],".\n")
		}

		escreva("Digite o nome do aluno desejado: ")
		leia(infoAluno)

		controleEncontro=0

		para(cont=0;cont<10;cont++)
		{
			se(infoAluno==vetAlunos[cont])
			{
				controleEncontro=1
				para(cont2=0;cont2<5;cont2++)
				{
					escreva("A nota do(a) aluno(a) ",vetAlunos[cont]," na disciplina ",vetMaterias[cont2]," é ",matNotas[cont][cont2],"\n")
				}
			}
		}

		se(controleEncontro==0)
		{
			escreva("Aluno não encontrado!\n")
		}

		controleMaior=-1
		controleMaiorNome=""

		para(cont=0;cont<10;cont++)
		{
			se(matNotas[cont][3]>controleMaior)
			{
				controleMaior=matNotas[cont][3]
				controleMaiorNome=vetAlunos[cont]
			}
		}

		escreva("O aluno que obteve a maior pontuação em Física foi ",controleMaiorNome,", e sua nota foi ",controleMaior,".\n")

		controleMenor=200
		controleMenorNome=""

		para(cont=0;cont<10;cont++)
		{
			se(matNotas[cont][0]<controleMenor)
			{
				controleMenor=matNotas[cont][0]
				controleMenorNome=vetAlunos[cont]
			}
		}

		escreva("O aluno que obteve a menor pontuação em Português foi ",controleMenorNome,", e sua nota foi ",controleMenor,".\n")

		escreva("Esses são os alunos que tiveram uma média individual maior que a média geral:\n")

		para(cont=0;cont<10;cont++)
		{
			se(mediaAlunos[cont]>mediaGeral)
			{
				escreva(vetAlunos[cont],"\n")
			}
		}

		para(cont=0;cont<10;cont++)
		{
			se(mediaAlunos[cont]<4)
			{
				situacaoAluno[cont]="Reprovado"
			}
			senao
				se(mediaAlunos[cont]>=4 e mediaAlunos[cont]<=5.9)
				{
					situacaoAluno[cont]="Recuperação"
				}
				senao
					se(mediaAlunos[cont]>=6)
					{
						situacaoAluno[cont]="Aprovado"
					}
		}

		escreva("Situação geral da turma:\n")

		para(cont=0;cont<10;cont++)
		{
			escreva(vetAlunos[cont],", média ",mediaAlunos[cont],", situação: ",situacaoAluno[cont],".\n")
		}
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 3424; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */