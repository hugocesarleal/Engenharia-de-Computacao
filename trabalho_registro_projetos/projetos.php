<?php

require_once 'clsProjeto.php';
require_once 'clsEquipe.php';

$equipes = new clsEquipe();
$projetos = new clsProjeto();

$acao = '';

echo "<html lang='pt-BR'>
    <head>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <title>Cadastro de Projetos</title>
        <link rel='stylesheet' type='text/css' href='estilos/style_projetos.css'>
        <script src='scripts/script.js'></script>
    </head>
    <body>
        <div class='background'></div>
        <div class='content'>
            <h2>Projetos Cadastrados</h2>";

$registros = $projetos->selecionarTodos();
if ($registros) {
    echo '<center><table border="1px">';
    echo '<tr><th>ID</th><th>Nome do Projeto</th><th>Salário</th><th>Equipe</th><th>Ação</th></tr>';
    foreach ($registros as $linha) {
        echo '<tr>';
        echo '<td>' . $linha['id_projeto'] . '</td>';
        echo '<td>' . $linha['nome_projeto'] . '</td>';
        echo '<td>R$ ' . $linha['salario'] . '</td>';
        echo '<td>' . $linha['nome_equipe'] . '</td>';
        echo '<td><a href="?acao=excluir1&id=' . $linha['id_projeto'] . '">
                  <img src="imagens/lixeira.png" alt="Excluir" width="50" height="50">
              </a></td>';
        echo '</tr>';
    }
    echo '</table></center>';
} else {
    echo '<h4>Nenhum Projeto encontrado.</h4>';
}

if (isset($_GET['acao']) && $_GET['acao'] == 'excluir1' && isset($_GET['id'])) {
    $idProjeto = $_GET['id'];
    if ($projetos->excluir($idProjeto)) {
        header("Location: projetos.php?sucesso=1");
        exit;
    } else {
        echo 'Erro ao excluir o projeto.';
    }
}

if (isset($_GET['sucesso']) && $_GET['sucesso'] == 1) {
    echo '<script>alert("Projeto excluído com sucesso!");</script>';
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nomeProjeto = $_POST['nome'];
    
    $salario = $_POST['salario'];
    $salario = preg_replace('/[^0-9.,]/', '', $salario);
    $salario = str_replace(',', '.', $salario);
    
    $idEquipe = $_POST['equipe'];
    
    if ($projetos->inserir($nomeProjeto, $salario, $idEquipe)) {
        echo '<script>alert("Projeto adicionado com sucesso!");</script>';
        header("Location: projetos.php");
        exit;
    } else {
        echo '<script>alert("Erro ao adicionar projeto.");</script>';
    }
}


echo '<br><br>';
echo '<button onclick="document.getElementById(\'formularioProjeto\').style.display=\'block\'">Adicionar Projeto</button>';

$equipesDisponiveis = $equipes->selecionarTodos();

echo '<div id="formularioProjeto" style="display:none;">';
echo '<h3>Adicionar Novo Projeto</h3>';
echo '<form action="projetos.php" method="POST">';
echo 'Nome do Projeto: <input type="text" name="nome" required><br>';
echo 'Salário: <input id="salario" type="text" name="salario" required oninput="formatarMoeda(event)" placeholder="R$ 0,00"><br>';
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

echo "</body></html>";

?>