#ifndef ARVORE_H
#define ARVORE_H


//Struct Nó
typedef struct No
{
    Livro livro;
    struct No* esquerda;
    struct No* direita;
} No;
//Struct livro
typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int numero_paginas;
} Livro;

No* criar_no(Livro livro);
//Função para criar árvore
No* inicializar_arvore();

// Função para Inserir um Novo Livro
void inserir_livro(No** raiz, Livro livro);

//Função para Buscar por Gênero
void buscar_por_genero(No* raiz, char genero[]);

// Função para Carregar Livros do Arquivo CSV
No* carregar_livros(char* nome_arquivo, No* raiz);

//Função para Exibir a Árvore
void exibir_arvore(No* raiz);

//Função para Liberar a Memória da Árvore
void liberar_arvore(No* raiz);

int arv_vazia(No* raiz);

#endif