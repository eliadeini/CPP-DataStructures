#pragma once
#include "../GenericStack/GenericStack.h"

template <typename T>
class GenericQueueByTwoStacks
{
public:
	GenericQueueByTwoStacks();
	~GenericQueueByTwoStacks();
	void Push(T element);
	T Pop();
	T Top();
	int size();

private:
	int numOfElements;
	GenericStack<T> pushStack;
	GenericStack<T> popStack;
	bool dataInPushStack;

	void swapStacks();

};


template <typename T>
GenericQueueByTwoStacks<T>::GenericQueueByTwoStacks() : numOfElements(0), dataInPushStack(true)
{
}


template <typename T>
GenericQueueByTwoStacks<T>::~GenericQueueByTwoStacks()
{
}


template <typename T>
int GenericQueueByTwoStacks<T>::size()
{
	return numOfElements;
}


template <typename T>
void GenericQueueByTwoStacks<T>::Push(T element)
{
	/* If the data is not in the PushStack, we need to move it to the pushStack in order to be
	   able to push data to the end of the queue.												*/
	if (!dataInPushStack) {
		swapStacks();
	}

	pushStack.Push(element);
	numOfElements++;
}


template <typename T>
T GenericQueueByTwoStacks<T>::Pop()
{
	/* If the data is not in the PushStack, we need to move it to the pushStack in order to be
	able to push data to the end of the queue.												*/
	if (dataInPushStack) {
		swapStacks();
	}

	numOfElements--;
	return popStack.Pop();
}


template <typename T>
T GenericQueueByTwoStacks<T>::Top()
{
	/* If the data is not in the PushStack, we need to move it to the pushStack in order to be
	able to push data to the end of the queue.												*/
	if (dataInPushStack) {
		swapStacks();
	}

	return popStack.Top();
}


template <typename T>
void GenericQueueByTwoStacks<T>::swapStacks()
{
	GenericStack<T>* fromStack = nullptr;
	GenericStack<T>* toStack = nullptr;

	if (dataInPushStack) {
		fromStack = &pushStack;
		toStack = &popStack;
	}
	else {
		fromStack = &popStack;
		toStack = &pushStack;
	}

	while (fromStack->size() > 0) {
		T curr_data = fromStack->Pop();
		toStack->Push(curr_data);
	}

	dataInPushStack = !dataInPushStack;
}