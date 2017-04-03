// Constantes.
#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'

// Declaracao de uma struct para agrupar variaveis que sempre estao juntas.
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

struct posicao {
    int x;
    int y;
};

// Da um apelido para o tipo, n�o sendo necessario usar "struct mapa" e sim "MAPA".
typedef struct mapa MAPA;

typedef struct posicao POSICAO;

// Somente agora declarar as funcoes.
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
int ehvalida(MAPA* m, int x, int y);
int ehparede(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int encontramapa(MAPA* m, POSICAO* p, char c);
