programa
{
	funcao inicio()
	{
		inteiro num
		real resto
		
		escreva("Digite um número: ")
		leia(num)

		resto=num%2

		se (resto==0)
		{
			escreva("O número ",num," é par.")
		}
		senao
			escreva("O número ",num," é ímpar.")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 10; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */