#include "Repository.h"
#include <stdio.h>
#define H 10

void addition(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns) 
{
	int u, v;
	for(u=1;u<=num_m1_rows;u++){
		for(v=1;v<=num_m1_columns;v++){
			re[u][v]=m1[u][v]+m2[u][v];  
		}
	}
	//Output result
	printf("Matrix A adds matrix B :\n");
		for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_columns;v++)
			{
				printf("%4.0f", re[u][v]);
				if((v % num_m1_columns)==0) //New lines
					printf("\n");
			}
		}	
}


void subtraction(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns)
{
	int u, v;
	for(u=1;u<=num_m1_rows;u++){
		for(v=1;v<=num_m1_columns;v++){
			re[u][v]=m1[u][v]-m2[u][v];
		}
	}
	//Output result
	printf("Matrix A decreases matrix B :\n");
		for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_columns;v++)
			{
				printf("%4.0f", re[u][v]); 
				if((v % num_m1_columns)==0) //New lines
					printf("\n");
			}
		}
}

