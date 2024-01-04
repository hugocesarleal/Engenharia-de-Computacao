package entidades;

import entidades.Cliente;

public class Conta {
	private int codigo;
	private Cliente cliente;
	
	public Conta(int codigo, Cliente cliente) {
		this.codigo = codigo;
		this.cliente = cliente;
	}
	
	public void setNome(String nome) {
		this.cliente.nome = nome;
	}
	public void getNome() {
		System.out.println(cliente.nome);
	}
}
