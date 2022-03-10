#pragma once
#include <iostream>
#include <string>


struct Tree
{
	Tree(int _key, std::string _data) :key(_key), data(_data), right(nullptr), left(nullptr) {};
	int key;
	std::string data;
	Tree* right;
	Tree* left;
};

class Map
{
private:
	Tree* root;
	Tree* insert(int key, std::string value, Tree* root);
public:
	Map();
	void print(Tree* leaf) const;
	bool insert(int key, std::string value);
	const std::string& find(int key) const;
};

