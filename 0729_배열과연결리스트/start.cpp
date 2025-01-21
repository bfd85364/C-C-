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


//배열, 단일연결리스트 
void exam1()
{
	MyArr arr(5); //void*를 5개 저장 공간 생성
	MyList list;  //NULL을 저장 head
	cout << "초기 상태" << endl;
	arr.printall();

	cout << "\n1~5까지 저장" << endl;
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

	cout << "\n\n삭제" << endl;
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

//이중연결리스트
void exam2()
{
	cout << "초기 상태" << endl;
	MyDList list; 	
	list.printall();

	cout << "\n1~5까지 저장" << endl;
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

	cout << "\n\n삭제 요청" << endl;
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
		cout << "없다" << endl;
	}

	list.clear();
	list.printall();

	//for (int i = 0; i < 9; i++)
	//{
	//	list.pop_back();
	//	list.printall();
	//}
}

//이중연결리스트 : 사용자 정의 객체의 주소
void exam3()
{
	cout << "초기 상태" << endl;
	MyDList1 list;
	list.printall();

	cout << "\n2개 객체" << endl;
	list.push_back(new Member("홍길동", 10));
	list.push_back(new Member("김길동", 20));
	list.printall(); //코드 수정*******************
	
	list.push_node_next(list.get_head(), new Member("이길동",30));
	list.printall();
	
	cout << "\n\n삭제 요청" << endl;
	list.pop_node(list.get_head());
	//list.pop_node(list.get_tail());
	//list.pop_node(list.get_head()->next);
	list.printall();
	
	MyDList1::Node* ret = list.select("이길동");
	if (ret != NULL)
	{
		Member* p = (Member*)ret->data;
		p->print();
	}
	else
	{
		cout << "없다" << endl;
	}
}


//이중연결리스트 : 함수포인터 활용
void exam4_print(void *p)
{
	((Member*)p)->print();
}
bool exam4_select(void* p)
{
	Member* mem = (Member*)p;
	if (mem->get_name() == "홍길동")
		return true;
	else
		return false;
}

void exam4()
{
	cout << "초기 상태" << endl;
	MyDList2 list;
	list.printall(exam4_print);

	cout << "\n2개 객체" << endl;
	list.push_back(new Member("홍길동", 10));
	list.push_back(new Member("김길동", 20));
	list.printall(exam4_print); //코드 수정*******************

	list.push_node_next(list.get_head(), new Member("이길동", 30));
	list.printall(exam4_print);

	
	cout << "\n\n삭제 요청" << endl;
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
		cout << "없다" << endl;
	}
}

//배열 스택 
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
		cout << "삭제되는 값 : " << *value << endl;
		delete value;	//***************
		stack.pop();
		stack.print(exam5_print);
	}

	stack.clear();
	stack.print(exam5_print);
}

//연결리스트 직접 사용하는 스택
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
		cout << "삭제되는 값 : " << *value << endl;
		delete value;	//***************
		stack.pop_front();
		stack.printall_next(exam5_print);
	}

	//stack.clear();
	//stack.print(exam5_print);
}

//exam5를 복사 -> 객체만 변경, 코드는 동일!
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
		cout << "삭제되는 값 : " << *value << endl;
		delete value;	//***************
		stack.pop();
		stack.print(exam5_print);
	}	

	stack.clear();
	stack.print(exam5_print);
}

//배열기반 큐 사용
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
		cout << "삭제되는 값 : " << *value << endl;
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