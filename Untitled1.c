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

int main() {
	
	struct user{
    	char nome[20];
    	char senha[6];
	};

	int qtdUsuarios;

    printf("Insira a quantidade de usuarios ");
    scanf("%d", &qtdUsuarios);
    
//    struct user usuarios[qtdUsuarios];    
//    
    printf("Insira o nome e a senha dos usuarios\n ");
    int i;
    
    	
    	char string1[100];
    	
    	gets(string1);
    	
//    	for (i = 0; i < sizeof(string1); i++){
//    		copy[i] = string1[i];
//		}
		
		
    	    	
//    	char* cred1;
//    	
//    	cred1 = strtok(copy, " ");
//    	
//    	printf("nome : ");
//    	printf(cred1);
//    	printf("\n");
//    	
//    	cred1 = strtok(NULL, " ");
//    	printf("senha : ");
//    	printf(cred1);
//    	printf("\n");
    	
//    	char *ch;
//  		ch = strtok(copy, " ");
//  		while (ch != NULL) {
//  			printf("%s\n", ch);
//  			ch = strtok(NULL, " ,");
//  		}
    	// strcpy(usuarios[i].nome, string2);
    	
    	
	
    
    return 0;
}
