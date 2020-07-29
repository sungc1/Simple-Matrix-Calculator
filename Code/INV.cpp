#include "Repository.h"
#include <stdio.h>
#include <math.h>
#define H 10


float cofactor(float m1[][H], float temp[][H], int num_m1_rows, int a, int b){
    int i, j, u, v;
	float cofactor;
	for(i = 1; i <= num_m1_rows; i++){
	    for(j = 1; j <= num_m1_rows; j++){
		   temp[i][j] = 0; 
		}
	 }
	
	
	
	for(i = 1; i <= num_m1_rows; i++){
		//i is the operating row of m1 at the moment.
		if(i == a){
		    continue; //Except row a; 
		   }
	   for(j = 1; j <= num_m1_rows; j++){
		//j is the operating column of m1 at the moment.
	     if(j == b){
		     continue; //Except column a; 
		   }
		 if(i > a){
		    u = i - 1;
		 }else{
		    u = i;
		 }
		 if(j > b){
		    v = j - 1;
		 }else{
		    v = j;
		 }
		   temp[u][v] = m1[i][j];
	   }
	}
	
	cofactor = pow(-1,a+b) * DET(temp, num_m1_rows-1);
	
	return cofactor;
}

int INV(float m1[][H], float re[][H], int num_m1_rows, int n){
    int i, j, u, v;
	float det;
	float temp[H][H];
	for(i = 1; i <= num_m1_rows; i++){
	    for(j = 1; j <= num_m1_rows; j++){
		   temp[i][j] = m1[i][j];
		}
	}
	
	det = DET(temp, num_m1_rows);
	if(det == 0){
	   printf("The inverse doesn't exist!\n");
	   return 0;
	}
	
	for(i = 1; i <= num_m1_rows; i++){
	    for(j = 1; j <= num_m1_rows; j++){
		   re[i][j] = cofactor(m1,temp,num_m1_rows,i,j);
		   
		}
	}
	
	
	Trans(re, num_m1_rows, num_m1_rows, 0);
	
	for(i = 1; i <= num_m1_rows; i++){
	    for(j = 1; j <= num_m1_rows; j++){
		    
			re[i][j] = re[i][j]/det;
		   
			if(re[i][j] == -0){
				   re[i][j] = 0;
				}
		}
	}
	if(n == 1){
	printf("Matrix A Inverse is :\n");
	   for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_rows;v++)
			{
				printf("%6.2f", re[u][v]);
				if((v % num_m1_rows)==0) //New lines
					printf("\n");
			}
		}
	}
	return 0;
}
