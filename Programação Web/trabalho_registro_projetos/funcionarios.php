<?php

require_once 'clsFuncionario.php';
require_once 'clsEquipe.php';

$equipes = new clsEquipe();
$funcionarios = new clsFuncionario();

echo "<html lang='pt-BR'>
    <head>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <title>Cadastro de Funcionários</title>
        <link rel='stylesheet' href='estilos/style_funcionarios.css'>
    </head>
    <body>
        <div class='background'></div>
        <div class='content'>
            <h2>Funcionários Cadastrados</h2>";

echo "<div id='tabelaFuncionarios'>";

$registros = $funcionarios->selecionarTodos();
if ($registros) {
    echo '<center><table class="funcionarios-table">';
    echo '<tr><th>ID</th><th>Nome</th><th>Email</th><th>Equipe</th><th>Ação</th></tr>';
    foreach ($registros as $linha) {
        echo '<tr>';
        echo '<td>' . $linha['id_funcionario'] . '</td>';
        echo '<td>' . $linha['nome_funcionario'] . '</td>';
        echo '<td>' . $linha['email'] . '</td>';
        echo '<td>' . $linha['nome_equipe'] . '</td>';
        echo '<td><a href="?acao=excluir1&id=' . $linha['id_funcionario'] . '">
                  <img src="imagens/lixeira.png" alt="Excluir" width="50" height="50">
              </a></td>';
        echo '</tr>';
    }
    echo '</table></center>';
} else {
    echo '<h4>Nenhum Funcionário encontrado.</h4>';
}

echo "</div>";

if (isset($_GET['acao']) && $_GET['acao'] == 'excluir1' && isset($_GET['id'])) {
    $idFuncionario = $_GET['id'];
    if ($funcionarios->excluir($idFuncionario)) {
        echo '<script>alert("Funcionário excluído com sucesso!");</script>';
        header("Location: funcionarios.php?sucesso=1");
        exit;
    } else {
        echo 'Erro ao excluir o funcionário.';
    }
}

if (isset($_GET['sucesso']) && $_GET['sucesso'] == 1) {
    echo '<script>alert("Funcionário adicionado com sucesso!");</script>';
}

echo '<br><br>';
echo '<button id="addFuncionarioButton" onclick="document.getElementById(\'formularioFuncionario\').style.display=\'block\'">Adicionar Funcionário</button>';

$equipesDisponiveis = $equipes->selecionarTodos();

echo '<div id="formularioFuncionario">';
echo '<h3>Adicionar Novo Funcionário</h3>';
echo '<form action="funcionarios.php" method="POST">';
echo 'Nome do Funcionário: <input type="text" name="nome" required><br>';
echo 'Email: <input type="text" name="email" required><br>';
echo 'Equipe: <select name="equipe" required>';

if ($equipesDisponiveis) {
    foreach ($equipesDisponiveis as $equipe) {
        echo '<option value="' . $equipe['id_equipe'] . '">' . $equipe['nome'] . '</option>';
    }
} else {
    echo '<option value="">Nenhuma equipe disponível</option>';
}

echo '</select><br>';
echo '<input type="submit" value="Enviar">';
echo '</form>';
echo '</div>';

echo '<button id="homeButton" onclick="window.location.href=\'index.php\'">
    <img src="imagens/casa.png" alt="Home">
</button>';

echo "</div>";
echo "</body>
</html>";

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nomeFuncionario = $_POST['nome'];
    $email = $_POST['email'];
    $idEquipe = $_POST['equipe'];

    $sucesso = $funcionarios->inserir($nomeFuncionario, $email, $idEquipe);

    if ($sucesso) {
        header("Location: funcionarios.php?sucesso=1");
        exit;
    } else {
        echo '<script>alert("Erro ao adicionar funcionário.");</script>';
    }
}
?>