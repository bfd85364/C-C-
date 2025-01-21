//mylist.h
#pragma once

//���� ���Ḯ��Ʈ ��� 
struct Node
{
	void* data; 
	Node* next;
public:
	Node() {}  //......
	Node(void* _data) : data(_data), next(NULL)
	{}
};

class MyList
{
private:
	Node* head; 
	int size;	//�ɼ�

public:
	MyList();
	~MyList();
public:
	Node* get_head() { return head;  }

public:
	void push_front(void* data);
	void push_back(void* data);
	void push_node_next(Node* cur, void* data);

	void pop_front();
	void pop_back();
	void pop_node(Node* cur);

	void printall();
};