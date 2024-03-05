#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkRows(unsigned char (*problem)[9][9], int k, int i); //
bool checkCols(unsigned char (*problem)[9][9], int k, int i, int j); //  
bool checkRegs(unsigned char (*problem)[9][9], int k, int i, int j);  //
int miniCheck(int l);

void solve(unsigned char (*problem)[9][9]){
	unsigned char copia[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			copia[i][j]=*problem[i][j]; 
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(!*problem[i][j]){  
				int k; // dove metto slo slash ho tolto il puntatore
				k=1;
				checkpoint:
				if(checkRows(problem, k, i) && checkCols(problem, k, i, j) && checkRegs(problem, k, i, j))
					*problem[i][j]=k;
				else{
					do{
						while(j>0){
							--j;
							if(!copia[i][j]){
								k=(*problem[i][j])+1;
								goto checkpoint; 
							}
						}
						if(i>0){
							i--;
							j=9;
						}
					}while(i>=0);
				}
			}
		}
	}
}

bool checkRows(unsigned char (*problem)[9][9], int k, int i){  //
	if(k>9) //
		return false;
	for(int j=0;j<9;j++){
		if(k==*problem[i][j]){ //
			(k)++; // non dovrebbe cambiare se scrivo *++k
			return(checkRows(problem, k, i)); // forse mi conviene scrivere k++ subito sotto l'if. Così incremento puntatore o valore di k?
		} 	
	}
	return true;
}

bool checkCols(unsigned char (*problem)[9][9], int k, int i, int j){ 
	if (k>9)
		return false;
	for(int h=0;h<9;h++){
		if(k==*problem[h][j]){
			(k)++;
			return(checkRows(problem,k ,i) && checkCols(problem, k, i, j));  
		}
	}
	return true;
}

bool checkRegs(unsigned char (*problem)[9][9], int k, int i, int j){ 
	int q=miniCheck(i); // mi restituisce 0, 1, 2 in base a se sto nella 1ma, 2nda o 3za regione
        int w=miniCheck(j);
	if (k>9)
		return false;
	for(int h=q;h<q+3;h++){
 		for(int u=w;u<w+3;u++){
			if(k==*problem[h][u]){
				(k)++;
				return(checkRows(problem, k, i) && checkCols(problem, k, i, j) && checkRegs(problem, k, i, j));
			}
		}	
	}
	return true;
}

int miniCheck(int l){
	int temp=l/3;
	switch(temp){
		case 2:
			temp=temp+2;
		case 1:
			temp=temp+2;
			break;
		default:  // posso evitarlo?
	}
	return temp;
}

