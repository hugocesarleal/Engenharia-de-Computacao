<?php

require_once 'clsEquipe.php';

$equipes = new clsEquipe();

$acao = '';

echo "<html lang='pt-BR'>
    <head>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <title>Cadastro de Equipes</title>
        <link rel='stylesheet' type='text/css' href='estilos/style_equipes.css'>
    </head>
    <body>
        <div class='background'></div>
        <div class='content'>
            <h2>Equipes Cadastradas</h2>";

$registros = $equipes->selecionarTodos();
if ($registros) {
    echo '<center><table border="1px">';
    echo '<tr><th>ID</th><th>Nome</th><th>Ação</th></tr>';
    foreach ($registros as $linha) {
        echo '<tr>';
        echo '<td>' . $linha['id_equipe'] . '</td>';
        echo '<td>' . $linha['nome'] . '</td>';
        echo '<td><a href="?acao=excluir1&id=' . $linha['id_equipe'] . '">
                  <img src="imagens/lixeira.png" alt="Excluir" width="50" height="50">
              </a></td>';
        echo '</tr>';
    }
    echo '</table></center>';
} else {
    echo '<h4>Nenhuma equipe encontrado.</h4>';
}

if (isset($_GET['acao']) && $_GET['acao'] == 'excluir1' && isset($_GET['id'])) {
    $idEquipe = $_GET['id'];
    if ($equipes->excluir($idEquipe)) {
        header("Location: equipes.php?sucesso=1");
        exit;
    } else {
        echo 'Erro ao excluir a equipe.';
    }
}

if (isset($_GET['sucesso']) && $_GET['sucesso'] == 1) {
    echo '<script>alert("Equipe excluída com sucesso!");</script>';
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nomeEquipe = $_POST['nome'];
    
    if ($equipes->inserir($nomeEquipe)) {
        echo '<script>alert("Equipe adicionada com sucesso!");</script>';
        header("Location: equipes.php");
        exit;
    } else {
        echo '<script>alert("Erro ao adicionar equipe.");</script>';
    }
}

echo '<br><br>';
echo '<button onclick="document.getElementById(\'formularioEquipe\').style.display=\'block\'">Adicionar Equipe</button>';

echo '<div id="formularioEquipe" style="display:none;">';
echo '<h3>Adicionar Nova Equipe</h3>';
echo '<form action="equipes.php" method="POST">';
echo 'Nome da Equipe: <input type="text" name="nome" required><br>';
echo '<input type="submit" value="Enviar">';
echo '</form>';
echo '</div>';

echo '<button id="homeButton" onclick="window.location.href=\'index.php\'">
    <img src="imagens/casa.png" alt="Home">
</button>';

echo "</body></html>";

?>