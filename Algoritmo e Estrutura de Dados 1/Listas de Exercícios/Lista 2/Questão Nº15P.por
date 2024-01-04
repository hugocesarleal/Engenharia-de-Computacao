programa
{
	
	funcao inicio()
	{
		inteiro contador
		real controlemaior,controlemenor,num

		controlemenor=999999
		controlemaior=-999999
		num=0

		para(contador=1;contador<=10;contador++)
		{
			escreva("Informe um número: ")
			leia(num)

			se(num>controlemaior)
			{
				controlemaior=num
			}

			se(num<controlemenor)
			{
				controlemenor=num
			}
		}
		
		escreva("O maior número informado é ",controlemaior,"\nO menor número informado é ",controlemenor)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 51; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {controlemaior, 7, 7, 13}-{controlemenor, 7, 21, 13}-{num, 7, 35, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */