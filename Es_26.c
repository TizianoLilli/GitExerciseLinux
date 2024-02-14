#include <stdio.h>
#include <string.h>

void alltoupper(char buff[]){
	int len=strlen(buff);
	for (int i=0; i<len; i++){
	       if (buff[i]>96 && buff[i]<123){
			buff[i]=buff[i]-32;
	       }
	}	       
}

int main(int argc, char *argv[]){
	char buff[]="Provaprovasasa";

	alltoupper(buff);
	printf("Your string in upper case:\n%s\n", buff);
	return 0;
}
