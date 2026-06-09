#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void menu_print(void);
Contato incluir_contato(void);
void listar_contatos(void);
void consultar_contato_nome(void);
void excluir_contato(void);

typedef struct {
	char nome[50];
	char telefone[20];
} Contato;

Contato lista_contatos[MAX];

int main() {
	
    return 0;
}