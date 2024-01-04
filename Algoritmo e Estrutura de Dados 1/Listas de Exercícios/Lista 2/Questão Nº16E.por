programa
{
	
	funcao inicio()
	{

		real contador,num,contadorintervalo

		contadorintervalo=0
		contador=1
	
		enquanto(contador<=20)
		{
			contador=contador+1
			
			escreva("Informe um número: ")
			leia(num)

			se(num>=100 e num<=200)
			{
				contadorintervalo=contadorintervalo+1
			}
		}
		se(contadorintervalo==0)
		{
			escreva("Nenhum número entre 100 e 200 foi informado.")
		}
		senao
			escreva("Foram informados ",contadorintervalo," valores que estão entre 100 e 200.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 161; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */