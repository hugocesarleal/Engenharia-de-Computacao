programa
{
	
	funcao inicio()
	{

		inteiro ano,nascimento,idade
	
		escreva("Em que ano estamos? ")
		leia(ano)

		escreva("Em que ano você nasceu? ")
		leia(nascimento)

		se (ano>nascimento)
		{
			idade=ano-nascimento
			escreva("Você tem ",idade," anos.")
		}
		senao
			escreva("A menos que você seja um viajante do tempo, seu ano de nascimento não pode ser maior que o ano atual.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 36; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */