<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header>
        <h1>Login - Papelaria do DCE</h1>
    </header>
    <main>
        <form id="login-form" action="/login" method="POST">
            <label for="username">Usuário:</label>
            <input type="text" id="username" name="username" required>
            <label for="password">Senha:</label>
            <input type="password" id="password" name="password" required>
            <button type="submit">Entrar</button>
        </form>
    </main>
    <footer>
        <p>&copy; 2024 Papelaria do DCE</p>
    </footer>
</body>
</html>
