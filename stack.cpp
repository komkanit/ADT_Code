#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stack[10];
int* head = stack;
int* tail = head;
int maxStack = 5;

int getStackLength() {
  int i = 0;
  while(stack[i] != 0){
    i++;
  }
  return i;
}

void push(int data) {
  if(getStackLength() >= maxStack) {
    printf("stack overflow\n");
  }
  else {
    *tail = data;
    tail++;
  }
}
void pop() {
  if(tail == head) {
    printf("stack empty\n");
  }
  else {
    tail--;
    printf("pop %d\n", *tail);
    *tail = 0;
  }
}
void print(){
  for(head ; head != tail ; head++){
    printf("%d ",*head);
  }
  printf("\n");
  head = stack;
}

int main() {
  char input[100];
  int data;
  
  while(1){
    printf("command: ");
    scanf("%s",input);
    if(strcmp(input,"push") == 0) {
      printf("input: ");
      scanf("%d",&data);
      push(data);
    }
    else if(strcmp(input,"print") == 0) {
      print();
    }
    else if(strcmp(input,"pop") == 0) {
      pop();
    }
  }
}

