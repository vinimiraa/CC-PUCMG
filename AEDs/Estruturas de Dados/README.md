# 🎲 Estruturas de Dados

Nesta pasta estão diversas estruturas de dados estudadas durante as aulas de AEDs2, organizadas em pastas para `C` e `Java`.
Vale ressaltar que a maioria dos algoritmos em `C`estão melhor implementados do que em `Java`.

## Árvores

- **Binária (BST)**: Estrutura de dados onde cada nó pode ter no máximo dois filhos, com a propriedade de que o filho à esquerda é menor e o filho à direita é maior que o nó pai.

- **AVL**: Árvore BST balanceada onde a diferença de altura entre as subárvores filhas de qualquer nó é 0 ou +/- 1, mantendo o balanceamento através de rotações.

- **Bicolor**: BST balanceada onde os nós são coloridos de vermelho ou preto, com regras para garantir que o caminho mais longo da raiz a uma folha não seja mais que o dobro do caminho mais curto.

- **2-3-4**: Árvore 2-3-4, uma árvore B balanceada onde cada nó pode ter 2, 3 ou 4 filhos, mantendo a árvore balanceada através de divisão de nós quando eles se enchem.

- **TRIE**: Árvore de prefixos usada para armazenar um conjunto dinâmico de strings, onde cada nó representa um caractere e as arestas entre nós representam a concatenação de caracteres.

```sh
# Para navegar até a pasta pelo terminal:
cd AEDs/Estruturas\ de\ Dados/Flexiveis/Arvores/C
cd AEDs/Estruturas\ de\ Dados/Flexiveis/Arvores/Java

# Para listar os arquivos no diretório:
ls

# Para abrir um arquivo no vim:
vim NomeDoArquivo.java
vim NomeDoArquivo.c

# Para sair do vim:
:q
```

## Lineares e Flexíveis

- **Lista**: Estrutura de dados que permite inserção, remoção e acesso a elementos em qualquer posição.

- **Fila**: Estrutura de dados onde os elementos são inseridos no final e removidos do início (FIFO - First In, First Out).

- **Pilha**: Estrutura de dados onde os elementos são inseridos e removidos do topo (LIFO - Last In, First Out).

```sh
# Para navegar até a pasta pelo terminal:
cd AEDs/Estruturas\ de\ Dados/Flexiveis/C
cd AEDs/Estruturas\ de\ Dados/Flexiveis/Java

cd AEDs/Estruturas\ de\ Dados/Lineares/C
cd AEDs/Estruturas\ de\ Dados/Lineares/Java

# Para listar os arquivos no diretório:
ls

# Para abrir um arquivo no vim:
vim NomeDoArquivo.java
vim NomeDoArquivo.c

# Para sair do vim:
:q
```

## Hash

- **Hash Direta**: Técnica de hash onde cada chave é mapeada diretamente para um endereço único no array, sem tratamento de colisões.

- **Hash com Overflow**: Técnica de hash onde as colisões são resolvidas armazenando os dados em uma área de reserva separada.

- **Hash com Rehash**: Técnica de hash que resolve colisões aplicando uma segunda função hash para encontrar outro endereço disponível.

- **Hash com Lista**: Técnica de hash onde cada posição no array de hash contém uma lista (geralmente uma lista encadeada) para armazenar todas as entradas que mapeiam para o mesmo endereço, resolvendo colisões através de encadeamento.

```sh
# Para navegar até a pasta pelo terminal:
cd AEDs/Estruturas\ de\ Dados/Flexiveis/Hash/C
cd AEDs/Estruturas\ de\ Dados/Flexiveis/Hash/Java

# Para listar os arquivos no diretório:
ls

# Para abrir um arquivo no vim:
vim NomeDoArquivo.java
vim NomeDoArquivo.c

# Para sair do vim:
:q
```

`FIM`
