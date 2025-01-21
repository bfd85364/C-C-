//mystack1.h
//�迭 ���
#pragma once

class MyStack1
{
private:
	int max;
	int top;			//����, ���� ��ġ
	void* *base;		//�����迭, void* ����

public:
	MyStack1(int _max = 10);
	~MyStack1();

public:
	int get_max() const;
	int get_size() const;

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
	void print( void (*fun)(void*) );
};
