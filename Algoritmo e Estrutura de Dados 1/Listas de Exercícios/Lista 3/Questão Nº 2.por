/* Aula: 01/jul/2022
 * Faça um algoritmo que leia o nome de 4 alunos e suas notas em 5 disciplinas.
 * Em seguida, calcule, armazene e mostre as médias de cada aluno.
 * OBS: use 1 vetor e 1 matriz, conforme abstração que fizemos juntos no quadro branco
 * 
 * PARA CASA 1: modifique o algoritmos de modo que agora ele também seja capaz de:
 * 	a) mostrar todas as notas cadastradas para cada aluno. Ex:
 * 		Aluno: Fulano
 * 		Notas: 
 * 			8
 * 			7.5
 * 			9
 * 			6
 * 			10
 * 		Aluno: ...
 * 	b) calcular e mostrar a média GERAL da turma
 * 
 */

programa
{
	
	funcao inicio()
	{
		// estruturas
		cadeia vetNomes[4]
		real matNotas[4][6], media, somaNotas, mediaT, somaMedia
		inteiro cL, cC

		//ENTRADA DOS DADOS
		// alimentando o vetor
		para (cL=0;cL<4;cL++)
		{
			escreva("Nome do aluno ",cL+1,": ")
			leia(vetNomes[cL])
		}

		escreva("\n")

		// alimentando a matriz
		para (cL=0;cL<4;cL++) // controla linhas da matNotas 
		{
			escreva("Informe as notas do aluno(a) ",vetNomes[cL],": \n") // mostra a frase e quebra a linha
			para (cC=0;cC<5;cC++) // controla colunas
			{
				escreva("Nota ",cC+1,": ")
				leia(matNotas[cL][cC])	
			}			
			escreva("\n")
		}
		// PROCESSAMENTO OU OPERAÇOES
		media = 0 // inicializa uma única vez
		
		para (cL=0;cL<4;cL++) // controla linhas da matNotas 
		{
			somaNotas = 0 // zera a cada mudança de linha
			para (cC=0;cC<6;cC++) // controla colunas
			{
				somaNotas = somaNotas + matNotas[cL][cC]
			}
			// neste momento, tenho a soma das notas de um aluno
			// e devo calcular sua média
			media = somaNotas/5
			// agora, posso guardar este valor numa coluna fixa da matriz
			matNotas[cL][5] = media
			
		}

		//Parte responsável por mostrar as notas de todos os alunos cadastrados
		para (cL=0;cL<4;cL++)
		{
			escreva("Aluno: ",vetNomes[cL],"\n")
			para (cC=0;cC<6;cC++)
			{
				escreva("Nota ",cC+1,": ",matNotas[cL][cC],"\n")
			}
			escreva("Média: ",matNotas[cL][5],"\n\n")
		}

		//Parte responsável por calcular e mostrar a média geral da sala
		somaMedia=0

		para (cL=0;cL<4;cL++)
		{
			somaMedia=somaMedia+matNotas[cL][5]
		}

		mediaT=somaMedia/4

		escreva("Média geral da sala: ",somaMedia)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 2178; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNomes, 26, 9, 8}-{matNotas, 27, 7, 8}-{somaMedia, 27, 49, 9};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */