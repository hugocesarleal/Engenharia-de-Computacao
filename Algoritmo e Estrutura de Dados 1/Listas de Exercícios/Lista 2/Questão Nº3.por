programa
{
	
	funcao inicio()
	{
		real valOri, dias, multa, valAtt

		escreva("Informe o valor original da dívida: ")
		leia(valOri)

		escreva("Informe a quantidade de dias em atraso: ")
		leia(dias)

		escreva("Informe o valor da multa por dia de atraso: ")
		leia(multa)

		valAtt=valOri+(dias*multa)

		

		escreva("O valor da original da dívida é: R$",valOri,"\n")
		escreva("O valor da multa por dia de atraso é: R$",multa,"\n")
		escreva("O valor atualizado da dívida é R$",valAtt)
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 417; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */