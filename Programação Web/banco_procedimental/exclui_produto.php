<?php
	//verifica a existencia do usuario
	require('conexao.php');

	$codigo = $_GET['codigo'];

	echo "Codigo: ".$codigo;

	
	//verificar a existencia previa deste login
	$sql = "SELECT * FROM tb_produto WHERE id_produto='.$codigo.';";
	
	$tabela_imagem = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));

	$nome_imagem = '';

	// Iterar sobre os resultados e obter o nome da imagem
	while ($row = mysqli_fetch_assoc($tabela_imagem)) {
		$nome_imagem = $row['nome_produto']; // Substitua 'nome_produto' pelo nome real da coluna
		break; // Se você tiver certeza que só haverá uma linha, pode sair do loop aqui
	}
		  
	//averigua dentro da matrix quantas linhas existem


	
	//se exister apenas um admin no banco entao nao permite a exclusao dele
	//pois o sistema tem que ter pelo menos um administrador
	
		//criar a string sql que exclui o usuario do banco de dados
	$sql = "DELETE FROM tb_produto WHERE id_produto=".$codigo.";";

	//executa o comando DELETE no banco de dados para o usuario que tem
	//aquele codigo especifico
	$resultado = mysqli_query($conexao, $sql);

	$caminho_imagem = 'imagens/' . $nome_imagem . '.jpg';

	// Verificar se o arquivo existe
	if (file_exists($caminho_imagem)) {
		// Tentar excluir o arquivo
		if (!unlink($caminho_imagem)) {
			// Tratar erro de exclusão
			echo "Erro ao excluir a imagem: $caminho_imagem";
			// Adicionar log ou notificação
		}
	} else {
		echo "Imagem não encontrada: $caminho_imagem";
	}
	
	unlink('imagens/'.$nome_imagem.'.jpg');
	
	//avaliando o resultado
	if ($resultado == true)
	{
		header('location:lista_produto.php');
	}
	else
	{
		echo 'Problema ao apagar o registro no banco de dados <br>';
		echo 'O erro que aconteceu foi este: ' . mysqli_error($conexao);
		echo '<a href="menu.php"> VOLTAR </a>';
	}
	
?>