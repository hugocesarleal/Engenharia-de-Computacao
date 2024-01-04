package entidades;

public class CalcularCusto {
	public String calculaEficiência(int a, int b) {
		int resultado = 0;
		String saida = "";
		
		if(b < a) {
			resultado = ((a - b)/b);
			saida = "O algoritmo B é " + resultado + " vezes mais eficiente que A";
			return saida; 
		}
		
		if(b > a) {
			resultado = ((b - a)/a);
			saida = "O algoritmo B é " + resultado + " vezes menos eficiente que A";
			return saida; 
		}
		
		return "Eles são iguais";
	}
}
