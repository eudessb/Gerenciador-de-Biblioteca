## Gerenciador de Biblioteca 
Projeto de um sistema de gerenciamento de uma biblioteca, escrito em __C__ e utilizando uma árvore binária, para a disciplina de Estruturas de Dados Básicas II.

**STATUS**: Em andamento

## Estrutura de diretórios

Este projeto contém a seguinte estrutura de diretórios:     

* src: Contém os arquivos de código-fonte em C. Aqui estão os principais módulos do programa:
  - `main.c`: Função principal que executa o programa e interage com o usuário.
  - `arvore.c`: Implementação da árvore binária de busca, incluindo inserção, exibição e busca.
* include: Contém os arquivos de cabeçalho (.h) com as definições das funções e tipos usados no projeto.
  - `arvore.h`: Definições de funções para manipulação da árvore binária e estrutura `Livro`.
* data: Contém os arquivos CSV usados para carregar os dados dos livros.
  - `livros.csv`:arquivo com dados de livros.
* bin: Contém os arquivos executáveis gerados durante a compilação do projeto.
  - `main`: Executável principal do projeto.


## Arquivo Makefile 

O projeto usa um **Makefile** para facilitar a compilação e execução. Aqui estão os comandos principais disponíveis, utilize-os no diretório 
**../Gerenciador_De_Biblioteca**.

- **Compilar o programa**:
  `make`
- **Compilar e executar o programa**:
  `make run`
- **Limpar o diretório**:
  `make clean`

## Dependências
- **Compilador:** GCC
- **Make**: Para facilitar a compilação e execução do projeto.