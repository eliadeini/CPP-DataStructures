// GenericStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenericStack.h"
#include <iostream>

using namespace std;


int main(int argc, _TCHAR* argv[])
{
	GenericStack<int> my_stack;
	my_stack.Push(1);
	my_stack.Push(2);
	my_stack.Push(3);
	my_stack.Push(4);
	my_stack.Push(5);
	cout << "Curr top is " << my_stack.Top() << "  stack size is " << my_stack.size() << endl;
	my_stack.Pop();
	my_stack.Pop();
	cout << "Curr top is " << my_stack.Top() << "  stack size is " << my_stack.size() << endl;
	my_stack.Push(7);
	cout << "Curr top is " << my_stack.Top() << "  stack size is " << my_stack.size() << endl;

	getchar();
	return 0;
}

