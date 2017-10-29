// GenericQueueByTwoStacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenericQueueByTwoStacks.h"
#include <iostream>


using namespace std;

int main(int argc, _TCHAR* argv[])
{
	GenericQueueByTwoStacks<int> queue;
	queue.Push(1);
	queue.Push(2);
	cout << "Poped element is " << queue.Pop() << endl;

	queue.Push(3);
	queue.Push(4);
	queue.Push(5);
	cout << "Poped element is " << queue.Pop() << endl;

	getchar();
	return 0;
}


