#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno* criarAluno(char nome[], int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

void removerArvoreAlunos(Aluno* T) {
    if (T != NULL) {
        removerArvoreAlunos(T->esquerdo);
        removerArvoreAlunos(T->direito);
        free(T);
    }
}

Aluno* buscarAlunoPorNome(Aluno* raiz, const char* nome) {
    if (raiz == NULL) return NULL;
    
    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0) return raiz;
    if (cmp < 0) return buscarAlunoPorNome(raiz->esquerdo, nome);
    return buscarAlunoPorNome(raiz->direito, nome);
}

float calcularMediaNotas(Aluno* raiz, int* total) {
    if (raiz == NULL) {
        *total = 0;
        return 0.0f;
    }
    
    int totalEsq, totalDir;
    float somaEsq = calcularMediaNotas(raiz->esquerdo, &totalEsq);
    float somaDir = calcularMediaNotas(raiz->direito, &totalDir);
    
    *total = 1 + totalEsq + totalDir;
    return (raiz->nota + somaEsq * totalEsq + somaDir * totalDir) / (*total);
}

Aluno* inserirAluno(Aluno* T, char nome[], int matricula, float nota) {
    if (T == NULL) return criarAluno(nome, matricula, nota);
    
    int cmp = strcmp(nome, T->nome);
    if (cmp < 0) T->esquerdo = inserirAluno(T->esquerdo, nome, matricula, nota);
    else if (cmp > 0) T->direito = inserirAluno(T->direito, nome, matricula, nota);
    
    return T;
}

void imprimirEmOrdem(Aluno* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerdo);
        printf("Nome: %-20s Matrícula: %-6d Nota: %.2f\n", 
               raiz->nome, raiz->matricula, raiz->nota);
        imprimirEmOrdem(raiz->direito);
    }
}