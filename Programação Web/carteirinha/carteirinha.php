<?php
session_start();

if (isset($_SESSION['txtNome'], $_SESSION['txtEmail'], $_SESSION['txtCpf'], $_SESSION['txtData'], $_SESSION['imgRecorte'])) {

    $nome = $_SESSION['txtNome'];
    $email = $_SESSION['txtEmail'];
    $cpf = $_SESSION['txtCpf'];
    $data = $_SESSION['txtData'];
    $imgRecorte = $_SESSION['imgRecorte'];

    echo "<div class='background-overlay'></div>
    <div class='new-container'>
        <div class='card'>
            <div class='card-header'>
                <h2>Carteirinha de Fã Clube</h2>
            </div>
            <div class='card-body'>
                <div class='card-photo'>
                    <img src='$imgRecorte' alt='User Photo'>
                </div>
                <div class='card-info'>
                    <p><strong>Nome:</strong> $nome</p>
                    <p><strong>Email:</strong> $email</p>
                    <p><strong>CPF:</strong> $cpf</p>
                    <p><strong>Data de Nascimento:</strong> $data</p>
                </div>
            </div>
             <div class='card-footer'>
            <button onclick=\"location.href='index.php'\" class='btnGerarOutra'>Gerar Outra Carteirinha</button>
        </div>
        </div>
    </div>";

    session_unset();
    session_destroy();
} else {
    echo "Nenhum dado encontrado. Por favor, faça o cadastro novamente.";
}
?>

<style>
    /* Container principal da carteirinha */
    .new-container {
        position: relative;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        animation: fadeInContainer 1s ease-in-out;
        /* Animação de fade-in para o container */
    }

    /* Animação de fade-in para o container */
    @keyframes fadeInContainer {
        0% {
            opacity: 0;
            transform: scale(0.95);
        }

        100% {
            opacity: 1;
            transform: scale(1);
        }
    }

    /* Estilo da carteirinha */
    .card {
        width: 450px;
        /* Aumenta a largura da carteirinha */
        border-radius: 12px;
        box-shadow: 0 12px 25px rgba(0, 0, 0, 0.15);
        background-color: #f9f9f9;
        font-family: Arial, sans-serif;
        color: #333;
        overflow: hidden;
        display: flex;
        flex-direction: column;
        transition: transform 0.4s ease, box-shadow 0.4s ease;
        /* Transição suave para transformações */
        animation: zoomInCard 0.7s ease-in-out;
        /* Animação de zoom-in para a carteirinha */
    }

    /* Animação de zoom-in para a carteirinha */
    @keyframes zoomInCard {
        0% {
            opacity: 0;
            transform: scale(0.8);
        }

        100% {
            opacity: 1;
            transform: scale(1);
        }
    }

    /* Efeito ao passar o mouse na carteirinha */
    .card:hover {
        transform: translateY(-5px);
        /* Leve elevação ao passar o mouse */
        box-shadow: 0 15px 30px rgba(0, 0, 0, 0.2);
    }

    /* Cabeçalho da carteirinha */
    .card-header {
        background-color: #0f96af;
        color: white;
        padding: 15px;
        text-align: center;
        font-size: 20px;
        font-weight: bold;
        transition: background-color 0.3s ease;
        /* Transição suave para mudança de cor */
    }

    /* Corpo da carteirinha */
    .card-body {
        display: flex;
        padding: 20px;
        animation: slideUpBody 0.5s ease-out;
        /* Animação de slide-up para o corpo da carteirinha */
    }

    /* Animação de slide-up para o corpo da carteirinha */
    @keyframes slideUpBody {
        0% {
            opacity: 0;
            transform: translateY(20px);
        }

        100% {
            opacity: 1;
            transform: translateY(0);
        }
    }

    .card-photo {
        width: 120px;
        /* Mantém o tamanho da foto quadrada */
        height: 120px;
        margin-right: 15px;
        border-radius: 0%;
        /* Mantém a foto quadrada (sem borda arredondada) */
        overflow: hidden;
        box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.15);
        transition: box-shadow 0.3s ease, transform 0.3s ease;
        /* Transições para efeitos */
    }

    /* Efeito ao passar o mouse na foto */
    .card-photo:hover {
        box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.2);
        transform: scale(1.05);
        /* Leve aumento ao passar o mouse */
    }

    .card-photo img {
        width: 100%;
        height: 100%;
        object-fit: cover;
    }

    /* Informações da carteirinha */
    .card-info {
        flex-grow: 1;
        animation: fadeInInfo 0.6s ease-in-out 0.2s forwards;
        /* Animação de fade-in com delay */
    }

    /* Animação de fade-in para as informações */
    @keyframes fadeInInfo {
        0% {
            opacity: 0;
        }

        100% {
            opacity: 1;
        }
    }

    .card-info p {
        margin: 8px 0;
        font-size: 15px;
        color: #333;
        transition: color 0.3s ease;
        /* Transição suave para mudança de cor */
    }

    /* Rodapé da carteirinha */
    .card-footer {
        background-color: #e8e8e8;
        padding: 10px;
        text-align: center;
        font-size: 13px;
        color: #777;
        animation: fadeInFooter 0.7s ease-in-out 0.4s forwards;
        /* Animação de fade-in com delay */
    }

    /* Animação de fade-in para o rodapé */
    @keyframes fadeInFooter {
        0% {
            opacity: 0;
            transform: translateY(10px);
        }

        100% {
            opacity: 1;
            transform: translateY(0);
        }
    }

    /* Estilo do fundo com animação */
    .background-overlay {
        background-image: url('https://i.redd.it/riligd3n8gk21.png');
        filter: blur(10px) grayscale(20%) brightness(0.9);
        /* Aplica o blur junto com outros filtros */
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background-position: center;
        background-repeat: no-repeat;
        background-size: cover;
        z-index: -1;
        animation: bgFadeIn 1.5s ease-in-out;
        /* Animação de fade-in para o fundo */
    }

    /* Animação de fade-in para o fundo */
    @keyframes bgFadeIn {
        0% {
            opacity: 0;
        }

        100% {
            opacity: 1;
        }
    }

    .button-container {
        display: flex;
        justify-content: center;
        margin-top: 20px;
        animation: fadeInButton 0.7s ease-in-out 0.5s forwards;
    }

    .btnGerarOutra {
        background-color: #0f96af;
        color: white;
        padding: 10px 20px;
        font-size: 16px;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        transition: background-color 0.3s ease;
        text-align: center;
        outline: none;
        box-shadow: none;
    }

    .btnGerarOutra:hover {
        background-color: #0d7a88;
    }

    /* Animação de fade-in para o botão */
    @keyframes fadeInButton {
        0% {
            opacity: 0;
            transform: translateY(10px);
        }

        100% {
            opacity: 1;
            transform: translateY(0);
        }
    }
</style>