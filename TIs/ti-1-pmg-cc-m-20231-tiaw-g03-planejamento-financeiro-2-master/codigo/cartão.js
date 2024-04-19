// Dados dos cartões de crédito em formato JSON
var cartoes = {};

function carregarCartoesDoLocalStorage() {
    var cartoesArmazenados = localStorage.getItem("cartoes");
    if (cartoesArmazenados) {
        cartoes = JSON.parse(cartoesArmazenados);
    }
}

function salvarCartoesNoLocalStorage() {
    localStorage.setItem("cartoes", JSON.stringify(cartoes));
}

function formatarNumeroCartao(numero) {
    var formattedNumber = numero.replace(/\s/g, '').replace(/(.{4})/g, '$1 ');
    return formattedNumber.trim();
}

function formatarValidade(validade) {
    if (validade.length >= 2) {
        validade = validade.substr(0, 2) + '/' + validade.substr(2);
    }
    return validade;
}

function adicionarCartao() {
    var nomeTitular = document.getElementById("nome").value;
    var numeroCartao = document.getElementById("numero").value;
    var validade = document.getElementById("validade").value;
    var bandeira = document.getElementById("bandeira").value;

    numeroCartao = formatarNumeroCartao(numeroCartao);
    validade = formatarValidade(validade);

    // Verifica se algum campo está vazio
    if (nomeTitular === '' || numeroCartao === '' || validade === '' || bandeira === '') {
        alert("Por favor, preencha todos os campos antes de adicionar o cartão.");
        return; // Encerra a função sem adicionar o cartão
    }

    // Criando um novo objeto para o cartão
    var novoCartao = {
        "nomeTitular": nomeTitular,
        "numeroCartao": numeroCartao,
        "validade": validade,
        "bandeira": bandeira
    };

    // Adicionando o novo cartão ao objeto de cartões
    var novoCartaoId = "cartao" + (Object.keys(cartoes).length + 1);
    cartoes[novoCartaoId] = novoCartao;

    // Limpar os campos do formulário
    document.getElementById("nome").value = "";
    document.getElementById("numero").value = "";
    document.getElementById("validade").value = "";
    document.getElementById("bandeira").selectedIndex = 0;

    // Armazenar cartões no localStorage
    salvarCartoesNoLocalStorage();

    // Exibindo os cartões de crédito na página HTML
    exibirCartoes();
}

function excluirCartao(cartaoId) {
    delete cartoes[cartaoId];
    exibirCartoes();
}

function exibirCartoes() {
    var cartoesDiv = document.getElementById("cartoes");
    cartoesDiv.classList.add("bg-primary-subtle", "p-4");
    cartoesDiv.innerHTML = "";

    for (var cartaoId in cartoes) {
        var divCartao = document.createElement("div");
        divCartao.classList.add("cartao");

        var nomeTitular = document.createElement("p");
        nomeTitular.innerText = "Titular: " + cartoes[cartaoId].nomeTitular;

        var numeroCartao = document.createElement("p");
        numeroCartao.innerText = "Número: " + cartoes[cartaoId].numeroCartao;

        var validade = document.createElement("p");
        validade.innerText = "Validade: " + cartoes[cartaoId].validade;

        var bandeira = document.createElement("p");
        bandeira.innerText = "Bandeira: " + cartoes[cartaoId].bandeira;

        var excluirBtn = document.createElement("button");
        excluirBtn.classList.add("btn", "btn-danger", "px-2", "mx-2");
        excluirBtn.innerText = "Excluir";
        excluirBtn.onclick = (function (id) {
            return function () {
                excluirCartao(id);
            }
        })(cartaoId);

        var pagarfatBtn = document.createElement("button");
        pagarfatBtn.classList.add("btn", "btn-primary", "px-2", "mx-2");
        pagarfatBtn.innerText = "Pagar Fatura";
        pagarfatBtn.onclick = (function (id) {
            return function () {
                pagarfatBtn(id);
            }
        })(cartaoId);

        var fatresumoBtn = document.createElement("button");
        fatresumoBtn.classList.add("btn", "btn-primary", "px-2", "mx-2");
        fatresumoBtn.innerText = "Resumo das Faturas";
        fatresumoBtn.onclick = (function (id) {
            return function () {
                fatresumoBtn(id);
            }
        })(cartaoId);

        var ajustelimBtn = document.createElement("button");
        ajustelimBtn.classList.add("btn", "btn-primary", "px-2", "mx-2");
        ajustelimBtn.innerText = "Ajustar Limite";
        ajustelimBtn.onclick = (function (id) {
            return function () {
                ajustelimBtn(id);
            }
        })(cartaoId);

        var pagarboletoBtn = document.createElement("button");
        pagarboletoBtn.classList.add("btn", "btn-primary", "px-2", "mx-2");
        pagarboletoBtn.innerText = "Pagar Boleto";
        pagarboletoBtn.onclick = (function (id) {
            return function () {
                pagarboletoBtn(id);
            }
        })(cartaoId);

        divCartao.appendChild(nomeTitular);
        divCartao.appendChild(numeroCartao);
        divCartao.appendChild(validade);
        divCartao.appendChild(bandeira);
        divCartao.appendChild(pagarfatBtn);
        divCartao.appendChild(fatresumoBtn);
        divCartao.appendChild(ajustelimBtn);
        divCartao.appendChild(pagarboletoBtn);
        divCartao.appendChild(excluirBtn);

        cartoesDiv.appendChild(divCartao);
    }
}
// Carregar cartões do localStorage ao carregar a página
window.onload = function() {
    carregarCartoesDoLocalStorage();
    exibirCartoes();
  };