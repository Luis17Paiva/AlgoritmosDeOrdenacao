#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR_NOME 50

//a função getNome deve colocar o seu nome dentro da chamada
//seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

//Assum que os vetores estão ordenados ao chamar as funções de busca
//As funções de busca não devem alterar o vetor
//O retorno das funções de busca é o índice do elemento no vetor,
//ou -1 caso o elemeno não exista no vetor
//Você deve armazenar no ponteiro long int* numComparacoes o número de comparações
//envolvendo elementos do vetor feito pelo seu algoritmo na chamada


//a busca sequencial é a busca ingênua
//busca o elemento começando pelo ultimo elemento do vetor
int buscaSequencial(int vetor[],int tam, int valor,long int* numComparacoes);

//busca binária no vetor
int buscaBinaria(int vetor[], int tam, int valor,long int* numComparacoes);
 
//Cada uma das funções deve ordenar o vetor passado como parâmetro
//O retorno das funções de ordenação é o número de comparações
//entre elementos do vetor

long int insertionSort(int vetor[], int tam);

long int selectionSort(int vetor[], int tam);

int mergeSort(int vetor[], int tam);

long int quickSort(int vetor[], int tam);

// funções para gerar vetores 

void gera_vetor_randomico (int v[], int tam);

void gera_vetor_em_ordem (int v[], int tam);

//Embaralhar um vetor, util caso o vetor esteja ordenado

void embaralha_vetor (int v[], int tam);

//Função para copiar um vetor
void copiar (int w[], int u[], int a, int b);

#endif // ORDENACAO_H_
