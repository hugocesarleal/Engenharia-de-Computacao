programa
{
	
	funcao inicio()
	{
		inteiro contador,contdentista
		cadeia profissao

		contdentista=0
			
		para(contador=1;contador<=30;contador++)
		{
			escreva("Informe sua profissão: ")
			leia(profissao)

			se(profissao=="DENTISTA" ou profissao=="Dentista" ou profissao=="dentista")
			{
				contdentista=contdentista+1
			}
		}
		escreva("Das 30 pessoas, ",contdentista," são dentistas.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 37; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */