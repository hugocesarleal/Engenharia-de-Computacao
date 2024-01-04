programa
{
	
	funcao inicio()
	{
		inteiro cont,contf
		cadeia sexo
		real porcentagem

		contf=0
	
		para(cont=1;cont<=15;cont++)
		{
			escreva("Informe seu sexo (M ou F):")
			leia(sexo)

			se(sexo!="M" e sexo!="F")
			{
				escreva("Informe o sexo apenas usando 'M' ou 'F'\n")
				cont=cont-1
			}
			senao
				se(sexo=="F")
				{
					contf=contf+1
				}	
		}
		
		porcentagem=(contf*100)/15
		
		escreva("Das 15 pessoas questionadas, ",porcentagem,"% são do sexo feminino.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 373; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */