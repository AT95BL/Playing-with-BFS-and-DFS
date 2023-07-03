#pragma once

#include <iostream>
#include <Windows.h>
#include <chrono>

template <class T>
class BST
{
public:

	BST(const T& data)								// Parametrized constructor definition...
	{
		this->data = data;							// New node data...
		this->left = this->right = nullptr;			// New node children...
	}


	BST* insert(BST* root, const T& value)			// Insert method definition...
	{
		if (!root)									// In a case 'current' node is going to be an 'first' node...
			return new BST(value);					// Just create an 'BST' object and give us his adress...

		// Otherwise...Before we add a brand new node... we need to find a BST level for him and a place for him...
		if (value > root->data)											
			root->right = insert(root->right, value);
		else
			root->left = insert(root->left, value);

		return root;
	}


	void inorder(BST* root)							// To complete a task, Inorder BST traversal must be defined...
	{
		if (!root)
			return;

		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
	

	void printLevelOrder(BST* root)					// This method displays our BST level by level...
	{
		int h = height(root);						// We need to know how many levels are there...
		int i;
		for (i = 1; i <= h; i++)					// And for every level,
			printCurrentLevel(root, i);				// show us the information...
	}

	
	void printCurrentLevel(BST* root, int level)		// Mentioned function...
	{
		if (root == NULL)								// Case that we are on a level which has nothing to display...
			return;
		if (level == 1)									// 'Root' ...
			std::cout << root->data << " ";
		else if (level > 1) {							// Levels above the 'root' ...
			printCurrentLevel(root->left, level - 1);
			printCurrentLevel(root->right, level - 1);
		}
	}

	
	int height(BST* node)								// Calculate the height of an our BST ...
	{
		if (node == NULL)
			return 0;
		else {
			
			int lheight = height(node->left);
			int rheight = height(node->right);

			
			if (lheight > rheight) {
				return (lheight + 1);
			}
			else {
				return (rheight + 1);
			}
		}
	}



private:
	// Class atributes...BST standard...
	T data;
	BST* left, * right;
	
};