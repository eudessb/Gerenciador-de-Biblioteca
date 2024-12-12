/**
 *Cabeçalho com a declaração das funções implementadas no projeto. 
 */
#ifndef ARVORE_H
#define ARVORE_H

typedef struct Livro
{
    int codigo;
    char titulo[99];
    char autor[99];
    char genero[99];
    int ano;
    char editora[99];
    int numero_paginas;
} Livro;

typedef struct No
{
    Livro livro;
    struct No *esquerda;
    struct No *direita;
} No;

No *criar_no(Livro livro);

No *inicializar_arvore();

void inserir_livro(No **raiz, Livro livro);

void buscar_por_genero(No *raiz, char *genero);

void inserir_manualmente(No **raiz);

No *carregar_livros(char *nome_arquivo, No *raiz);

void exibir_arvore(No *raiz);

void liberar_arvore(No *raiz);

void exibir_menu();

#endif