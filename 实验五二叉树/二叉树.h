#include <iostream>
#include <string>
using namespace std;
#include "stack.h";
#include "Queue.h";
/*
二叉树节点类的定义
*/
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
class PostorderNode
{
public:
	BinTreeNode<T> *ptr;
	int tag;
	PostorderNode(BinTreeNode<T> *tl = NULL, int tag = 0)
	{
		ptr = tl;
		tag = 0;
	}
};

template <class T>
class BinTree
{
public:
	static T* px;
	BinTreeNode<T> *root;//二叉树的根节点
	T endflag;//数据停止输入的标志
	void visit(BinTreeNode<T> *rt);//访问函数 √
	void CreateBinTree(BinTreeNode<T>* &BT,char *str);//用广义表建立二叉树 √
	BinTreeNode<T> *copy(BinTreeNode<T> *orignode);//复制树  √
	int Size(BinTreeNode<T> *subtree)const;//返回节点数目   √
	int Leaf(BinTreeNode<T> *subtree)const;//计算树的叶节点   √
	int Height(BinTreeNode<T> *subtree)const;//返回树的高度  √
	BinTreeNode<T>* FindNode(BinTreeNode<T>* subtree,T x);//查找节点  √
	
	int Level(BinTreeNode<T> *subtree, T x);//计算节点层次 √
	int Degree(BinTreeNode<T>* subtree,T x);//计算节点度   √
	void child(BinTreeNode<T> *subtree, T x);//找节点的子女  √
	BinTreeNode<T>* parent(BinTreeNode<T> *subtree, BinTreeNode<T>* current);//返回父节点地址  √
	
	void LevelOrder();//层次遍历  √
	void preOrder(BinTreeNode<T>* subtree);//递归前序遍历  √
	void inOrder(BinTreeNode<T>* subtree);//递归中序遍历  √
	void postOrder(BinTreeNode<T>* subtree);//递归后序遍历  √

	void Preorder(BinTreeNode<T>* subtree);//前序遍历的非递归调用  √
	void Inorder(BinTreeNode<T>* subtree);//中序遍历的非递归调用  √
	void Postorder(BinTreeNode<T>* subtree);//后序遍历的非递归调用  √
	int ReadFile(string str,BinTreeNode<T>* &subtree);//文件读
	int WriteFile(char *str1, string str);//文件写
};
template <class T>
T* BinTree<T>::px = NULL;

template <class T>
void BinTree<T>::visit(BinTreeNode<T> *rt)//访问节点数据的函数
{
	if (rt != NULL)
		cout << rt->data << " ";
}

/*以广义表建立二叉树 类似于 （2，（3，4））*/
template <class T>
void BinTree<T>::CreateBinTree(BinTreeNode<T>* &BT,char *str)
{
	BinTreeNode<T> *size[100], *p = NULL, *b = NULL;
	int top = -1 , k, j = 0;
	char ch;
	for (j = 0; str[j] != endflag; j++)
	{
		ch = str[j];
		switch (ch)
		{
		case '(':top++; size[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:
			p = new BinTreeNode<char>(ch);
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:size[top]->left = p; break;
				case 2:size[top]->right = p; break;
				}
			}
		}

	}
	root = b;
	BT = b;
	root = BT;
}

template <class T>
BinTreeNode<T> * BinTree<T>::copy(BinTreeNode<T>* orignode)//递归调用copy函数复制
{
	if (orignode == NULL)
		return NULL;
	BinTreeNode<T> *t = new BinTreeNode<T>();
	t->data = orignode->data;
	t->left = copy(orignode->left);//要递归调用，不能直接赋值，因为需要分配新的节点空间
	t->right = copy(orignode->right);//同上
	return t;
}

template <class T>
int BinTree<T>::Size(BinTreeNode<T> *subtree)const//递归调用size函数
{
	if (subtree == NULL)
		return 0;
	else
		return 1 + Size(subtree->left) + Size(subtree->right);//分别求到左子树的节点数目和右子树的节点数目
}

template <class T>
int BinTree<T>::Leaf(BinTreeNode<T> *subtree)const
{
	if (subtree == NULL)
		return 0;
	else if (subtree->left == NULL&&subtree->right == NULL)
		return 1;
	else
		return  Leaf(subtree->left) + Leaf(subtree->right);
}

template <class T>
int BinTree<T>::Height(BinTreeNode<T> *subtree)const//递归调用height函数
{
	if (subtree == NULL)
		return 0;
	else
	{
		int a = 1 + Height(subtree->left);
		int b = 1 + Height(subtree->right);
		if (a < b)
			return b;
		else
			return a;//将左右子树求出的高度比较，最大的为树的总高度
	}
}

template <class T>
BinTreeNode<T>* BinTree<T>::FindNode(BinTreeNode<T>* subtree, T x)
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
int BinTree<T>::Level(BinTreeNode<T> *subtree, T x)
{
	int l = 0;
	BinTreeNode<T> *t = FindNode(subtree, x);
	if (t == NULL)
		return 0;
	while (t != subtree)
	{
		l++;
		t = parent(subtree, t);
	}
	return l + 1;
}

template <class T>
int BinTree<T>::Degree(BinTreeNode<T>* subtree,T x)
{
	BinTreeNode<T> *g = FindNode(subtree, x);
	if (g == NULL || (g->left == NULL&&g->right == NULL))
		return 0;
	else if (g->left != NULL&&g->right != NULL)
		return 2;
	else
		return 1;
}


template <class T>
void BinTree<T>::child(BinTreeNode<T> *subtree, T x)
{
	BinTreeNode<T>* p = FindNode(subtree, x);
	if (p->left == NULL&&p->right == NULL)
		cout << "没有找到它的子女" << endl;
	else
	{
		if (p->left == NULL&&p->right != NULL)
			cout << "它没有左子女"<< " " << "它的右子女是：" << p->right->data << endl;
		else if (p->left != NULL&&p->right == NULL)
			cout << "它的左子女是：" << p->left->data << " " << "它没有右子女" << endl;
		else
			cout << "它的左子女是：" << p->left->data << " " << "它的右子女是：" << p->right->data << endl;
	}
}


template <class T>
BinTreeNode<T>* BinTree<T>::parent(BinTreeNode<T> *subtree, BinTreeNode<T>* current)
{
	if (subtree == NULL )
		return NULL;
	if (subtree->left == current || subtree->right == current)
		return subtree;
	BinTreeNode<T>* p;
	p = parent(subtree->left, current);
	if (p != NULL)
		return p;
	else
		return parent(subtree->right, current);	
}

template <class T>
void BinTree<T>::LevelOrder()
{
	Queue<BinTreeNode<T>*> q;
	BinTreeNode<T> *p = root;
	q.push(p);
	while (!q.Isempty())
	{
		q.pop(p); visit(p);
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
}

template <class T>
void BinTree<T>::preOrder(BinTreeNode<T>* subtree)
{
	if (subtree != NULL)
	{
		visit(subtree);
		preOrder(subtree->left);
		preOrder(subtree->right);
	}
}

template <class T>
void BinTree<T>::inOrder(BinTreeNode<T>* subtree)
{
	if (subtree != NULL)
	{
		inOrder(subtree->left);
		visit(subtree);
		inOrder(subtree->right);
	}
}

template <class T>
void BinTree<T>::postOrder(BinTreeNode<T>* subtree)
{
	if (subtree != NULL)
	{
		postOrder(subtree->left);
		postOrder(subtree->right);
		visit(subtree);
	}
}

template <class T>
void BinTree<T>::Preorder(BinTreeNode<T>* subtree)
{
	stack<BinTreeNode<T> * >S;
	BinTreeNode<T> *p;
	S.Push(subtree);
	while (!S.IsEmpty())
	{
		S.Pop(p);
		visit(p);
		if (p->right != NULL)
			S.Push(p->right);
		if (p->left != NULL)
			S.Push(p->left);
	}
}

template <class T>
void BinTree<T>::Inorder(BinTreeNode<T>* subtree)
{
	stack<BinTreeNode<T> * >s;
	BinTreeNode<T> *p = root;
	do
	{
		while (p != NULL)
		{
			s.Push(p);
			p = p->left;
		}
		if (!s.IsEmpty())
		{
			s.Pop(p);
			visit(p);
			p = p->right;
		}
	} while (p != NULL || !s.IsEmpty());
}


template <class T>
void BinTree<T>::Postorder(BinTreeNode<T>* subtree)
{
	stack<PostorderNode<T> > s;
	PostorderNode<T> w;
	BinTreeNode<T> *p = root;
	do
	{
		while (p != NULL)
		{
			w.ptr = p;
			w.tag = 0;
			s.Push(w);
			p = p->left;
		}
		int count = 1;
		while (count&&!s.IsEmpty())
		{
			s.Pop(w);
			p = w.ptr;
			switch (w.tag)
			{
			case 0:
				w.tag = 1;
				s.Push(w);
				count = 0;
				p = p->right;
				break;
			case 1:
				visit(p);
				break;
			}
		}
	} while (!s.IsEmpty());
	cout << endl;
}

template <class T>
int BinTree<T>::ReadFile(string str1,BinTreeNode<T>* &subtree)
{
	BinTreeNode<T> *size[100], *p = NULL, *b = NULL;
	int top = -1, k, j = 0, i = -1;
	char ch, str[100];
	ifstream fin(str1.c_str(), ios::in);
	if (!fin)
	{
		cout << "Cannot open input file!" << endl;
		return 1;
	}
	do
	{
		i++;
		fin >> str[i];
		cout << str[i];
	} while (str[i]!='#');
//	px = str;
	for (j = 0; str[j] != '#'; j++)
	{
		ch = str[j];
		switch (ch)
		{
		case '(':top++; size[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:
			p = new BinTreeNode<char>(ch);
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:size[top]->left = p; break;
				case 2:size[top]->right = p; break;
				}
			}
		}
	}
	root = b;
	subtree = b;
	root = subtree;
	cout << endl;
	fin.close();
	return 0;
}


template <class T>
int BinTree<T>::WriteFile(char *str1,string str)
{
		ofstream fout(str.c_str(), ios::out);
		if (!fout)
		{
			cout << "Cannot open output file!" << endl;
			return 1;
		}
		for (int h = 0; h < strlen(str1); h++)
			fout << str1[h];
		fout << '$';
		fout.close();
		cout << "保存成功！" << endl;
		return 0;
}
