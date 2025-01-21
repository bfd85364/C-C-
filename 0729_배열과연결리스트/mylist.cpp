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
[Insert] ��� ���� �� �ʱ�ȭ -> ����[EMPTY, !EMPTY]
*/
void MyList::push_front(void* data)
{
//	Node* newnode = new Node;
//	newnode->data = data; 
//	newnode->next = NULL;
	Node* newnode = new Node(data); 
	if (newnode == NULL)
		throw "��� ���� ����";

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
		throw "��� ���� ����";

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		//���� ã��
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
		throw "��� ���� ����";

	newnode->next = cur->next; 
	cur->next = newnode;
	size++;
}

/*
[����] ������ ��带 ã�´�.-> ��������
       -> ��带 ����
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
	//�������
	Node* tail = head;
	while (tail->next != NULL)
		tail = tail->next;

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
		Node* prev = head;
		while (prev->next != cur)
			prev = prev->next;

		prev->next = cur->next;
		delete cur;
		size--;
	}
}

//�������� ��ȸ
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