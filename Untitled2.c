#include <stdio.h>

int main()
{
		struct user{
    	char nome[20];
    	char senha[6];
	};

	char qtdUsuarios[10];	
	
    printf("Insira a quantidade de usuarios : ");
	fgets(qtdUsuarios, 10, stdin); 
	
	int qtd = atoi(qtdUsuarios);
	
	struct user usuarios[qtd]; 
	
    char name[100];
    printf("\nEnter your name:\n ");
    fgets(name, 100, stdin); 
    printf("Your Name is: %s", name);
    return 0;
}
