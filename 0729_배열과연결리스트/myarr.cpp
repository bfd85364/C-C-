//myarr.cpp
#include <iostream>
using namespace std;
#include "myarr.h"

MyArr::MyArr(int _max /*= 10*/) : max(_max), size(0)
{
	base = new void* [max];
}

MyArr::~MyArr()
{
	delete[] base;
}

void MyArr::push_back(void* data)
{
	if (max <= size)
		throw "Overflow";

	base[size] = data; 
	size++;
}

void MyArr::erase(int idx)
{
	for (int i=idx; i<size; i++)
	{
		base[i] = base[i + 1];
	}
	size--;
}

void MyArr::printall()
{
	printf("[%d] ", size);
	for (int i = 0; i < size; i++)
	{
		void* data = base[i];
		cout << *(int*)data << " ";
	}
	cout << endl;
}