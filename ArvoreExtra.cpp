#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no
{
	int info;
	struct no *esq, *dir;
};
typedef struct no Arvore;

Arvore * cria_arv_vazia(void)
{
	return NULL;
}

Arvore * cria_arv (int x, Arvore* sae, Arvore* sad)
{
	Arvore * r;
	r = (Arvore *)malloc(sizeof(Arvore));
	r -> info = x;
	r -> esq = sae;
	r -> dir = sad;
	return r;
}

void mostrar_arv_pre(Arvore* r)
{
	if(r != NULL)
	{
		printf("\n%d\n", r -> info);
		mostrar_arv_pre(r -> esq);
		mostrar_arv_pre(r -> dir);
	}
}

void mostrar_arv_in(Arvore * r)
{
	if(r != NULL)
	{
		mostrar_arv_pre(r -> esq);
		printf("\n%d\n", r -> info);
		mostrar_arv_pre(r -> dir);
	}
}

void mostrar_arv_pos(Arvore* r)
{
	if(r != NULL)
	{
		mostrar_arv_pre(r -> esq);
		mostrar_arv_pre(r -> dir);
		printf("\n%d\n", r -> info);
	}
}

Arvore * libera_arv(Arvore *r)
{
	if(r != NULL)
	{
		libera_arv(r -> esq);
		libera_arv(r -> dir);
		free(r);
	}
	return NULL;
}

Arvore * remover_no(Arvore *r)
{
	if(r != NULL)
	{
		r -> esq -> dir = libera_arv(r -> esq -> dir);
	}else
	{
		printf("\nNão ha no para remover!\n");
	}
	return r;
}

int busca_arv(Arvore *r, int x){
    if(r == NULL){
        return 0;
    }else{
        return (r->info == x  || busca_arv(r->esq, x) || busca_arv(r->dir, x));
    }
}

int main()
{
	Arvore * r, * r1, * r2, * r3, * r4, * r5;
	int valor, menu, remove;
	char op;
	
	r = cria_arv_vazia();
	
	r1 = cria_arv(3, cria_arv(10, cria_arv_vazia(), cria_arv_vazia()), cria_arv(17, cria_arv_vazia(), cria_arv_vazia()));
	r2 = cria_arv(1, cria_arv(4, cria_arv_vazia(), cria_arv_vazia()), r1);
	r3 = cria_arv(8, cria_arv_vazia(), cria_arv(25, cria_arv(22, cria_arv_vazia(), cria_arv_vazia()), cria_arv_vazia()));
	r4 = cria_arv(5, r3, cria_arv(2, cria_arv_vazia(), cria_arv_vazia()));
	r = cria_arv(7, r2, r4);
	
	do
	{
		printf("\n1 - Mostrar Pre-Ordem\n2 - Mostrar In-Ordem\n3 - Mostrar Pos-Ordem\n4 - Acrescentar a subarvore abaixo do numero 2\n5 - Remover o numero 3 da sua subarvore\n6 - Buscar elemento na Arvore\n");
		
		scanf("%d", &menu);
		printf("\n-------\n");
		
		switch (menu)
		{
			case 1:
				mostrar_arv_pre(r);
				break;
			
			case 2:
				mostrar_arv_in(r);
				break;
			
			case 3:
				mostrar_arv_pos(r);
				break;
			
			case 4:
				r -> dir -> dir -> esq = cria_arv(6, cria_arv(12, cria_arv_vazia(), cria_arv_vazia()), cria_arv(9, cria_arv_vazia(), cria_arv_vazia()));
				break;
			
			case 5:
				r = remover_no(r);
				break;
			
			case 6:
				printf("\nDigite o valor para buscar na Arvore\n");
                scanf("%d", &valor);
                remove = busca_arv(r, valor);
                if (remove == 0) {
                    printf("\nValor nao encontrado!\n");
                } else {
                    printf("\nValor encontrado na arvore!");
                }
                break;
			default:
				printf("\nOpcao invalida!\n");
				break;
		}
		
		printf("\nFazer outra operacao? (S/N)\n");
		scanf(" %c", &op);
	}while ((op == 's') || (op == 'S'));
	
	return 0;
}

