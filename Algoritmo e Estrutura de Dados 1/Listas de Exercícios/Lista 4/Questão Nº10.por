programa
{
	
	funcao inicio()
	{
		inteiro matA[4][4], cL, cC, somaL, somaC, infoNum, controleEncontro, somaAcimadiag, somaMat

		para(cL=0;cL<4;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				escreva("Informe o valor da ",cL+1,"ª linha da ",cC+1,"ª coluna: ")
				leia(matA[cL][cC])
			}
		}

		somaL=0

		para(cC=0;cC<4;cC++)
		{
			somaL=somaL+matA[0][cC]
		}

		escreva("A soma dos números da primeira linha é ",somaL)

		somaC=0

		para(cL=0;cL<4;cL++)
		{
			somaC=somaC+matA[cL][2]
		}

		escreva("\nA soma dos números da terceira coluna é ",somaC)

		escreva("\nInforme o número que deseja encontrar: ")
		leia(infoNum)


		controleEncontro=0
		
		para(cL=0;cL<4;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				se(matA[cL][cC]==infoNum)
				{
					escreva("Número encontrado na ",cL+1,"ª linha da ",cC+1,"ª coluna.\n")
					controleEncontro=1
				}
			}
		}

		se(controleEncontro==0)
		{
			escreva("Valor naõ encontrado.")
		}


		escreva("Informe a linha do número desejado: ")
		leia(cL)

		escreva("Informe a coluna do número desejado: ")
		leia(cC)

		se(cL>=1 e cL<=4 e cC>=1 e cC<=4)
		{
			escreva("O número posicionado na ",cL,"ª linha da ",cC,"ª coluna é ",matA[cL-1][cC-1])
		}
		senao
			escreva("Número de linha ou coluna inválido!")


		somaAcimadiag=matA[0][1]+matA[0][2]+matA[0][3]+matA[1][2]+matA[1][3]+matA[2][3]
		escreva("\nA soma dos números acima da diagonal principal é ",somaAcimadiag)


		escreva("\nEsses são os números da diagonal principal: ")
		
		para(cL=0;cL<4;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				se(cL==cC)
				{
					escreva(matA[cL][cC],", ")
				}
			}
		}


		escreva("\nEsses são os números da diagonal secundária: ")
		escreva(matA[0][3],", ",matA[1][2],", ",matA[2][1],", ",matA[3][0],"\n")


		somaMat=0
		
		para(cL=0;cL<4;cL++)
		{
			para(cC=0;cC<4;cC++)
			{
				somaMat=somaMat+matA[cL][cC]
			}
		}

		escreva("O somatório de todos os elementos da matriz é ",somaMat)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1233; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {matA, 6, 10, 4};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */