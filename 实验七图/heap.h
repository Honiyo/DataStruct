#include <iostream>
#include <string>
using namespace std;
const int defaultsize = 50;
template <class T>
class MinHeap
{
public:
	
	MinHeap(int sz);//���캯��
	bool Insert(const T& x);
	bool RemoveMin(T& x);//ɾ����Сֵ
	void Create(T arr[], int n);
	~MinHeap(){ delete[]heap; }//��������
	bool IsEmpty()//�п�
	{
		return (currentsize == 0) ? true : false;
	}
	bool IsFull()//����
	{
		return(currentsize == maxsize) ? true : false;
	}
	void MakeEmpty(){ currentsize = 0; }//�ÿպ���
private:
	T *heap;//���С����Ԫ�ص�����
	int currentsize;//��ǰ���е�Ԫ�ظ���
	int maxsize;//����������
	void siftDown(int start, int m);//��start��m�»�����
	void siftUp(int strat);//��strat��0�ϻ�����
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
		cout << "�Ѵ洢����ʧ�ܣ�" << endl;
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
		cout << "�Ѵ洢����ʧ�ܣ�" << endl;
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