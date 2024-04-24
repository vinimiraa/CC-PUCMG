# 📜Informações

PONTIFÍCIA UNIVERSISADE CATÓLICA DE MINAS GERAIS

Instituto de Ciências Exatas e Informática – ICEI

Autor : Vinícius Miranda de Araújo

Matéria : Arquitetura de Computadores I

Ano : 2024

## 📑 Estrutura do Documento

- [Circuitos Lógicos](#circuitos-lógicos)
  - [Projetos de Circuitos](#projeto-de-circuitos-lógicos)
  - [Codificadores e Decodificadores](#codificadores-e-decodificadores)
    - [Código BCD](#código-bcd)
    - [Código de Gray](#código-de-gray)
  - [Multiplexadores](#multiplexador)
  - [Demultiplexadores](#demultiplexador)
  - [Aplicações Aritméticas](#aplicações-aritméticas)
- [Fim](#fim)

# Circuitos Lógicos

## Projeto de Circuitos Lógicos

A síntese de circuitos lógicos pode ser executada em cinco níveis:

| N | Nível       | Atividades                                                                               |
|---|-------------|------------------------------------------------------------------------------------------|
| 1 | Sistema     | - especificação de requisitos - particionamento                                          |
| 2 | Algoritmo   | - especificação de comportamento - concorrência - complexidade - representação de dados  |
| 3 | Arquitetura | - representação de dados - sinais e controle - paralelismo e pipelining - data paths     |
| 4 | Lógico      | - circuitos - otimizações em portas e transistores - mapeamento em bibliotecas           |
| 5 | Físico      | - otimização lógica - planejamento de layout - fabricação e encapsulamento               |

## Codificadores e Decodificadores

Sequências de bits podem ser usadas para codificar valores numéricos. Dois códigos binários têm aplicações especiais: o
**BCD** (Binary-Coded Decimal) e o de **Gray**.

Decodificadores em geral são circuitos lógicos capazes de ativar uma saída de acordo com uma seleção de sinais de entrada:

- Um decodificador de **nível alto** ativa uma saída quando uma das entradas estiver em nível 1 e as outras em nível 0.

- Um decodificador de **nível baixo** ativa uma saída quando uma das entradas estiver em nível 0 e as outras em nível 1

### Código BCD

O código BCD é basicamente uma forma de codificar valores numéricos na base 10 em seus equivalentes
binários.

      | Decimal | BCD  |
      |---------|------|
      |    0    | 0000 |
      |    1    | 0001 |
      |    2    | 0010 |
      |    3    | 0011 |
      |    4    | 0100 |
      |    5    | 0101 |
      |    6    | 0110 |
      |    7    | 0111 |
      |    8    | 1000 |
      |    9    | 1001 |

- Exemplo:

      Codificar o valor decimal 369 em código BCD: 369 = (0011) (0110) (1001).

      Um circuito codificador “decimal-para-BCD” é aquele capaz de mapear um conjunto de entradas (0-9) em um outro conjunto
      de  quatro  valores  binários  (s3s2s1s0),  se  apenas  uma  das  entradas  for acionada.

### Código de Gray

O código de Gray serve para expressar sequências binárias nas quais dois valores sucessivos tenham apenas um bit de
diferença (distância de Hamming = 1). Esse código também é conhecido com “código binário refletido“.

      | Decimal | Binário | Gray |
      |---------|---------|------|
      | 0       | 000     | 000  |
      | 1       | 001     | 001  |
      | 2       | 010     | 011  |
      | 3       | 011     | 010  |
      | 4       | 100     | 110  |
      | 5       | 101     | 111  |
      | 6       | 110     | 101  |
      | 7       | 111     | 100  |

## Multiplexador

Multiplexadores (ou seletores de dados) são circuitos lógicos capazes de atuar como chaves digitais: recebem várias
entradas e selecionam uma delas, em certo instante, e realizam sua transferência para a saída, mediante um código de
seleção. Podem ser usados para rotear dados, sequenciar operações, realizar conversões do tipo paralelo-série e gerar
tabelas ou formas de ondas.

Multiplexadores  podem  selecionar  mais  sinais  dependendo  do  número  de  bits  (tamanho)  da
chave de seleção

      if ( selector == 1 )
         output = input_b;
      else
         output = input_a;
      
               selector
                  _|_ 
      input_a ---|0  \
                 |    |--- output
      input_b ---|___/
      
               selector
                   |   ____
                   |  |    |\      ____
                   +--|  1 |-+----|    |
                   |  |____|      | &  |---+   ____ 
      input_a -----|--------------|____|   |__|    |
                   |               ____     __| >=1|--- output
                   +--------------|    |   |  |____|
                                  | &  |---+        
      input_b --------------------|____|

## Demultiplexador

Demultiplexadores  (ou  distribuidores  de  dados)  são  circuitos  capazes  de  receber  um  sinal  de entrada e
distribuí-lo  em  uma dentre  várias saídas, segundo um  código  de seleção. Podem ser  usados para distribuir um mesmo
sinal de ativação ou sequenciamento (clock) para vários circuitos.

      if ( selector == 1 )
         output_1 = input_a;
      else
         output_0 = input_a;

               selector
                  _|_
                 /  0|--- output_0
      nput_a ---|    | 
                 \___|--- output_1 

               selector
                   |   ____
                   |  |    |\      ____
                   +--|  1 |-+----|    |
                   |  |____|      | &  |--- output_0
      input_a --+--|--------------|____|            
                |  |               ____              
                |  +--------------|    |            
                |                 | &  |--- output_1      
                +-----------------|____|

## Aplicações Aritméticas

### Somadores

- Somador de 2 bits ( "meia-soma" ou "meio-somador" ou "half-adder" ) :

      - Equações características :

            Forma completa (ou canônica) :

            s1 = v =     a.b     (v -> "vai-um" )
            s0 = r = a'.b + a.b' (r -> resultado)

            Forma compacta (soma de produtos) :

            s1 = v = SoP (3)
            s0 = r = SoP (1,2)

      - Verilog :

            - Definição por expressão :

                  module halfAdder ( output carryOut, output sum, input a, input b ); 
                      assign s0 = a ^ b; // a xor b
                      assign s1 = a & b; // a and b 
                  endmodule // halfAdder

            - Definição por portas lógicas ( gates ):

                  module halfAdder ( output carryOut, output sum, input a, input b ); 
                      xor XOR (     sum , a, b ); 
                      and AND ( carryOut, a, b ); 
                  endmodule // halfAdder

- Somador de 3 bits ( "somador completo em cascata" ou "ripple-carry adder" ) :

      - Definição por expressão :

            module fullAdder ( output carryOut, output sum, input a, input b, input carry );
                assign carryOut = (a ^ b) & carry | (a & b);
                assign sum = (a ^ b) ^ carry;
            endmodule // fullAdder

      - Definição por portas lógicas ( gates ) :

            module fullAdder ( output carryOut, output sum, input a, input b, input carry );
                wire w1, w2, w3;
                xor XOR_1 ( w1, a ,  b );
                xor XOR_2 ( sum, w1,  carry );
                and AND_1 ( w2, w1,  carry );
                and AND_2 ( w3, a ,  b );
                and OR__1 ( carryOut, w2, w3 );
            endmodule // fullAdder

            module fullAdder ( output carry, output sum, input a,  input b,  input carry ); 
                wire w1,w2,w3;
                halfAdder HA0 ( w1, w2, a, b );
                halfAdder HA1 ( w3, sum, w2, carry );
                or        OR1 ( carry, w1, w3 );
            endmodule // fullAdder

# Fim