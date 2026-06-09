#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
	char nome[50];
	char telefone[20];
} Contato;

void menu_print(void);
Contato incluir_contato(void);
void listar_contatos(void);
void consultar_contato_nome(void);
void excluir_contato(void);

Contato lista_contatos[MAX];

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
                sleep(1000);
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