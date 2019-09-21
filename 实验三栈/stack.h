#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
const int addnum = 20;
template <class T>
class Seqstack
{
private:
	T  *elements;
	int top;
	int maxsize;
public:
	Seqstack(int sz = 150);
	~Seqstack(){ delete[] elements; }
	bool Push(const T& x);
	bool Pop(T &x);
	bool Peek(T &x);
	bool IsEmpty()const{ return(top == -1) ? true : false; }
	bool IsFull()const{ return(top == maxsize - 1) ? true : false; }
	int getnum()const{ return (top + 1); }
	void overflow();
	void MakeEmpty(){ top = -1; }
	int gettop(){ return top; }
	void reversestring();
	void match();
	int instack(char c);
	int outstack(char c);
	void calculate();
	friend ostream &operator<<(ostream &os, Seqstack<T> &s);

};

template <class T>
void Seqstack<T>::overflow()
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
Seqstack<T>::Seqstack(int sz)
{
	top = -1;
	maxsize = sz;
	elements = new T[maxsize];
}

template <class T>
bool Seqstack<T>::Push(const T& x)
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
bool Seqstack<T>::Pop(T &x)
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
bool Seqstack<T>::Peek(T &x)
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
ostream &operator<<(ostream &os, Seqstack<T> &s)
{
	os << "目前栈顶位置top=" << s.top << endl;
	for (int j = s.top; j >=0; j--)
	{
		os << "| " << " " << s.elements[j] << " " << " |" << endl;
	}
	return os;
}

template <class T>
void Seqstack<T>::reversestring()
{
	char c[50];
	char m;
	cout << "请输入一个字符串：(小于50的长度)" << endl;
	cin >> c;
	for (int j = 0; j < strlen(c); j++)
		Push(c[j]);
	for (int i = 0; i < strlen(c); i++)
	{
		Pop(m);
		cout << m;
	}
	cout << endl;
	MakeEmpty();
}

template <class T>
void Seqstack<T>::match()
{
	char c[60];
	char m;
	cout << "请输入一串括号：(小于60的长度)" << endl;
	cin >> c;
	for (int k = 0; k < strlen(c); k++)
	{
		switch (c[k])
		{
		case '(':
		case '{':
		case '[':Push(c[k]); break;
		case ')':
		case '}':
		case ']':Pop(m); break;
		}
	}
	if (IsEmpty() == true)
		cout << "括号匹配！" << endl;
	else
		cout << "括号不匹配！" << endl;
	MakeEmpty();	
}

template <class T>
int Seqstack<T>::instack(char c)
{
	int x;
	switch (c)
	{
	case '#':x = 0; break;
	case '(':x = 1; break;
	case '*':
	case '/':
	case '%':x = 5; break;
	case '+':
	case '-':x = 3; break;
	case ')':x = 6; break;
	}
	return x;
}

template <class T>
int Seqstack<T>::outstack(char c)
{
	int z;
	switch (c)
	{
	case '#':z = 0; break;
	case '(':z = 6; break;
	case '*':
	case '/':
	case '%':z = 4; break;
	case '+':
	case '-':z = 2; break;
	case ')':z = 1; break;
	}
	return z;
}

template <class T>
void Seqstack<T>::calculate()
{
	Seqstack<char> s;
	Seqstack<double>temp;
	char ch = '#', ch1, op;
	double left, right,val, value;
	int i = 0, count = 0;
	double re = 0;
	s.Push(ch);
	char exp[100];
	cout << "请输入算术表达式(并以#号结束)：";
	cin >> exp;
	while (s.IsEmpty() == false )
	{
		if (isdigit(exp[i]))
		{
			temp.Push(exp[i] - '0');
		    count += 1;
			if (!isdigit(exp[i + 1]))
			{
				for (int k = 0; k < count; k++)
				{
					temp.Pop(val);
					re += val*pow(10, k);
				}
				temp.Push(re);
			}
		}
		else
		{
			re = 0;
			count = 0;
			s.Peek(ch1);
			while (instack(ch1) > outstack(exp[i]))
			{
				temp.Pop(right);
				temp.Pop(left);
				s.Pop(op);
				switch (op)
				{
				case '+':value = left + right; temp.Push(value); break;
				case '-':value = left - right; temp.Push(value); break;
				case '*':value = left * right; temp.Push(value); break;
				case '/':
					if (right == 0.0)
					{
						cout << "Divide by 0!" << endl;
						MakeEmpty();
					}
					else{ value = left / right; temp.Push(value); }
					break;
				}
				s.Peek(ch1);
			}
			if (instack(ch1) < outstack(exp[i]))
			{
				s.Push(exp[i]);
			}
			else
			{
				s.Pop(op);
			}
			
		}
		i++;
	}
	cout << temp <<s<< endl;
	temp.MakeEmpty();
	s.MakeEmpty();
}
