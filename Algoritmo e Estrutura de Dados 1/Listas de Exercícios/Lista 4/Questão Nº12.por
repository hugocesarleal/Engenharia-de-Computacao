programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{
		cadeia controleMaiorDia, controleMenorDia, vetDias[7]
		inteiro matTemp[2][7], somaTemporaria, cont, controleMaior, controleMenor
		real mediaMin, mediaMax

		vetDias[0]="Segunda" vetDias[1]="Terça"//, vetDias[2], vetDias[3], vetDias[4], vetDias[5], vetDias[6]
		matTemp[0][0]=14 matTemp[0][1]=16 matTemp[0][2]=17 matTemp[0][3]=16 matTemp[0][4]=16 matTemp[0][5]=18 matTemp[0][6]=19
		matTemp[1][0]=29 matTemp[1][1]=29 matTemp[1][2]=28 matTemp[1][3]=28 matTemp[1][4]=28 matTemp[1][5]=27 matTemp[1][6]=22 

		escreva("Temperatura / Dias   Segunda   Terça   Quarta   Quinta   Sexta   Sábado   Domingo\n")
		escreva("      Mínima      ","      ",matTemp[0][0],"       ", matTemp[0][1],"      ", matTemp[0][2],"       ", matTemp[0][3],"      ", matTemp[0][4],"       ", matTemp[0][5],"       ", matTemp[0][6],"\n")
		escreva("      Máxima      ","      ",matTemp[1][0],"       ", matTemp[1][1],"      ", matTemp[1][2],"       ", matTemp[1][3],"      ", matTemp[1][4],"       ", matTemp[1][5],"       ", matTemp[1][6],"\n")

		somaTemporaria = 0

		para(cont=0;cont<7;cont++)
		{
			somaTemporaria = somaTemporaria+matTemp[0][cont]
		}

		mediaMin = Matematica.arredondar(somaTemporaria/7,2)

		somaTemporaria=0

		para(cont=0;cont<7;cont++)
		{
			somaTemporaria = somaTemporaria+matTemp[1][cont]
		}

		mediaMax = Matematica.arredondar(somaTemporaria/7,2)

		escreva("\nMédia semanal para temperatura mínima: ",mediaMin,"\nMédia semanal para temperatura máxima: ",mediaMax,"\n")

		controleMaior=0
		controleMaiorDia=""

		para(cont=0;cont<7;cont++)
		{
			se(matTemp[1][cont]>=controleMaior)
			{
				controleMaior=matTemp[1][cont]
				controleMaiorDia=controleMaiorDia+" "+vetDias[cont]
			}
		}

		escreva("Os dias com maior previsão de temperatura são",controleMaiorDia," com ",controleMaior,"ºC.\n")

		controleMenor=50
		controleMenorDia=""

		para(cont=0;cont<7;cont++)
		{
			se(matTemp[0][cont]<=controleMenor)
			{
				controleMenor=matTemp[0][cont]
				controleMenorDia=controleMenorDia+" "+vetDias[cont]
			}
		}

		escreva("Os dias com menor previsão de temperatura são",controleMenorDia," com ",controleMenor,"ºC.\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1971; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {controleMaiorDia, 7, 9, 16};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */