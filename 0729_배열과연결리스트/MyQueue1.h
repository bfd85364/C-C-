//MyQueue1.h
//�迭 ť(������ ���� ť)-������� �ϳ��� ����.
#pragma once

class MyQueue1
{
private:
	int max;
	int rear;			//���� ��ġ
	int front;			//���� ��ġ
	void** base;		//�����迭, void* ����

public:
	MyQueue1(int _max = 10);
	~MyQueue1();

public:
	int get_max() const;
	int get_size() const;

public:
	void* get_data(int idx);
	void* operator[](int idx);

public:
	void enqueue(void* data);	//***
	void dequeue();				//***
	void* peek();
	void clear();
	bool is_overflow();
	bool is_empty();
public:
	void print(void (*fun)(void*));
};
