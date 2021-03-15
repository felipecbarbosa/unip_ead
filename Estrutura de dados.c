#include <stdio.h>
#include <stdlib.h>
struct Aluno{ // cria registro aluno
	int ra;
	float nota [3];
	float media;
};
int main(){
	struct Aluno Pedro;
	Pedro.ra=1234;
	Pedro.nota[0]=6.5;
	Pedro.nota[1]=5.5;
	Pedro.nota[2]=8.5;
	Pedro.nota[3]=8.0;
	Pedro.media=(Pedro.nota[0]+Pedro.nota[1]+Pedro.nota[2]+Pedro.nota[3])/4;
	printf("RA :  %d\n",Pedro.ra);
	printf("Media :%.2f\n",Pedro.media);
	printf("\n");
	printf("\n");
	system("PAUSE");
	return 0;
}
