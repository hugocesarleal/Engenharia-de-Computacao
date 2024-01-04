package aplicação;

import entidades.Carro;

import java.util.Scanner;

public class Aplicacao {

	public static void main(String[] args) {
		
		Carro c = new Carro();
		
		int resp;
		double precoGas;
		
		Scanner sc;
		
		sc = new Scanner (System.in);
		
		precoGas = 7.5;
		
		System.out.println("Quantos quilometros serão percorridos?");
		resp=sc.nextInt();
		
		c.quilometragem(precoGas, resp);
		
		System.out.println("Escolha a ação que o carro irá executar:\r\n"
				+ "1 - Frear\r\n"
				+ "2 - Acelerar\r\n"
				+ "3 - Parar\r\n"
				+ "4 - Trocar Marcha");
		
		resp = sc.nextInt();
		
		if(resp==1) {
			c.frear();
		}else if(resp==2) {
			c.acelerar();
		}else if(resp==3) {
			c.parar();
		}else if(resp==4) {
			c.trocarMarchas();
		}else {
			System.out.println("Opção incorreta");
		}
			
		
	}
}

