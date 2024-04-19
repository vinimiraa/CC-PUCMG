// Função para verificar o login
function verificarLogin() {
    var email = document.getElementById('email').value;
    var senha = document.getElementById('senha').value;

    // Verificar se os campos de email e senha não estão vazios
    if (email === '' || senha === '') {
        alert('Por favor, preencha o email e a senha.');
        return;
    }

    // Obter os dados cadastrados do localStorage
    var dadosUsuario = localStorage.getItem('dadosUsuario');

    // Verificar se existem dados cadastrados
    if (dadosUsuario) {
        var dados = JSON.parse(dadosUsuario);

        // Verificar se o email e a senha correspondem aos dados cadastrados
        if (email === dados.email && senha === dados.senha) {
            // Redirecionar para a página "main.html"
            alert('Login feito com sucesso!')
            location.href = "home.html";
        } else {
            alert('Email ou senha incorretos. Por favor, tente novamente.');
        }
    } else {
        alert('Não existem dados de usuário cadastrados.');
    }
}

// Função para atualizar a exibição da senha
function atualizarCampoSenha() {
    var campoSenha = document.getElementById('senha');
    var visualizarSenha = document.getElementById('visualizarSenha').checked;

    if (visualizarSenha) {
        campoSenha.type = 'text';
    } else {
        campoSenha.type = 'password';
    }
}
