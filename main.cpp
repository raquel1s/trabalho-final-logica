#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
void carregar_dados(void);
void salvar_dados(void);

Contato lista_contatos[MAX];
int qnt_contatos = 0;

int main() {
    int choice;
	carregar_dados();
    do
    {
        menu_print();
        printf("Escolha uma opcao: ");
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
            excluir_contato();
            break;
        case 5:
			salvar_dados();
            system("cls");
            for(int i = 0;i<10;i++) printf("====================ADEUS====================\n");
            break;
        default:
            system("cls");
            for(int i = 0;i < 10;i++) printf("====================ERRO - escolha invalida====================\n");
			Sleep(1000);
            break;
        }
    } while (choice != 5);
    return 0;
}

void salvar_dados(void){
	FILE *dd;
	dd = fopen("dados.txt","w");
	if(dd == NULL) return;

	for(int i = 0; i < qnt_contatos; i++){
		char name[50];
		char tel[20];

		strcpy(name, lista_contatos[i].nome);
		strcpy(tel, lista_contatos[i].telefone);
		name[strcspn(name, "\n")] = '\0';
		tel[strcspn(tel,"\n")] = '\0';
		fprintf(dd,"%s\n%s\n",name,tel);
	}
	fclose(dd);
}

void carregar_dados(void){
	FILE *dd;
	dd = fopen("dados.txt","r");
	if(dd == NULL) return;

	for(qnt_contatos = 0; qnt_contatos < MAX;qnt_contatos++){
		if(fgets(lista_contatos[qnt_contatos].nome,50,dd) == NULL) break;;
		if(fgets(lista_contatos[qnt_contatos].telefone,20,dd) == NULL) break;;
	}
	fclose(dd);
	for(int i = 0; i < 10; i++) printf("====================DADOS CARREGADOS====================\n");
	Sleep(1000);
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

		if(lista_contatos[qnt_contatos].nome[0] == '\n'){
    		printf("Nome nao pode ser vazio!\n");
    		getchar();
    		return;
		}
		
		printf("Digite o telefone do contato: ");
		fgets(lista_contatos[qnt_contatos].telefone, 20, stdin);

		if(lista_contatos[qnt_contatos].telefone[0] == '\n'){
    		printf("Telefone nao pode ser vazio!\n");
    		getchar();
    		return;
		}
		
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
	
	if(qnt_contatos != 0){
		printf("=========AGENDA=========\n");
		for(int i=0; i<qnt_contatos; i++){
			printf("\n==============================");
			printf("\n%i Contato:\n", i+1);
			printf("Nome: %s", lista_contatos[i].nome);
			printf("Telefone: %s", lista_contatos[i].telefone);
			printf("===============================\n");
		}
	}else{
		printf("Agenda vazia!");
	}
	printf("\nPressione enter para voltar");
	getchar();
}

void identificar_por_nome(){
    system("cls");
    char nome_procura[50];
    int encontrou = 0;
    
    printf("=========PROCURAR USUARIO=========\n\n");
    printf("Qual nome quer procurar: ");
    fgets(nome_procura, 50, stdin);
    for(int i=0; i<qnt_contatos; i++){
        if(strcmp(nome_procura,lista_contatos[i].nome) == 0){
            printf("\n==============================");
            printf("\n%i Contato:\n", i+1);
            printf("Nome: %s", lista_contatos[i].nome);
            printf("Telefone: %s", lista_contatos[i].telefone);
            printf("===============================\n");
            encontrou = 1;
        }
	}
	
	if(!encontrou){
		printf("Contato nao encontrado!");
	}
	
	printf("\nPressione enter para voltar");
	getchar();
}

void excluir_contato(){
    system("cls");
    char nome_procura[50];
    int encontrou = 0;
    
    printf("=========EXCLUIR USUARIO=========\n\n");
    printf("Digite nome de quem deseja excluir: ");
    fgets(nome_procura, 50, stdin);
    
    for(int i=0; i<qnt_contatos; i++){
        if(strcmp(nome_procura,lista_contatos[i].nome) == 0){
            for(int j=i; j<qnt_contatos-1; j++){
            	lista_contatos[j] = lista_contatos[j+1];
			}
			qnt_contatos--;
			encontrou = 1;
			break;
        }
	}
	
	if(encontrou){
		printf("Contato excluido com sucesso!");
	}else{
		printf("Contato nao encontrado!");
	}
	
	printf("\nPressione enter para voltar");
	getchar();
}