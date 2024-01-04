programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{
		real f,c

		c=1

		enquanto(c<=100)
		{
			f = Matematica.arredondar(c*1.8+32,1)
			
			se(c==1)
			{
				escreva(c,"° Celsius corresponde a ",f,"° Fahrenheit\n")
			}
			senao
				escreva(c,"° Celsius correspondem a ",f,"° Fahrenheit\n")
			
			c=c+1
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 135; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */