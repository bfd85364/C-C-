//mydlist1.cpp
#include <iostream>
using namespace std;
#include "mydlist1.h"

MyDList1::MyDList1()
	: size(0), head(NULL), tail(NULL)
{
}

MyDList1::~MyDList1()
{
}

/*
[Insert] ��� ���� �� �ʱ�ȭ -> ����[EMPTY, !EMPTY]
*/
void MyDList1::push_front(void* data)
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

void MyDList1::push_back(void* data)
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

void MyDList1::push_node_next(Node* cur, void* data)
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
void MyDList1::pop_front()
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

void MyDList1::pop_back()
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

void MyDList1::pop_node(Node* cur)
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

void MyDList1::clear()
{
	while (true)
	{
		if (head == NULL)
			break;

		pop_front();
	}
}


MyDList1::Node* MyDList1::select(string value)
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		Member* data = (Member*)cur->data;
		if (data->get_name() == value)
			return cur;
	}
	return NULL;
}

//�������� ��ȸ
void MyDList1::printall()
{
	printall_next();
	printall_prev();
}

void MyDList1::printall_next()
{
	printf("[%d] ", size);

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		//�ڵ� ����...
		Member* data = (Member*)cur->data;
		data->print();
	}
	cout << endl;
}

void MyDList1::printall_prev()
{
	printf("[%d] ", size);

	for (Node* cur = tail; cur != NULL; cur = cur->prev)
	{
		//�ڵ� ����...
		Member* data = (Member*)cur->data;
		data->print();
	}
	cout << endl;
}