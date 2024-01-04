package aplicação;

import entidades.Conta;
import entidades.Cliente;

public class Aplicacao {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cliente cliente = new Cliente();
		
		Conta c = new Conta(524,cliente);
		
		c.setNome("João");
		c.getNome();
	}

}
