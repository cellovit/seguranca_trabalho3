#include <stdio.h>

int main()
{
		struct user{
    	char* nome;
    	char* senha;
	};

	char qtdUsuarios[10];	
	int i = 0;
	
    printf("Insira a quantidade de usuarios : ");
	fgets(qtdUsuarios, 10, stdin); 
	
	int qtd = atoi(qtdUsuarios);
	
	struct user usuarios[qtd]; 
	
	printf("\nInsira o nome e a senha dos usuarios:\n ");
	
	for (i = 0; i < qtd; i++){
		char str1[100];    
    	fgets(str1, 100, stdin);
    	
    	char *ch;
  		ch = strtok(str1, " ");
  		usuarios[i].nome = ch;
  		printf("nome : %s", usuarios[i].nome);
  		ch = strtok(NULL, " ");
  		usuarios[i].senha = ch;
  		printf("senha : %s", usuarios[i].senha);
	}
    
    return 0;
}
