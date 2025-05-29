#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Funções para árvore de alunos
Aluno* criarAluno(char nome[], int matricula, float nota);
void removerArvoreAlunos(Aluno* T);
Aluno* buscarAlunoPorNome(Aluno* raiz, const char* nome);
float calcularMediaNotas(Aluno* raiz, int* total);
Aluno* inserirAluno(Aluno* T, char nome[], int matricula, float nota);
void imprimirEmOrdem(Aluno* raiz);

#endif