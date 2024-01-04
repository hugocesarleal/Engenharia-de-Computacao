programa
{
	inclua biblioteca Util
	
	funcao inicio()
	{
		real matInfos[50][13]
		inteiro funcionarios, cont
		cadeia vetNomes[50]

		//Salario base: coluna 0  número de horas contratuais: coluna 1     salário por hora: coluna 2
		//número de horas trabalhadas: coluna 3   horas extras: coluna 4   dependentes: coluna 5
		//quanto vai receber por hora extra ou perder por dever horas: coluna 6   receber dos dependentes: coluna 7
		//total de proventos: coluna 8    inss recolhido: coluna 9   irrf recolhido: coluna 10
		//total descontos: coluna 11   salário líquido: coluna 12

		funcionarios=51

		escreva("Quantos funcionários serão armazenados? (Máximo de 50) ")
		leia(funcionarios)

		enquanto(funcionarios<1 ou funcionarios>50)
		{
		escreva("Você digitou um número inválido, ele deve ser maior ou igual a 1 e menor ou igual a 50: ")
		leia(funcionarios)
		}

		para(cont=0;cont<funcionarios;cont++)
		{
			escreva("Informe o nome do ",cont+1,"º funcionário: ")
			leia(vetNomes[cont])

			escreva("Informe o salário base de ",vetNomes[cont],": ")
			leia(matInfos[cont][0])

			escreva("Informe o número de horas contratuais de ",vetNomes[cont],": ")
			leia(matInfos[cont][1])

			//Cálculo de quanto recebe por hora
			matInfos[cont][2]=matInfos[cont][0]/matInfos[cont][1]

			escreva("Informe o número de horas trabalhadas de ",vetNomes[cont],": ")
			leia(matInfos[cont][3])

			//Cálculo de quantas horas extras foram feitas ou quantas horas esta devendo
			matInfos[cont][4]=matInfos[cont][3]-matInfos[cont][1]

			Util.aguarde(1000)

			se(matInfos[cont][4]<0)
			{
				escreva("O funcionário ",vetNomes[cont]," está devendo ",matInfos[cont][4]*(-1)," horas para a empresa.\n")
				matInfos[cont][6]=((matInfos[cont][4]*(-1))*matInfos[cont][2])
			}
			senao
				matInfos[cont][6]=(matInfos[cont][2]*1.5)*matInfos[cont][4]

			escreva("Informe a quantidade de dependentes de ",vetNomes[cont],": ")
			leia(matInfos[cont][5])

			//Cálculo de quanto recebe por dependente
			matInfos[cont][7]=50*matInfos[cont][5]

			//Cálculo total dos proventos
			se(matInfos[cont][4]>=0)
			{
				matInfos[cont][8]=matInfos[cont][0]+matInfos[cont][6]+matInfos[cont][7]
			}
			senao
				matInfos[cont][8]=matInfos[cont][0]+matInfos[cont][7]

			//Cálculo INSS
			matInfos[cont][9]=matInfos[cont][8]*0.11

			//Cálculo IRRF
			se(matInfos[cont][8]>3000)
			{
				matInfos[cont][10]=matInfos[cont][8]*0.275
			}
			senao
				matInfos[cont][10]=matInfos[cont][8]*0.15

			escreva("Processando contra-cheque...\n")
			
			Util.aguarde(5000)

			se(matInfos[cont][4]<0)
			{
				//Total de descontos
				matInfos[cont][11]=matInfos[cont][9]+matInfos[cont][10]+matInfos[cont][6]
				//Salário Líquido
				matInfos[cont][12]=matInfos[cont][0]+matInfos[cont][7]-matInfos[cont][9]-matInfos[cont][10]-matInfos[cont][6]
				escreva("Nome: ",vetNomes[cont],"\nSalário Base: ",matInfos[cont][0],"\nAbono-dependentes: ",matInfos[cont][7])
				escreva("\nTotal de Proventos: ",matInfos[cont][8],"\nDesconto INSS: ",matInfos[cont][9])
				escreva("\nDesconto IRRF: ",matInfos[cont][10],"\nDesconto de Horas pendentes: ",matInfos[cont][6],"\nTotal dos Descontos: ",matInfos[cont][11],"\nSalário Líquido: ",matInfos[cont][12],"\n")
			}
			se(matInfos[cont][4]>=0)
			{
				//Total de descontos
				matInfos[cont][11]=matInfos[cont][9]+matInfos[cont][10]
				//Salário Líquido
				matInfos[cont][12]=matInfos[cont][0]+matInfos[cont][6]+matInfos[cont][7]-matInfos[cont][9]-matInfos[cont][10]
				escreva("Nome: ",vetNomes[cont],"\nSalário Base: ",matInfos[cont][0],"\nAbono-dependentes: ",matInfos[cont][7])
				escreva("\nHoras Extras: ",matInfos[cont][6],"\nTotal de Proventos: ",matInfos[cont][8],"\nDesconto INSS: ",matInfos[cont][9])
				escreva("\nDesconto IRRF: ",matInfos[cont][10],"\nTotal dos Descontos: ",matInfos[cont][11],"\nSalário Líquido: ",matInfos[cont][12],"\n")
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 3094; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {matInfos, 7, 7, 8}-{vetNomes, 9, 9, 8};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */