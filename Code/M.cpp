#include "Repository.h"
#include <stdio.h>
#define H 10

void multiply(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns, int num_m2_columns) 
   {
	   int u, v, k;
       for (int u = 1; u <= num_m1_rows; u++) {
		  for (int v = 1; v <= num_m2_columns; v++) {
			  re[u][v] = 0;  //Array initializing
			  for (int k = 1; k <= num_m1_columns; k++) {
				re[u][v] += m1[u][k] * m2[k][v]; //Rows of matrix 1 dot product columns of matrix 2
				}
			}
		}
	   
	   //Output result
	   printf("Matrix A multiplies matrix B :\n");
	   for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m2_columns;v++)
			{
				printf("%4.0f", re[u][v]);
				if((v % num_m2_columns)==0) //New lines
					printf("\n");
			}
		}
   }
