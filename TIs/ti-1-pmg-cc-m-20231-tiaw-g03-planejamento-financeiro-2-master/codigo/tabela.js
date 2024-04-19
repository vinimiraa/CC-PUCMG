 // Dados iniciais
 var tabelaDxR = {
    categorias: [],
    dados: []
  };

  // Carregar os dados existentes
  var tabelaDxRJSON = localStorage.getItem('tabelaDxR');
  if (tabelaDxRJSON) {
    tabelaDxR = JSON.parse(tabelaDxRJSON);
  }

  // Atualizar a tabela de categorias
  function atualizarCategorias() {
    var categoriasElement = document.getElementById('categorias');
    categoriasElement.innerHTML = '';

    tabelaDxR.categorias.forEach(function(categoria) {
      var li = document.createElement('li');
      li.textContent = categoria;
      var excluirLink = document.createElement('a');
      excluirLink.href = '#';
      excluirLink.textContent = 'Excluir';
      excluirLink.addEventListener('click', function() {
        excluirCategoria(categoria);
      });
      li.appendChild(excluirLink);
      categoriasElement.appendChild(li);
    });

    // Atualizar a lista de categorias para adicionar dados
    var categoriaSelect = document.getElementById('categoriaSelecionada');
    categoriaSelect.innerHTML = '';
    tabelaDxR.categorias.forEach(function(categoria) {
      var option = document.createElement('option');
      option.value = categoria;
      option.textContent = categoria;
      categoriaSelect.appendChild(option);
    });
  }

  // Excluir uma categoria
  function excluirCategoria(categoria) {
    var index = tabelaDxR.categorias.indexOf(categoria);
    if (index > -1) {
      tabelaDxR.categorias.splice(index, 1);
      atualizarCategorias();
      atualizarDados();
      salvarDados();
    }
  }

  // Atualizar a tabela de dados
  function atualizarDados() {
    var dadosTable = document.getElementById('dados');
    dadosTable.innerHTML = '';

    tabelaDxR.dados.forEach(function(dado) {
      var row = dadosTable.insertRow();
      var dataCell = row.insertCell();
      dataCell.textContent = dado.data;
      var descricaoCell = row.insertCell();
      descricaoCell.textContent = dado.descricao;
      var categoriaCell = row.insertCell();
      categoriaCell.textContent = dado.categoria;
      var receitasCell = row.insertCell();
      receitasCell.textContent = dado.receitas;
      var despesasCell = row.insertCell();
      despesasCell.textContent = dado.despesas;
      var valorCell = row.insertCell();
      valorCell.textContent = dado.valor;
      var saldoCell = row.insertCell();
      saldoCell.textContent = dado.saldo;
      var acoesCell = row.insertCell();
      var excluirLink = document.createElement('a');
      excluirLink.href = '#';
      excluirLink.textContent = 'Excluir';
      excluirLink.addEventListener('click', function() {
        excluirDado(dado);
      });
      acoesCell.appendChild(excluirLink);
    });
  }

  // Adicionar uma nova categoria
  function adicionarCategoria() {
    var novaCategoriaInput = document.getElementById('novaCategoria');
    var novaCategoria = novaCategoriaInput.value.trim();

    if (novaCategoria === '') {
      alert('Por favor, insira um nome para a categoria.');
      return;
    }

    if (tabelaDxR.categorias.includes(novaCategoria)) {
      alert('Essa categoria já existe.');
      return;
    }

    tabelaDxR.categorias.push(novaCategoria);
    novaCategoriaInput.value = '';

    atualizarCategorias();
    atualizarDados();

    salvarDados();
  }
  
  // Adicionar novos dados
  function adicionarDados() {
    var dataInput = document.getElementById('data');
    var data = dataInput.value;
    var descricaoInput = document.getElementById('descricao');
    var descricao = descricaoInput.value.trim();
    var categoriaSelect = document.getElementById('categoriaSelecionada');
    var categoria = categoriaSelect.value;
    var receitasInput = document.getElementById('receitas');
    var receitas = parseFloat(receitasInput.value);
    var despesasInput = document.getElementById('despesas');
    var despesas = parseFloat(despesasInput.value);
    var valorInput = document.getElementById('valor');
    var valor = parseFloat(valorInput.value);

    if (descricao === '') {
      alert('Por favor, insira uma descrição para os dados.');
      return;
    }

    if (isNaN(receitas) || receitas < 0) {
      alert('Por favor, insira um valor válido para as receitas.');
      return;
    }

    if (isNaN(despesas) || despesas < 0) {
      alert('Por favor, insira um valor válido para as despesas.');
      return;
    }

    if (isNaN(valor) || valor <= 0) {
      alert('Por favor, insira um valor válido para os dados.');
      return;
    }

    var saldo = valor - despesas;
    var novoDado = {
      data: data,
      descricao: descricao,
      categoria: categoria,
      receitas: receitas,
      despesas: despesas,
      valor: valor,
      saldo: saldo
    };

    tabelaDxR.dados.push(novoDado);
    dataInput.value = '';
    descricaoInput.value = '';
    receitasInput.value = '';
    despesasInput.value = '';
    valorInput.value = '';

    atualizarDados();

    salvarDados();
  }

  // Excluir um dado
  function excluirDado(dado) {
    var index = tabelaDxR.dados.indexOf(dado);
    if (index > -1) {
      tabelaDxR.dados.splice(index, 1);
      atualizarDados();
      salvarDados();
    }
  }

  // Salvar os dados na memória local
  function salvarDados() {
    localStorage.setItem('tabelaDxR', JSON.stringify(tabelaDxR));
  }

  // Inicializar a tabela
  atualizarCategorias();
  atualizarDados();