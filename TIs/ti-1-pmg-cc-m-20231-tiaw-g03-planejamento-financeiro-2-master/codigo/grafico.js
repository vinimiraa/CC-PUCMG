//Função para ler os dados do Local Storage	
function leDados() {
    let strDados = localStorage.getItem('db');
    let objDados = {};
    
    if (strDados) {
      objDados = JSON.parse(strDados);
    }
    else {
      objDados = {
        data: [
                {
                    Data: "2023-05-01",
                    Descrição: "Salário",
                    Categoria: "Receita",
                    Receitas: 3000,
                    Despesas: 0,
                    Valor: 3000,
                    Saldo: 3000
                },
                {
                    Data: "2023-05-03",
                    Descrição: "Venda de Livro",
                    Categoria: "Receita",
                    Receitas: 200,
                    Despesas: 0,
                    Valor: 200,
                    Saldo: 3200
                },
                {
                    Data: "2023-05-05",
                    Descrição: "Escola",
                    Categoria: "Receita",
                    Receitas: 1000,
                    Despesas: 0,
                    Valor: 1000,
                    Saldo: 4200
                },
                {
                    Data: "2023-05-08",
                    Descrição: "Aluguel",
                    Categoria: "Despesa",
                    Receitas: 0,
                    Despesas: 800,
                    Valor: -800,
                    Saldo: 3400
                },
                {
                    Data: "2023-05-10",
                    Descrição: "Supermercado",
                    Categoria: "Despesa",
                    Receitas: 0,
                    Despesas: 250,
                    Valor: -250,
                    Saldo: 3150
                },
                {
                    Data: "2023-05-12",
                    Descrição: "Restaurante",
                    Categoria: "Despesa",
                    Receitas: 0,
                    Despesas: 150,
                    Valor: -150,
                    Saldo: 2000
                }                
            ]
        } 
    }
  
    return objDados;
}

//Fução para somar as despesas
function somaDespesas() {
    let soma = 0;
    let objDados = leDados();
    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Despesa"){
            soma += objDados.data[i].Despesas;
        }
    }
    return soma;
}

//Função para somar as receitas
function somaReceitas() {
    let soma = 0;
    let objDados = leDados();
    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Receita"){
            soma += objDados.data[i].Receitas;
        }
    }
    return soma;
}

// Função para alternar entre mostrar/esconder as despesas
function alternarDespesas() {
    let botao = document.getElementById('btn-despesas');
    let despesasHtml = document.getElementById('despesas');
    botao.addEventListener('click', function() {
        if (despesasHtml.style.display === 'none') {
            despesasHtml.style.display = 'block';
            botao.innerText = 'Esconder Despesas';
        } else {
            despesasHtml.style.display = 'none';
            botao.innerText = 'Ver Despesas Mensal';
        }
    });
}

// Função para alternar entre mostrar/esconder a receita
function alternarReceita() {
    let botao = document.getElementById('btn-receita');
    let receitaHtml = document.getElementById('receita');
    botao.addEventListener('click', function() {
        if (receitaHtml.style.display === 'none') {
            receitaHtml.style.display = 'block';
            botao.innerText = 'Esconder Receita';
        } else {
            receitaHtml.style.display = 'none';
            botao.innerText = 'Ver Receita Mensal';
        }
    });
}

//Função escreve a receita na tela
function escreveReceita() {
    let botao = document.getElementById('btn-receita');
    let receitaHtml = document.getElementById('receita');
    botao.addEventListener('click', function() {
        let receita = somaReceitas();
        receitaHtml.innerHTML = 'R$ ' + receita;
    });
}

//Função escreve as despesas na tela
function escreveDespesas() {
    let botao = document.getElementById('btn-despesas');
    let despesasHtml = document.getElementById('despesas');
    botao.addEventListener('click', function() {
        let despesas = somaDespesas();
        despesasHtml.innerHTML = 'R$ ' + despesas;
    });
}


//Funcão salvar os dados no Local Storage
function salvaDados(dados) {
    localStorage.setItem('db', JSON.stringify(dados));
}

//Carrega o Local Storage e imprime os dados ao carregar a página
window.onload = function() {
    let objDados = leDados();
    salvaDados(objDados);
    imprimeDados();
    google.charts.load('current', { 'packages': ['corechart'] });
    google.charts.setOnLoadCallback(criarGraficoDespesas);
    escreveReceita();
    escreveDespesas();
    alternarReceita();
    alternarDespesas();
}
    
//Coloca os dados na tela para visualizar se funcionou (provisório)
function imprimeDados() {
    let text = document.getElementById('text');
    let strHtml = '';
    let objDados = leDados();

    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Despesa") {
            strHtml += "<div id='despesas' class='border border-danger border-2 fw-bold opacity-50 mb-5 p-1 text-center rounded' style='width: 400px' >";
                strHtml += "<p>" + objDados.data[i].Descrição +' - '+ objDados.data[i].Categoria + "</p>";
                strHtml += "<p>" + 'Valor da Despesa:  ' + objDados.data[i].Despesas + "</p>";
            strHtml += "</div>";
        }
    }
    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Receita") {
            strHtml += "<div id='receitas' class='border border-success border-2 fw-bold opacity-50 mb-5 p-1 text-center rounded' style='width: 400px' >";
                strHtml += "<p>" + objDados.data[i].Descrição +' - '+ objDados.data[i].Categoria + "</p>";
                strHtml += "<p>" + 'Valor da Despesa:  ' + objDados.data[i].Receitas + "</p>";
            strHtml += "</div>";
        }
    }
    text.innerHTML = strHtml;
}

// Cria o gráfico de despesas
function criarGraficoDespesas() {
    let objDados = leDados();
    let despesasArray = [];
    let receitaTotal = 0;

    for (let i = 0; i < objDados.data.length; i++) {
        receitaTotal += objDados.data[i].Receitas;
    }

    let despesasTotais = 0;

    for (let i = 0; i < objDados.data.length; i++) {
        if (objDados.data[i].Despesas > 0) {
            despesasArray.push([
            objDados.data[i].Descrição,
            objDados.data[i].Despesas
        ]);
        despesasTotais += objDados.data[i].Despesas;
        }
    }

    let valorRestante = receitaTotal - despesasTotais;

    despesasArray.push(['Valor Restante', valorRestante]);

    // Cria o array de dados para o gráfico
    let data = new google.visualization.DataTable();
    data.addColumn('string', 'Descrição');
    data.addColumn('number', 'Despesas');
    data.addRows(despesasArray);
  
    // Configurações do gráfico
    let options = {
        title: 'Gráfico de Despesas',
        is3D: true,
        titleTextStyle: {
            fontSize: 30,
            bold: true,
            alignment: 'center'
        },
        slices: {
        0: { color: '#e0440e' },  // Cor para despesas1
        1: { color: '#03301a' },  // Cor para depesas2
        2: { color: '#3366cc' },  // Cor para despesas3
        3: { color: '#41d072' }   // Cor para valor restante
      }
    };
  
    // Cria o gráfico de pizza
    let chart = new google.visualization.PieChart(document.getElementById('chart-container'));
    chart.draw(data, options);
}