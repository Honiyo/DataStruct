#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <windows.h>
template <class T>
class BinTreeNode
{
public:
	T data;//节点数据域
	BinTreeNode<T> *left, *right;//两个指向节点的左子女和右子女的指针
	BinTreeNode()//构造函数，使左右子女均指向空
	{
		left = NULL;
		right = NULL;
	}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)//重载构造函数，传参赋值
	{
		data = x;
		left = l;
		right = r;
	}
};

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
class List
{
protected:
	LinkNode<T> *first;
public:
	LinkNode<T> a;
	LinkNode<T> b;
	int number;
	int number1;
	List(){ first = new LinkNode<T>; }//
	List(const T& x){ first = new LinkNode<T>(x); }//
	~List(){ makeEmpty(); }//
	int Length()const;//
	void makeEmpty();//
	LinkNode<T> *Search(T &x, int &m);//顺序搜索
	LinkNode<T> *Locate(int i, T &x);//定位
	bool Sort();//排序
	int HalfSearch(List<T> &l);//折半搜索
	void input();//随机数输入
	void output();//输出
	bool Insert(BinTreeNode<T>* &subrtree, T &el);//二叉搜索树的插入
	void CreateBinTree(BinTreeNode<T>* &tree);//建立二叉搜索树
	BinTreeNode<T>* BinTreeSearch(BinTreeNode<T>* &subtree,T x);//在二叉搜索树中查找
	BinTreeNode<T>* FindNode(BinTreeNode<T>* &subtree, T x);//查找节点  √
	void child(BinTreeNode<T>* &subtree, T x);//找节点的子女  √
	BinTreeNode<T>* dele(BinTreeNode<T>* &subtree, T x);//删除节点
	BinTreeNode<T>* FindMin(BinTreeNode<T>* subtree);//找到子树中最小的值
};

template <class T>
void List<T>::makeEmpty()
{
	LinkNode<T> *q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template <class T>
int List<T>::Length()const
{
	LinkNode<T> *p = first->link;
	int count = 0;
	while (p != NULL)
	{
		p = p->link;
		count++;
	}
	return count;
}

template <class T>
LinkNode<T> *List<T>::Search(T &x, int &m)
{
	int count = 0;
	LinkNode<T> *curr = first->link;
	while (curr != NULL)
	{
		if (curr->data == x){ count++; break; }
		else { curr = curr->link; count++; }
	}
	m = count;
	return curr;
}

template <class T>
LinkNode<T> *List<T>::Locate(int i, T &p)
{
	if (i < 0)
		return NULL;
	LinkNode<T> *curr = first;
	int k = 0;
	while (curr != NULL&&k < i)
	{
		curr = curr->link;
		k++;
	}
	p = curr->data;
	return curr;
}

template <class T>
bool List<T>::Sort()
{
	LinkNode<T> *p;
	LinkNode<T> *r;
	T temp;
	int i, j;
	for (i = 0, p = first->link; i < Length() - 1; i++, p = p->link)
	{
		for (j = i + 1, r = p->link; j<Length(); j++, r = r->link)
		{
			if (p->data > r->data)
			{
				temp = p->data;
				p->data = r->data;
				r->data = temp;
			}
		}
	}
	return true;
}

template <class T>
void List<T>::input()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	double t = sys.wMilliseconds * 1000 + sys.wSecond + sys.wMinute * 60 + sys.wHour * 360;
	LinkNode<T> *newnode, *last; T val;
	makeEmpty();
	srand(t);
	last = first;
	for (int k = 1; k <= 1000; k++)
	{
		val = rand();
		cout << val << " ";
		newnode = new LinkNode<T>(val);
		if (newnode == NULL)
		{
			cerr << "存储分配失败！" << endl;
			exit(1);
		}
		last->link = newnode; last = newnode;
		if (k % 20 == 0)
			cout << endl;
	}
	cout << endl;
	number = 1000;
	last->link = NULL;
}

template <class T>
void List<T>::output()
{
	LinkNode<T> *curr = first->link;
	for (int i = 1; i <= Length(); i++)
	{

		cout << "第" << i  << "个：" << curr->data << "  ";
		if (i % 7 == 0)
			cout << endl;
		curr = curr->link;
	}
	cout << endl;
}

template <class T>
int List<T>::HalfSearch(List<T> &l)
{
	l.Sort();//升序排列
	l.output();
	T p;
	LinkNode<T>* pt;
	cout << "请输入你想搜索的值：";
	cin >> l.a.data;
	int high = number, low = 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		pt = l.Locate(mid, p);
		if (l.a.data > p)
			low = mid + 1;
		else if (l.a.data < p)
			high = mid - 1;
		else
			return mid + 1;
	}
	return 0;
}

template <class T>
bool List<T>::Insert(BinTreeNode<T>* &subtree, T &el)
{
	if (subtree == NULL)
	{
		subtree = new BinTreeNode<T>(el);
		if (subtree == NULL)
		{
			cout << "分配失败！" << endl;
			exit(1);
		}
		return true;
	}
	else if (el < subtree->data)
		Insert(subtree->left, el);
	else if (el>subtree->data)
		Insert(subtree->right, el);
	else
		return false;
}

template <class T>
void List<T>::CreateBinTree(BinTreeNode<T>* &tree)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	double t = sys.wMilliseconds * 1000 + sys.wSecond + sys.wMinute * 60 + sys.wHour * 360;
	srand(t);
	T x;
	tree = NULL;
	for (int m = 1; m <= 1000;m++)
	{	
		x = rand();
		cout << x << " ";
		Insert(tree, x);
		if (m % 20 == 0)
			cout << endl;
	}
	number1 = 1000;
	cout << endl;
}

template <class T>
BinTreeNode<T>* List<T>::BinTreeSearch(BinTreeNode<T>* &subtree, T x)
{
	if (subtree == NULL)
		cout << "空树！" << endl;
	else if (x < subtree->data)
		BinTreeSearch(subtree->left, x);
	else if (x > subtree->data)
		BinTreeSearch(subtree->right, x);
	else
		return subtree;
}

template <class T>
BinTreeNode<T>* List<T>::FindNode(BinTreeNode<T>* &subtree, T x)
{
	BinTreeNode<T>* m = NULL;
	if (subtree == NULL)
		return NULL;
	if (subtree->data == x)
		return subtree;
	else
	{
		m = FindNode(subtree->left, x);
		if (m&&m->data == x)
			return m;
		else
			return FindNode(subtree->right, x);
	}
}

template <class T>
void List<T>::child(BinTreeNode<T>* &subtree, T x)
{
	BinTreeNode<T>* p = FindNode(subtree, x);
	if (p == NULL)
		cout << "没有找到该节点！" << endl;
	else if (p->left == NULL&&p->right == NULL)
		cout << "没有找到它的子女" << endl;
	else
	{
		if (p->left == NULL&&p->right != NULL)
			cout << "它没有左子女" << " " << "它的右子女是：" << p->right->data << endl;
		else if (p->left != NULL&&p->right == NULL)
			cout << "它的左子女是：" << p->left->data << " " << "它没有右子女" << endl;
		else
			cout << "它的左子女是：" << p->left->data << " " << "它的右子女是：" << p->right->data << endl;
	}
}

template <class T>
BinTreeNode<T>* List<T>::FindMin(BinTreeNode<T>* subtree)
{
	if (subtree)
	while (subtree->left)
	{
		if (subtree->left)
			subtree = subtree->left;
	}
	return subtree;
}

template <class T>
BinTreeNode<T>* List<T>::dele(BinTreeNode<T>* &subtree, T x)
{
	BinTreeNode<T> *temp;
	if (subtree == NULL)
		cout << "空树！" << endl;
	else if (subtree->data > x)
		subtree->left = dele(subtree->left, x);//在左子树执行删除
	else if (subtree->data < x)
		subtree->right = dele(subtree->right, x);//在右子树执行删除
	else//找到了这个值
	{
		if (subtree->left != NULL&&subtree->right != NULL)
		{
			temp = FindMin(subtree->right);//找它右子树中的最小值，也可以找左子树中最大的值
			subtree->data = temp->data;//演变为删除右子树最小值
			subtree->right = dele(subtree->right, subtree->data);
		}
		else//该值只有0或1个子女
		{
			temp = subtree;
			if (!subtree->left)
				subtree = subtree->left;//直接将该值用它的子女替换
			else if (!subtree->right)
				subtree = subtree->right;
			delete temp;
		}
	}
	return subtree;
}