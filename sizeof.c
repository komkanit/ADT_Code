#include<stdio.h>

typedef struct {
  char a; //1
  int c; //4
  // padding 3
  int d; //4
  int e; //4
  int f; //4
  // padding 4
  double b;//8
}S;
typedef struct 
{
    short s; /* 2 bytes */
    // padding 2
    int   i; /* 4 bytes */
    // padding 3
    char  c; /* 1 byte */
}X;

typedef struct
{
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
    short s; /* 2 bytes */
             /* 1 padding byte */
}Y;
typedef struct {
    char a[3]; //3
    short int b; //2
    // padding 3
    long int c; //8
    // padding 5
    char d[3]; //3
}Z;
typedef struct {
  int a;//4
  int b;//4
  double c;//8
}A;
int main() {
  printf("size of int : %ld\n", sizeof(int));
  printf("size of long int : %ld\n", sizeof(long int));
  printf("size of int[3] : %ld\n", sizeof(int [3]));
  printf("size of char : %ld\n", sizeof(char));
  printf("size of char[3] : %ld\n", sizeof(char [3]));
  printf("size of float : %ld\n", sizeof(float));
  printf("size of double : %ld\n", sizeof(double));
  printf("size of int* : %ld\n", sizeof(int *));
  printf("size of char* : %ld\n", sizeof(char *));
  printf("size of double* : %ld\n", sizeof(double *));
  printf("%ld\n", sizeof(A));
  printf("%ld\n", sizeof(S));
  printf("%ld\n", sizeof(Y));
  printf("%ld\n", sizeof(Z));
  
}