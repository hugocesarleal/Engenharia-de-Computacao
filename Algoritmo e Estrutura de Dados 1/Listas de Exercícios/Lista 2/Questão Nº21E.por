programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{
		inteiro cont
		real A,B,arredondamento,arredondamentoA,arredondamentoB

		cont=0

		A=5000000
		B=7000000

		escreva("A população inicial do país A é de ",A," de habitantes.\nA população inicial do país B é de ",B," de habitantes.\n")

		enquanto(cont<=14)
		{
			cont=cont+1
			
			A=A+(A*0.03)
			B=B+(B*0.02)

			arredondamentoA = Matematica.arredondar(A, 2)
			arredondamentoB = Matematica.arredondar(B, 2)

			se(cont==1)
			{
				escreva("Após ",cont," ano, a população do país A é de ",arredondamentoA," habitantes.\nApós ",cont," ano, a população do país B é de ",arredondamentoB," habitantas.\n")
			}
			senao
				escreva("Após ",cont," anos, a população do país A é de ",arredondamentoA," habitantes.\nApós ",cont," anos, a população do país B é de ",arredondamentoB," habitantas.\n")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 721; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */