/*
Made by Eudes Silva Bezerra

in progress...
*/
#include <arvore.h>
#include <stdio.h>
#define MAX_LINHAS 100;
//Função para inicializar uma árvore vazia
No* inicializar_arvore(void)
{
    return NULL;
}
No* criar_no(Livro livro)
{
    No* novo_no = (No*)malloc(sizeof(No));

    novo_no->livro = livro;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}
// Função para Inserir um novo livro
void inserir_livro(No** raiz, Livro livro){
    if ((*raiz) == NULL) {
        return criar_no(livro);
    }
    if (livro.codigo < (*raiz)->livro.codigo){
        (*raiz)->esquerda = inserir(&(*raiz)->esquerda, livro);   
    }
    else if (livro.codigo > (*raiz)->livro.codigo){
        (*raiz)->direita = inserir(&(*raiz)->direita, livro);
    }    
    else {
        printf("livro com código %d já foi inserido." ,livro.codigo);
    }
}
//Função para Buscar por Gênero
void buscar_por_genero(No* raiz, char genero[])
{
    if (!strcmp(raiz->livro.genero, genero) == 0 ){
        print("livro:%s\n",raiz->livro.genero);
    }
    buscar_por_genero(raiz->esquerda, genero);
    buscar_por_genero(raiz->direita,  genero);
}
// Função para Carregar livros do Arquivo CSV
No* carregar_livros(char* nome_arquivo, No* raiz)
{
    char linha[1024];
    int count = 0;
    Livro livros[100];
    FILE* file = fopen(nome_arquivo,'r');
    if (file ==NULL)
    {
        perror("Não foi possível ler o arquivo");
    }
    fgets(linha,sizeof(linha),file);
    while(fgets(linha,sizeof(linha),file))
    {
        //Pular cabeçalho   
        linha[strcspn(linha,"\n")] = '\0';
        //Copia o código do livro
        char *token = strtok(linha, ",");
        livros[count].codigo = atoi(token);
        //Copia o título do livro
        token= strtok(NULL,",");
        strcpy(livros[count].titulo,token);
        //Copia o nome do autor
        token= strtok(NULL,",");
        strcpy(livros[count].autor,token);
        //Gênero do livro
        token = strtok(NULL,",");
        strcpy(livros[count].genero,token);
        //Copia o ano
        token = strtok(NULL,",");
        livros[count].codigo = atoi(token);
        //Copia a editora
        token = strtok(NULL,",");
        strcpy(livros[count].editora,token);
        //Copia o Nº de páginas
        token = strtok(NULL,",");
        livros[count].numero_paginas = atoi(token);
        inserir_livro(raiz,livros[count]);
        count++;
    }
    fclose(file); //Fechar arquivo
}


//Função para Exibir a Árvore
void exibir_arvore(No* raiz)
{
     if (raiz != NULL) {
        exibir_arvore(raiz->esquerda);
        printf("%s", raiz->livro.titulo);
        exibir_arvore(raiz->direita);
    }
};

//Função para Liberar a Memória da Árvore
void liberar_arvore(No* raiz){
    if (!arv_vazia(raiz))
    {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }

}
int arv_vazia (No** raiz){
    return (*raiz) = NULL;
}

