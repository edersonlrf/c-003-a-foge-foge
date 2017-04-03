// Declaracao de uma struct para agrupar variaveis que sempre estao juntas.
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

// Da um novo nome ao tipo, n�o sendo necessario usar "struct mapa m;".
typedef struct mapa MAPA;

void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
