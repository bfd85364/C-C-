//mystack2.cpp
#include <iostream>
using namespace std;
#include "mystack2.h"

MyStack2::MyStack2(int _max /*= 10*/)	
{
}

MyStack2::~MyStack2()
{
}

int MyStack2::get_max() const
{
	throw "사용하지 않는 메서드";
	return -1;
}

int MyStack2::get_size() 
{	
	return list.get_size();
}

void* MyStack2::get_data(int idx)
{
	MyDList2::Node* cur = list.get_head();
	for (int i = 0; i < idx; i++)
		cur = cur->next;

	return cur->data;
}

void* MyStack2::operator[](int idx)
{
	MyDList2::Node* cur = list.get_head();
	for (int i = 0; i < idx; i++)
		cur = cur->next;

	return cur->data;
}

bool MyStack2::is_overflow()
{
	return false;
}

bool MyStack2::is_empty()
{
	if (list.get_head() == NULL)		return true;
	else								return false;
}

void MyStack2::push(void* data)
{
	list.push_front(data);
}

void MyStack2::pop()
{
	if (is_empty() == true)
		throw "Empty";

	list.pop_front();
}

void* MyStack2::peek()
{
	if (is_empty())
		throw "Empty";

	return list.get_head()->data;
}

void MyStack2::clear()
{
	while(true)
	{
		if (list.get_head() == NULL)
			break;

		delete list.get_head()->data;
		list.pop_front();
	}	
}

void MyStack2::print(void (*fun)(void*))
{
	printf("[%d] ", get_size());
	
	for(MyDList2::Node* b = list.get_head();
		b != NULL; b = b->next)
	{	
		fun(b->data);
	}
	cout << endl;
}