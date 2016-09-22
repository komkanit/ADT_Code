#include<cstdio>
#include<stack>
using namespace std;

int priority(char); //return operator's priority
int hasHigherPriority(char,char); 
//return 0 if op2 has higher priority than op1
//return 1 if otherwise 

int main()
{
	stack<char> myStack;
	char equation[1000];
	char* ptr=equation;

	printf("input infix: ");
	scanf("%s",equation);

	while(*ptr!='\0'){
		if(*ptr=='(')	//manage bracket
		{
			myStack.push('(');
		}
		else if(*ptr==')'){
			while(myStack.top()!='('){
				printf("%c",myStack.top());
				myStack.pop();
			}
			myStack.pop();
		}
		else if(priority(*ptr)>0)	//operator check
		{
				while(myStack.size()!=0){ //pop until top of stack has lower priority than *ptr or stack is empty
					if(hasHigherPriority(myStack.top(),*ptr)==0)
						break;
					printf("%c",myStack.top());
					myStack.pop();
				}
			
			myStack.push(*ptr);
		}
		else	//operand
			printf("%c",*ptr);
		ptr++;
	}

	//clear stack
	while(myStack.size()>0){
		printf("%c",myStack.top());
		myStack.pop();
	}
	printf("\n");
	return 0;
}

int priority(char op)
{
	int r;
	switch(op){
		case '+':
		case '-':r = 1; break;
		case '*':
		case '/':r = 10; break;
		case '^':r = 100; break;
		default :r = 0;
	}
	return r;
}

int hasHigherPriority(char op1,char op2)
{
	return priority(op1)>=priority(op2)?1:0;
}
