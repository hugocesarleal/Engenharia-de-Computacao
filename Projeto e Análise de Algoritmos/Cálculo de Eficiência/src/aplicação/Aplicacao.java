package aplicação;

import entidades.CalcularCusto;

public class Aplicacao {

	public static void main(String[] args) {

		CalcularCusto c = new CalcularCusto();
		
		String resposta;

		resposta = c.calculaEficiência(120, 1);
		
		System.out.println(resposta);
	}

}
