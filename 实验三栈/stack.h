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
		cerr << "�洢����ʧ�ܣ�";
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
		cout << "ջ������ʼ���ӵ�Ԫ��" << endl;
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
		cout << "ջ����Ԫ�أ��޷�������" << endl;
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
		cout << "ջ����Ԫ��!�޷�ȡջ��Ԫ��!" << endl;
		cout << endl;
		return false;
	}
	x = elements[top];
	return true;
}

template <class T>
ostream &operator<<(ostream &os, Seqstack<T> &s)
{
	os << "Ŀǰջ��λ��top=" << s.top << endl;
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
	cout << "������һ���ַ�����(С��50�ĳ���)" << endl;
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
	cout << "������һ�����ţ�(С��60�ĳ���)" << endl;
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
		cout << "����ƥ�䣡" << endl;
	else
		cout << "���Ų�ƥ�䣡" << endl;
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
	cout << "�������������ʽ(����#�Ž���)��";
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
