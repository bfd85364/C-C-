//mylist.cpp
#include <iostream>
using namespace std;
#include "mylist.h"

MyList::MyList() : size(0), head(NULL)
{
}

MyList::~MyList()
{
}

/*
[Insert] 노드 생성 및 초기화 -> 연결[EMPTY, !EMPTY]
*/
void MyList::push_front(void* data)
{
//	Node* newnode = new Node;
//	newnode->data = data; 
//	newnode->next = NULL;
	Node* newnode = new Node(data); 
	if (newnode == NULL)
		throw "노드 생성 에러";

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
	size++;
}

void MyList::push_back(void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		//꼬리 찾기
		Node* cur = head; 
		while (cur->next != NULL)
			cur = cur->next;

		cur->next = newnode;
	}
	size++;
}

void MyList::push_node_next(Node* cur, void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	newnode->next = cur->next; 
	cur->next = newnode;
	size++;
}

/*
[삭제] 삭제할 노드를 찾는다.-> 연결제외
       -> 노드를 제거
*/
void MyList::pop_front()
{
	if (head == NULL)
		throw "Empty";

	Node* del = head;

	head = del->next;

	delete del;

	size--;
}

void MyList::pop_back()
{
	if (head == NULL)
		throw "EMPTY";

	Node* prev = NULL;
	Node* del = head; 
	while (del->next != NULL)
	{
		prev = del;
		del = del->next;
	}

	if (prev == NULL)
		head = NULL;
	else
		prev->next = NULL;

	delete del;
	size--;
}

void MyList::pop_node(Node* cur)
{
	//꼬리노드
	Node* tail = head;
	while (tail->next != NULL)
		tail = tail->next;

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
		Node* prev = head;
		while (prev->next != cur)
			prev = prev->next;

		prev->next = cur->next;
		delete cur;
		size--;
	}
}

//순차적인 순회
void MyList::printall()
{
	printf("[%d] ", size);

	Node* cur = head;
	while ( cur != NULL)
	{
		void* data = cur->data;
		cout << *(int*)data << " ";
		cur = cur->next;
	}
	cout << endl;
}