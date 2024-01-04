programa
{
	
	funcao inicio()
	{
		inteiro cont, cont1
		caracter vetOriginal[8], vetInvertido[8]

		para(cont=0;cont<8;cont++)
		{
			escreva("Informe o ",cont+1,"º caracter: ")
			leia(vetOriginal[cont])
		}

		cont1=3
		
		para(cont=0;cont<4;cont++)
		{
			cont1=cont1+1
			vetInvertido[cont1]=vetOriginal[cont]
		}

		cont1=3
		
		para(cont=0;cont<4;cont++)
		{
			cont1=cont1+1
			vetInvertido[cont]=vetOriginal[cont1]
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 99; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetOriginal, 7, 11, 11}-{vetInvertido, 7, 27, 12};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */