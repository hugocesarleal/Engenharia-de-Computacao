programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{
		cadeia nome
		real idade,somatorio,contador,media

		nome="a"
		contador=0
		somatorio=0
		idade=0
		
		enquanto(nome!="fim")
		{
			escreva("Informe o nome da pessoa: (Caso não tenham mais pessoas, digite 'fim').")
			leia(nome)

			se(nome!="fim")
			{
			escreva("Informe a idade de ",nome,":")
			leia(idade)

			contador=contador+1

			somatorio=somatorio+idade
			}
		}

		media = Matematica.arredondar(somatorio/contador,1)
		
		se(contador==1)
		{
			escreva("Foi contabilizada a idade de ",contador," pessoa e sua média é de ",media," anos.")
		}
		senao
			escreva("Foi contabilizada a idade de ",contador," pessoas e sua média é de ",media," anos.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 725; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {idade, 8, 7, 5}-{somatorio, 8, 13, 9}-{contador, 8, 23, 8}-{media, 8, 32, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */