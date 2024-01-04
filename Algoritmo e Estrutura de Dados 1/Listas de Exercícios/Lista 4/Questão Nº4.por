programa
{
	
	funcao inicio()
	{
		inteiro vetNum[10], cont, x, y

		para(cont=0;cont<10;cont++)
		{
			escreva("Informe o valor do ",cont+1,"º número: (Seja ele inteiro) ")
			leia(vetNum[cont])
		}

		escreva("Informe a posição do primeiro número a ser somado: ")
		leia(x)

		escreva("Informe a posição do segundo número a ser somado: ")
		leia(y)

		escreva("A soma dos números ",vetNum[x-1]," e ",vetNum[y-1]," é: ",vetNum[x-1]+vetNum[y-1])
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 439; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNum, 6, 10, 6}-{x, 6, 28, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */