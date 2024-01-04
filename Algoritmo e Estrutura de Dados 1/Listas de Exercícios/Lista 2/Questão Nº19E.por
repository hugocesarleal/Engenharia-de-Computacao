programa
{
	
	funcao inicio()
	{
		cadeia sexo,info
		inteiro contm,cont

		sexo="a"
		info="S"
		contm=0
		cont=0
		
		enquanto(info=="S" ou info=="s")
		{
			cont=cont+1
			
			escreva("Informe seu sexo (Utilize apenas as letras M ou F):")
			leia(sexo)

			se(sexo!="M" e sexo!="F")
			{
				escreva("Responda apenas com 'M' ou 'F'.\n")
				cont=cont-1
			}
			senao
				se(sexo=="M")
			{
				contm=contm+1	
			}	
			se(sexo=="M" ou sexo=="F")
			{
				escreva("Existem mais pessoas a serem questionadas? (Responda apenas com 'S' ou 'N') ")
				leia(info)
			}
		}
		escreva("Das ",cont," pessoas questionadas, ",contm," são do sexo masculino.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 337; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {sexo, 6, 9, 4}-{info, 6, 14, 4}-{contm, 7, 10, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */