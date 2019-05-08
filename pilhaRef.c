#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct no
{
	float info;
	struct no* prox;
};
typedef struct no No;

struct pilha
{
	No* prim;
};
typedef struct pilha Pilha;

Pilha* cria (void);
void push (Pilha* p, float v);
float pop (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);

Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

No* ins_ini (No* l, float v) {
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

No* ret_ini (No* l) {
	No* p = l->prox;
	free(l);
	return p;
}

int vazia (Pilha* p)
{
	return (p->prim == NULL);
}

void libera (Pilha* p)
{
	No* q = p->prim;
	while (q != NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void imprime (Pilha* p) {
	No* q;
	for (q=p->prim; q != NULL; q=q->prox)
		printf("%f\n", q->info);
}

void push (Pilha* p, float v)
{
	p->prim = ins_ini(p->prim, v);
}

float pop (Pilha* p) 
{
	float v;
	if (vazia(p)) {
		printf("A pilha esta' vazia\n");
		exit(1);
	}

	// Retira o elemento do topo
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}

int main()
{
	float ultimoElemento;

	// Cria uma pilha
	Pilha* stack;
	stack = cria();

	// Preenche valores na pilha
	for (int i = 0; i < 50; ++i)
	{
		push(stack, (i * 2.2));
	}

	// Armazena o ultimo elemento
	ultimoElemento = pop(stack);

	// Imprime a pilha
	printf("Impressão da Pilha:\n");
	imprime(stack);

	printf("\nUltimo elemento removido: %.2f\n", ultimoElemento);

	libera(stack);

	if(vazia(stack)) {
		printf("\n\n\n\nLiberou a pilha.\n");
	}

	return 0;
}