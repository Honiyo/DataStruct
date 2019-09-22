#include <iostream>
using namespace std;
const int Dsize = 10;
template <class T>
class UFSets
{
public:
	UFSets(int sz);
	~UFSets(){ delete[]parent; }
	void Union(T root1, T root2);//�ϲ�
	int Find(T x);//����x���ڵļ�����
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
int UFSets<T>::Find(T x)//����x�ĸ��ڵ�
{
	while (parent[x] != x)//������Ԫ�صĽڵ������0����ѭ��ɨ���Ҹ��ڵ�
		x = parent[x];
	return x;
}

template <class T>
void UFSets<T>::Union(T root1, T root2)//��root2���뵽root1��
{
	int x = Find(root1);
	int y = Find(root2);
	if (x == y)
		return;
	else
		parent[x] = y;
}
