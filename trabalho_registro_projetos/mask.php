<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Máscara de Dinheiro</title>
    <script>
        function formatarMoeda(event) {
            let valor = event.target.value.replace(/\D/g, ''); // Remove qualquer coisa que não seja número
            valor = (valor / 100).toFixed(2) + ''; // Divide por 100 e fixa 2 casas decimais
            valor = valor.replace('.', ','); // Substitui ponto por vírgula
            let partes = valor.split(','); // Separa as partes da moeda
            let inteiro = partes[0];
            let decimal = partes[1];
            
            // Adiciona os separadores de milhar
            inteiro = inteiro.replace(/\B(?=(\d{3})+(?!\d))/g, '.');
            
            // Concatena a parte inteira e decimal com o símbolo 'R$'
            event.target.value = 'R$ ' + inteiro + ',' + decimal;
        }
    </script>
</head>
<body>
    <label for="dinheiro">Valor: </label>
    <input id="dinheiro" type="text" oninput="formatarMoeda(event)" placeholder="R$ 0,00">
</body>
</html>
