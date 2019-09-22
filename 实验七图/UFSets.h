#include <iostream>
using namespace std;
const int Dsize = 10;
template <class T>
class UFSets
{
public:
	UFSets(int sz);
	~UFSets(){ delete[]parent; }
	void Union(T root1, T root2);//合并
	int Find(T x);//搜索x所在的集合名
private:
	T *parent;
	int size;
};

template <class T>
UFSets<T>::UFSets(int sz)
{
	if (sz > Dsize)
		size = sz;
	else
		size = Dsize;
	parent = new T[size];
	for (int i = 0; i < size; i++)
	{
		parent[i] = i;
	//	cout << parent[i] << " ";
	}
}

template <class T>
int UFSets<T>::Find(T x)//查找x的根节点
{
	while (parent[x] != x)//如果这个元素的节点域大于0，则循链扫描找父节点
		x = parent[x];
	return x;
}

template <class T>
void UFSets<T>::Union(T root1, T root2)//将root2加入到root1里
{
	int x = Find(root1);
	int y = Find(root2);
	if (x == y)
		return;
	else
		parent[x] = y;
}
