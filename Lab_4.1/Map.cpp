#include "Map.h"
#include <iostream>


Map::Map()
{
	root = nullptr;
}

void Map::print(Tree* leaf) const
{
	if (root)
	{
		std::cout << root->data;
		print(root->left);
		print(root->right);
	}
}

Tree* Map::insert(int key, std::string value, Tree* root)
{
	if (root == nullptr)
	{
		root = new Tree(key, value);
	}
	else if (key < root->key)
	{
		root->left = insert(key, value, root->left);
	}
	else if (key > root->key)
	{
		root->right = insert(key, value, root->right);
	}
	else throw "Fatal error";
	return root;
}

bool Map::insert(int key, std::string value)
{
	root = insert(key, value, root);
	return true;
}

const std::string& Map::find(int key) const
{
	Tree* temp = root;
	while (temp != nullptr)
	{
		if (key == temp->key) return root->data;
		if (key < temp->key)
		{
			temp = temp->left;
		}
		if (key > temp->key)
		{
			temp = temp->right;
		}
    }
	throw "No elements with this key!";
}
