programa
{
	
	funcao inicio()
	{
		inteiro cont, cont1, cont2, cont3
		real vetNum1[5], vetNum2[5], vetNum3[25], vetNum4[25], vetNum5[5], produto, soma

		para(cont=0;cont<5;cont++)
		{
			escreva("Informe o ",cont+1,"º número a ser armazenado no primeiro vetor: ")
			leia(vetNum1[cont])
		}

		para(cont=0;cont<5;cont++)
		{
			escreva("Informe o ",cont+1,"º número a ser armazenado no segundo vetor: ")
			leia(vetNum2[cont])
		}

		//Parte responsável por Multiplicar os elementos dos vetores vetNum1 e vetNum2 e guardalos no vetNum3
		cont3=-1

		para(cont1=0;cont1<5;cont1++)
		{
			para(cont2=0;cont2<5;cont2++)
			{	
				produto=vetNum1[cont1]*vetNum2[cont2]
				cont3=cont3+1
				vetNum3[cont3]=produto
			}
		}

		//Parte responsável por Somar os elementos dos vetores vetNum1 e vetNum2 e guardalos no vetNum3
		cont3=-1

		para(cont1=0;cont1<5;cont1++)
		{
			para(cont2=0;cont2<5;cont2++)
			{	
				soma=vetNum1[cont1]+vetNum2[cont2]
				cont3=cont3+1
				vetNum4[cont3]=soma
			}
		}

		//Parte responsável por atribuir os números do vetNum1 para o vetNum5 de forma inversa
		cont2=5
		
		para(cont1=0;cont1<5;cont1++)
		{
			cont2=cont2-1
			vetNum5[cont1]=vetNum1[cont2]
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1091; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNum1, 7, 7, 7}-{vetNum5, 7, 57, 7};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */