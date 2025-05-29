#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

No* criarNo(int c) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = c;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

void removerArvore(No* T) {
    if (T != NULL) {
        removerArvore(T->esquerdo);
        removerArvore(T->direito);
        free(T);
    }
}

No* buscar(No* T, int c) {
    if (T == NULL) return NULL;
    if (T->dado == c) return T;
    if (c < T->dado) return buscar(T->esquerdo, c);
    return buscar(T->direito, c);
}

No* inserir(No* T, int c) {
    if (T == NULL) return criarNo(c);
    if (c < T->dado) T->esquerdo = inserir(T->esquerdo, c);
    else if (c > T->dado) T->direito = inserir(T->direito, c);
    return T;
}

void percorrerInOrdem(No* T) {
    if (T != NULL) {
        percorrerInOrdem(T->esquerdo);
        printf("%d ", T->dado);
        percorrerInOrdem(T->direito);
    }
}

void percorrerPreOrdem(No* T) {
    if (T != NULL) {
        printf("%d ", T->dado);
        percorrerPreOrdem(T->esquerdo);
        percorrerPreOrdem(T->direito);
    }
}

void percorrerPosOrdem(No* T) {
    if (T != NULL) {
        percorrerPosOrdem(T->esquerdo);
        percorrerPosOrdem(T->direito);
        printf("%d ", T->dado);
    }
}

int altura(No* T) {
    if (T == NULL) return -1;
    int alturaEsq = altura(T->esquerdo);
    int alturaDir = altura(T->direito);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int profundidade(No* raiz, No* no, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz == no) return nivel;
    int profEsq = profundidade(raiz->esquerdo, no, nivel + 1);
    if (profEsq != -1) return profEsq;
    return profundidade(raiz->direito, no, nivel + 1);
}

int soma(No* T) {
    if (T == NULL) return 0;
    return T->dado + soma(T->esquerdo) + soma(T->direito);
}

int contarNos(No* T) {
    if (T == NULL) return 0;
    return 1 + contarNos(T->esquerdo) + contarNos(T->direito);
}

int contarFolhas(No* T) {
    if (T == NULL) return 0;
    if (T->esquerdo == NULL && T->direito == NULL) return 1;
    return contarFolhas(T->esquerdo) + contarFolhas(T->direito);
}