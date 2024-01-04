programa
{
	
	funcao inicio()
	{
		inteiro cont, contNum
		real vetNum[20]

		para(cont=0;cont<20;cont++)
		{
			escreva("Digite o ",cont+1,"º número : ")
			leia(vetNum[cont])
		}

		contNum=0

		para(cont=0;cont<20;cont++)
		{
			se(vetNum[cont]>100 e vetNum[cont]<200)
			{
				contNum=contNum+1
			}
		}

		se(contNum==0)
		{
			escreva("Nenhum número entre 100 e 200 foi informado.")
		}
		senao
			escreva("Dos números informados, ",contNum," estão no intervalo entre 100 e 200.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 441; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNum, 7, 7, 6};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */