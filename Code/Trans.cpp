#include "Repository.h"
#include <stdio.h>
#define H 10

void Trans(float m1[][H], int num_m1_rows, int num_m1_columns, int n){
     int i, j, u, v, max;
	 float a;
	 if(num_m1_rows < num_m1_columns){
	    max = num_m1_columns;
	 }else{
	    max = num_m1_rows;
	 }
	 for(i = 1; i <= max; i++){
		for(j = 1; j < i; j++){
		     a = m1[i][j];
			 m1[i][j] = m1[j][i];
			 m1[j][i] = a;	
		}
	 }
	 if(n == 1){
	 printf("Matrix A transpose is :\n");
	   for(u=1;u<=num_m1_columns;u++){
			for(v=1;v<=num_m1_rows;v++)
			{
				printf("%4.0f", m1[u][v]);
				if((v % num_m1_rows)==0) //New lines
					printf("\n");
			}
		}
	}
}
