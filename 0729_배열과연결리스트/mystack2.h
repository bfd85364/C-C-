//mystack2.h
//����ڰ� �����ϴ� Ŭ����
//���� ������ ���Ḯ��Ʈ�� Ȱ�� ����
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
