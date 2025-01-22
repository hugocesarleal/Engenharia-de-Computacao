<?php
    // Captura de variáveis
    $hidden = $_POST['hddCodigo'];
    $codigo = $_POST['txtCodigo'];
    $nome = $_POST['txtNome'];
    $email = $_POST['txtEmail'];
    $nasc = $_POST['txtDataNasc'];
    $nasc = date('d/m/Y', strtotime($nasc));
    $arquivo = $_FILES['txtArquivo'];

    $senha = 'Senha n&atilde;o informada';
    if (isset($_POST['txtSenha'])) {
        $senha = $_POST['txtSenha'];
    }

    if (empty($nasc) || $nasc == '01/01/1970') {
        $nasc = 'N&atilde;o informada ou inv&aacute;lida';
    }

    if (isset($_POST['rdbEstCivil'])) {
        $estCivil = $_POST['rdbEstCivil'];
    }

    $atuacao = '';

    if (isset($_POST['chkEngenharias'])) {
        $atuacao .= ' Engenharias';
    }

    if (isset($_POST['chkAgrarias'])) {
        $atuacao .= ' Agrarias';
    }

    if (isset($_POST['chkHumanas'])) {
        $atuacao .= ' Humanas';
    }

    if (isset($_POST['chkLinguagens'])) {
        $atuacao .= ' Linguagens';
    }
    
    if (empty($atuacao)) {
        $atuacao = ' Nenhuma área selecionada!';
    }

    echo 'Hidden: ' . $hidden . '<br>';
    echo 'C&oacute;digo: ' . $codigo . '<br>';

    if (empty($nome)) {
        echo 'Nome n&atilde;o informado! <br>';
    } else {
        echo 'Nome: ' . $nome . '<br>';
    }

    echo 'Senha: ' . $senha . '<br>';
    echo 'Email: ' . $email . '<br>';
    echo 'Data de Nascimento: ' . $nasc . '<br>';
    echo 'Arquivo: ' . $arquivo['name'] . ' - Tamanho: ' . $arquivo['size'] . '<br>';

    if ($estCivil == '1') {
        echo 'Estado Civil: Casado<br>';
    } else if ($estCivil == '2') {
        echo 'Estado Civil: Solteiro<br>';
    } else if ($estCivil == '3') {
        echo 'Estado Civil: Enrolado<br>';
    }

    echo 'Área de atuação:' . $atuacao . '<br>';

    if (!empty($_POST['txaMensagem'])) {
        $mensagem = $_POST['txaMensagem'];
    }else{
        $mensagem = 'Mensagem nao informada!';
    }

    echo 'A mensagem digitada foi: ' . $mensagem . '<br>';

    $sadi = $_POST['slcSadi'];
    if ($sadi == 'amo') {
        $sadi = 'Amo';
    } else if ($sadi == 'suporto') {
        $sadi = 'Suporto';
    } else if ($sadi == 'ponte') {
        $sadi = 'Jogaria de uma ponte';
    }

    echo 'Isso é o quanto voc&ecirc; gosta do Sadi: ' . $sadi . '<br>';

    $cor = $_POST['clrColor'];

    echo 'Essa é sua cor favorita: ' . $cor . '<br>';

    $lista = [];

    if(isset($_POST['slcLista'])){
        $lista = $_POST['slcLista'];
    }

    echo 'Lista de Compras:<br>';
    echo '<ul>';
    foreach ($lista as $item){
        echo '<li>' . $item . '</li>';
    }
    echo '</ul>';

    if (isset($_POST['rdbEstCivil'])) {
        $ia = $_POST['rdbIA'];
    }

    if (isset($_POST['rdbEstCivil'])) {
        $web = $_POST['rdbWeb'];
    }

    echo 'Professor favorito de IA: ' . $ia . '<br>';
    echo 'Professor favorito de Web: ' . $web . '<br>';

?>
