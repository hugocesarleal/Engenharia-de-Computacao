programa
{
	
	funcao inicio()
	{
		cadeia vetNome[10], vetSexo[10], info
		inteiro vetIdade[10], cont, contM, contF, somaIdade, posicao, mV,mN, posMn, posMv

		contM=0
		contF=0
		somaIdade=0
		posicao=0
		mN=200
		mV=-1
		posMv=0
		posMn=0

		para(cont=0;cont<10;cont++)
		{
			escreva("Informa o nome da ",cont+1,"ª pessoa: ")
			leia(vetNome[cont])

			escreva("Informa a idade de ",vetNome[cont],": ")
			leia(vetIdade[cont])

			//Somatorio das idades
			somaIdade=somaIdade+vetIdade[cont]

			//Salva a maior e menor idade e a posição que está
			se(vetIdade[cont]>mV)
			{
				mV=vetIdade[cont]
				posMv=cont
			}

			se(vetIdade[cont]<mN)
			{
				mN=vetIdade[cont]
				posMn=cont
			}

			enquanto(vetSexo[cont]!="M" e vetSexo[cont]!="F")
			{
				escreva("Informa o sexo de ",vetNome[cont],": (Utilize 'M' ou 'F')")
				leia(vetSexo[cont])
			}

			//Contabiliza quantas são do sexo masculino e quantas são do feminino
			se(vetSexo[cont]=="M")
			{
				contM=contM+1
			}
			senao
				contF=contF+1
		}

		escreva("A média das idades é: ",somaIdade/10,".\n")
		
		escreva("Das 10 pessoas, ",contM," são do sexo masculino e ",contF," são do sexo feminino.\n")

		escreva("Informe o nome da pessoa que deseja saber as informações: ")
		leia(info)

		//Busca a posição da pessoa informada
		para(cont=0;cont<10;cont++)
		{
			se(vetNome[cont]==info)
			{
				posicao=cont
			}
		}

		//Traz as informações da pessoa informada
		se(vetSexo[posicao]=="M")
		{
			escreva(vetNome[posicao]," é do sexo masculino e tem ",vetIdade[posicao]," anos.\n")
		}
		senao
			escreva(vetNome[posicao]," é do sexo feminino e tem ",vetIdade[posicao]," anos.\n")

		escreva("Essas são as pessoas do sexo masculino: \n")

		//Busca todas as pessoas do sexo masculino
		para(cont=0;cont<10;cont++)
		{
			se(vetSexo[cont]=="M")
			{
				escreva(vetNome[cont],"\n")
			}
		}

		//Traz as informações da pessoa mais nova e a mais velha
		se(vetSexo[posMv]=="M")
		{
			escreva("A pessoa mais velha se chama ",vetNome[posMv],", tem ",vetIdade[posMv]," anos e é do sexo masculino.\n")
		}
		senao
			escreva("A pessoa mais velha se chama ",vetNome[posMv],", tem ",vetIdade[posMv]," anos e é do sexo feminino.\n")

		se(vetSexo[posMn]=="M")
		{
			escreva("A pessoa mais nova se chama ",vetNome[posMn],", tem ",vetIdade[posMn]," anos e é do sexo masculino.")
		}
		senao
			escreva("A pessoa mais nova se chama ",vetNome[posMn],", tem ",vetIdade[posMn]," anos e é do sexo feminino.")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1927; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vetNome, 6, 9, 7}-{vetSexo, 6, 22, 7}-{vetIdade, 7, 10, 8}-{somaIdade, 7, 44, 9};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */