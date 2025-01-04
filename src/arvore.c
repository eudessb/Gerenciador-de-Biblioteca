/**
Made by Eudes Silva Bezerra
*/
#include "../include/arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// Inicializa a árvore vazia
No *inicializar_arvore(void)
{
    printf("Árvore inicializada\n");
    return NULL;
}
/**
 * Insere um livro após receber um nó, caso o nó esteja vazio aloca memória para o mesmo e armazena o livro.
 * Define como NULL a raiz esquerda e direita do nó onde o livro foi inserido.
 */
void inserir_livro(No **raiz, Livro livro)
{
    if ((*raiz) == NULL)
    {
        *raiz = (No *)malloc(sizeof(No));
        (*raiz)->livro = livro;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        return;
    }
    if (livro.codigo < (*raiz)->livro.codigo)
    {
        inserir_livro(&(*raiz)->esquerda, livro);
    }
    else if (livro.codigo > (*raiz)->livro.codigo)
    {
        inserir_livro(&(*raiz)->direita, livro);
    }
    else
    {
        printf("livro com código %d já foi inserido.\n", livro.codigo);
        return;
    }
}
// Busca o gênero do livro desejado pelo usuário através de buscas recursivas.
void buscar_por_genero(No *raiz, char *genero)
{
    if (raiz == NULL){return;}
    if (strcmp(raiz->livro.genero, genero) == 0)
    {
        printf("%s\n", raiz->livro.titulo);
    }
    buscar_por_genero(raiz->esquerda, genero);
    buscar_por_genero(raiz->direita, genero);
}

// Lê cada linha do arquivo csv, usa o método strtok para tokenizar as strings presentes usando as vírgulas como delimitadores e insere o livro na árvore.
No *carregar_livros(char *nome_arquivo, No *raiz)
{
    char linha[1024];
    Livro Livro_temp;
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL)
    {
        perror("Não foi possível ler o arquivo");
        return raiz;
    }
    while (fgets(linha, sizeof(linha), file))
    {
        // Copia o código do livro
        char *token = strtok(linha, ",");
        if (token == NULL)
            continue;
        Livro_temp.codigo = atoi(token);
        // Copia o título do livro
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(Livro_temp.titulo, token);
        // Copia o nome do autor
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(Livro_temp.autor, token);
        // Gênero do livro
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(Livro_temp.genero, token);
        // Copia o ano
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        Livro_temp.ano = atoi(token);
        // Copia a editora
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(Livro_temp.editora, token);
        // Copia o Nº de páginas
        token = strtok(NULL, ",");
        Livro_temp.numero_paginas = atoi(token);
        inserir_livro(&raiz, Livro_temp);
    }
    fclose(file);
    return raiz;
}
/**
 Insere manualmente um novo livro na árvore utilizando informações passadas pelo usuário.
 O caso do livro já estar na árvore é tratado pelo método inserir_livro(), também usado nesse método.
 */
void inserir_manualmente(No **raiz)
{
    Livro dados_livro;
    printf("Digite o código do livro:\n");
    scanf("%d", &dados_livro.codigo);
    while (getchar() != '\n')
        ;

    printf("Digite o título do livro\n");
    fgets(dados_livro.titulo, sizeof(dados_livro.titulo), stdin);
    dados_livro.titulo[strcspn(dados_livro.titulo, "\n")] = '\0';

    printf("Digite o nome do autor do livro\n");
    fgets(dados_livro.autor, sizeof(dados_livro.autor), stdin);
    dados_livro.autor[strcspn(dados_livro.autor, "\n")] = '\0';

    printf("Digite o gênero do livro\n");
    fgets(dados_livro.genero, sizeof(dados_livro.genero), stdin);
    dados_livro.genero[strcspn(dados_livro.genero, "\n")] = '\0';

    printf("Digite a editora do livro\n");
    fgets(dados_livro.editora, sizeof(dados_livro.editora), stdin);
    dados_livro.editora[strcspn(dados_livro.editora, "\n")] = '\0';

    printf("Digite o ano de lançamento do livro\n");
    scanf("%d", &dados_livro.ano);

    printf("Digite a quantidade de páginas do livro\n");
    scanf("%d", &dados_livro.numero_paginas);

    inserir_livro(raiz, dados_livro);
}
/**
 * Caso a árvore não esteja vazia, exibe,utilizando recursividade, cada nó presente na mesma.
 */
void exibir_arvore(No *raiz)
{
    if (raiz != NULL)
    {
        exibir_arvore(raiz->esquerda);
        printf("%s Gênero: %s\n", raiz->livro.titulo, raiz->livro.genero);
        exibir_arvore(raiz->direita);
    }
}
/**
 * Caso a árvore não esteja vazia, utiliza recursividade para liberar cada nó da árvore
 */
void liberar_arvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}
// Menu com todas as opções de operações disponíveis no arquivo main.c .
void exibir_menu()
{
    printf("\n==== Gerenciador de Biblioteca ====\n");
    printf("0. ENCERRAR PROGRAMA.\n");
    printf("1. EXIBIR O MENU.\n");
    printf("2. EXIBIR ÁRVORE (mostra todos os livros organizados pela ordem do código).\n");
    printf("3. INSERIR LIVRO MANUALMENTE\n");
    printf("4. CONSULTAR LIVRO.\n");
}
