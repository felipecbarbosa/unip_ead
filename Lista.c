#include<stdio.h>
#include<stdlib.h>
#include<conio.h>	// Para getch()
typedef struct Livro{
	char Titulo[30];
	char Autor[30];
	int NumReg;
	double Preco;
	struct Livro *Proximo;
	}Livro;
	Livro *primeiro, *atual, *NovoLivro;
	void GetLivro(){
		char temp[80];
		NovoLivro=(Livro *)malloc(sizeof(Livro));
		if(primeiro==(Livro *)NULL)
			primeiro=atual=NovoLivro;
		else
			{
				atual=primeiro;
				while(atual->Proximo !=(Livro *)NULL)
				atual=atual->Proximo;
				atual->Proximo=NovoLivro;
				atual=NovoLivro; 
			}
			printf("Digite titulo : ");
			gets(atual->Titulo);
			printf("Digite Autor : ");
			gets(atual->Autor);
			printf("Digite o numero do registro : ");
			gets(temp);
			atual->NumReg=atoi(temp);
			printf("Digite o preco : ");
			gets(temp);
			atual->Preco=atof(temp);
			atual->Proximo=(Livro *)NULL;
	}
	
	void PrintLivro(){
		if (primeiro==(Livro *)NULL){
		puts("Lista VAZIA");
		return;
		}
		atual=primeiro;
		do{
			printf("Titulo : %s\n",atual->Titulo);
			printf("Autor : %s\n",atual->Autor);
			printf("Numero do Registro : %d\n",atual->NumReg);
			printf("Preco : %.2f\n\n",atual->Preco);
			atual=atual->Proximo;
		}while(atual != NULL);
	}
int main(){			//Criando lista ligada
	char ch;
	primeiro=(Livro *)NULL;
	do{
		GetLivro();
		puts("\nInserir outro livro(s/n?) ");
		ch=getch();
	}while((ch!='n') && (ch!='N'));
	puts("\nLista dos Livros Cadastrados");
	puts("=================================");
	PrintLivro();
	system("PAUSE");
	return 0;
}
