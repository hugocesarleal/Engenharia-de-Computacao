programa
{
	
	funcao inicio()
	{

		inteiro idade
	
		escreva("Qual a idade do nadador? ")
		leia(idade)

		se(idade<5)
		{
			escreva("Esse nadador não se encaixa em nenhuma categoria.")
		}
		senao
			se(idade>=5 e idade<=10)
			{
				escreva("Esse nadador se encaixa na categoria infantil.")
			}
		senao
			se(idade>=11 e idade<=13)
			{
				escreva("Esse nadador se encaixa na categoria juvenil.")
			}
		senao
			se(idade>=14 e idade<=17)
			{
				escreva("Esse nadador se encaixa na categoria sênior.")
			}
		senao
				escreva("Esse nadador se encaixa na categoria adulto.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 582; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */