programa
{
	
	funcao inicio()
	{
		cadeia code,idavolta
	
		escreva("Informe o código da cidade de destino: ")
		leia(code)

		escreva("Se sua passagem for ida e volta, digite 'S', se sua passagem for somente ida, digite 'N': ")
		leia(idavolta)

		se(code!="ARA" e code!="BH" e code!="FGA" e code!="UBA")
		{
			escreva("O código de cidade informado é inválido.")
		}
		senao
			se(idavolta!="S" e idavolta!="N")
			{
				escreva("Por favor, responda o segundo questionamento apenas com 'S' ou 'N'.")
			}
		senao
			se(code=="ARA")
			{
				se(idavolta=="S")
				{
					escreva("O preço da passagem de ida e volta para Araxá é de R$180,00")
				}
				senao
					escreva("O preço da passagem apenas de ida para Araxá é de R$100,00")
			}
		senao
			se(code=="BH")
			{
				se(idavolta=="S")
				{
					escreva("O preço da passagem de ida e volta para Belo Horizonte é de R$250,00")
				}
				senao
					escreva("O preço da passagem apenas de ida para Belo Horizonte é de R$150,00")
			}
		senao
			se(code=="FGA")
			{
				se(idavolta=="S")
				{
					escreva("O preço da passagem de ida e volta para Formiga é de R$50,00")
				}
				senao
					escreva("O preço da passagem apenas de ida para Formiga é de R$30,00")
			}
		senao
			se(code=="UBA")
			{
				se(idavolta=="S")
				{
					escreva("O preço da passagem de ida e volta para Uberlândia é de R$370,00")
				}
				senao
					escreva("O preço da passagem apenas de ida para Uberlândia é de R$200,00")
			}	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 12; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */