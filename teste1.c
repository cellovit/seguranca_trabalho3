#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

unsigned int DJBHash(unsigned char* str) {
	unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void int64ToChar(char mesg[], int64_t num) {
  for(int i = 0; i < 8; i++) mesg[i] = num >> (8-1-i)*8;
}

int64_t charTo64bitNum(char a[]) {
  int64_t n = 0;
  n = (((int64_t)a[0] << 56) & 0xFF00000000000000U)
    | (((int64_t)a[1] << 48) & 0x00FF000000000000U)
    | (((int64_t)a[2] << 40) & 0x0000FF0000000000U)
    | (((int64_t)a[3] << 32) & 0x000000FF00000000U)
    | ((a[4] << 24) & 0x00000000FF000000U)
    | ((a[5] << 16) & 0x0000000000FF0000U)
    | ((a[6] <<  8) & 0x000000000000FF00U)
    | (a[7]        & 0x00000000000000FFU);
  return n;
}

int main()
{
	struct user{
    	char nome[50];
    	uint64_t senha;
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
  		
  		printf("nome : %s ", usuarios[i].nome);
  		ch = strtok(NULL, " ,");

	
		// strcpy(usuarios[i].senha, ch);
		
		char senha1[50];
		strcpy(senha1, ch);	
  		
  		uint64_t p = charTo64bitNum(senha1);
  		
  		usuarios[i].senha = p;
  		
		// int senhaEncriptada = DJBHash(senha1);
		
		// itoa(senhaEncriptada, usuarios[i].senha, 10);
		
  		printf("senha salva: %s", usuarios[i].senha);
  		
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
  		printf("ch NOME : %s\n", ch1);  		
  		
  		char str3[50];
  		char str4[50];
  		
  		// str 3 = nome a comparar
  		
  		strcpy(str3, ch1);
  		
  		// str 4 = senha a comparar
  		
  		ch1 = strtok(NULL, " ");
  		printf("ch SENHA : %s\n", ch1);  	
  		strcpy(str4, ch1);
  		
  		//verificação de nome
  		
  		int j;
  		int usuarioEncontrado = 0;
  		
  		for (j = 0; j < qtd; j++){
  			
  			// printf("comparando ch : %s == %s \n", str3, usuarios[j].nome);
  			
  			if (strcmp (usuarios[j].nome, str3) == 0){
  				usuarioEncontrado = 1;
  				// printf("usuario encontrado : %d", usuarioEncontrado);
			}
		}
		
		if (usuarioEncontrado == 0){
			printf("usuario nao encontrado\n");
			break;
		}
  		
  		
  		//verificação de senha
  		
  		for (j = 0; j < qtd; j++){
  			
  			int senhaEncriptada = DJBHash(ch1);
  			char senha1[50];
			itoa(senhaEncriptada, senha1, 10);
  			
  			printf("comparando ch : %d == %s \n", senhaEncriptada, usuarios[j].senha);
  			
  			if (strcmp (usuarios[j].senha, senha1) == 0){
  				printf("senha igual");
			}
		}
  		
//  		ch = strtok(NULL, " ");
//  		usuarios[i].senha = ch;
//  		printf("senha : %s", usuarios[i].senha);
	}
    
    return 0;
}
