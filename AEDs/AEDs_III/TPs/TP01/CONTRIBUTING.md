# Como Colaborar

### Pré-requisitos

- Java Development Kit (JDK) 8 ou superior.
- Um ambiente de desenvolvimento Java (Eclipse, IntelliJ IDEA, etc.).

### Passos para Executar

1. Faça um fork deste repositório.
2. Clone o seu fork: `git clone`.
3. Crie uma branch: `git checkout -b minha-branch`.
   - Por favor, não use a branch `main`.
   - Cada aluno deve criar uma branch com seu nome; eu decidirei se o pull request será aceito ou não, apenas para garantir que seja alguém do grupo.
4. Faça suas alterações.
5. Faça o commit das suas alterações: `git commit -m 'minhas alterações'`.
6. Envie sua branch: `git push origin minha-branch`.
7. Crie um pull request.

#### Como criar sua branch

##### 1. Certifique-se de que você está no repositório correto.

```bash
cd caminho/para/seu/repositorio
```

##### 2. Atualize seu repositório local com as últimas mudanças do repositório remoto (opcional, mas recomendado).

```bash
git fetch origin
```

##### 3. Crie uma nova branch com o nome desejado. Substitua `nome-da-branch` pelo nome que você deseja dar à sua branch.

```bash
git checkout -b nome-da-branch
```

##### 4. (Opcional) Se quiser criar a branch a partir de uma branch específica, certifique-se de que está nessa branch antes de criar a nova.

```bash
git checkout branch-existente
git checkout -b nome-da-branch
```

#### Se o seu repositorio ficar obisoleto com o repositorio Dev

1. Caso isso venha a acontecer, execulte o segunte comando para atualizar o seu repositorio local
```bash
git pull origin NOME_DA_BRANCH
```
no nosso caso, vc substituiria NOME_DA_BRANCH por dev

#### Como criar um Pull Request

##### 1. Certifique-se de que você está no repositório correto.

```bash
cd caminho/para/seu/repositorio
```
##### 2. Atualize seu repositório local com as últimas mudanças do repositório remoto (opcional, mas recomendado).

```bash
git fetch origin
```
##### 3. Crie e mude para uma nova branch para realizar suas alterações.

```bash
git checkout -b nome-da-branch
```
##### 4. Faça as alterações necessárias no código.

##### 5. Adicione as alterações ao índice (staging area).

```bash
git add .
```
##### 6. Faça o commit das suas alterações com uma mensagem descritiva.

```bash
git commit -m "Descrição das mudanças realizadas"
```
##### 7. Envie sua nova branch para o repositório remoto.

```bash
git push origin nome-da-branch
```

##### Ou também...

- Vá para a página do repositório original no GitHub.
- Clique em "Pull Requests" e depois em "New Pull Request".
- Selecione a branch develop como a base e sua branch como a branch de comparação.
- Adicione uma descrição detalhada sobre suas alterações e envie o pull request.

##### 8. Revisão e Feedback
Os mantenedores do projeto revisarão seu pull request. Esteja preparado para receber feedback e fazer ajustes conforme necessário.

Diretrizes de Contribuição
Código Limpo e Legível: Certifique-se de que seu código é fácil de entender e siga os padrões de codificação do projeto.
Testes: Inclua testes para quaisquer novas funcionalidades ou correções.
Documentação: Atualize a documentação do projeto conforme necessário.

**Atenção:** Certifique-se de que todas as alterações sejam enviadas para a branch `dev` e não para a branch `main`. A branch `main` é reservada para a versão estável e final do projeto.

## Regras

Certifique-se de comentar seu commit seguindo o padrão:

- **criação** => create: criar um novo arquivo
- **nova funcionalidade** => feat: nova funcionalidade
- **correção de bug** => fix: correção de bug
- **documentação** => docs: documentação

## FIM
