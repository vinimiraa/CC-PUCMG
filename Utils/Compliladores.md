# Compiladores

- `c`
  - [Windows](#compilador-gcc-para-windows)
    - [Versão Atual](#versão-mais-atual)
    - [Versão Completa](#versão-mais-completa)
  - [Linux/WSL](#compilador-gcc-para-linux-ou-windows-10--wsl-ou-wsl2)
- `Java`
  - [Windows](#compilador-jdk-para-windows)
    - [Versão Atual](#versão-mais-atual-1)
    - [Versão ALternativa](#versão-alternativa)
- `Verilog`
  - [Windows](#compilador-verilog-para-windows)
    - [Versão Atual](#versão-mais-atual-2)
  - [Linux/WSL](#compilador-verilog-para-ubuntu-linux-ou-windows-10--wsl-ou-wsl2)
- [Compiladores Online](#compiladores-online)
- [Nota](#nota)
- [Observação](#observação)

# Compilador GCC para Windows

## Versão mais atual

### WinLibs

- Site: [winlibs.com](http://winlibs.com)
- Versão: GCC 13.2.0 + LLVM/Clang/LLD/LLDB 16.0.6 + MinGW-w64 11.0.0 (UCRT) - release 1
- Detalhe: Win64 without LLVM/Clang/LLD/LLDB

### Instalação

1. Baixe e extraia a pasta no diretório de sua preferência, como, por exemplo: `C:\MinGW`.

2. Para completar a instalação no Windows, supondo que a pasta do compilador seja `C:\MinGW`:
    - Abra o **Menu Iniciar**
    - Vá para **Configurações**
    - Procure por **variáveis de ambiente**
    - Escolha **Variáveis de ambiente do sistema**
    - Clique em **Variáveis de ambiente**
    - Procure pela variável **Path**
    - Clique em **Editar**
    - Adicione os seguintes caminhos, clicando em **Novo** a cada um:
      - `C:\MinGW`
      - `C:\MinGW\bin`
      - `C:\MinGW\include`
      - `C:\MinGW\lib`
    - Clique em **OK** para finalizar.

```sh
 Menu Iniciar
    |_ Configurações
       |_ Procurar: variáveis de ambiente 
          |_ Escolher: Variáveis de ambiente do sistema
             |_ Apertar o botão: Variáveis de ambiente
                |_ Procurar: Path
                   |_ Apertar o botão: Editar
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\MinGW
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\MinGW\bin
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\MinGW\include
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\MinGW\lib
                      |  |_ OK
                      |_ OK
```

### Testar a instalação

1. Abra o **Menu Iniciar**
2. Execute `cmd`
3. No prompt de comando, digite:

    ```sh
    gcc -v
    ```

4. Verifique se a resposta indica a versão 13.2.0.

## Versão mais completa

### MSYS2

- Site: [msys2.org](https://www.msys2.org)
- Pacotes essenciais:

    ```sh
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    pacman -S editors
    ```

# Compilador GCC para Linux ou Windows 10 / WSL ou WSL2

1. Atualize o sistema:

    ```sh
    sudo apt-get update
    sudo apt-get upgrade
    ```

2. Instale os pacotes essenciais:

    ```sh
    sudo apt-get install build-essential
    sudo apt-get install manpages-dev man-db manpages-posix-dev
    ```

# Compilador JDK para Windows

## Versão mais atual

### Oracle JDK

- Site: [oracle.com](https://www.oracle.com/java/technologies/javase-downloads.html)
- Versão: JDK 21 (ou a mais recente disponível no site)

### Instalação

1. Baixe o instalador do JDK a partir do site da Oracle.
2. Execute o instalador e siga as instruções na tela para completar a instalação.
3. Após a instalação, verifique o caminho onde o JDK foi instalado (por exemplo: `C:\Program Files\Java\`).

### Configuração das variáveis de ambiente

1. Abra o **Menu Iniciar**
2. Vá para **Configurações**
3. Procure por **variáveis de ambiente**
4. Escolha **Variáveis de ambiente do sistema**
5. Clique em **Variáveis de ambiente**
6. Procure pela variável **Path**
7. Clique em **Editar**
8. Adicione os seguintes caminhos, clicando em **Novo** a cada um:
    - `C:\Program Files\Java\jdk-21`
    - `C:\Program Files\Java\jdk-21\bin`
9. Clique em **OK** para finalizar.

```sh
 Menu Iniciar
    |_ Configurações
       |_ Procurar: variáveis de ambiente 
          |_ Escolher: Variáveis de ambiente do sistema
             |_ Apertar o botão: Variáveis de ambiente
                |_ Procurar: Path
                   |_ Apertar o botão: Editar
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\Program Files\Java\jdk-21
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\Program Files\Java\jdk-21\bin
                      |  |_ OK
                      |_ OK
```

### Testar a instalação

1. Abra o **Menu Iniciar**
2. Execute `cmd`
3. No prompt de comando, digite:

    ```sh
    java -version
    ```
4. Verifique se a resposta indica a versão instalada do JDK (por exemplo, `jdk-20`).

## Versão Alternativa

### OpenJDK

- Site: [jdk.java.net](https://jdk.java.net/)
- Versão: OpenJDK 20 (ou a mais recente disponível no site)

### Instalação

1. Baixe o arquivo binário do OpenJDK a partir do site do OpenJDK.
2. Extraia o arquivo para um diretório de sua preferência (por exemplo: `C:\OpenJDK`).
3. Siga o mesmo processo de configuração das variáveis de ambiente descrito acima, ajustando o caminho para onde você extraiu o OpenJDK.

# Compilador Verilog para Windows

## Versão mais atual

### Icarus Verilog

- Site: [icarus.com](https://bleyer.org/icarus/)
- Versão: Icarus Verilog 11.0 (ou a mais recente disponível no site)

### Instalação

1. Baixe o instalador do Icarus Verilog a partir do site oficial.
2. Execute o instalador e siga as instruções na tela para completar a instalação.
3. Após a instalação, verifique o caminho onde o Icarus Verilog foi instalado (por exemplo: `C:\iverilog`).

### Configuração das variáveis de ambiente

1. Abra o **Menu Iniciar**
2. Vá para **Configurações**
3. Procure por **variáveis de ambiente**
4. Escolha **Variáveis de ambiente do sistema**
5. Clique em **Variáveis de ambiente**
6. Encontre a variável **Path** e clique em **Editar**
7. Adicione os seguintes caminhos, clicando em **Novo** a cada um:
    - `C:\iverilog`
    - `C:\iverilog\bin`
    - `C:\iverilog\gtkwave\bin`
8. Clique em **OK** para finalizar.

```sh
 Menu Iniciar
    |_ Configurações
       |_ Procurar: variáveis de ambiente 
          |_ Escolher: Variáveis de ambiente do sistema
             |_ Apertar o botão: Variáveis de ambiente
                |_ Procurar: Path
                   |_ Apertar o botão: Editar
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\iverilog
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\iverilog\bin
                      |  |_ OK
                      |_ Apertar o botão: Novo
                      |  |_ Procurar o caminho: C:\iverilog\gtkwave\bin
                      |  |_ OK
                      |_ OK
```

### Testar a instalação

1. Abra o **Menu Iniciar**
2. Execute `cmd`
3. No prompt de comando, digite:

    ```sh
    iverilog -v
    ```
4. Verifique se a resposta indica a versão instalada do Icarus Verilog.

# Compilador Verilog para Ubuntu Linux ou Windows 10 / WSL ou WSL2

1. Atualize o sistema:
    ```sh
    sudo apt-get update
    sudo apt-get upgrade
    ```
2. Instale o Icarus Verilog:
    ```sh
    sudo apt-get install iverilog
    ```

3. Verifique a instalação:
    ```sh
    iverilog -v
    ```

# Opcionais

- [Flowgorithm](http://flowgorithm.org/download/index.htm)
  - Versão: Flowgorithm v3.4.1
  - Descrição: Ferramenta para edição e testes de fluxogramas (opcional)
- [Visual Studio Code](https://code.visualstudio.com/)
  - Descrição: Editor de código leve e poderoso, com suporte para várias linguagens de programação, incluindo Java, 
  através de extensões.
- [IntelliJ IDEA](https://www.jetbrains.com/idea/download/)
  - Descrição: IDE poderosa para desenvolvimento em Java, oferecida nas versões Community (gratuita) e Ultimate (paga).
- [Eclipse IDE](https://www.eclipse.org/downloads/)
  - Descrição: Uma das IDEs mais populares para desenvolvimento em Java, totalmente gratuita.
- [GTKWave](http://gtkwave.sourceforge.net/)
  - Descrição: Visualizador de formas de onda para simulações em Verilog.
- [Visual Studio Code](https://code.visualstudio.com/)
  - Descrição: Editor de código leve e poderoso, com suporte para Verilog através de extensões como 
  Verilog-HDL/SystemVerilog/Bluespec.

# Compiladores online

- [Online GDB - C Compiler](https://www.onlinegdb.com/online_c_compiler)
- [Online GDB - C++ Compiler](https://www.onlinegdb.com/online_c++_compiler)
- [Online GDB - Java Compiler](https://www.onlinegdb.com/online_java_compiler)
- [Compile Java](https://www.compilejava.net/)
- [JDoodle](https://www.jdoodle.com/)
- [TutorialsPoint](https://www.tutorialspoint.com/compile_c_online.php)
- [CodeChef IDE](https://www.codechef.com/ide)
- [Ideone](https://www.ideone.com)
- [Compile Online](https://www.compileonline.com)
- [Codenvy](https://codenvy.io)
- [Paiza](https://paiza.io)
- [EDA Playground](https://www.edaplayground.com/)
- [JDoodle](https://www.jdoodle.com/a/4hG)
- [Verilog Online Compiler](https://www.tutorialspoint.com/compile_verilog_online.php)

# Nota

Para mais informações, consulte: [wikihow.com](https://www.wikihow.com/Change-the-PATH-Environment-Variable-on-Windows).

# Observação

Compiladores online são opções para testes rápidos. Recomenda-se identificar a versão do compilador antes de uso, para garantir a compatibilidade do código em outros sistemas.

`FIM`
