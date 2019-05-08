#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct pilha
{
	int n;
	float vet[MAX];
};

typedef struct pilha Pilha;


Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0;
	return p;
}

int vazia (Pilha* p)
{
	return (p->n == 0);
}

void libera (Pilha* p)
{
	free(p);
}

void push (Pilha* p, float v)
{
	if (p->n == MAX) {
		printf("Capacidade da pilha estourou.\n");
		exit(1);
	}

	// Insere o elemento na proxima posição livre
	p->vet[p->n] = v;
	p->n++;
}

float pop (Pilha* p) 
{
	float v;
	if (vazia(p)) {
		printf("A pilha esta' vazia\n");
		exit(1);
	}

	// Retira o elemento do topo
	v = p->vet[p->n-1];
	p->n--;
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
	for (int i = 0; i < 50; ++i)
	{	
		printf("Posicao %d: %.2f\n", i + 1, stack->vet[i]);
	}

	printf("\nUltimo elemento: %.2f\n", ultimoElemento);

	libera(stack);

	if(vazia(stack)) {
		printf("\n\n\n\nLiberou a pilha.\n");
	}

	return 0;
}