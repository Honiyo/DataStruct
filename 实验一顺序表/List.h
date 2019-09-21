#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const int defaultSize = 100;
template <class T>
class SeqList
{
protected:
	T *data;     //模板数组
	int maxsize; //最大容量
	int last;    //表的项数
public:
	T a;
	T b;
	SeqList(int sz = defaultSize); //构造函数
	~SeqList(){ delete[] data; }   //析构函数 释放数组
	int Size()const{ return maxsize; } //返回容量
	int Length()const{ return last + 1; } //返回长度
	int Search(T &x)const;//查找指定元素
	int Location(T &x)const;//定位指定元素的序号
	void Updata(T &p, T &x);//修改指定元素的数据
	bool Insert(int i, T &x);//插入在指定位置
	bool Insertbefore(T &p, T &x);//插入在指定元素之前
	bool Insertafter(T &p, T &x);//插入在指定元素之后
	bool Remove(int i, T &x);//删除指定位置的元素
	bool Removepoint(T &p); // 删除指定元素
	int Readfile(string str,T &x);
	int Writefile(string str);
	bool Sort();
	void input();
	void output();
};

template<class T>
SeqList<T>::SeqList(int sz)
{
	if (sz>0)
	{
		maxsize = sz;
		last = -1; 
		data = new T[maxsize];
		if (data == NULL)
		{
			cerr << "存储分配失败！" << endl; exit(1);
		}
	}
}

template<class T>
int SeqList<T>::Search(T &x)const
{
	for (int i = 0; i < last; i++)
	if (data[i] == x)
		return i + 1;
	return 0;
}

template<class T>
int SeqList<T>::Location(T &x)const
{
	for (int i = 0; i < last; i++)
	if (data[i] == x)
		return i + 1;
	return 0;
}

template<class T>
void SeqList<T>::Updata(T &p, T &x)
{
	int m = 0;
	for (int i = 0; i < last; i++)
	{
		if (data[i] == p)
			data[i] = x;
		else
			m++;
	}
	if (m == last)
		cout << "没有可更新的数据！" << endl;
}

template<class T>
bool SeqList<T>::Insert(int i, T &x)
{
	if (last == maxsize - 1)
		return false;
	if (i<0 || i>=last )
		return false;
	for (int j = last-1; j >= i-1; j--)
		data[j + 1] = data[j];
	data[i-1] = x;
	last++;
	return true;
}

template<class T>
bool SeqList<T>::Insertbefore(T &p, T &x)
{
	int count = 0;
	if (last == maxsize - 1)
		return false;
	for (int k = 0; k < last; k++)
	{
		if (data[k] == x)
		{
			for (int j = last-1; j >= k; j--)
				data[j + 1] = data[j];
			data[k] = p;
			last++;
			break;
		}
		else count++;
		if (count == last )
			return false;
	}
	return true;
}

template<class T>
bool SeqList<T>::Insertafter(T &p, T &x)
{
	int count = 0;
	if (last == maxsize - 1)
		return false;
	for (int k = 0; k < last; k++)
	{
		if (data[k] == x)
		{
			for (int j = last - 1; j >= k + 1; j--)
				data[j + 1] = data[j];
			data[k + 1] = p;
			last++;
			break;
		}
		else
			count++;
		if (count == last )
			return false;
	}
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T &x)
{
	if (last == -1)
		return false;
	if (i<1 || i>=last)
		return false;
	x = data[i - 1];
	for (int j = i; j < last; j++)
		data[j - 1] = data[j];
	last--;
	return true;
}

template<class T>
bool SeqList<T>::Removepoint(T &p)
{
	int count = 0;
	for (int i = last-1; i >=0 ; i--)
	if (data[i] == p)
	{
		for (int j = i; j < last; j++)
			data[j] = data[j + 1];
		last--;
	}
	else
		count++;
	if (count == last)
		return false;
	return true;
}

template <class T>
bool SeqList<T>::Sort()
{
	T temp;
	int i, j, k;
	for (i = 0; i < last - 1; i++)
	{
		k = i;
		for (j = i + 1; j < last;j++)
		if (data[j] < data[k])
			k = j;
		if (i != k)
		{
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}

	}
	return true;
}

template<class T>
void SeqList<T>::input()
{
	cout << "开始建立顺序表，请输入表中元素个数: ";
	while (1){
		cin >> last;
		if (last <= maxsize - 1)break;
		cout << "表元素个数输入有误！";
	}
	for (int i = 0; i<last; i++)
	{
Qu:		cout << "第" << i + 1 << "个：";
		cin >> data[i];
		if (cin.fail())
		{
			cout << "数据类型错误！请重新输入！" << endl;
			cin.clear();
			cin.sync();
			goto Qu;
		}
	}
}

template<class T>
void SeqList<T>::output()
{
	cout << "顺序表当前元素最后位置:" << last-1 << endl;
	for (int i = 0; i<last; i++)
		cout << "$" << i + 1 << ":" << data[i] << endl;
}


template <class T>
int SeqList<T>::Writefile(string str)
{
	ofstream fout(str.c_str(), ios::out);
	if (!fout)
	{
		cout << "Cannot open output file!" << endl;
		return 1;
	}
	for (int i = 0; i < last; i++)
		fout << data[i] << " ";
	fout.close();
	cout << "保存成功！" << endl;
	return 0;
}

template <class T>
int SeqList<T>::Readfile(string str,T &x)
{
	ifstream fin(str.c_str(), ios::in);
	if (!fin)
	{
		cout << "Cannot open input file!" << endl;
		return 1;
	}
	T *ds = new T[maxsize];
	for (int i = 0; i < last; i++)
		fin >> ds[i];
	for (int j = 0; j < last; j++)
		cout << ds[j] << " ";
	x = ds[0];
	cout << endl;
	fin.close();
	return 0;
}


