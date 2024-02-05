#include <stdlib.h>
#include <stdio.h>

void iniciliza_tabuleiro(int v[8][8], int n){
	int i,j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			v[i][j] = 0;
		}
	}

	return;
}

void imprime_tabuleiro(int v[8][8], int n){
	int i,j;

	for (i = 0; i < n; i++){
		printf("\n");
		for (j = 0; j < n; j++){
			if(v[i][j] == 1){
				printf("R ");
			}else{
				printf("- ");
			}
		}
	}
	printf("\n");
	return;
}

int possivel(int v[8][8], int n, int l, int c){
	int i,j;

	/*Verifica se tem uma rainha na mesma coluna*/
	for (i = 0; i < n; i++){

		if (v[i][c] == 1){
			return 0;
		}
	}


	for (i = l, j = c; i >= 0 && j >= 0; i--,j--){

		if (v[i][j] == 1){
			return 0;
		}
	}

	for (i = l, j = c; i >= 0 && j < n; i--,j++){

		if (v[i][j] == 1){
			return 0;
		}
	}

	return 1;

}


int resolve(int tab[8][8], int n, int l, int c){
	int i;

	if (l == n){
		printf("SOLUÇÃO ENCONTRADA \n");
		imprime_tabuleiro(tab,n);
    return 1;

	}

	for (i = 0; (c+i) < n; i++){

		if (possivel(tab,n,l,(c+i)) == 1){

			tab[l][c+i] = 1;
			resolve(tab,n,l+1,0);
			tab[l][c+i] = 0;
		}
	}

	return 0;

}

int main(){
	int n = 8;
	int v[8][8];

	iniciliza_tabuleiro(v,n);
	resolve(v,n,0,0);

	return 0;

}