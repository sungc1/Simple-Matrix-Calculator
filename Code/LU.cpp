#include "Repository.h"
#include <stdio.h>
#define H 10

int LU(float m1[][H], float re[][H], int num_m1_rows){
	int u, v, i, j;
	float k, det;
	float copy[H][H];
	
	for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_rows;v++)
			{
				re[u][v] = 0;
				if(u==v){
				  re[u][v] = 1;
				}
				copy[u][v] = m1[u][v];
			}
	}
	
		
	//Calculate U
    k = upper(m1, num_m1_rows);
	det = DET(m1, num_m1_rows);
	if((k != 0)||(det == 0)){
	  printf("The LU factorization does not exist!!");
	  return 0;
	}
	printf("The upper matrix(U) is :\n");
	   for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_rows;v++)
			{
				printf("%5.2f", m1[u][v]);
				if((v % num_m1_rows)==0) //New lines
					printf("\n");
			}
		}
	   

	//Calculate L
	for(i = 1,j = 1;( i <= num_m1_rows )&&( j <= num_m1_rows ); i++, j++){
		//i : rows.  j : columns. Locate diagonal elements
	   for(u = num_m1_rows; u > i; u--){
		   k = copy[u][j];
		  for(v = j; v <= num_m1_rows; v++){
			 re[u][j] += (copy[u][j] / copy[i][j]);
		
		     copy[u][v] -= copy[i][v] * (k / copy[i][j]); // The third elementary transformation to opeatet rows
		    
			 
		  }
	   }
	
	  
	}
	
    printf("The lower unit matrix(L) is :\n");
	   for(u=1;u<=num_m1_rows;u++){
			for(v=1;v<=num_m1_rows;v++)
			{
				printf("%5.2f", re[u][v]);
				if((v % num_m1_rows)==0) //New lines
					printf("\n");
			}
		}
	
	return 0;

}
