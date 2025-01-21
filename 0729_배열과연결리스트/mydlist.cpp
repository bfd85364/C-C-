//mydlist.cpp
#include <iostream>
using namespace std;
#include "mydlist.h"

MyDList::MyDList() 
	: size(0), head(NULL), tail(NULL)
{
}

MyDList::~MyDList()
{
}

/*
[Insert] ��� ���� �� �ʱ�ȭ -> ����[EMPTY, !EMPTY]
*/
void MyDList::push_front(void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

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

void MyDList::push_back(void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

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

void MyDList::push_node_next(Node* cur, void* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

	if (cur != tail)	//�߰� ��� ����
	{
		newnode->prev = cur;
		newnode->next = cur->next; 
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else   //���� ��� ����
	{
		newnode->prev = tail;
		cur->next = newnode; 
		tail = newnode; 
	}

	
	size++;
}

/*
[����] ������ ��带 ã�´�.-> �������� -> ��带 ����
*/
void MyDList::pop_front()
{
	if (head == NULL)	throw "Empty";

	Node* del = head;
	if (del->next != NULL)  //���� ��� O
	{
		del->next->prev = NULL;
		head = del->next;		
	}
	else  //���� ��� X
	{
		head = tail = NULL;
	}
	delete del;
	size--;
}

void MyDList::pop_back()
{
	if (head == NULL)	throw "Empty";

	Node* del = tail;
	if (del->prev != NULL)  //���� ��� O
	{
		del->prev->next = NULL;
		tail = del->prev;
	}
	else  //���� ��� X
	{
		head = tail = NULL;
	}
	delete del;
	size--;
}

void MyDList::pop_node(Node* cur)
{
	if (cur == head)	//ù��° ��� ����
	{
		pop_front();
	}
	else if (cur == tail)			//������ ��� ����
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

void MyDList::clear()
{
	while (true)
	{
		if (head == NULL)
			break;

		pop_front();
	}
}


MyDList::Node* MyDList::select(int value)
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		void* data = cur->data;
		if (*(int*)data == value)
			return cur;
	}
	return NULL;
}

//�������� ��ȸ
void MyDList::printall()
{
	printall_next();
	printall_prev();
}

void MyDList::printall_next()
{
	printf("[%d] ", size);
	
	for(Node* cur = head; cur != NULL; cur = cur->next)
	{
		void* data = cur->data;
		cout << *(int*)data << " ";
	}
	cout << endl;
}

void MyDList::printall_prev()
{
	printf("[%d] ", size);

	for (Node* cur = tail; cur != NULL; cur = cur->prev)
	{
		void* data = cur->data;
		cout << *(int*)data << " ";
	}
	cout << endl;
}