#include<stdio.h>

void hanoi(int num,char a[],char b[],char c[]) {
  if(num > 0) {
    hanoi(num -1 , a, c, b);
    printf("move disk %d from %s to %s\n", num, a, c);
    hanoi(num - 1, b, a, c);
  }
  
}

int main() {
  int num;
  scanf("%d", &num);
  char a[] = "A";
  char b[] = "B";
  char c[] = "C";
  
  hanoi(num, a, b, c);
}