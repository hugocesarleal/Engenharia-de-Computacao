<?php
	session_start();
	//averigua se o usuario fez login corretamente no sistema
	//caso nao tenha feito esse bloco de codigo a seguir impede o usuario
	//de acessar a pagina e redireciona o mesmo para a pagina inicial.
	//Caso o usuario tenha feito login corretamente, entao os dados deste
	//usuario serao capturados.
	if (!isset($_SESSION['login']))
	{
		header('location:index.php');
	}
	else
	{
		//faz a conexao com o banco de dados
		require('conexao.php');
		
		//constroi a string sql com base no login ja verificado na pagina de login
		$sql = "SELECT * FROM tb_usuario WHERE login_usuario='" . $_SESSION['login'] . "';";
		
		//vai no banco de dados e executa a consulta sql para buscar os dados do usuario
		//que acabou de fazer login
		$tabela = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));

		//prepara um vetor para receber os dados do usuario que esta no banco
		$dados_usuario = '';

		while ($linha = mysqli_fetch_row($tabela))
		{
			//busca o vetor com as informacoes do usuario e coloca no vetor dados_usuario
			$dados_usuario = $linha;
		}
		
		//ACESSA O BANCO DE DADOS E COLETA AS INFORMACOES DO USUARIO QUE SERA ALTERADO
		//captura o codigo do usuario
		$codigo = $_GET['codigo'];
		
		$sql = "SELECT * FROM tb_usuario WHERE id_usuario='" . $codigo . "';";
		
		$tabela = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));

		$nome = '';
		$login = '';
		$senha = '';
		$id_perfil = '';

		while ($linha = mysqli_fetch_row($tabela))
		{
			$nome = $linha[1];
			$login = $linha[2];
			$senha = $linha[3];
			$id_perfil = $linha[4];
		}
	}
?>

<html>
	<head>
		<title>Menu do Sistema</title>
		<style>
			table {
				width:100%;
			}
			table, th, td {
				border: 1px solid black;
				border-collapse: collapse;
			}
			th, td {
				padding: 5px;
				text-align: left;
			}
			table#t01 tr:nth-child(even) {
				background-color: #eee;
			}
			table#t01 tr:nth-child(odd) {
			   background-color:#fff;
			}
			table#t01 th {
				background-color: black;
				color: white;
			}
		</style>
	</head>
	<body>
		<table>
			<tr style="height:50px">
				<td colspan="2">
					<h1>MENU DO SISTEMA</h1>
				</td>
			</tr>
			<tr style="height:50px">
				<td>
					<img style="height:100px" src="imagens/<?php echo $dados_usuario[2] . '.jpg'; ?>"></img> <br>
					Seja bem vindo(a) <?php echo $dados_usuario[1]; ?>!
				</td>
				<td>
					<a href="logout.php"><img src="imagens/logout.jpg"></img></a>
				</td>
			</tr>
			<tr style="height:400px">
				<td colspan="2">
					<!-- TABELA QUE MOSTRA O MENU DO USUARIO -->
					<table style="height:400px;">
						<tr>
							<td style="width:150px; vertical-align:top;">
								<?php
									if ($dados_usuario[4]==1)
									{
										echo '
											<b>>> USU&Aacute;RIO</b></br>
											<a href="novo_usuario.php">Novo usu&aacute;rio</a><br>
											<a href="lista_usuario.php">Gerenciar Usu&aacute;rios</a><br>											
										';
									}
									else
									{
										echo '
											Voc&ecirc; n&atilde;o tem acesso a nenhum cadastro no momento.										
										';
									}								
								?>
							</td>
							<td style="vertical-align:top; text-align:left;">							
								<form method="post" action="salva_alteracao_usuario.php" enctype="multipart/form-data">
									
									<input type="hidden" name="hddCodigo" value="<?php echo $codigo; ?>"/>
									<table>
										<tr>
											<td colspan="2">
												<b>:: Novo Usu&aacute;rio ::</b>
											</td>
										</tr>
										<tr> 
											<td>
												Nome:											
											</td>
											<td>
												<input type="text" size="70" name="txtNome" value="<?php echo $nome; ?>"/>
											</td>
										</tr>
										<tr> 
											<td>
												Login:											
											</td>
											<td>
												<input type="text" size="30" name="txtLogin" readonly="disabled" value="<?php echo $login; ?>"/>
											</td>
										</tr>
										<tr> 
											<td>
												Senha:											
											</td>
											<td>
												<input type="text" size="30" name="txtSenha" value="<?php echo $senha; ?>"/>
											</td>
										</tr>
										<tr> 
											<td>
												Perfil:											
											</td>
											<td>
												<select name="slcPerfil">
												  <?php
													//faz a conexao com o banco de dados
													require('conexao.php');
													
													$sql = "SELECT * FROM tb_perfil;";

													$tabela = mysqli_query($conexao, $sql) 
													  or die(mysqli_error($conexao));

													while ($linha = mysqli_fetch_row($tabela))
													{
														$option = '<option value="'.$linha[0].'">'.$linha[1].'</option>';
														if ($linha[0]==$id_perfil)
														{														
															$option = '<option value="'.$linha[0].'" selected="selected">'.$linha[1].'</option>';
														}
														
														echo $option;
													}
												  ?>
												</select>
											</td>
										</tr>
										<tr> 
											<td>
												Foto:											
											</td>
											<td>
												<img style="height:150px" src="imagens/<?php echo $login . '.jpg'; ?>"></img><br>
												<input type="file" size="30" name="txtArquivo"/>
											</td>
										</tr>
										<tr>
											<td colspan="2" align="right">
												<button type="reset" name="btnApagar">Apagar</button>
												<button type="submit" name="btnAlterar">Alterar</button>
											</td>
										</tr>
									</table>
								</form>
							</td>
						</tr>
					</table>					
				</td>
			</tr>
		</table>
	</body>
</html>