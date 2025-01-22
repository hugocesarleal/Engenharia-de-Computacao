<?php
require_once('../controle/clsConexao.php');
require_once('clsComum.php');

class clsCategoria extends clsComum
{
	function __construct()
	{
	}
	
	public function pegaCategorias()
	{
		$conexao = new clsConexao();
		$perfis = $conexao->executaSQL('SELECT * from tb_categoria;');
		return $perfis;
	}
	
	public function pegaCategoriaPorId($id)
	{
		$conexao = new clsConexao();
		$sql = "SELECT nome_categoria FROM tb_produto WHERE id_produto=" . $id . ";";
		
		$tabela = $conexao->executaSQL($sql);
		$nome_produto = '';
		
		while ($linha = mysqli_fetch_row($tabela))
		{
			$nome_produto = $linha[0];
		}
		
		return $nome_produto;
	}
}
?>