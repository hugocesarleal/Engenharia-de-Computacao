package entidades;

import java.util.*;

public class Carro {
	
	public String marca, modelo, cor, chaci;
	public double quilometros;
	
	
	public void frear() {
		System.out.println("O carro está freando.");
	}
	
	public void acelerar() {
		System.out.println("O carro está acelerando.");
	}
	
	public void parar() {
		System.out.println("O carro está parando.");
	}
	
	public void trocarMarchas() {
		System.out.println("Trocando marcha");
	}
	
	public void quilometragem(double precoGas, double quilometros) {
		
		System.out.println("O valor gasto de combustível é: R$"+quilometros*precoGas);
	}
}
