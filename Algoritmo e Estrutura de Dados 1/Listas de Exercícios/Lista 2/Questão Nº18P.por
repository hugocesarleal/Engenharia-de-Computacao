programa
{
	
	funcao inicio()
	{
		inteiro cont,contm
		cadeia sexo

		contm=0
	
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
				se(sexo=="M")
				{
					contm=contm+1
				}	
		}
		escreva("Das 15 pessoas questionadas, ",contm," são do sexo masculino.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 128; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {cont, 6, 10, 4}-{contm, 6, 15, 5}-{sexo, 7, 9, 4};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */