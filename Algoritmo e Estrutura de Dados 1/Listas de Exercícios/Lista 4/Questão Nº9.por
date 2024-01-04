programa
{
	
	funcao inicio()
	{
		inteiro matA[3][4], matB[3][4], matC[3][4], matSoma[3][4], matSub[3][4],matMulti[3][4], cL,cC
		
		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				escreva("Matriz A - Informe o valor da ",cL+1,"ª linha da ",cC+1,"ª coluna: ")
				leia(matA[cL][cC])
			}
		}

		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				escreva("Matriz B - Informe o valor da ",cL+1,"ª linha da ",cC+1,"ª coluna: ")
				leia(matB[cL][cC])
			}
		}

		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				escreva("Matriz C - Informe o valor da ",cL+1,"ª linha da ",cC+1,"ª coluna: ")
				leia(matC[cL][cC])
			}
		}

		escreva("Resultados das somas entre as Matrizes A e B: ")

		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				matSoma[cL][cC]=matA[cL][cC]+matB[cL][cC]
				escreva(matSoma[cL][cC],", ")
			}
		}

		escreva("\nResultados das subtrações entre as Matrizes A e B: ")

		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				matSub[cL][cC]=matA[cL][cC]-matB[cL][cC]
				escreva(matSub[cL][cC],", ")
			}
		}

		escreva("\nResultados das multiplicações entre as Matrizes A e C: ")

		para(cL=0;cL<3;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				matMulti[cL][cC]=matA[cL][cC]*matC[cL][cC]
				escreva(matMulti[cL][cC],", ")
			}
		}

	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 120; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {matA, 6, 10, 4}-{matB, 6, 22, 4}-{matC, 6, 34, 4}-{matSoma, 6, 46, 7}-{matSub, 6, 61, 6}-{matMulti, 6, 74, 8};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */