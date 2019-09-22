#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
const int addnum = 20;
template <class T>
class stack
{
private:
	T  *elements;
	int top;
	int maxsize;
public:
	stack(int sz = 150);
	~stack(){ delete[] elements; }
	bool Push(T &x);
	bool Pop(T &x);
	bool Peek(T &x);
	bool IsEmpty()const{ return(top == -1) ? true : false; }
	bool IsFull()const{ return(top == maxsize - 1) ? true : false; }
	int getnum()const{ return (top + 1); }
	void overflow();
	void MakeEmpty(){ top = -1; }
	bool getTop(T &x);
	friend ostream &operator<<(ostream &os, stack<T> &s);

};

template <class T>
bool stack<T>::getTop(T &x)
{
	if (IsEmpty() == true)
		return 0;
	x = elements[top];
	return true;
}

template <class T>
void stack<T>::overflow()
{
	T *newarray = new T[maxsize + addnum];
	if (newarray = NULL)
	{
		cerr << "存储分配失败！";
		exit(1);
	}
	for (int i = 0; i < maxsize + addnum; i++)
		newarray[i] = elements[i];
	maxsize = maxsize + addnum;
	delete[]elements;
}


template <class T>
stack<T>::stack(int sz)
{
	top = -1;
	maxsize = sz;
	elements = new T[maxsize];
}

template <class T>
bool stack<T>::Push(T &x)
{
	if (IsFull() == true)
	{
		cout << "栈满！开始增加单元！" << endl;
		overflow();
	}
	elements[++top] = x;
	return true;
}

template <class T>
bool stack<T>::Pop(T &x)
{
	if (IsEmpty() == true)
	{
		cout << "栈内无元素！无法弹出！" << endl;
		cout << endl;
		return false;
	}
	x = elements[top];
	top--;
	return true;
}

template <class T>
bool stack<T>::Peek(T &x)
{
	if (IsEmpty() == true)
	{
		cout << "栈内无元素!无法取栈顶元素!" << endl;
		cout << endl;
		return false;
	}
	x = elements[top];
	return true;
}

template <class T>
ostream &operator<<(ostream &os, stack<T> &s)
{
	os << "目前栈顶位置top=" << s.top << endl;
	for (int j = s.top; j >=0; j--)
	{
		os << "| " << " " << s.elements[j] << " " << " |" << endl;
	}
	return os;
}

	