# Teoria dos Grafos e Computabilidade - Trabalho 01

## Estrutura

- Codigo: contém todos os arquivos de códigos desenvolvidos.
    |_ libs: implementação da estrutura de dados e dos algoritmos propriamente ditos.
    |_ teste_caminhamento: teste do algoritmo de caminhamento.
    |_ teste_permutacao: teste do algoritmo de permutação.

- Relatorio: relatório em pdf.

- Relatorio_LaTeX: arquivo zipado do relatório em LaTeX, contendo o código fonte e demais dependências.

## Testes

Para realizer o teste, é necessário, primeiramente, compilar o projeto:

    - Caminhamento: $ g++ -o teste_caminhamento teste_caminhamento.cpp libs/grafo.cpp libs/caminhamento.cpp

    - Permutação: $ g++ -o teste_permutacao teste_permutacao.cpp libs/grafo.cpp libs/permutacao.cpp

Após a compilação, executar o código:

    - No Windows:
    
        - Caminhamento: $ teste_permutacao

        - Permutação: $ teste_permutacao

    - No Linux:

        - Caminhamento: $ ./teste_caminhamento

        - Permutação: $ ./teste_permutacao

Finalmente, a entrada de dados é feita da seguinte maneira:

    - Exemplo 1:

        Enter the number of vertices: 3

        Enter the adjacency matrix: (v1 v2) (0 0 to stop)
        A B B A A C B C 0 0

    Assim, a entrada de dados é feita inserindo um par de vértices, sendo o par 0 0 para parada da
    entrada de dados.

# Notas 

Para o funcionamento do algoritmo de caminhamento é necessário ter, no mínimo, 3 (três) vértices.

## GitHub

- https://github.com/sabarense/GraphCycleEnumeration

## Grupo

- André Luis
- Breno Pires
- Caio Diniz
- Vinícius Miranda
- Yan Sabarense
