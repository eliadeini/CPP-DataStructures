#pragma once
#include "FixedGenericNode.h"

template <typename T>
class FixedGenericTree
{
public:
	FixedGenericTree(unsigned int num_of_sons = 2);    /* The default is a Binary Tree */
	FixedGenericTree(T root_data, unsigned int num_of_sons);
	~FixedGenericTree();
	bool AddNode(FixedGenericNode<T>* to_node, T new_data, int index, bool delete_if_occupied = false);
	bool RemoveSubTree(FixedGenericNode<T>* sub_tree_root);    /* Actually removes a node and its sub nodes  */
	FixedGenericNode<T>* getRoot();
	FixedGenericNode<T>* SearchTree(T elem_to_search);
	void PrintTree();

private:
	FixedGenericNode<T>* TreeRoot;
	unsigned int NumOfSons;

	FixedGenericNode<T>* SearchTreeDFS(FixedGenericNode<T>* sub_tree_root, T elem_to_search);
	void printSubTreeWIdentation(FixedGenericNode<T>* root, int num_of_indent);
};


template <typename T>
FixedGenericTree<T>::FixedGenericTree(unsigned int num_of_sons) : TreeRoot(nullptr), NumOfSons(num_of_sons)
{
}


template <typename T>
FixedGenericTree<T>::FixedGenericTree(T root_data, unsigned int num_of_sons) : NumOfSons(num_of_sons)
{
	TreeRoot = new FixedGenericNode<T>(root_data, num_of_sons);
}


template <typename T>
FixedGenericTree<T>::~FixedGenericTree()
{
	delete root;
}


/* Note: When (to_node == NULL), we will add a root if it is missing, or a son to the root if there is a root */
template <typename T>
bool FixedGenericTree<T>::AddNode(FixedGenericNode<T>* to_node, T new_data, int index, bool delete_if_occupied = false)
{
	if ((INDEX < 0) || (index >= NumOfSons)) {
		return false;
	}
	FixedGenericNode<T>* new_node = FixedGenericNode(new_data, NumOfSons, to_node);
	return setSonByIndex(new_node, index, delete_if_occupied);
}


/* Removes a node and its sub nodes  */
template <typename T>
bool FixedGenericTree<T>::RemoveSubTree(FixedGenericNode<T>* sub_tree_root)
{
	if (sub_tree_root == nullptr) {
		return false;
	}
	delete sub_tree_root;
	return true;
}


template <typename T>
FixedGenericNode<T>* FixedGenericTree<T>::getRoot()
{
	return TreeRoot;
}


template <typename T>
FixedGenericNode<T>* FixedGenericTree<T>::SearchTree(T elem_to_search)
{
	return SearchTreeDFS(TreeRoot, elem_to_search);
}


template <typename T>
void FixedGenericTree<T>::PrintTree()
{
	printSubTreeWIdentation(TreeRoot, 0);
}


/* Private functions */
template <typename T>
FixedGenericNode<T>* FixedGenericTree<T>::SearchTreeDFS(FixedGenericNode<T>* sub_tree_root, T elem_to_search)
{
	if (sub_tree_root == nullptr) {
		return nullptr;
	}
	if (elem_to_search == sub_tree_root->getData()) {
		return sub_tree_root;
	}

	FixedGenericNode<T>* sub_tree_result = nullptr;
	for (unsigned int i = 0; i < NumOfSons; i++) {
		sub_tree_result = SearchTreeDFS(sub_tree_root->getSonByIndex(i), elem_to_search);
		if (sub_tree_result != nullptr) {
			return sub_tree_result;
		}
	}
	return nullptr;
}


/* This function is good for printing of simple types only. */
template <typename T>
void FixedGenericTree<T>::printSubTreeWIdentation(FixedGenericNode<T>* root, int num_of_indent)
{
	if (root == nullptr) {
		return;
	}

	for (int i = 0; i < num_of_indent; i++) {
		cout << "    ";
	}
	cout << root->getData() << endl;

	for (unsigned int i = 0; i < NumOfSons; i++) {
		printSubTreeWIdentation(root->getSonByIndex(i), num_of_indent + 1);
	}
}

