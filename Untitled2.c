#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uint64_t DJBHash(unsigned char* str) {
	uint64_t hash = 5381;
    uint64_t c = *(str); //primeiro caractere

    while (c){
    	hash = ((hash << 5) + hash) + c;  /* hash * 33 + c */
    	c = *(++str);
	}        

    return hash;
}

int main()
{
	struct user{
    	char nome[20];
    	uint64_t senha;
	};

	char qtdUsuarios[10];
	int i = 0;
	
    printf("Insira a quantidade de usuarios : ");
	fgets(qtdUsuarios, 10, stdin); 
	
	int qtd = atoi(qtdUsuarios);
	
	struct user usuarios[qtd]; 
	
//	printf("\nInsira o nome e a senha dos usuarios:\n ");
	
	for (i = 0; i < qtd; i++){
//		char str1[100];    
//    	fgets(str1, 100, stdin);
//    	
//    	char *ch;
//  		ch = strtok(str1, " ");
//  		strcpy(usuarios[i].nome, ch);
//  		
//  		printf("nome : %s ", usuarios[i].nome);
//  		ch = strtok(NULL, " ,");
  		
  		
  		//RESOLVER SE VAI PEGAR A SENHA SEPARADA OU NA MESMA STRING
  		
//		char senha1[50];
//		strcpy(senha1, ch);
//		
		// usuarios[i].senha = charTo64bitNum(senha1);
//		usuarios[i].senha = (uint64_t) senha1;
		
		printf("insira o nome do usuario : ");
		scanf("%s", &usuarios[i].nome);
		
		printf("insira a senha do usuario : ");
		scanf("%"SCNu64, &usuarios[i].senha);
//		
		// usuarios[i].senha = convert(ch);
		
		printf("senha salva: ");
		printf("%" PRIu64 "\n", usuarios[i].senha); 		
  		
	}
	
//	for (i = 0; i < qtd; i++){
//		printf("\ntestando\n");
//		printf("nome : %s", usuarios[i].nome);
//		printf("\n");
//		printf("senha : %s", usuarios[i].senha);
//	
//	}
	
	int nTentativas;
	
	printf("insira o numero de tentativas : ");
	scanf("%d", &nTentativas);
	
	fflush(stdin);
	
	for (i = 0; i < nTentativas; i++){
		
//		char str2[100];
//		
//		printf("Insira o login e a senha :\n");
//		
//		fgets(str2, 100, stdin);
//    	
//    	char *ch1;
//  		ch1 = strtok(str2, " ");
//  		printf("ch NOME : %s\n", ch1);  		
//  		
//  		char str3[100];
//  		char str4[100];
//  		
//  		// str 3 = nome a comparar
//  		
//  		strcpy(str3, ch1);
  		
  		// str 4 = senha a comparar
  		
//  		ch1 = strtok(NULL, " ");
//  		printf("ch SENHA : %s\n", ch1);  	
//  		strcpy(str4, ch1);

		char login[20];
		printf("insira o login : ");
		scanf("%s", &login);
		
		char senha[20];
		printf("insira a senha : ");
		scanf("%s", &senha);

  		//verificação de nome
  		
  		int j;
  		int usuarioEncontrado = 0;
  		
  		for (j = 0; j < qtd; j++){
  			
  			// printf("comparando ch : %s == %s \n", str3, usuarios[j].nome);
  			
  			int indiceUsuarioEncontrado = -1;
  			
  			if (strcmp (usuarios[j].nome, login) == 0){
  				usuarioEncontrado = 1;
  				
  				indiceUsuarioEncontrado = j;
  				// printf("usuario encontrado : %d", usuarioEncontrado);
			}
			
			if (usuarioEncontrado == 1){
				
				uint64_t senha1 = DJBHash(senha);
				printf("senha1: ");
				printf("%" PRIu64 "\n", senha1);
			
				if (senha1 == usuarios[indiceUsuarioEncontrado].senha) {
					
					printf("usuarios[indiceUsuarioEncontrado].senha : ");
					printf("%" PRIu64 "\n", usuarios[indiceUsuarioEncontrado].senha);
					
					printf("login aceito\n");
					break;
				}else{
					
					printf("usuarios[indiceUsuarioEncontrado].senha : ");
					printf("%" PRIu64 "\n", usuarios[indiceUsuarioEncontrado].senha);
					
					printf("login recusado\n");
					break;
				}
			}else{
				printf("usuario nao encontrado\n");
				break;
			}
			
			 
		}
		
//		if (usuarioEncontrado == 0){
//			printf("usuario nao encontrado\n");
//			break;
//		}
  		
  		
  		//verificação de senha
  		
  				
//		uint64_t senha1;
//		printf("insira a senha");
//		scanf("%"SCNu64, &senha1);
  		
  		
//  		for (j = 0; j < qtd; j++){
  			
//  			int senhaEncriptada = DJBHash(ch1);
//  			char senha1[50];
//			itoa(senhaEncriptada, senha1, 10);
  			
  			// printf("comparando ch : %d == %s \n", senhaEncriptada, usuarios[j].senha);
  			
//  			printf("usuarios[j].senha: ");
//			printf("%" PRIu64 "\n", usuarios[j].senha);
//  			
//  			printf("senha1: ");
//			printf("%" PRIu64 "\n", senha1);

				
//			
//		}
  		
	}
    
    return 0;
}
