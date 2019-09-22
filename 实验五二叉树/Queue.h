#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int maxsize = 100;
template <class T>
class LinkNode
{
public:
	LinkNode<T> *link;
	T data;
	LinkNode(LinkNode<T> *ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const T& item, LinkNode<T> *ptr = NULL)
	{
		data = item;
		link = ptr;
	}
};


template <class T>
class Queue
{
public:
	Queue(){ front = NULL; rear = NULL; };//构造函数
	~Queue(){ makeempty(); };//析构函数
	bool push(const T& x);//元素入队
	bool pop(T &x);//元素出队
	bool peek(T &x);//取队列头元素
//	bool back(T &x);//取队列尾部元素
	bool Isempty(){ return (front == NULL) ? true : false; };//判断队列是否为空
//	bool Isfull();//判断队列是否已满
	int getsize()const ;//获取队列元素个数
	void makeempty();
protected:
	LinkNode<T> *front, *rear;
};

template <class T>
void Queue<T>::makeempty()
{
	LinkNode<T> *p;
	while (front != NULL)
	{
		p = front;
		front = front->link;
		delete p;
	}
}

template <class T>
bool Queue<T>::push(const T& x)
{
	if (front == NULL)
	{
		front = rear = new LinkNode<T>(x);
		if (front == NULL)
			return false;
	}
	else
	{
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL)
			return false;
		rear = rear->link;
	}
	return true;
}

template <class T>
bool Queue<T>::pop(T &x)
{
	if (Isempty() == true)
		return false;
	LinkNode<T> *p = front;
	x = front->data;
	front = front->link;
	delete p;
	return true;
}

template <class T>
bool Queue<T>::peek(T &x)
{
	if (Isempty() == true)
		return false;
	x = front->data;
	return true;
}

template <class T>
int Queue<T>::getsize()const
{
	LinkNode<T> *p = front;
	int k = 0;
	while (p != NULL)
	{
		p = p->link; k++;
	}
	return k;
}
