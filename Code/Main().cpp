#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Repository.h"

#define H 10

int num_rows(char a[]);
int num_columns(char a[]);
void input(float a[][H], int n, int m);
void initialize(float a[][H]);

int main(){
	
	float m1[H][H], m2[H][H], re[H][H],  det;
	int num_matrices, num_m1_rows, num_m1_columns, num_m2_rows, num_m2_columns;
	char ope;
	
    printf("Here is a super super matrix calculator!!!\n");   
	
    Restart: printf("How many matrices would you like to operate(1 or 2, 0 to quit): "); 
    scanf("%d",&num_matrices);
	
	if(num_matrices == 0){
	    return 0;
	}
	
    while( ((num_matrices != 1) && (num_matrices != 2))&&(num_matrices != 0)){
	  printf("\nPlease enter a valid number!\n\n"); 
	  printf("How many matrices would you like to operate(1 or 2): "); 
      scanf("%d",&num_matrices);
	}//Check

	//Preparation for inputing matrix
    if(num_matrices == 1){
		
		do{
		printf("\nPlease choose which operation would you like to try(f:LU factorization d:Determinant i:Inverse t:Transpose):");
		scanf(" %c",&ope);
	    }while(((ope != 'f')&&(ope != 'd')) && ((ope != 'i')&&(ope != 't')));//Check
		
		do{
		if(ope != 't'){
		   printf("Your matrix must be a square matrix which the number of rows equal to the number of columns.\n\n");
		}
		num_m1_rows = num_rows(" ");
		num_m1_columns = num_columns(" ");
		if((ope == 't')&&((num_m1_rows < 10)&&(num_m1_columns < 10))){
		  break;
		}
		//Input end
		}while( (num_m1_rows != num_m1_columns)||((num_m1_rows >= 10)||(num_m1_columns >= 10)) );//Check
		
	}else{
		
		do{
		printf("\nPlease choose which operation would you like to try(a:+ s:- m:*): ");
		scanf(" %c",&ope);
	    }while(((ope != 'a')&&(ope != 's')) && (ope != 'm'));//Check
		num_m1_rows = num_rows(" first ");
		num_m1_columns = num_columns(" first ");
		num_m2_rows = num_rows(" second ");
		num_m2_columns = num_columns(" second ");
		
		//Input end
	    if((ope == 'a')||(ope == 's')){
		    while( num_m1_rows != num_m2_rows){
			   printf("\nThe numbers of two matrix rows must be equal!!!\n");
			   num_m1_rows = num_rows(" first ");
			   num_m2_rows = num_rows(" second ");
			}//Check num_rows
			while( num_m1_columns != num_m2_columns){
			   printf("\nThe numbers of two matrix columns must be equal!!!\n");
			   num_m1_columns = num_columns(" first ");
			   num_m2_columns = num_columns(" second ");
			}//Check num_columns
		}else{
		    while( num_m1_columns != num_m2_rows){
		       printf("\nThe number of first matrix columns must be equal to the number of second matrix rows!!!\n");
			   num_m1_columns = num_columns(" first ");
			   num_m2_rows = num_rows(" second ");
		   }//Check num of first columns and second rows.
		}
		
	}
	
	//Initializing all matrix
	initialize(m1);
	initialize(m2);
	initialize(re);
	
	//Start inputing matrix
	printf("Please input your (first) matrix.\n");
	input(m1,num_m1_rows,num_m1_columns);
	if(num_matrices == 2){
		printf("Please input your second matrix.\n");
		input(m2,num_m2_rows,num_m2_columns);
	}
	//Input end
	//Start operating
	if(num_matrices == 1){
	   if(ope == 'f'){
		 LU(m1, re, num_m1_rows);
	   }else if(ope == 'd'){
	     det = DET(m1, num_m1_rows);
		 printf("The determinant is %.2f.\n",det);
	   }else if(ope == 'i'){
	     INV(m1, re, num_m1_rows,1);
	   }else{
	      Trans(m1, num_m1_rows, num_m1_columns,1);
	   }
	   
	}else{
	   if(ope == 'a'){
	     addition(m1, m2, re, num_m1_rows, num_m1_columns);
	   }else if(ope == 's'){
	     subtraction(m1, m2, re, num_m1_rows, num_m1_columns);
	   }else{
	     multiply(m1, m2, re, num_m1_rows, num_m1_columns, num_m2_columns);
	   }
	}
	printf("\n");
	goto Restart;
    return 0;
}


//Function of inputing matrices
void input(float a[][H], int n, int m){
	int i, j;
     for(i = 1; i <= n; i++){
	   for(j = 1; j <= m; j++){
	       scanf("%f",&a[i][j]);
	   }
	}
}

//Function of inputing the number of matrix rows
int num_rows(char a[]){
	int n;
	printf("Please enter the number of your%smatrix rows(<10): ",a);
	scanf("%d",&n);
	return n;
}

//Function of inputing the number of matrix columns
int num_columns(char a[]){
	int n;
	printf("Please enter the number of your%smatrix columns(<10): ",a);
	scanf("%d",&n);
	return n;
}

//Function of initializing the array
void initialize(float a[][H]){
     int i, j;
	 for(i = 0; i < H; i++){
	    for(j = 0; j < H; j++){
		   a[i][j] = 0; 
		}
	 }
}


