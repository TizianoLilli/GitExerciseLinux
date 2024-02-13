#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char *argv[]){
	
	char buff[40];
	printf("Inserisci una stringa:\n");
	if (fgets(buff, 40, stdin)) {
		buff[strcspn(buff, "\n")] = 0;
	}

	char cpy[40]; 
	int i, j;
	int k=0;
	int len=strlen(buff);
	bool check;
	for (i=0; i<len; i++){
		check=true;
		j=0;
		while (check && j<i){ 
			if (buff[i]==buff[j]) check=false;
			else j++;
		}
		if (check){ 
			cpy[k]=buff[i];
			k++;	
		}
	}
	cpy[k]=0;

	printf("Ecco la tua stringa senza ripetizioni: \n%s\n", cpy);

	return 0;
}

