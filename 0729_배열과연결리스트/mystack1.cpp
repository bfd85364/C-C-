//mystack1.cpp
#include <iostream>
using namespace std;
#include "mystack1.h"

MyStack1::MyStack1(int _max /*= 10*/)
	:max(_max), top(-1)
{
	base = new void* [max];
}

MyStack1::~MyStack1()
{
	delete base; 
}

int MyStack1::get_max() const
{
	return max;
}

int MyStack1::get_size() const
{
	return top+1; 
}

void* MyStack1::get_data(int idx)
{
	return base[idx];
}

void* MyStack1::operator[](int idx)
{
	return base[idx];
}

bool MyStack1::is_overflow()
{
	if (top + 1 >= max)		return true;
	else					return false;
}

bool MyStack1::is_empty()
{
	if (top == -1)		return true;
	else				return false; 
}

void MyStack1::push(void* data)
{
	if (is_overflow() == true)
		throw "Overflow";

	top++;
	base[top] = data;  //base[++top] = data;
}

void MyStack1::pop()
{
	if (is_empty() == true)
		throw "Empty";

	top--;
}

void* MyStack1::peek()
{
	if (is_empty())
		throw "Empty";

	return base[top];
}

void MyStack1::clear()
{
	for (int i = 0; i <= top; i++)
	{
		delete base[i];
	}

	top = -1;
}

void MyStack1::print(void (*fun)(void*))
{
	printf("[%d] ", get_size());

	for (int i = 0; i <= top; i++)
	{
		fun(base[i]);
	}
	cout << endl; 
}