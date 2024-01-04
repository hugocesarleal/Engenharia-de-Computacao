programa
{
	
	funcao inicio()
	{
		cadeia nome
		inteiro hora
	
		escreva("Qual o seu nome? ")
		leia(nome)

		escreva("Que horas são? (De 0 a 24) ")
		leia(hora)

		
		se ((hora >= 0) e (hora<=12))
			{
				escreva("Bom dia ",nome,"!")
			}
	
		senao
			se ((hora>12) e (hora<=18))
			{
				escreva("Boa tarde ",nome,"!")
			}
			
	     senao
	          se ((hora>18) e (hora<=24))
	         	{
	          	escreva("Boa noite ",nome,"!")
	          }
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 174; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */