//MyQueue1.h
//배열 큐(개선된 원형 큐)-저장공간 하나를 비운다.
#pragma once

class MyQueue1
{
private:
	int max;
	int rear;			//저장 위치
	int front;			//삭제 위치
	void** base;		//동적배열, void* 저장

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
