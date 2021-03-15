#include<stdio.h>
#include<stdlib.h>
int main(){
	int *pi;  	// Criando uma variável dinâmica
	pi=(int *) malloc(sizeof(int));
	puts("Digite um numero : ");
	scanf("%d",pi);
	printf("\nVoce digitou o numero %d\n",*pi);
	free(pi);
	printf("\n");
	printf("\n");
	system("PAUSE");
	return 0;
}
