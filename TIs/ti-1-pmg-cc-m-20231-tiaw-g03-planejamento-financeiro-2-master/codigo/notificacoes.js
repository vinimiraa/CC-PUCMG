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
                    Saldo: 3000
                }                
            ]
        } 
    }
  
    return objDados;
}

//Função para salvar os dados no Local Storage

function salvaDados(dados) {
    localStorage.setItem('db', JSON.stringify(dados));
}

//Função para calcular soma da receita
function somaReceita() {
    let objDados = leDados();
    let somaReceita = 0;
    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Receita") {
            somaReceita += objDados.data[i].Receitas;
        }
    }
    return somaReceita;
}

//Função para calcular soma da despesas
function somaDespesa() {
    let objDados = leDados();
    let somaDespesa = 0;
    for (let i = 0; i < objDados.data.length; i++) {
        if(objDados.data[i].Categoria == "Despesa") {
            somaDespesa += objDados.data[i].Despesas;
        }
    }
    return somaDespesa;
}


//Carrega o Local Storage e imprime os dados ao carregar a página
window.onload = function() {
    let objDados = leDados();
    imprimeDados();
    salvaDados(objDados);
}

//Coloca as notificações na tela
function imprimeDados() {
    let text = document.getElementById('text');
    let strHtml = '';
    let objDados = leDados();
    let saldo = somaReceita() - somaDespesa();
    let dia = new Date(); 
    let mes = new Date();
    let ano = new Date();
    //Insere o saldo na tela
    if(somaReceita < somaDespesa) {
        strHtml += `<div class="alert alert-danger text-white">`;
        strHtml += `<h4>Alerta! - ` + dia.getDate() +"/"+ (mes.getMonth()+1) +"/"+ ano.getFullYear() + `</h4>`;
        strHtml += `<p>Saldo Negativo: R$ ${saldo}</p>`;
        strHtml += `</div>`;
        text.innerHTML = strHtml;
    }else {
        strHtml += `<div class="alert alert-success">`;
        strHtml += `<h4 class="">Notificação! - ` + dia.getDate() +"/"+ (mes.getMonth() + 1) +"/"+ ano.getFullYear() + `</h4>`;
        strHtml += `<p class="">Saldo Positivo: R$ ${saldo}</p>`;
        strHtml += `</div>`;
        text.innerHTML = strHtml;
    }

    let maior=0;
    let descricao = '';
    for(let i=0; i<objDados.data.length; i++){
        if(objDados.data[i].Despesas > maior){
            maior = objDados.data[i].Despesas;
            descricao = objDados.data[i].Descrição;
        }
    }
    //Insere a maior despesa na tela
    strHtml += `<div class="bg-secondary rounded-3 p-3 mb-3 text-light">`;
    strHtml += `<h4 class="">Notificação! - 12/05/2023</h4>`;
    strHtml += `<p class="">Maior Despesa: R$ ${maior} - ` + descricao + `</p>`;
    strHtml += `</div>`;
    text.innerHTML = strHtml;
    //Insere a maior receita na tela
    strHtml += `<div class="bg-secondary rounded-3 p-3 mb-3 text-light">`;
    strHtml += `<h4 class="">Notificação! - 10/05/2023</h4>`;
    strHtml += `<p class="">Despesa Recorrente: R$ ${maior} - ` + descricao + `</p>`;
    strHtml += `</div>`;
    text.innerHTML = strHtml;
    //Insere um alerta de pagamentos na tela
    strHtml += `<div class="bg-danger rounded-3 p-3 mb-3 text-light">`;
    strHtml += `<h4 class="">Alerta! - 02/05/2023</h4>`;
    strHtml += `<p class="">Confira se seus pagamentos estão em dia!</p>`;
    strHtml += `</div>`;
    text.innerHTML = strHtml;
}