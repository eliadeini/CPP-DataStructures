#pragma once

template <typename T>
class FixedGenericNode
{
public:
	FixedGenericNode(T element, unsigned int num_of_sons, FixedGenericNode<T>* parent_node = nullptr);
	~FixedGenericNode();
	FixedGenericNode<T>* getSonByIndex(int index);
	bool setSonByIndex(T new_data, int index, bool delete_if_occupied = false);
	T getData();
	void setData(T elem);
	FixedGenericNode<T>* getParent();
	bool setParent(FixedGenericNode<T>* parent_node);

private:
	FixedGenericNode<T>* parentNode;
	FixedGenericNode<T>** arrayOfSons;
	T element;
	int numOfSons;
};



template <typename T>
FixedGenericNode<T>::FixedGenericNode(T element, unsigned int num_of_sons,
	FixedGenericNode<T>* parent_node)
	: element(element), parentNode(parent_node), numOfSons(num_of_sons),
	arrayOfSons(nullptr)
{
	arrayOfSons = (FixedGenericNode<T>**)malloc(numOfSons*sizeof(FixedGenericNode<T>*));
	for (unsigned int i = 0; i < num_of_sons; i++) {
		arrayOfSons[i] = nullptr;
	}
}


template <typename T>
FixedGenericNode<T>::~FixedGenericNode()
{
	for (int i = 0; i < numOfSons; i++) {
		delete arrayOfSons[i];
	}
}


template <typename T>
FixedGenericNode<T>* FixedGenericNode<T>::getSonByIndex(int index)
{
	if ((index < 0) || (index >= numOfSons)) {
		return nullptr;
	}
	return arrayOfSons[index];
}


template <typename T>
bool FixedGenericNode<T>::setSonByIndex(T new_data, int index, bool delete_if_occupied) {
	if ((index < 0) || (index >= numOfSons)) {
		return false;
	}
	if (arrayOfSons[index] != nullptr) {
		if (delete_if_occupied) {
			delete arrayOfSons[index];
		}
		else {
			return false;
		}
	}
	arrayOfSons[index] = new FixedGenericNode(new_data, numOfSons, this);
	return true;
}


template <typename T>
T FixedGenericNode<T>::getData()
{
	return element;
}


template <typename T>
void FixedGenericNode<T>::setData(T elem)
{
	element = elem;
}


template <typename T>
FixedGenericNode<T>* FixedGenericNode<T>::getParent()
{
	return parentNode;
}


template <typename T>
bool FixedGenericNode<T>::setParent(FixedGenericNode<T>* parent_node)
{
	if (parent_node == nullptr) {
		return false;
	}
	parentNode = parent_node;
	return true;
}

