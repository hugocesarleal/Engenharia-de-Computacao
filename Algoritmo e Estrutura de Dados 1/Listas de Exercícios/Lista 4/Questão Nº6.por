programa
{
	
	funcao inicio()
	{
		inteiro cont, cont1
		caracter vetOriginal[16]

		para(cont=0;cont<8;cont++)
		{
			escreva("Informe o ",cont+1,"º caracter: ")
			leia(vetOriginal[cont])
		}
		
		//Para a resolução do problema utilizei o mesmo vetor, porém aumentei oito casas que seriam equivalentes ao segundo vetor

		cont1=7

		para(cont=0;cont<8;cont++)
		{
			cont1=cont1+1
			vetOriginal[cont1]=vetOriginal[cont]
			
		}

		cont1=11
		
		para(cont=0;cont<4;cont++)
		{
			cont1=cont1+1
			vetOriginal[cont]=vetOriginal[cont1]
		}

		cont1=7
		
		para(cont=4;cont<8;cont++)
		{
			cont1=cont1+1
			vetOriginal[cont]=vetOriginal[cont1]
		}

		escreva("Valores do vetor após a leitura: ")
		para(cont=8;cont<16;cont++)
		{
			escreva(vetOriginal[cont],", ")
		}

		escreva("\nValores do vetor após a troca de posições: ")
		para(cont=0;cont<8;cont++)
		{
			escreva(vetOriginal[cont],", ")
		}
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 769; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */