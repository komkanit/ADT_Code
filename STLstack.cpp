#include<cstdio>
#include<stack>
using namespace std;//wjthout this line, you must use"std::stack<type>" instead of using "stack<type>"

int main()
{	
	stack<int> intStack; 
	// same as InitializeStack(intStack)
	// syntax = stack<type> name;

	intStack.push(1);
	// same as Push(intStack,1);
	// syntax = name.push(value);
	
	intStack.pop();
	// same as Pop(intStack);
	// syntax = name.pop()
	// ***this is void function

	intStack.top();
	// same as Top(intStack);
	// syntax = name.top();
	
	intStack.empty();
	// same as IsEmpty(intStack);
	// syntax = name.empty();
	// return true if stack's size is 0, false otherwise.

	//STL stack never full = not have IsFull :P
	//but it still can underflow
	
	intStack.size();
	// return size of stack
	//
	return 0;
}
