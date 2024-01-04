programa
{
	
	funcao inicio()
	{

		real num1,num2
	
		escreva("Digite o primeiro número: ")
		leia(num1)

		escreva("Digite o segundo número: ")
		leia(num2)

		se(num1==num2)
		{
			escreva("Os números informados são iguais.")
		}
		senao
			se(num2>num1)
		{
			escreva("Números informados em ordem crescente: ",num1," e ",num2,".")
		}
		senao
			escreva("Números informados em ordem crescente: ",num2," e ",num1,".")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 250; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */