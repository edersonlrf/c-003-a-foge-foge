#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

// Ponteiro de ponteiro.
char** mapa;
int linhas;
int colunas;

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    alocamapa();

	int i;
    for(i = 0; i < linhas; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocamapa() {
	// O "malloc()" aloca uma quantidade de bytes e devolve um ponteiro.
	// O "sizeof()" retorna a qtd de bytes para o tipo char nessa maquina.
	mapa = malloc(sizeof(char*) * linhas);

	int i;
	for(i = 0; i < linhas; i++) {
		//mapa[i] = malloc(sizeof(char) * colunas + 1);
	}
}

void liberamapa() {
	int i;
    for(i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    // Cada "malloc()" deve ter um free, se n�o ninguem + usa o espa�o alocado.
    free(mapa);
}

int main() {
	lemapa();
	
	int i;
	for(i = 0; i < 5; i++) {
	    printf("%s\n", mapa[i]);
	}
	
	liberamapa();
}
