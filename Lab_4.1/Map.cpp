#include "Map.h"
#include <iostream>


Tree* Map::insert(int key, std::string value, Tree* root)
{
	if (root == nullptr)
	{
		root = new Tree(key, value);
	}
	else if (key > root->key)
	{
		root->left = insert(key, value, root->left);
	}
	else if (key < root->key)
	{
		root->right = insert(key, value, root->right);
	}
	else throw "Fatal error";
	return root;
}

void Map::delete_tree(Tree* p)
{
	if (p) {
		delete_tree(p->left);
		delete_tree(p->right);
		delete p;
	}
}

void Map::print(Tree* p, int level) const
{
	if (p)
	{
		print(p->left, level + 1);
		for (int i = 0; i < level; i++) std::cout << "   ";
		std::cout << p->key << std::endl;
		print(p->right, level + 1);
	}
}

unsigned Map::height(Tree* p)
{
	return p ? p->height : 0;
}

int Map::balance_factor(Tree* p)
{
	return height(p->right) - height(p->left);
}

void Map::fix_height(Tree* p)
{
	unsigned  hl = height(p->left);
	unsigned hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Tree* Map::rotate_right(Tree* p)
{

	Tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}

Tree* Map::rotateleft(Tree* q)
{
	Tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fix_height(q);
	fix_height(p);
	return p;
}

Tree* Map::balance(Tree* p)
{

	fix_height(p);
	if (balance_factor(p) == 2)
	{
		if (balance_factor(p->right) < 0)
			p->right = rotate_right(p->right);
		return rotateleft(p);
	}
	if (balance_factor(p) == -2)
	{
		if (balance_factor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotate_right(p);
	}
	return p;
}

Map::Map()
{
	root = nullptr;
}

Map::~Map()
{
	delete_tree(root);
	root = nullptr;
}

void Map::print() const
{
	if (!root)
	{
		std::cout << "Nothing" << std::endl;
	}
	else print(root, 0);
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

bool Map::erase(int key)
{
	
	return false;
}
