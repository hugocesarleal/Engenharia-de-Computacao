<?php
require_once 'clsPessoa.php';
require_once 'clsAnimal.php';
$pessoa = new clsPessoa();
$animal = new clsAnimal();

echo "<html><body><center>";

echo '<h2>O QUE QUER FAZER?</h2>';
echo '<a href="?acao=inserir1">INSERIR UM DADO NO BANCO DE DADOS PESSOA</a><br>';
echo '<a href="?acao=inserir2">INSERIR UM DADO NO BANCO DE DADOS ANIMAL</a><br>';
echo '<a href="?acao=consultar">EXECUTAR UMA CONSULTA NO BANCO DE DADOS</a><br>';
echo '<a href="?acao=listar1">EXIBIR CONSULTA NA FORMA DE TABELA PESSOA</a><br>';
echo '<a href="?acao=listar2">EXIBIR CONSULTA NA FORMA DE TABELA ANIMAL</a><br>';
echo '</center><br>';

$acao = $_GET['acao'] ?? '';

switch ($acao) {
    case 'inserir1':
        $pessoa->inserir("Rodrigo Oliveira", 23);
        echo 'Registro inserido com sucesso';
        break;

    case 'inserir2':
        $animal->inserir("Cachorro","Pug",9);
        echo 'Registro inserido com sucesso';
        break;

    case 'consultar':
        $registros = $pessoa->selecionarTodos();
        if ($registros) {
            foreach ($registros as $linha) {
                echo 'Id: ' . htmlspecialchars($linha['id']) . '<br>';
                echo 'Nome: ' . htmlspecialchars($linha['nome']) . '<br>';
                echo 'Idade: ' . htmlspecialchars($linha['idade']) . '<br><br>';
            }
        } else {
            echo 'Nenhum registro encontrado.';
        }
        break;

    case 'listar1':
        $registros = $pessoa->selecionarTodos();
        if ($registros) {
            echo '<center><table border="1px">';
            echo '<tr><th>ID</th><th>Nome</th><th>Idade</th><th>Ação</th></tr>';
            foreach ($registros as $linha) {
                echo '<tr>';
                echo '<td>' . htmlspecialchars($linha['id']) . '</td>';
                echo '<td>' . htmlspecialchars($linha['nome']) . '</td>';
                echo '<td>' . htmlspecialchars($linha['idade']) . '</td>';
                echo '<td><a href="?acao=excluir1&id=' . urlencode($linha['id']) . '">APAGAR</a></td>';
                echo '</tr>';
            }
            echo '</table></center>';
        } else {
            echo 'Nenhum registro encontrado.';
        }
        break;

    case 'listar2':
        $registros = $animal->selecionarTodos();
        if ($registros) {
            echo '<center><table border="1px">';
            echo '<tr><th>ID</th><th>Animal</th><th>Raça</th><th>Nome</th><th>Ação</th></tr>';
            foreach ($registros as $linha) {
                echo '<tr>';
                echo '<td>' . htmlspecialchars($linha['id']) . '</td>';
                echo '<td>' . htmlspecialchars($linha['animal']) . '</td>';
                echo '<td>' . htmlspecialchars($linha['raca']) . '</td>';
                echo '<td>' . htmlspecialchars($linha['nome']) . '</td>';
                echo '<td><a href="?acao=excluir2&id=' . urlencode($linha['id']) . '">APAGAR</a></td>';
                echo '</tr>';
            }
            echo '</table></center>';
        } else {
            echo 'Nenhum registro encontrado.';
        }
        break;

    case 'excluir1':
        $id = $_GET['id'] ?? 0;
        if ($pessoa->excluir($id)) {
            echo 'Registro apagado com sucesso';
        } else {
            echo 'Problema ao apagar o registro.';
        }
        break;

    case 'excluir2':
        $id = $_GET['id'] ?? 0;
        if ($animal->excluir($id)) {
            echo 'Registro apagado com sucesso';
        } else {
            echo 'Problema ao apagar o registro.';
        }
        break;

    default:
        echo '<p>Escolha uma opção do menu acima.</p>';
        break;
}

echo "</body></html>";
?>