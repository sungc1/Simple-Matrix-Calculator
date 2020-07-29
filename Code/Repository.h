#ifndef Repository_h
#define Repository_h
#define H 10

//For addition & subtraction
    void addition(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns);
    void subtraction(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns);
//For DET
    float upper(float m1[][H], int num_m1_rows);
    float DET(float m1[][H], int num_m1_rows);
//For INV
    float cofactor(float m1[][H],float re[][H],int Num_m1_rows, int i, int j);
    int INV(float m1[][H], float re[][H], int num_m1_rows, int n);
//For LU
    int LU(float m1[][H], float re[][H], int num_m1_rows);
//For Multiple
    void multiply(float m1[][H], float m2[][H], float re[][H], int num_m1_rows,int num_m1_columns, int num_m2_columns);
//For Transposition
    void Trans(float m1[][H], int num_m1_rows, int num_m1_columns, int n);

#endif 
