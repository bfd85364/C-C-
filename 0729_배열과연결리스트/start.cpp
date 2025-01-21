//start.cpp
#include <iostream>
using namespace std;

#include "myarr.h"
#include "mylist.h"
#include "mydlist.h"
#include "mydlist1.h"
#include "mydlist2.h"
#include "mystack1.h"
#include "mystack2.h"
#include "MyQueue1.h"


//�迭, ���Ͽ��Ḯ��Ʈ 
void exam1()
{
	MyArr arr(5); //void*�� 5�� ���� ���� ����
	MyList list;  //NULL�� ���� head
	cout << "�ʱ� ����" << endl;
	arr.printall();

	cout << "\n1~5���� ����" << endl;
	for (int i = 1; i <= 5; i++)
	{
		arr.push_back(new int(i));
		arr.printall();
	}
	for (int i = 1; i <= 3; i++)
	{
		//list.push_front(new int(i));
		list.push_back(new int(i));
		list.printall();
	}

	list.push_node_next(
		list.get_head()->next->next, new int(-1));
	list.printall();

	cout << "\n\n����" << endl;
	arr.erase(2);
	arr.printall();

	/*
	try
	{
		for (int i = 0; i < 4; i++)
		{
			//list.pop_front();
			list.pop_back();
			list.printall();
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	*/

	list.pop_node(list.get_head()->next->next->next);
	list.printall();

}

//���߿��Ḯ��Ʈ
void exam2()
{
	cout << "�ʱ� ����" << endl;
	MyDList list; 	
	list.printall();

	cout << "\n1~5���� ����" << endl;
	for (int i = 1; i <= 5; i++)
	{
		list.push_back(new int(i));
		list.printall();
	}

	list.push_node_next(list.get_head(), new int(10));
	list.push_node_next(list.get_tail(), new int(20));
	list.push_node_next(list.get_head()->next, new int(11));
	list.push_node_next(list.get_tail()->prev, new int(12));
	list.printall();

	cout << "\n\n���� ��û" << endl;
	list.pop_node(list.get_head());
	list.pop_node(list.get_tail());
	list.pop_node(list.get_head()->next->next);
	list.printall();

	MyDList::Node* ret = list.select(3);
	if (ret != NULL)
	{
		int*p = (int*)ret->data;
		cout << *p << endl;
	}
	else
	{
		cout << "����" << endl;
	}

	list.clear();
	list.printall();

	//for (int i = 0; i < 9; i++)
	//{
	//	list.pop_back();
	//	list.printall();
	//}
}

//���߿��Ḯ��Ʈ : ����� ���� ��ü�� �ּ�
void exam3()
{
	cout << "�ʱ� ����" << endl;
	MyDList1 list;
	list.printall();

	cout << "\n2�� ��ü" << endl;
	list.push_back(new Member("ȫ�浿", 10));
	list.push_back(new Member("��浿", 20));
	list.printall(); //�ڵ� ����*******************
	
	list.push_node_next(list.get_head(), new Member("�̱浿",30));
	list.printall();
	
	cout << "\n\n���� ��û" << endl;
	list.pop_node(list.get_head());
	//list.pop_node(list.get_tail());
	//list.pop_node(list.get_head()->next);
	list.printall();
	
	MyDList1::Node* ret = list.select("�̱浿");
	if (ret != NULL)
	{
		Member* p = (Member*)ret->data;
		p->print();
	}
	else
	{
		cout << "����" << endl;
	}
}


//���߿��Ḯ��Ʈ : �Լ������� Ȱ��
void exam4_print(void *p)
{
	((Member*)p)->print();
}
bool exam4_select(void* p)
{
	Member* mem = (Member*)p;
	if (mem->get_name() == "ȫ�浿")
		return true;
	else
		return false;
}

void exam4()
{
	cout << "�ʱ� ����" << endl;
	MyDList2 list;
	list.printall(exam4_print);

	cout << "\n2�� ��ü" << endl;
	list.push_back(new Member("ȫ�浿", 10));
	list.push_back(new Member("��浿", 20));
	list.printall(exam4_print); //�ڵ� ����*******************

	list.push_node_next(list.get_head(), new Member("�̱浿", 30));
	list.printall(exam4_print);

	
	cout << "\n\n���� ��û" << endl;
	list.pop_node(list.get_head());
	//list.pop_node(list.get_tail());
	//list.pop_node(list.get_head()->next);
	list.printall(exam4_print);
	
	MyDList2::Node* ret = list.select(exam4_select);
	if (ret != NULL)
	{
		Member* p = (Member*)ret->data;
		p->print();
	}
	else
	{
		cout << "����" << endl;
	}
}

//�迭 ���� 
void exam5_print(void* p)
{
	int* value = (int*)p;
	cout << *value << " ";
}
void exam5()
{
	MyStack1 stack(5);

	for (int i = 1; i <= 5; i++) //1, 2, 3, 4, 5
	{
		stack.push(new int(i));
		stack.print(exam5_print);
	}

	for (int i = 0; i < 3; i++)
	{
		int* value = (int*)stack.peek();
		cout << "�����Ǵ� �� : " << *value << endl;
		delete value;	//***************
		stack.pop();
		stack.print(exam5_print);
	}

	stack.clear();
	stack.print(exam5_print);
}

//���Ḯ��Ʈ ���� ����ϴ� ����
void exam6()
{
	MyDList2 stack;

	for (int i = 1; i <= 5; i++) //1, 2, 3, 4, 5
	{
		stack.push_front(new int(i));
		stack.printall_next(exam5_print);
	}

	for (int i = 0; i < 2; i++)
	{
		MyDList2::Node* node = (MyDList2::Node*)stack.get_head();
		int* value = (int*)node->data;
		cout << "�����Ǵ� �� : " << *value << endl;
		delete value;	//***************
		stack.pop_front();
		stack.printall_next(exam5_print);
	}

	//stack.clear();
	//stack.print(exam5_print);
}

//exam5�� ���� -> ��ü�� ����, �ڵ�� ����!
void exam7()
{
	MyStack2 stack(5);

	for (int i = 1; i <= 5; i++) //1, 2, 3, 4, 5
	{
		stack.push(new int(i));
		stack.print(exam5_print);
	}
	
	for (int i = 0; i < 3; i++)
	{
		int* value = (int*)stack.peek();
		cout << "�����Ǵ� �� : " << *value << endl;
		delete value;	//***************
		stack.pop();
		stack.print(exam5_print);
	}	

	stack.clear();
	stack.print(exam5_print);
}

//�迭��� ť ���
void exam8()
{
	MyQueue1 qu(5);

	for (int i = 1; i <= 4; i++) //1, 2, 3, 4, 5
	{
		qu.enqueue(new int(i));
		qu.print(exam5_print);
	}
		
	for (int i = 0; i < 2; i++)
	{
		int* value = (int*)qu.peek();
		cout << "�����Ǵ� �� : " << *value << endl;
		delete value;	//***************
		qu.dequeue();
		qu.print(exam5_print);
	}
	
	qu.enqueue(new int(10));
	qu.print(exam5_print);
	
	qu.clear();
	qu.print(exam5_print);	
}

int main()
{ 
	exam6();

	return 0;
}