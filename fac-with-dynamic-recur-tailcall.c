#include<stdio.h>
#include<stdlib.h>

int facDynamic(int n)
{
	int* value;
	int i;
	
	value=malloc(sizeof(int)*(n+2));
	value[0]=1;
	
	for(i=1;i<=n;i++)
	{
		value[i]=value[i-1]*i;
	}

	return value[n];
}

int facRecursion(int n)
{
	if(n==0){
		return 1;
	}
	else
		return n*facRecursion(n-1);
}

int facTail(int n,int sum)
{
	if(n==0)
		return sum;
	else
		return facTail(n-1,sum*n);
}

int facTailCall(int n)
{
	return facTail(n,1);
}


int main()
{
	int n;
	printf("input n:");
	scanf("%d",&n);
	printf("n! is: %d %d %d\n",facDynamic(n),facRecursion(n),facTailCall(n));
}
