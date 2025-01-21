//mydlist2.cpp
#include <iostream>
using namespace std;
#include "mydlist2.h"

MyDList2::MyDList2()
	: size(0), head(NULL), tail(NULL)
{
}

MyDList2::~MyDList2()
{
}

/*
[Insert] 노드 생성 및 초기화 -> 연결[EMPTY, !EMPTY]
*/
void MyDList2::push_front(void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	size++;
}

void MyDList2::push_back(void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
}

void MyDList2::push_node_next(Node* cur, void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	if (cur != tail)	//중간 노드 삽입
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else   //꼬리 노드 삽입
	{
		newnode->prev = tail;
		cur->next = newnode;
		tail = newnode;
	}


	size++;
}

/*
[삭제] 삭제할 노드를 찾는다.-> 연결제외 -> 노드를 제거
*/
void MyDList2::pop_front()
{
	if (head == NULL)	throw "Empty";

	Node* del = head;
	if (del->next != NULL)  //다음 노드 O
	{
		del->next->prev = NULL;
		head = del->next;
	}
	else  //다음 노드 X
	{
		head = tail = NULL;
	}
	delete del;
	size--;
}

void MyDList2::pop_back()
{
	if (head == NULL)	throw "Empty";

	Node* del = tail;
	if (del->prev != NULL)  //이전 노드 O
	{
		del->prev->next = NULL;
		tail = del->prev;
	}
	else  //이전 노드 X
	{
		head = tail = NULL;
	}
	delete del;
	size--;
}

void MyDList2::pop_node(Node* cur)
{
	if (cur == head)	//첫번째 노드 삭제
	{
		pop_front();
	}
	else if (cur == tail)			//마지막 노드 삭제
	{
		pop_back();
	}
	else
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;

		delete cur;
		size--;
	}
}

void MyDList2::clear()
{
	while (true)
	{
		if (head == NULL)
			break;

		pop_front();
	}
}


MyDList2::Node* MyDList2::select(bool (*fun)(void*))
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		void* data = cur->data;
		if( fun(data) == true)
			return cur;
	}
	return NULL;
}

//순차적인 순회
void MyDList2::printall(void (*fun)(void*))
{
	printall_next(fun);
	printall_prev(fun);
}

void MyDList2::printall_next(void (*fun)(void*))
{
	printf("[%d] ", size);

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		void* data = cur->data;
		fun(data);
	}
	cout << endl;
}

void MyDList2::printall_prev(void (*fun)(void*))
{
	printf("[%d] ", size);

	for (Node* cur = tail; cur != NULL; cur = cur->prev)
	{
		void* data = cur->data;
		fun(data);
	}
	cout << endl;
}