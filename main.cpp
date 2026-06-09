#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

typedef struct {
	char nome[50];
	char telefone[20];
} Contato;

void menu_print(void);
void incluir_contato(void);
void listar_contatos(void);
void identificar_por_nome(void);
void excluir_contato(void);

Contato lista_contatos[MAX];
int qnt_contatos = 0;

int main() {
    int choice;
    do
    {
        menu_print();
        printf("Oque deseja fazer: ");
        scanf("%i",&choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
			incluir_contato();
            break;
        case 2:
			listar_contatos();
            break;
        case 3:
			identificar_por_nome();
            break;
        case 4:
        
            break;
        default:
            system("cls");
            for(int i = 0;i < 3;i++){
                printf("ERRO -scolha invalida");
                sleep(1);
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
	printf("\nPressione enter para voltar");
	getchar();
}

void listar_contatos(void){
	system("cls");
	for(int i=0; i<qnt_contatos; i++){
		printf("\n==============================");
		printf("\n%i Contato:\n", i+1);
		printf("Nome: %s", lista_contatos[i].nome);
		printf("Telefone: %s", lista_contatos[i].telefone);
		printf("===============================\n");
	}
	printf("\nPressione enter para voltar");
	getchar();
}

void identificar_por_nome(){
    char nome_procura[50];

    printf("Qual nome quer procurar: ");
    fgets(nome_procura, 50, stdin);
    for(int i=0; i<qnt_contatos; i++){
        if(strcmp(nome_procura,lista_contatos[i].nome) == 0){
            printf("\n==============================");
            printf("\n%i Contato:\n", i+1);
            printf("Nome: %s", lista_contatos[i].nome);
            printf("Telefone: %s", lista_contatos[i].telefone);
            printf("===============================\n");
        }
	}
	printf("\nPressione enter para voltar");
	getchar();
}