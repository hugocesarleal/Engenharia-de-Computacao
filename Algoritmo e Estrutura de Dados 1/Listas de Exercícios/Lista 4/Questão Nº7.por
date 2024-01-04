programa
{
	
	funcao inicio()
	{
		inteiro cont, posicao, infoNum
		cadeia vetNomes[10], info
		
		para(cont=0;cont<10;cont++)
		{
			escreva("Informe o ",cont+1,"º nome: ")
			leia(vetNomes[cont])
		}

		escreva("Informe o nome que deseja procurar: ")
		leia(info)

		posicao=0
		
		para(cont=0;cont<10;cont++)
		{
			se(vetNomes[cont]==info)
			{
				posicao=cont+1
				escreva("O nome ",info," está na ",posicao,"ª posição.\n")
			}
		}

		se(posicao==0)
		{
			escreva("Nome não encontrado!\n")
		}

		escreva("Informe a posição que está o nome desejado: ")
		leia(infoNum)

		escreva("O nome que está na ",infoNum,"ª posição é: ",vetNomes[infoNum-1])
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 503; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNomes, 7, 9, 8};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */