#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned int DJBHash(unsigned char* str) {
	unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

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
  		printf("nome : %s ", usuarios[i].nome);
  		ch = strtok(NULL, " ");
  		usuarios[i].senha = ch;
  		printf("senha : %s", usuarios[i].senha);
  		
  		int senhaEncriptada = DJBHash(usuarios[i].senha);
  		
  		printf("senha encriptada : %d\n", senhaEncriptada);
	}
    
    return 0;
}
