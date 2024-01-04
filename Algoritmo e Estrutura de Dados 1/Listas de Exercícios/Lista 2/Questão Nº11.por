programa
{
	
	funcao inicio()
	{

		inteiro num1,num2,num3,controlemaior,controlemenor

		controlemaior=-99999999
		controlemenor=999999999
	
		escreva("Informe o primeiro número: ")
		leia(num1)

		escreva("Informe o segundo número: ")
		leia(num2)

		escreva("Informe o terceiro número: ")
		leia(num3)

		se(num1!=num2 ou num1!=num3 ou num2!=num3)
		{
			se(num1<controlemenor)
			{
				controlemenor=num1
			}
				
			se(num2<controlemenor)
			{
				controlemenor=num2
			}

			se(num3<controlemenor)
			{
				controlemenor=num3
			}

			se(num1>controlemaior)
			{
				controlemaior=num1
			}

			se(num2>controlemaior)
			{
				controlemaior=num2
			}

			se(num3>controlemaior)
			{
				controlemaior=num3
			}

			escreva("O menor número informado é: ",controlemenor,"\nO maior número informado é: ",controlemaior)
		}
		senao
			escreva("Alguns dos números informados são iguais.")	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 890; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {num1, 7, 10, 4}-{num2, 7, 15, 4}-{num3, 7, 20, 4}-{controlemaior, 7, 25, 13}-{controlemenor, 7, 39, 13};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */