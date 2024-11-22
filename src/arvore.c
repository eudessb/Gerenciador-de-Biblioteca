/*
Made by Eudes Silva Bezerra

in progress...
*/
#include <arvore.h>
#include <stdio.h>

//Função para inicializar uma árvore vazia
No* inicializar_arvore(void)
{
    return NULL;
}
No* criar_no(Livro livro)
{
    No* novo_no = (No*)malloc(sizeof(No));

    novo_no->Livro = livro;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}
// Função para Inserir um novo Livro
void inserir_livro(No** raiz, Livro livro){
    if ((*raiz) == NULL) {
        return criar_no(livro);
    }
    if (livro.codigo < (*raiz)->Livro.codigo){
        (*raiz)->esquerda = inserir(&(*raiz)->esquerda, livro);   
    }
    else if (livro.codigo > (*raiz)->Livro.codigo){
        (*raiz)->direita = inserir(&(*raiz)->direita, livro);
    }    
    else {
        printf("Livro com código %d já foi inserido." ,livro.codigo);
    }
}
//Função para Buscar por Gênero
void buscar_por_genero(No* raiz, char genero[]);

// Função para Carregar Livros do Arquivo CSV
No* carregar_livros(char* nome_arquivo, No* raiz);

//Função para Exibir a Árvore
void exibir_arvore(No* raiz);

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

