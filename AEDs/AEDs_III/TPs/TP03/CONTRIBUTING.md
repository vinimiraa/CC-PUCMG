# Como Colaborar

### Pré-requisitos

- **Java Development Kit (JDK) 8** ou superior.
- Um ambiente de desenvolvimento Java como **Eclipse**, **IntelliJ IDEA**, etc.

---

### Passos para Executar o Projeto

1. Faça um **fork** deste repositório para sua conta GitHub.
2. **Clone** o seu fork para sua máquina local:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```
3. Crie uma nova **branch** para suas alterações:
   ```bash
   git checkout -b minha-branch
   ```
   > **Observações:**
   > - **Não use** a branch `main` para realizar alterações.
   > - Nomeie a branch com o seu nome ou um identificador relevante, para que o pull request seja facilmente reconhecível e aceito.

4. Faça suas **alterações** no código.
5. **Comite** suas alterações com uma mensagem clara:
   ```bash
   git commit -m "minhas alterações"
   ```
6. **Envie** suas alterações para o seu repositório remoto no GitHub:
   ```bash
   git push origin minha-branch
   ```
7. **Crie um Pull Request** diretamente no GitHub para solicitar a inclusão das suas alterações.

---

### Sincronizando com o Repositório Original

Para garantir que seu fork esteja sempre atualizado com o repositório original, siga estes passos antes de realizar alterações:

1. **Adicione o repositório original** como um "remote" chamado `upstream`:
   ```bash
   git remote add upstream https://github.com/usuario-original/repositorio-original.git
   ```
   
2. **Busque** as atualizações do repositório original:
   ```bash
   git fetch upstream
   ```
   
3. **Mescle** as atualizações da branch `dev` do repositório original na sua branch local:
   ```bash
   git checkout dev  # Certifique-se de estar na branch dev
   git merge upstream/dev
   ```

4. Resolva possíveis **conflitos** (se houver) e faça um commit das resoluções:
   ```bash
   git add .
   git commit -m "Resolvendo conflitos de merge"
   ```

5. Atualize seu fork no GitHub com as mudanças mescladas:
   ```bash
   git push origin dev
   ```

> **Dica:** Sempre sincronize seu repositório local com o repositório original antes de criar uma nova branch ou realizar 
alterações. Isso evita conflitos e garante que você está trabalhando com a versão mais atual do projeto.

---

### Enviando um Pull Request

1. Certifique-se de que você **sincronizou seu repositório** local com o original (veja as instruções de sincronização acima).
2. Faça suas alterações em uma nova **branch** criada a partir da branch `dev`:
   ```bash
   git checkout -b nome-da-branch
   ```
3. Após realizar as alterações, **adicione** os arquivos modificados:
   ```bash
   git add .
   ```
4. Faça o **commit** das alterações com uma mensagem descritiva:
   ```bash
   git commit -m "Descrição das mudanças realizadas"
   ```
5. **Envie** a branch para o seu repositório remoto:
   ```bash
   git push origin nome-da-branch
   ```
6. No GitHub, vá para o seu repositório fork e crie um **Pull Request**.
   - Selecione a branch `dev` como a base e sua nova branch como a branch de comparação.
   - Adicione uma descrição clara e detalhada sobre as alterações realizadas.
7. Aguarde a **revisão** dos mantenedores do projeto. Eles podem solicitar ajustes ou aprovar o pull request.

---

### Mantendo o Repositório Atualizado

Caso seu repositório local fique desatualizado em relação ao repositório original, siga estas etapas para atualizá-lo:

1. Atualize o repositório local com as mudanças do `upstream`:
   ```bash
   git fetch upstream
   git merge upstream/dev
   ```
2. Após mesclar, resolva quaisquer conflitos e faça o **push** das mudanças para o seu repositório remoto:
   ```bash
   git push origin dev
   ```

---

### Regras de Commit

Seguir um padrão claro para mensagens de commit facilita a leitura e o entendimento do histórico do projeto. Abaixo 
estão as diretrizes e sugestões para estruturar suas mensagens de commit:

#### Formato da Mensagem de Commit

Cada mensagem de commit deve seguir o formato abaixo:

```
<tipo>: <descrição concisa>

[Corpo da mensagem opcional]
```

1. **`<tipo>`**: O tipo de alteração que você está fazendo.
2. **`<descrição concisa>`**: Uma breve descrição das mudanças (máximo 72 caracteres).
3. **Corpo (opcional)**: Explicação mais detalhada sobre o que foi alterado, se necessário. Aqui você pode descrever 
o motivo da alteração e, se aplicável, as consequências das mudanças. Use linhas de até 72 caracteres para garantir que 
o corpo do commit seja fácil de ler em várias ferramentas de Git.

#### Tipos de Commits

Aqui estão os tipos de commit mais comuns que podem ser usados:

- **feat**: Quando você está adicionando uma nova funcionalidade.
  - Exemplo: `feat: implementar sistema de autenticação via OAuth`
  
- **fix**: Quando você está corrigindo um bug.
  - Exemplo: `fix: corrigir erro de null pointer ao acessar perfil`

- **docs**: Para mudanças na documentação.
  - Exemplo: `docs: atualizar README com instruções de instalação`

- **style**: Alterações de estilo, como formatação de código, sem mudanças de lógica.
  - Exemplo: `style: ajustar indentação em ArquivoCategoria.java`

- **refactor**: Para mudanças no código que não alteram funcionalidade, mas melhoram a estrutura.
  - Exemplo: `refactor: reorganizar métodos para melhor legibilidade`

- **test**: Para adicionar ou corrigir testes de unidade.
  - Exemplo: `test: adicionar teste para verificar login com credenciais inválidas`

- **perf**: Para melhorias de desempenho.
  - Exemplo: `perf: otimizar busca por categorias na árvore B+`

- **build**: Alterações que afetam o sistema de build ou dependências externas (como arquivos de configuração de compilação, dependências).
  - Exemplo: `build: atualizar versão do Maven para 3.8.1`

#### Exemplos de Mensagens de Commit

Aqui estão alguns exemplos completos que seguem as diretrizes acima:

1. **Commit simples**:
   ```
   feat: adicionar função de exportar relatório em PDF
   ```

2. **Commit com corpo explicativo**:
   ```
   fix: resolver erro de autenticação com token JWT inválido

   O erro ocorria quando o token expirava e o usuário tentava acessar
   uma rota protegida. Adicionada verificação extra para garantir que o
   token é renovado automaticamente antes de expirar.
   ```

3. **Commit com corpo e referência a uma issue**:
   ```
   perf: otimizar query de busca por categorias na árvore B+

   A busca estava levando até 3 segundos para ser concluída em grandes 
   volumes de dados. Refatorado o algoritmo de busca para reduzir a
   complexidade de O(n^2) para O(n log n).
   
   Closes #45
   ```

### Sugestões e Boas Práticas

- **Use verbos no imperativo**: Sempre comece a descrição com verbos de ação no imperativo, como “adicionar”, “corrigir”, “remover”. Exemplo: `fix: corrigir erro no módulo de autenticação`.
- **Seja claro e específico**: A descrição deve explicar de forma clara o que foi alterado, sem ser ambígua ou vaga.
- **Mantenha o histórico limpo**: Faça commits pequenos e coesos que tratam de uma única tarefa ou correção por vez, ao invés de um grande commit com várias mudanças.
- **Inclua referências a issues quando possível**: Se o commit está relacionado a um issue ou bug report, faça referência a ele no final do commit, usando a palavra-chave `Closes #número`, onde `número` é o número do issue.

---

### Diretrizes de Contribuição

- **Código Limpo e Legível**: Garanta que o código segue os padrões estabelecidos no projeto.
- **Testes**: Sempre que adicionar uma nova funcionalidade, inclua testes.
- **Documentação**: Atualize a documentação do projeto sempre que fizer mudanças relevantes.

> **Importante**: Todas as alterações devem ser enviadas para a branch `dev`. A branch `main` é reservada para a versão estável do projeto.

---

## FIM
