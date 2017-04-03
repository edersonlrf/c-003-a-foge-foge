#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

// struct mapa m;
MAPA m;
POSICAO heroi;

int acabou() {
    return 0;
}

void move(char direcao) {
    // O "return" sozinho geralmente � usado para finalizar metodos void.
	if (!ehdirecao(direcao))
        return;
	
	int proximox = heroi.x;
    int proximoy = heroi.y;

	// Determina o movimento do pj.
    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }
	    
    // Verifica se vai sair da matriz e nao deixa.
    if (!ehvalida(&m, proximox, proximoy))
    	return;

	// Verifica se a proxima posicao � vazia.
	if (!ehvazia(&m, proximox, proximoy))
    	return; 
    	
    // Aplica o movimento.
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

int ehdirecao(char direcao) {
	// S� aceita estas teclas.
    return
        direcao == ESQUERDA || 
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
}

void fantasmas() {
	MAPA copia;

    copiamapa(&copia, &m);
    
	int i, j;
    for(i = 0; i < copia.linhas; i++) {
        for(j = 0; j < copia.colunas; j++) {
            if (copia.matriz[i][j] == FANTASMA) {
                if (ehvalida(&m, i, j+1) && ehvazia(&m, i, j+1)) {
                    andanomapa(&m, i, j, i, j+1);
                }
            }
        }
    }

    liberamapa(&copia);
}

int main() {
	lemapa(&m);
	
	encontramapa(&m, &heroi, HEROI);
	
	do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        move(comando);
        fantasmas();
    } while (!acabou());
	
	liberamapa(&m);
}
