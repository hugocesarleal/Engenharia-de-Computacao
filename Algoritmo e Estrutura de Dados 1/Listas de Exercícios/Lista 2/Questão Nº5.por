programa
{	
	inclua biblioteca Matematica
	
	funcao inicio()
	{
		cadeia sexo
		real altura,pesoIdeal,pesoArr

		escreva("Qual sua altura? (Em metros) ")
		leia(altura)
	
		escreva("Se você for homem, digite M, se for mulher, digite F: ")
		leia(sexo)

		se(sexo=="m" ou sexo=="M")
		{
			pesoIdeal=(72.7*altura)-58

			pesoArr=Matematica.arredondar(pesoIdeal,2)
			
			escreva("Seu peso ideal é: ",pesoArr," kg.")
		}
		senao
			se(sexo=="f" ou sexo=="F")
			{
				pesoIdeal=(62.1*altura)-44.7

				pesoArr=Matematica.arredondar(pesoIdeal,2)
				
				escreva("Seu peso ideal é: ",pesoArr," kg.")
			}
		senao
			escreva("Você digitou uma letra inválida quando perguntado se é homem ou mulher.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 589; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */