//cadastro.html
// Função para salvar os dados no localStorage e redirecionar para a página de login
function salvarDados() {
    var nomeCompleto = document.getElementById('nomeCompleto').value;
    var email = document.getElementById('email').value;
    var telefone = document.getElementById('telefone').value;
    var idade = document.getElementById('idade').value;
    var sexo = document.getElementById('sexo').value;
    var estadoCivil = document.getElementById('estadoCivil').value;
    var profissao = document.getElementById('profissao').value;
    var senha = document.getElementById('senha').value;
    var aceiteDados = document.getElementById('aceiteDados').checked;

    // Verificar se a checkbox de aceite de dados está marcada
    if (!aceiteDados) {
        alert('Você precisa aceitar os termos e condições para prosseguir com o cadastro.');
        return;
    }

    
    // Verificar se todos os campos obrigatórios foram preenchidos
    if (
        nomeCompleto === '' ||
        email === '' ||
        telefone === '' ||
        idade === '' ||
        sexo === 'Clique para selecionar' ||
        estadoCivil === 'Clique para selecionar' ||
        profissao === '' ||
        senha === ''
    ) {
        alert('Por favor, preencha todos os campos obrigatórios.');
        return; // Impede o redirecionamento se os campos estiverem vazios
    } else {
        alert('Usuário cadastrado!');
        // Redirecionar para a página de login
        location.href = "login.html";
    }

    // Criar um objeto com os dados
    var dados = {
        nomeCompleto: nomeCompleto,
        email: email,
        telefone: telefone,
        idade: idade,
        sexo: sexo,
        estadoCivil: estadoCivil,
        profissao: profissao,
        senha: senha,
        aceiteDados: aceiteDados
    };

    // Salvar os dados no localStorage
    localStorage.setItem('dadosUsuario', JSON.stringify(dados));

}
// Função para carregar os dados do localStorage, se existirem
function carregarDados() {
    var dados = localStorage.getItem('dadosUsuario');
    if (dados) {
        var parsedDados = JSON.parse(dados);
        document.getElementById('nomeCompleto').value = parsedDados.nomeCompleto || '';
        document.getElementById('email').value = parsedDados.email || '';
        document.getElementById('telefone').value = parsedDados.telefone || '';
        document.getElementById('idade').value = parsedDados.idade || '';
        document.getElementById('sexo').value = parsedDados.sexo || 'Clique para selecionar';
        document.getElementById('estadoCivil').value = parsedDados.estadoCivil || 'Clique para selecionar';
        document.getElementById('profissao').value = parsedDados.profissao || '';
        document.getElementById('senha').value = parsedDados.senha || '';
        document.getElementById('visualizarSenha').checked = parsedDados.visualizarSenha || false;
        document.getElementById('aceiteDados').checked = parsedDados.aceiteDados || false;
        atualizarCampoSenha();
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
