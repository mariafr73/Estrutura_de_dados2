#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Estrutura básica da árvore binária para inteiros
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Funções básicas para árvore de inteiros
No* criarNo(int c);
void removerArvore(No* T);
No* buscar(No* T, int c);
No* inserir(No* T, int c);

// Percursos
void percorrerInOrdem(No* T);
void percorrerPreOrdem(No* T);
void percorrerPosOrdem(No* T);

// Funções auxiliares
int altura(No* T);
int profundidade(No* raiz, No* no, int nivel);
int soma(No* T);
int contarNos(No* T);
int contarFolhas(No* T);

#endif