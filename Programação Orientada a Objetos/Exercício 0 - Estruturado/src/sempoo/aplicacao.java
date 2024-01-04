package sempoo;

import java.util.Scanner;

public class aplicacao {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double xBase, xAltura, yBase, yAltura, xArea, yArea;
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Entre com as medidas do retângulo X:");
		xBase = sc.nextDouble();
		xAltura = sc.nextDouble();
		
		System.out.println("Entre com as medidas do retângulo Y:");
		yBase = sc.nextDouble();
		yAltura = sc.nextDouble();
		
		xArea = xBase * xAltura;
		yArea = yBase * yAltura;
		
		System.out.println("Área do Retângulo X = " + xArea);
		System.out.println("Área do Retângulo Y = " + yArea);
		
		if(xArea == yArea) {
			System.out.println("Os valores das áreas são iguais!");
		}
		else {if(xArea > yArea) {
			System.out.println("O valor da área de X é maior que Y!");
		}
		else {
			System.out.println("O valor da área de Y é maior que X!");
		}
	}
	}
}

