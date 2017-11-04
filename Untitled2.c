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
    	char nome[50];
    	char senha[50];
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
  		strcpy(usuarios[i].nome, ch);
  		
//  		usuarios[i].nome = ch;
  		printf("nome : %s ", usuarios[i].nome);
  		ch = strtok(NULL, " ,");
//  		usuarios[i].senha = ch;
		strcpy(usuarios[i].senha, ch);
  		printf("senha : %s", usuarios[i].senha);
  		
  		
//  		int senhaEncriptada = DJBHash(usuarios[i].senha);
//  		
//  		printf("senha encriptada : %d\n", senhaEncriptada);
	}
	
	for (i = 0; i < qtd; i++){
		printf("\ntestando\n");
		printf("nome : %s", usuarios[i].nome);
		printf("\n");
		printf("senha : %s", usuarios[i].senha);
	
	}
	
	char n[10];
	
	printf("insira o numero de tentativas : ");
	fgets(n, 10, stdin); 
	
	int nTentativas = atoi(n);
	
	for (i = 0; i < nTentativas; i++){
		
		char str2[100];
		
		printf("Insira o login e a senha :\n");
		
		fgets(str2, 100, stdin);
    	
    	char *ch1;
  		ch1 = strtok(str2, " ");
  		printf("ch : %s\n", ch1);
  		
  		char str3[50];
  		
  		strcpy(str3, ch1);
  		
  		//verificação de nome
  		
  		int j;
  		int usuarioEncontrado = 0;
  		
  		for (j = 0; j < qtd; j++){
  			
  			printf("comparando ch : %s == %s \n", str3, usuarios[j].nome);
  			
  			if (strcmp (usuarios[j].nome, str3) == 0){
  				usuarioEncontrado = 1;
  				printf("usuario encontrado : %d", usuarioEncontrado);
			}
		}
		
		if (usuarioEncontrado == 0){
			printf("usuario nao encontrado\n");
		}
  		
  		
  		//verificação de senha
//  		ch = strtok(NULL, " ");
//  		usuarios[i].senha = ch;
//  		printf("senha : %s", usuarios[i].senha);
	}
    
    return 0;
}
