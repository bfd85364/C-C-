//mydlist1.h
#pragma once

class Member
{
private:
	string name;
	int age;
public:
	Member(string _name, int _age) :
		name(_name), age(_age)
	{ }
public:
	string get_name() { return name; }
	void print()
	{
		printf("[%s:%d] ", name.c_str(), age);
	}
};

class MyDList1
{
public:
	//이중 연결리스트 노드 
	struct Node
	{
		void* data;
		Node* prev;
		Node* next;
	public:
		Node() {}  //......
		Node(void* _data)
			: data(_data), prev(NULL), next(NULL)
		{}
	};

private:
	Node* head;
	Node* tail;
	int size;	//옵션

public:
	MyDList1();
	~MyDList1();
public:
	Node* get_head() { return head; }
	Node* get_tail() { return tail; }
	int   get_size() { return size; }

public:
	void push_front(void* data);
	void push_back(void* data);
	void push_node_next(Node* cur, void* data);

	void pop_front();
	void pop_back();
	void pop_node(Node* cur);
	void clear();  

	void printall();
	void printall_next();		     //???????
	void printall_prev();			 //???????
	Node* select(string value);	     //???????
};