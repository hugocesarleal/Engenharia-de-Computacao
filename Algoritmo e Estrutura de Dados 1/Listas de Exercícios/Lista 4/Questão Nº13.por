programa
{
	
	funcao inicio()
	{
		cadeia vetEtapa[4], vetNome[2], nome, etapa
		inteiro cont, cont1
		real matTabela[2][5], somaTemp=0, controleMenor

		matTabela[0][0]=5 matTabela[0][1]=3 matTabela[0][2]=1 matTabela[0][3]=4 
		matTabela[1][0]=4.5 matTabela[1][1]=5 matTabela[1][2]=4 matTabela[1][3]=3 
		vetNome[0]="Rebimboca da Parafuseta" vetNome[1]="Flexímetro do Rabo do Jacaré"
		vetEtapa[0]="Etapa 1" vetEtapa[1]="Etapa 2" vetEtapa[2]="Etapa 3" vetEtapa[3]="Etapa 4"

		para(cont=0;cont<5;cont++)
		{
			somaTemp=somaTemp+matTabela[0][cont]
		}

		matTabela[0][4]=somaTemp/4

		somaTemp=0

		para(cont=0;cont<5;cont++)
		{
			somaTemp=somaTemp+matTabela[01][cont]
		}

		matTabela[1][4]=somaTemp/4

		se(matTabela[0][4]<matTabela[1][4])
		{
			escreva("A peça com menor qualidade é a Rebimboca da Parafuseta\n")
		}
		senao
			escreva("A peça com menor qualidade é o Flexímetro do Rabo do Jacaré")

		controleMenor=6
		nome=""
		etapa=""

		para(cont=0;cont<2;cont++)
		{
			para(cont1=0;cont1<5;cont1++)
			{
				se(matTabela[cont][cont1]<controleMenor)
				{
					controleMenor=matTabela[cont][cont1]
					nome=vetNome[cont]
					etapa=vetEtapa[cont1]
				}
			}
		}

		escreva("A peça ",nome," foi a que teve maior defeito na ",etapa,"\n")

		se(matTabela[0][4]>=4)
		{
			escreva("Rebimboca da Parafuseta foi aprovada\n")
		}
		senao
			escreva("Rebimboca da Parafuseta foi reprovado\n")

		se(matTabela[1][4]>=4)
		{
			escreva("Flexímetro do Rabo do Jacaré foi aprovado")
		}
		senao
			escreva("Flexímetro do Rabo do Jacaré foi reprovado")
			
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1402; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {matTabela, 8, 7, 9};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */