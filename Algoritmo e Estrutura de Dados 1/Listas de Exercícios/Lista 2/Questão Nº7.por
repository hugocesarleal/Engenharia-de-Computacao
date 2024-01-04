programa
{
	
	funcao inicio()
	{

		real salario,parcela,porcentagem
	
		escreva("Informe seu salário: ")
		leia(salario)

		escreva("Informe o valor que deseja pagar na parcela: ")
		leia(parcela)

		porcentagem=salario*0.3

		se(parcela<=porcentagem)
		{
			escreva("Seu salário é de ",salario," reais.\nVocê deseja pagar ",parcela," reais na parcela da sua linha de crédito.\nO empréstimo poderá ser concedido, já que a parcela é menor ou igual a 30% de seu salário.")
		}
		senao
			escreva("Seu salário é de ",salario," reais.\nVocê deseja pagar ",parcela," reais na parcela da sua linha de crédito.\nO empréstimo não poderá ser concedido, já que a parcela não é menor ou igual a 30% de seu salário.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 153; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */