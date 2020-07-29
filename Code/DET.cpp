#include "Repository.h"
#include <stdio.h>
#include <math.h>
#define H 10

float upper(float m1[][H], int num_m1_rows){ //Make matrix to upper
	int i, j, u, v, k = 0;
    float temp;
	for(i = 1,j = 1;( i <= num_m1_rows )&&( j <= num_m1_rows ); i++, j++){
		//i : rows.  j : columns. Locate diagonal elements
		
		//The second elementary transformation to exchange two rows
		if(m1[i][j] == 0){
		  u = i + 1; 
	      while((u <= num_m1_rows) && (m1[u][j] == 0)){
		     u++;
		    }
		  if(u > num_m1_rows){
		     break;
		  }else{
		     for(v = j; v <= num_m1_rows; v++){
			     temp = m1[i][v];
				 m1[i][v] = m1[u][v];
				 m1[u][v] = temp;
			 }
			 k++;
		  }
		}
	   for(u = num_m1_rows; u > i; u--){
	      temp = m1[u][j];
		  for(v = j; v <= num_m1_rows; v++){
		     m1[u][v] -= m1[i][v] * (temp / m1[i][j]);// The third elementary transformation to opeatet rows
		  }
	   }
	}
	return k; 
}


float DET(float m1[][H], int num_m1_rows){
	int i;
	float f = 1.0, k;
	//Make matrix to upper
	k = upper(m1, num_m1_rows);
	//Because matrix is upper, to calculate determinant just multiply the diagonal elements.
	for(i = 1; i <= num_m1_rows; i++){
	   if(m1[i][i] == 0){
	     return 0;
	   }
	   f *= m1[i][i];
	}
	k = pow(-1,k);
	return k * f;
}

