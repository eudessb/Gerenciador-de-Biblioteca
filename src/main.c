
#include "../include/arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    No *arvore;
    arvore = inicializar_arvore();
    arvore = carregar_livros("data/livros.csv", arvore);
    int expression;
    do
    {
        printf("Digite 1 para ver o menu com todas as opções, digite 0 caso deseje encerrar o programa\n");
        scanf("%d", &expression);
        switch (expression)
        {
        case 0:
            break;
        case 1:
            exibir_menu();
            break;
        case 2:
            printf("Livros disponíveis:\n");
            exibir_arvore(arvore);
            break;
        case 3:;
            inserir_manualmente(&arvore);
            break;
        case 4:
            getchar();
            char genero[99];
            printf("Digite o gênero que deseja consultar:\n");
            fgets(genero, 99, stdin);
            genero[strcspn(genero, "\n")] = '\0';

            printf("\nLivros do gênero:%s \n",genero);
            buscar_por_genero(arvore, genero);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (expression != 0);
    liberar_arvore(arvore);
    return 0;
}
