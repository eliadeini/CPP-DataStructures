#pragma once
#include <type_traits>

template <typename T>
class GenericStackNode
{
public:
	GenericStackNode(T element, GenericStackNode<T>* prev_node = nullptr, GenericStackNode<T>* next_node = nullptr);
	~GenericStackNode();
	T getData();
	void setNextNode(GenericStackNode<T>* next_node);
	void setPrevNode(GenericStackNode<T>* prev_node);
	GenericStackNode<T>* getNextNode();
	GenericStackNode<T>* getPrevNode();
	void shouldKeepDataOnDestruct(bool shouldKeep);

private:
	T data;
	GenericStackNode<T>* nextNode;
	GenericStackNode<T>* prevNode;
	bool keepDataOnDestruct;
};



/**********************************************************************
							Implamantation
***********************************************************************/

template <typename T>
GenericStackNode<T>::GenericStackNode(T element,
	GenericStackNode<T>* prev_node,
	GenericStackNode<T>* next_node) : data(element), nextNode(next_node), prevNode(prev_node),
	keepDataOnDestruct(false)
{
}


template <typename T>
GenericStackNode<T>::~GenericStackNode()
{
	if (keepDataOnDestruct && (std::is_pointer<T>::value)) {
		delete_if_pointer(data);
	}
}


template <typename T>
T GenericStackNode<T>::getData()
{
	return data;
}


template <typename T>
void GenericStackNode<T>::setNextNode(GenericStackNode<T>* next_node)
{
	nextNode = next_node;
}


template <typename T>
void GenericStackNode<T>::setPrevNode(GenericStackNode<T>* prev_node)
{
	prevNode = prev_node;
}


template <typename T>
GenericStackNode<T>* GenericStackNode<T>::getNextNode()
{
	return nextNode;
}


template <typename T>
GenericStackNode<T>* GenericStackNode<T>::getPrevNode()
{
	return prevNode;
}


template <typename T>
void GenericStackNode<T>::shouldKeepDataOnDestruct(bool shouldKeep)
{
	keepDataOnDestruct = shouldKeep;
}


template<typename T>
void delete_if_pointer(T & item) {}  //do nothing: item is not pointer


template<typename T>
void delete_if_pointer(T* item) { delete item; } //delete: item is pointer
