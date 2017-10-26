#pragma once

#include "GenericStackNode.h"
#include <string>

template <typename T>
class GenericStack
{
public:
	GenericStack();
	GenericStack(T firstElem);
	~GenericStack();
	void Push(T element);
	T Pop();
	T Top();
	int size();

private:
	int numOfElements;
	GenericStackNode<T>* firstNode;
	GenericStackNode<T>* topNode;
};




/**********************************************************************
						Implamantation
***********************************************************************/


template <typename T>
GenericStack<T>::GenericStack() : numOfElements(0), firstNode(nullptr), topNode(nullptr)
{
}


template <typename T>
GenericStack<T>::GenericStack(T firstElem) : numOfElements(1), firstNode(nullptr), topNode(nullptr)
{
	firstNode = topNode = new GenericStackNode(firstElem);
}


template <typename T>
GenericStack<T>::~GenericStack()
{
	GenericStackNode<T>* curr_node = firstNode, *next_node = nullptr;

	while (curr_node != nullptr) {
		next_node = curr_node->getNextNode();
		delete curr_node;
		curr_node = next_node;
	}
}


template <typename T>
void GenericStack<T>::Push(T element)
{
	GenericStackNode<T>* new_node = new GenericStackNode<T>(element, topNode);
	if (topNode != nullptr) {
		topNode->setNextNode(new_node);
	}

	topNode = new_node;
	numOfElements++;
}


template <typename T>
T GenericStack<T>::Pop()
{
	T top_elem = Top();
	GenericStackNode<T>* new_top_node = topNode->getPrevNode();
	topNode->shouldKeepDataOnDestruct(true);
	delete topNode;
	topNode = new_top_node;
	numOfElements--;
	return top_elem;
}


template <typename T>
T GenericStack<T>::Top()
{
	if (topNode == nullptr) {
		throw "Stack is empty";
	}

	return topNode->getData();
}


template <typename T>
int GenericStack<T>::size()
{
	return numOfElements;
}
