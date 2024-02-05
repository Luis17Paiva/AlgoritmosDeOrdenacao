#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

#include "ordenacao.h"

#define MAX_IT 100000
#define NTESTES 30
#define MAX_CHAR_NOME 50

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); 
	char nome[MAX_CHAR_NOME];
	long int numComp = 0;
	long int aux = 0;
	int i, Nalt, tamVetor;
	clock_t start, end;//variáveis do tipo clock_t
    double total;
    int *v = NULL;
    

	v = malloc((MAX_IT+2) * sizeof(int));
	if(v == NULL){
		printf("Falha fatal. Impossível alocar memoria. ");
		return 2;
	}

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
    printf("Numero de testes realizados com os algortimos: %d\n",NTESTES);

    /* Testes com a Busca Sequencial */
    printf("\n");
    printf("----------Testes com a Busca Sequencial---------- \n");
    printf("\n");

    for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
	  total = 0;
        gera_vetor_em_ordem(v,tamVetor);
        aux = 0;
        for (i=0; i<NTESTES; i++) {
            Nalt = (unsigned int) (rand() % tamVetor);
            start = clock();
            buscaSequencial(v,tamVetor,Nalt,&numComp);  /* mede tempo da Busca Sequencial*/
            end = clock();
			aux = aux + numComp;
            total += ((double)end - start)/CLOCKS_PER_SEC;   
            numComp = 0;
       }
        printf("tempo medio da Busca Sequencial para tam = %i : %f\n", tamVetor, total/NTESTES);
		printf("O numero de comparacoes medias da Busca Sequencial eh %li para um vetor de tam %i\n",aux/NTESTES,tamVetor);
    } 

    /* Testes com a Busca Binária */
    printf("\n");
    printf("----------Testes com a Busca BinAria----------\n");
    printf("\n");

	for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
	  total = 0;
        gera_vetor_em_ordem(v,tamVetor);
        aux = 0;
        for (i=0; i<NTESTES; i++) {
            Nalt = (unsigned int) (rand() % tamVetor);
            start = clock();
            buscaBinaria(v,tamVetor,Nalt,&numComp);  /* mede tempo da Busca Binaria */
            end = clock();
			aux = aux + numComp;
            total += ((double)end - start)/CLOCKS_PER_SEC;   
            numComp = 0;
       }
        printf("tempo medio da Busca Binaria para tam = %i : %f\n", tamVetor, total/NTESTES);
		printf("O numero de comparacoes medias da Busca Binaria eh %li para um vetor de tam %i\n",aux/NTESTES,tamVetor);
    } 


	//start = clock();//start recebe o "ciclo" corrente
	//end = clock();//end recebe o "ciclo" corrente
	//total = ((double)end - start)/CLOCKS_PER_SEC;
	//printf("Tempo total: %f", total);

	/* Testes com o QuickSort */
     
	printf("\n");
    printf("----------Testes com o QuickSort----------\n");
    printf("\n");

    aux = 0;
	for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
	  total = 0;
        gera_vetor_randomico(v,tamVetor);
        for (i=0; i<NTESTES; i++) {
            embaralha_vetor (v,tamVetor); 
            start = clock();
            aux = aux + quickSort(v,tamVetor-1);  /* mede tempo so do quicksort */
            end = clock();
            total += ((double)end - start)/CLOCKS_PER_SEC;   
       }
        printf("tempo medio do quicksort para tam = %i : %f\n", tamVetor, total/NTESTES);
		printf("O numero de Comparacoes medias do QuickSort eh %ld para um vetor de tam %i\n",aux/NTESTES,tamVetor);
        aux = 0;
    } 

    /* Testes com o MergeSort */
    printf("\n");
    printf("----------Testes com o MergeSort----------\n");
    printf("\n");

    for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
        total = 0;
        aux = 0;
        gera_vetor_randomico (v,tamVetor);
        for (i=0; i<NTESTES; i++) {
			embaralha_vetor (v,tamVetor); 
            start = clock();
            aux = aux + mergeSort(v,tamVetor-1);  /* mede tempo so do mergesort */
            end = clock(); 
            total += ((double)end - start)/CLOCKS_PER_SEC;
        }
        printf("tempo medio do mergesort para tam = %i : %f\n", tamVetor, total/NTESTES);
		printf("O numero de Comparacoes medias do mergeSort e %li para um vetor de tam %i\n",aux/NTESTES,tamVetor);
    }

    /* Testes com o InsertionSort */
    printf("\n");
    printf("----------Testes com o InsertionSort----------\n");
    printf("\n");
    
    for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
        total = 0;
        aux = 0;
        gera_vetor_randomico (v,tamVetor);
        for (i=0; i<NTESTES; i++) {
			embaralha_vetor (v,tamVetor); 
            start = clock();
            aux = aux + insertionSort(v,tamVetor-1);  /* mede tempo so do insertionsort */
            end = clock(); 
            total += ((double)end - start)/CLOCKS_PER_SEC;;
        }
    	 printf("tempo medio do insertionsort para tam = %i : %f\n", tamVetor, total/NTESTES);
		 printf("O numero de Comparacoes medias do insertionSort eh %li para um vetor de tam %i\n",aux/NTESTES,tamVetor);
    }
    
    /* Testes com o SelectionSort */
    printf("\n");
    printf("----------Testes com o SelectionSort----------\n");
    printf("\n");

    for (tamVetor = 100; tamVetor < MAX_IT-1; tamVetor = tamVetor * 10){
        total = 0;
        aux = 0;
        gera_vetor_randomico (v,tamVetor);
        for (i=0; i<NTESTES; i++) {
			embaralha_vetor (v,tamVetor); 
            start = clock();
            aux = aux + selectionSort(v,tamVetor-1);  /* mede tempo so do selectionsort */
            end = clock(); 
            total += ((double)end - start)/CLOCKS_PER_SEC;;
        }
    	 printf("tempo medio do selectionSort para um vetor de tamanho %i eh %f\n", tamVetor, total/NTESTES);
         printf("O numero de Comparacoes medias do selectionSort eh %li para um vetor de tam %i\n",aux/NTESTES,tamVetor);
    }
    printf("\n"); 	
	
	free(v);

	return 0;
}
