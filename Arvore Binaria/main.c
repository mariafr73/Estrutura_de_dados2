#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "aluno.h"

#define RESET        "\e[0m"
#define NEGRITO      "\e[1m"
#define SUBLINHADO   "\e[4m"

void menuInteiros(No** raiz);
void menuAlunos(Aluno** raizAlunos);
void limparBuffer();

int main() {
    No* raizInteiros = NULL;
    Aluno* raizAlunos = NULL;
    int opcao;

    do {
        printf(NEGRITO SUBLINHADO "\n=== MENU PRINCIPAL ===\n" RESET);
        printf("1. Operações com Árvore de Inteiros\n");
        printf("2. Operações com Árvore de Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                menuInteiros(&raizInteiros);
                break;
            case 2:
                menuAlunos(&raizAlunos);
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    // Liberar memória
    removerArvore(raizInteiros);
    removerArvoreAlunos(raizAlunos);
    
    return 0;
}

void menuInteiros(No** raiz) {
    int opcao, valor;
    
    do {
        printf(NEGRITO SUBLINHADO "\n=== ÁRVORE DE INTEIROS ===\n" RESET);
        printf("1. Inserir valor\n");
        printf("2. Percorrer in-ordem\n");
        printf("3. Mostrar altura da árvore\n");
        printf("4. Contar número de nós\n");
        printf("5. Contar número de folhas\n");
        printf("6. Calcular soma dos valores\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                *raiz = inserir(*raiz, valor);
                break;
            case 2:
                printf("Percorrendo in-ordem: ");
                percorrerInOrdem(*raiz);
                printf("\n");
                break;
            case 3:
                printf("Altura da árvore: %d\n", altura(*raiz));
                break;
            case 4:
                printf("Número de nós: %d\n", contarNos(*raiz));
                break;
            case 5:
                printf("Número de folhas: %d\n", contarFolhas(*raiz));
                break;
            case 6:
                printf("Soma dos valores: %d\n", soma(*raiz));
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

void menuAlunos(Aluno** raizAlunos) {
    int opcao, matricula;
    float nota;
    char nome[50];
    int totalAlunos;
    
    do {
        printf(NEGRITO SUBLINHADO "\n=== ÁRVORE DE ALUNOS ===\n" RESET);
        printf("1. Inserir aluno\n");
        printf("2. Buscar aluno por nome\n");
        printf("3. Calcular média das notas\n");
        printf("4. Listar todos os alunos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                printf("Nome do aluno: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                printf("Matrícula: ");
                scanf("%d", &matricula);
                
                printf("Nota: ");
                scanf("%f", &nota);
                limparBuffer();
                
                *raizAlunos = inserirAluno(*raizAlunos, nome, matricula, nota);
                break;
            case 2:
                printf("Nome a buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                Aluno* aluno = buscarAlunoPorNome(*raizAlunos, nome);
                if (aluno != NULL) {
                    printf("\nAluno encontrado:\n");
                    printf("Nome: %s\nMatrícula: %d\nNota: %.2f\n", 
                           aluno->nome, aluno->matricula, aluno->nota);
                } else {
                    printf("Aluno não encontrado!\n");
                }
                break;
            case 3:
                printf("Média das notas: %.2f\n", 
                    calcularMediaNotas(*raizAlunos, &totalAlunos));
                printf("Total de alunos: %d\n", totalAlunos);
                break;
            case 4:
                printf("\n=== Lista de Alunos ===\n");
                imprimirEmOrdem(*raizAlunos);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}