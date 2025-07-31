#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int mystrien(char *);
void mystrcpy(char *, char *);
int mystrcmp(char *, char *);

int mystrien(char *s){
	int cont;
	for(cont=0; *s!='\0'; cont++, s++);
	return cont++;
}
void mystrcpy(char *s1, char *s2){
	for( ; *s2!= '\0'; s1++, s2++)
		*s1 = *s2;
	*s1 = '\0';
}	
int mystrcmp(char *s1, char *s2){
	
	while(*s1!='\0' && *s2 !='\0' && *s1==*s2){
		s1++;
		s2++;
	}
	return ((*s1)-(*s2));
}
int main(int argc, char *argv[]) {
	int x;
	char s2[] = "amor";
	char s1[] = "amar";
	/*printf("%d letras\n", mystrien(s2));
	printf("s1 antes: %s\n", s1);
	mystrcpy(s1,s2);
	printf("s1 depois; %s\n", s1);*/
	
	x = mystrcmp(s2, s1);
	printf("x = %d\n", x );
	if(x<0){
		printf("%s %s ", s2, s1);
	}else if(x==0){
		printf("\n sao iguais");
	}else{
		printf("%s %s", s1, s2);
	}


	return 0;
	system("pause");
	
}
