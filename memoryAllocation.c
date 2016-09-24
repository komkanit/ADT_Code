#include <stdio.h>

int main() {
	//compare malloc and calloc
  int *a = (int*) malloc(sizeof(int)*10);
  int *b = (int*) calloc(10, sizeof(int));
  int i;
  for(i=0;i < 10;i++)
  {
      printf("a = %d, b = %d\n", a[i], b[i]);
  }
  return 0;
}