package aplicacao;

import entidades.RoboSimples;

import java.util.*;

public class Aplicação {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		RoboSimples r1 = new RoboSimples("Groucho",20,10,"Sul");
		RoboSimples r2 = new RoboSimples("Chico");
		RoboSimples r3 = new RoboSimples();
		
		r1.moveN(10);
		r2.mudarDirecao("Leste");
		r2.moveN(5);
		r3.moveUm();
		
		r1.mostrar();
		r2.mostrar();
		r3.mostrar();
		
	}
}
