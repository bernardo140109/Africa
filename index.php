<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Login Clone</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="login-box">
        <h2>Login</h2>
        <form method="POST" action="">
            <input type="text" name="username" placeholder="Phone number, username, or email" required>
            <input type="password" name="password" placeholder="Password" required>
            <button type="submit">Log In</button>
        </form>
        <p class="message">
            <?php
                if ($_SERVER['REQUEST_METHOD'] === 'POST') {
                    $user = htmlspecialchars($_POST['username']);
                    $pass = htmlspecialchars($_POST['password']);
                    echo "You entered:<br>Username: <strong>$user</strong><br>Password: <strong>$pass</strong>";
                }
            ?>
        </p>
    </div>
</body>
</html>
