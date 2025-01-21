//MyQueue1.cpp
#include <iostream>
using namespace std;
#include "MyQueue1.h"

MyQueue1::MyQueue1(int _max /*= 10*/)
	:max(_max), rear(0), front(0)
{
	base = new void* [max];
}

MyQueue1::~MyQueue1()
{
	delete base;
}

int MyQueue1::get_max() const
{
	return max;
}

int MyQueue1::get_size() const
{
	int count = 0;
	for (int i = front; i != rear; i = (i + 1) % max)
		count++;

	return count;
}

void* MyQueue1::get_data(int idx)
{
	return base[idx];
}

void* MyQueue1::operator[](int idx)
{
	return base[idx];
}

bool MyQueue1::is_overflow()
{
	return ((rear + 1) % max == front);
}

bool MyQueue1::is_empty()
{
	return (rear == front);
}

void MyQueue1::enqueue(void* data)
{
	if (is_overflow() == true)
		throw "Overflow";

	base[rear] = data;
	rear = (rear + 1) % max;
}

void MyQueue1::dequeue()
{
	if (is_empty() == true)
		throw "Empty";

	front = (front + 1) % max;
}

void* MyQueue1::peek()
{
	if (is_empty())
		throw "Empty";

	return base[front];
}

void MyQueue1::clear()
{
	for (int i = front; i!= rear; i=(i+1)%max)
	{
		delete base[i];
	}

	front = rear = 0;
}

void MyQueue1::print(void (*fun)(void*))
{
	printf("[%d] ", get_size());

	for (int i = front; i != rear; i = (i + 1) % max)
	{
		fun(base[i]);
	}
	cout << endl;
}