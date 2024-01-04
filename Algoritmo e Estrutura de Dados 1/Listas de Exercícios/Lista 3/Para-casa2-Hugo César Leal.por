/* Aula: 01/jul/2022
 * Faça um algoritmo que leia o nome de 4 alunos e suas notas em 5 disciplinas.
 * Em seguida, calcule, armazene e mostre as médias de cada aluno.
 * OBS: use 1 vetor e 1 matriz, conforme abstração que fizemos juntos no quadro branco
 * 
 * PARA CASA 2: modifique o algoritmos de modo que agora ele também seja capaz de:
 * 	a) mostrar o nome do aluno que teve a maior média e o valor da sua média
 * 	b) mostrar qual foi a menor nota na disciplina 2 e o nome do aluno que a tirou
 * 
 */

programa
{
	
	funcao inicio()
	{
		// estruturas
		cadeia vetNomes[4], controlMenorNome, controlMaiorNome
		real matNotas[4][6], media, somaNotas, controlMenorNum, controlMaiorNum
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
			escreva("Informe as notas do(a) aluno(a) ",vetNomes[cL],": \n") // mostra a frase e quebra a linha
			para (cC=0;cC<5;cC++) // controla colunas
			{
				escreva("Nota ",cC+1,": ")
				leia(matNotas[cL][cC])	
			}
			escreva("\n")			
		}
		// PROCESSAMENTO OU OPERAÇOES
		media = 0 // inicializa uma única vez
		controlMaiorNum=-999999
		controlMaiorNome="a"
		
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
			//Parte responsável por determinar quem tem a maior média, guardar a sua média e seu nome
			se(media>controlMaiorNum)
			{
				controlMaiorNum=media
				controlMaiorNome=vetNomes[cL]
			}
			// agora, posso guardar este valor numa coluna fixa da matriz
			matNotas[cL][5] = media
			escreva("Média do(a) aluno(a) ",vetNomes[cL],": ",matNotas[cL][5],"\n\n")
		}
		//Parte responsável por determinar quem tirou a menor nota na disciplina 2, guardar sua nota e seu nome
		controlMenorNum=9999999
		controlMenorNome="a"

		para (cL=0;cL<4;cL++)
		{
			se(matNotas[cL][1]<controlMenorNum)
			{
				controlMenorNum=matNotas[cL][1]
				controlMenorNome=vetNomes[cL]
			}
		}

		escreva("A maior média da sala é do(a) aluno(a) ",controlMaiorNome,", e sua média foi: ",controlMaiorNum,"\n\n")
		escreva("A menor nota na disciplina 2 é do(a) aluno(a) ",controlMenorNome,", e sua nota foi: ",controlMenorNum,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 632; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNomes, 18, 9, 8}-{matNotas, 19, 7, 8};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */