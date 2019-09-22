#include <iostream>
#include <string>
using namespace std;
const int defaultsize = 50;
template <class T>
class MinHeap
{
public:
	
	MinHeap(int sz);//构造函数
	bool Insert(const T& x);
	bool RemoveMin(T& x);//删除最小值
	void Create(T arr[], int n);
	~MinHeap(){ delete[]heap; }//析构函数
	bool IsEmpty()//判空
	{
		return (currentsize == 0) ? true : false;
	}
	bool IsFull()//判满
	{
		return(currentsize == maxsize) ? true : false;
	}
	void MakeEmpty(){ currentsize = 0; }//置空函数
private:
	T *heap;//存放小根堆元素的数组
	int currentsize;//当前堆中的元素个数
	int maxsize;//堆最大的容量
	void siftDown(int start, int m);//从start到m下滑调整
	void siftUp(int strat);//从strat到0上滑调整
};

template <class T>
MinHeap<T>::MinHeap(int sz)
{
	if (defaultsize < sz)
		maxsize = sz;
	else
		maxsize = defaultsize;
	heap = new T[maxsize];
	if (heap == NULL)
	{
		cout << "堆存储分配失败！" << endl;
		exit(1);
	}
	currentsize = 0;
}

template <class T>
void MinHeap<T>::Create(T arr[], int n)
{
	heap = new T[maxsize];
	if (heap == NULL)
	{
		cout << "堆存储分配失败！" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++)
		heap[i] = arr[i];
	currentsize = n;
	int currentpos = (currentsize - 2) / 2;
	while (currentpos >= 0)
	{
		siftDown(currentpos,currentsize-1);
		currentpos--;
	}
/*	for (int k = 0; k < n; k++)
		cout << heap[k] << " ";
	cout << endl;*/
}

template <class T>
void MinHeap<T>::siftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	T temp = heap[j];
	while (j>0)
	{
		if (heap[i] <= temp)
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

template <class T>
void MinHeap<T>::siftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	T temp = heap[i];
	while (j <= m)
	{
		if (j<m&&heap[j]>heap[j + 1])j++;
		if (temp <= heap[j])break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

template <class T>
bool MinHeap<T>::Insert(const T& x)
{
	if (currentsize == maxsize)
	{
		cout << "Heap Full!" << endl;
		return false;
	}
	heap[currentsize] = x;
	siftUp(currentsize);
	currentsize++;
/*	for (int k = 0; k < currentsize; k++)
		cout << heap[k] << " ";*/
	return true;
}

template <class T>
bool MinHeap<T>::RemoveMin( T& x)
{
	if (!currentsize)
	{
		cout << "Heap Empty!" << endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[currentsize - 1];
	currentsize--;
	siftDown(0, currentsize - 1);
	return true;
}