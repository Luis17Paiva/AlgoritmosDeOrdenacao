#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ordenacao.h"
#include <time.h>


void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Luis Eduardo Soares de Paiva", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

unsigned int getGRR(){
	return 20192614;
}

//a função a seguir deve retornar o seu número de GRR
//unsigned int getGRR();

void trocar(int vetor[],int a, int b){  //troca a com b
	int aux;

	aux = vetor[a];
	vetor[a] = vetor[b];

	vetor[b] = aux;

	return;
}

int maximo(int vetor[], int tam, long int* numComparacoes){
	int i,max,Imax;

	max = vetor[tam];
	Imax = tam;
	for (i = 0; i < tam; i++){

		*numComparacoes += 1;
		if(vetor[i] > max){
			
			max = vetor [i];
			Imax = i;
		}
	}
	
	return Imax;
}

void copiar (int w[], int u[], int a, int b){
	int i;

	for (i = 0; i <= (b - a); i++){
		 
		 w[a+i] = u[i];
	}
	
	return;
}

int merge(int vetor[], int ini, int m, int tam){
	long int numComparacoes = 0;
	int Vaux[tam];
	int i,j,k,p;

	i = 0 + ini;
	j = m + 1;
	p = 0;
 
	 
	for (k = 0 ; k <= (tam - ini );){

		
		if ((i <= m && vetor[i] <= vetor[j]) || j > tam){
			numComparacoes++;
			p = i;
			i++;
		}else{
			p = j;
			j++;
		}

		Vaux[k] = vetor[p];
		k++;

	}
	copiar(vetor,Vaux,ini,tam);

	return numComparacoes;
}

long int mergeSortInterno(int vetor[], int a, int b){
	long int numComparacoes = 0;
	int m;

	if (a >= b){

		return 0;
	}

	m = (a+b) / 2;

	numComparacoes += mergeSortInterno(vetor,a,m);
	numComparacoes += mergeSortInterno(vetor,m+1,b);
	numComparacoes += merge(vetor,a,m,b);

	return numComparacoes;
}

int particionar(int vetor[], int a, int b,long int *numComparacoes){
	int pivo,m,i;

	pivo = vetor[b];
	m = a;

	for (i = a; i <= b - 1; i++){

		if( vetor[i] <= pivo){
			*numComparacoes += 1;
			trocar(vetor,m,i);
			m++;
		}
	}
	trocar(vetor,m,b);
	
	return m;
}

long int quickSortInterno(int vetor[], int a, int b){
	long int numComparacoes = 0;
	int m;

	if( a>= b){

		return 0;
	}

	m = particionar(vetor,a,b,&numComparacoes);
	numComparacoes += quickSortInterno(vetor,a,m-1);
	numComparacoes += quickSortInterno(vetor,m+1,b);  

	return numComparacoes;
}

int buscaSequencial(int vetor[], int tam, int valor,long int* numComparacoesBusca) {
    if (tam < 0) {
        return -1; // Elemento não encontrado no vetor
    }
    *numComparacoesBusca += 1;

    if (vetor[tam] == valor) {
        return tam; // Elemento encontrado no índice 'tam'
    }

    return buscaSequencial(vetor, tam - 1, valor, numComparacoesBusca);
}


int buscaBinariaInterna(int vetor[], int ini, int tam, int* valor,long int* numComparacoes){
	int m;


	if (ini <= tam){

		m = (ini + tam)/2;
		if (vetor[m] == *valor){
            *numComparacoes = *numComparacoes + 1; 
			return m;         //Retorna o indice do vetor se econtrar o elemento
		}else{
			if(*valor < vetor[m]){
                *numComparacoes = *numComparacoes + 1; 
				
				return buscaBinariaInterna(vetor,ini,m-1,valor,numComparacoes);
		}
			else{
                *numComparacoes = *numComparacoes + 1; 
				return buscaBinariaInterna(vetor,m+1,tam,valor,numComparacoes);
			}
		}	
	}

	return -1;
}
int buscaBinaria(int vetor[], int tam, int valor,long int* numComparacoes){
	int a = 0;

	return buscaBinariaInterna(vetor,a,tam,&valor,numComparacoes);
}

long int inserir(int vetor[], int b){
    int i,j,aux;
	long int numComparacoes = 0;


	for (i = 1; i < b; i++){
		
		aux = vetor[i];
		j = i - 1;

		while (j >= 0 && vetor[j] > aux){
			numComparacoes += 1;
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
    return numComparacoes;  
}

long int insertionSort(int vetor[], int b){	
	long int numComparacoes = 0;
	
	if (0 >= b){
		return 0;
	}
	numComparacoes += insertionSort(vetor,b-1);
	numComparacoes += inserir(vetor,b);


    return numComparacoes;

}

long int selectionSort(int vetor[], int tam){
	long int numComparacoes = 0;
	
	if (tam < 0){
		return 0;
	}

	trocar(vetor,tam,maximo(vetor,tam,&numComparacoes));
	numComparacoes += selectionSort(vetor,tam-1);

	return numComparacoes;
}

int mergeSort(int vetor[], int tam){
	int a = 0;
	
	return mergeSortInterno(vetor,a,tam);
}

long int quickSort(int vetor[], int tam){
	int a = 0;

	return quickSortInterno(vetor,a,tam);
}

void gera_vetor_randomico (int v[], int tam){
    int i;

    srand(time(NULL));
    for (i=0; i<tam; i++){
        v[i] = (unsigned int) (rand() % (tam)); 
	}
	return;
}

void gera_vetor_em_ordem (int v[], int tam){
    int i;

    for (i=0; i<tam; i++){
        v[i] = i; 
	}
}

void embaralha_vetor (int v[], int tam){
    int k, i, j, max_trocas;

    max_trocas = (unsigned int) (rand() % tam) + tam; /* pode modificar */
    for (k=0; k<max_trocas; k++) {
        i = (unsigned int) (rand() % tam);
        j = (unsigned int) (rand() % tam);
        trocar (v,i,j);
    }
}
