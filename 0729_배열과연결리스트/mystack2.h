//mystack2.h
//사용자가 접근하는 클래스
//실제 연산은 연결리스트를 활용 제공
#pragma once

#include "mydlist2.h" 

class MyStack2
{
private:
	MyDList2 list; 

public:
	MyStack2(int _max = 10);
	~MyStack2();

public:
	int get_max() const;
	int get_size();

public:
	void* get_data(int idx);
	void* operator[](int idx);

public:
	void push(void* data);
	void pop();
	void* peek();
	void clear();
	bool is_overflow();
	bool is_empty();
public:
	void print(void (*fun)(void*));
};
