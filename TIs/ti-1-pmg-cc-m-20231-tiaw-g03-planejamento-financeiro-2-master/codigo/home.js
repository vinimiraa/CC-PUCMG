// Variável para armazenar a referência ao conteúdo atualmente aberto
var conteudoAberto = null;

// Função para carregar o conteúdo do arquivo HTML
function carregarHTML(url, elementId, scriptUrl) {
    fetch(url)
        .then(response => response.text())
        .then(html => {
            var element = document.getElementById(elementId);
            element.innerHTML = html;

            if (scriptUrl) {
                var scriptElement = document.createElement('script');
                scriptElement.src = scriptUrl;
                document.body.appendChild(scriptElement);
            }

        })
        .catch(error => {
            console.error('Erro ao carregar o arquivo HTML:', error);
        });
}

// Função para lidar com o evento de clique no link
function handleLinkClick(event, elementId, arquivo, scriptUrl) {
    event.preventDefault(); // Evita que o link execute a ação padrão de redirecionar

    // Remove o conteúdo anteriormente aberto, se houver
    if (conteudoAberto) {
        conteudoAberto.innerHTML = '';
    }

    var conteudoElement = document.getElementById(elementId);
    conteudoElement.innerHTML = 'Carregando...'; // Exibe uma mensagem enquanto o HTML está sendo carregado

    // Atualiza a referência ao conteúdo atualmente aberto
    conteudoAberto = conteudoElement;

    carregarHTML(arquivo, elementId, scriptUrl);
}

/*// Adiciona o evento de clique ao link
var linkCarregar1 = document.getElementById('linkCarregar1');
linkCarregar1.addEventListener('click', function(event) {
    handleLinkClick(event, 'conteudo1', 'grafico.html','grafico.js'); //PRONTO
});*/

// Adiciona o evento de clique ao link
var linkCarregar2 = document.getElementById('linkCarregar2');
linkCarregar2.addEventListener('click', function(event) {
    handleLinkClick(event, 'conteudo2', 'tabela.html', 'tabela.js'); //PRONTO
});

// Adiciona o evento de clique ao link
var linkCarregar3 = document.getElementById('linkCarregar3');
linkCarregar3.addEventListener('click', function(event) {
    handleLinkClick(event, 'conteudo3', 'cartão.html','cartão.js'); //PRONTO
});

/*// Adiciona o evento de clique ao link
var linkCarregar4 = document.getElementById('linkCarregar4');
linkCarregar4.addEventListener('click', function(event) {
    handleLinkClick(event, 'conteudo4', 'notificacoes.html', 'notificacoes.js'); //PRONTO
});*/