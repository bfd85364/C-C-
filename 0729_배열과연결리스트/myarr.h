//myarr.h
#pragma once

class MyArr
{
	void* *base;  //�����迭(��), void*
	int max;
	int size;

public:
	MyArr(int _max = 10);
	~MyArr();

public:
	void push_back(void* data);
	void printall();
	void erase(int idx);
};
