#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
const int defaultsize = 100;
template <class T>
class Element
{
public:
	T key;
	T otherdata;
	Element<T>* operator=(Element<T>& x)
	{
		key = x.key;
		otherdata = x.otherdata;
		return this;
	}
	bool operator==(Element<T>& x)
	{
		return key == x.key;
	}
	bool operator<=(Element<T>& x)
	{
		return key <= x.key;
	}
	bool operator>(Element<T>& x)
	{
		return key > x.key;
	}
	bool operator<(Element<T>& x)
	{
		return key < x.key;
	}
};

template <class T>
class dataList
{
public:
	dataList(int sz)
	{
		maxSize = sz;
		currentSize = 0;
		Vector = new Element<T>[maxSize];
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		double t = sys.wMilliseconds * 1000 + sys.wSecond + sys.wMinute * 60 + sys.wHour * 360;
		srand(t);
		for (int k = 1; k <= maxSize; k++)
		{
			Vector[k - 1].key = rand();
			cout << Vector[k - 1].key << " ";
			if (k % 10 == 0)
				cout << endl;
		}
		
	}
	dataList()
	{
		maxSize = defaultsize;
		currentSize = 0;
		Vector = new Element<T>[maxSize];
		for (int k = 0; k < maxSize; k++)
			Vector[k].key = 0;
	}
	void Swap(Element<T>& x, Element<T>& y)
	{
		Element<T>temp = x;
		x = y;
		y = temp;
	}
	int Length()
	{
		return currentSize;
	}
	Element<T>& operator[](int i)
	{
		return Vector[i];
	}
	void InsertSort(dataList<T>& L, const int left, const int right);
	void SelectSort(dataList<T>& L, const int left, const int right);
	void merge(dataList<T>& L1, dataList<T>& L2,const int left,const int mid,const int right);
	void mergeSort(dataList<T>& L1, dataList<T>& L2, int left, int right);
	void Exchange(dataList<T>& L, int n);
	void Show(dataList<T>& L,int n);
private:
	Element<T>* Vector;
	int maxSize;
	int currentSize;
};

template <class T>
void dataList<T>::InsertSort(dataList<T>& L, const int left, const int right)
{
	Element<T> temp;
	int i, j;
	for (i = left + 1; i <= right; i++)
	{
		if (L[i] < L[i - 1])
		{
			temp = L[i];
			j = i - 1;
			do{
				L[j + 1] = L[j];
				j--;
			} while (j >= left&&temp < L[j]);
			L[j + 1] = temp;
		}
	}
}

template <class T>
void dataList<T>::SelectSort(dataList<T>& L, const int left, const int right)
{
	for (int i = left; i < right; i++)
	{
		int k = i;
		for (int j = i + 1; j <= right; j++)
		{
			if (L[j] < L[k])
				k = j;
		}
		if (k != i)
			Swap(L[i], L[k]);
	}
}

template <class T>
void dataList<T>::merge(dataList<T>& L1, dataList<T>& L2, const int left, const int mid, const int right)
{
	for (int k = left; k <= right; k++)
	{
		L2[k] = L1[k];
	}
	int s1 = left, s2 = mid + 1, t = left;
	while (s1 <= mid&&s2 <= right)
	{
		if (L2[s1] <= L2[s2])
			L1[t++] = L2[s1++];
		else
			L1[t++] = L2[s2++];
	}
	while (s1 <= mid)
		L1[t++] = L2[s1++];
	while (s2 <= right)
		L1[t++] = L2[s2++];
}

template <class T>
void dataList<T>::Exchange(dataList<T>& L, int n)
{
	bool ex;
	int i, j;
	for (i = 1; i < n; i++)
	{
		ex = false;
		for (j = n - 1; j >= i; j--)
		{
			if (L[j - 1]>L[j])
			{
				Element<T> temp = L[j - 1];
				L[j - 1] = L[j];
				L[j] = temp;
				ex = true;
			}
		}
		if (ex == false)
			return;
	}
}

template <class T>
void dataList<T>::mergeSort(dataList<T>& L1, dataList<T>& L2, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(L1, L2, left, mid);
	mergeSort(L1, L2, mid + 1, right);
	merge(L1, L2, left, mid, right);
}

template <class T>
void dataList<T>::Show(dataList<T>& L,int n)
{
	for (int k = 1; k <= n; k++)
	{
		cout << L[k - 1].key << " ";
		if (k % 10 == 0)
			cout << endl;
	}
	cout << endl;
}