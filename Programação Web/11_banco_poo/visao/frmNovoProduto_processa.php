<?php
require('../modelo/clsProduto.php');

$produto = new clsProduto();
$produto->setNome($_POST['txtNome']);
$produto->setPreco($_POST['txtPreco']);
$produto->setCategoria($_POST['slcCategoria']);
$produto->setFoto($_FILES['txtArquivo']);


	if ($produto->salvar() == true)
	{
		#header('location:lista_usuario.php');
		echo 'Salvo!';
	}
	else
	{
		echo 'Problema ao inserir o registro no banco de dados <br>';
	}


echo '<a href="frmNovoProduto.php"> VOLTAR </a>';


?>