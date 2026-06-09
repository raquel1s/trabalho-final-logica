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
    int choice;
    do
    {
        menu_print();
        switch (choice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
        
            break;
        default:
            system("cls");
            for(int i = 0;i < 5;i++){
                printf("ERRO -scolha invalida");
                Sleep(1000);
            }
            break;
        }
    } while (choice != 5);
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
	system("cls");
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

void listar_contatos(void){
	for(int i=0; i<qnt_contatos; i++){
		printf("\n==============================");
		printf("%i Contato:\n", i+1)
		printf("Nome: %s", lista_contatos[i].nome);
		printf("Telefone: %s", lista_contatos[i].telefone);
		printf("===============================\n");
	}
}