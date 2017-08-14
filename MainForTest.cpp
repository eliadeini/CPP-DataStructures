#include "stdafx.h"
#include <iostream>
#include "FixedGenericTree.h"
#include "FixedGenericNode.h"


using namespace std;

int main()
{
	FixedGenericTree<int>* tree1 = new FixedGenericTree<int>(1, 5);
	FixedGenericNode<int>* root_node = tree1->getRoot();
	root_node->setSonByIndex(2, 0);
	root_node->setSonByIndex(3, 1);
	root_node->setSonByIndex(4, 2);
	root_node->setSonByIndex(5, 4);
	if (root_node->getSonByIndex(3) == nullptr) {
		cout << "There is nothing in root's index 3" << endl;
	}
	else {
		cout << "BUG 1 !!" << endl;
	}
	FixedGenericNode<int>* node4 = root_node->getSonByIndex(4);
	if (node4 == nullptr) {
		cout << "BUG 2 !!" << endl;
	}
	cout << endl << endl << endl;
	node4->setSonByIndex(6, 3);
	tree1->SearchTree(6);
	tree1->PrintTree();
	root_node->setSonByIndex(-3, 1, true);
	root_node->setSonByIndex(-2, 0);
	root_node->getSonByIndex(4)->setData(-5);
	tree1->PrintTree();
	cin.get();
}