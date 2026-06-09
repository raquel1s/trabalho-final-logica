#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	char nome[50];
	char telefone[20];
} Contato;

void menu_print(void);
void incluir_contato(void);
void listar_contatos(void);
void consultar_contato_nome(void);
void excluir_contato(void);

Contato lista_contatos[MAX];
int qnt_contatos = 0;

int main() {
    return 0;
}

void menu_print(void){
    system("cls");
    printf("=========MENU=========\n\n");
    printf("[1] INCLUIR CONTATO\n");
    printf("[2] LISTA DE CONTATOS\n");
    printf("[3] CONSULTAR CONTATO PELO NOME\n");
    printf("[4] EXCLUIR CONTATO\n");
    printf("[5] SAIR\n");
}

void incluir_contato(void){
	system(cls);
	printf("=========INCLUIR USUARIO=========\n\n");
	
	if(qnt_contatos < MAX){
		printf("Digite o nome do contato: ");
		fgets(lista_contatos[qnt_contatos].nome, 50, stdin);
		
		printf("Digite o telefone do contato: ");
		fgets(lista_contatos[qnt_contatos].telefone, 20, stdin);
		
		qnt_contatos++;
		printf("\nContato salvo com sucesso!");
	}else{
		printf("\nAgenda lotada!");
	}	
}