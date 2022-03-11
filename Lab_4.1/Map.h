#pragma once
#include <iostream>
#include <string>


struct Tree
{
	Tree(int _key, std::string _data) :key(_key), data(_data), right(nullptr), left(nullptr), height(1){};
	int key;
	std::string data;
	Tree* right;
	Tree* left;
	unsigned height;
};

class Map
{
private:
	Tree* root;
	Tree* insert(int key, std::string value, Tree* root);
	void delete_tree(Tree* p);
	void print(Tree* p, int level = 0) const;
	unsigned height(Tree* p);
	int balance_factor(Tree* p);
	void fix_height(Tree* p);
	Tree* rotate_right(Tree* p);
	Tree* rotateleft(Tree* q);
	Tree* balance(Tree* p);
public:
	Map();
	~Map();
	void print() const;
	bool insert(int key, std::string value);
	const std::string& find(int key) const;
	bool erase(int key);
};

