//Faça um algoritmo que receba a hora (de 0 à 24) atual a partir do teclado e informe se é manhã, tarde, ou noite. Critério: Até 12 horas é manhã, acima 12 até 18 é tarde e acima de 18 noite
programa
{
	
	funcao inicio()
	{

		inteiro hora
	
		escreva("Que horas são? (De 0 a 24) ")
		leia(hora)

			se ((hora >= 0) e (hora<=12))
			{
				escreva("Agora é manhã")
			}
	
		senao
			se ((hora>12) e (hora<=18))
			{
				escreva("Agora é tarde")
			}
			
	     senao
	          se ((hora>18) e (hora<=24))
	         	{
	          	escreva("Agora é noite")
	          }
	}	
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 345; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */