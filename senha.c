#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uint64_t DJBHash(unsigned char* str) {
	uint64_t hash = 5381;
    uint64_t c;

    while (c = *str++){
    	hash = ((hash << 5) + hash) + c;  /* hash * 33 + c */
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

		printf("insira o nome do usuario : ");
		scanf("%s", &usuarios[i].nome);
		
		printf("insira a senha do usuario : ");
		scanf("%"SCNu64, &usuarios[i].senha);

	}
	
	int nTentativas;
	
	printf("insira o numero de tentativas : ");
	scanf("%d", &nTentativas);
	
	for (i = 0; i < nTentativas; i++){

		char login[20];
		printf("insira o login : ");
		scanf("%s", &login);
		
		char senha[20];
		printf("insira a senha : ");
		scanf("%s", &senha);

  		int j;
  		int usuarioEncontrado = 0;
  		
  		for (j = 0; j < qtd; j++){
  			int indiceUsuarioEncontrado = -1;
  			
  			if (strcmp (usuarios[j].nome, login) == 0){
  				usuarioEncontrado = 1;
  				
  				indiceUsuarioEncontrado = j;
			}
			
			if (usuarioEncontrado == 1){
				
				uint64_t senha1 = DJBHash(senha);
			
				if (senha1 == usuarios[indiceUsuarioEncontrado].senha) {					
					printf("login aceito\n");
					break;
				}else{
					printf("login recusado\n");
					break;
				}
			}else{
				printf("usuario nao encontrado\n");
				break;
			}
			
		}
  		
	}
    
    return 0;
}
