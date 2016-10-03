#include<stdio.h>

void func(int b){
  b += 10;
  printf("func: %d\n", b);
}
void funptr(int *b){
  *b += 10;
  printf("funptr: %d\n", *b);
}
int main() {
  int a = 10;
  printf("%d\n", a);
  func(a);
  printf("%d\n", a);
  funptr(&a);
  printf("%d\n", a);
}
