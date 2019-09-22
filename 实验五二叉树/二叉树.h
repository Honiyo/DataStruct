#include <iostream>
#include <string>
using namespace std;
#include "stack.h";
#include "Queue.h";
/*
�������ڵ���Ķ���
*/
template <class T>
class BinTreeNode
{
public:
	
	T data;//�ڵ�������
	BinTreeNode<T> *left, *right;//����ָ��ڵ������Ů������Ů��ָ��
	BinTreeNode()//���캯����ʹ������Ů��ָ���
	{
		left = NULL;
		right = NULL;
	}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)//���ع��캯�������θ�ֵ
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
	BinTreeNode<T> *root;//�������ĸ��ڵ�
	T endflag;//����ֹͣ����ı�־
	void visit(BinTreeNode<T> *rt);//���ʺ��� ��
	void CreateBinTree(BinTreeNode<T>* &BT,char *str);//�ù������������ ��
	BinTreeNode<T> *copy(BinTreeNode<T> *orignode);//������  ��
	int Size(BinTreeNode<T> *subtree)const;//���ؽڵ���Ŀ   ��
	int Leaf(BinTreeNode<T> *subtree)const;//��������Ҷ�ڵ�   ��
	int Height(BinTreeNode<T> *subtree)const;//�������ĸ߶�  ��
	BinTreeNode<T>* FindNode(BinTreeNode<T>* subtree,T x);//���ҽڵ�  ��
	
	int Level(BinTreeNode<T> *subtree, T x);//����ڵ��� ��
	int Degree(BinTreeNode<T>* subtree,T x);//����ڵ��   ��
	void child(BinTreeNode<T> *subtree, T x);//�ҽڵ����Ů  ��
	BinTreeNode<T>* parent(BinTreeNode<T> *subtree, BinTreeNode<T>* current);//���ظ��ڵ��ַ  ��
	
	void LevelOrder();//��α���  ��
	void preOrder(BinTreeNode<T>* subtree);//�ݹ�ǰ�����  ��
	void inOrder(BinTreeNode<T>* subtree);//�ݹ��������  ��
	void postOrder(BinTreeNode<T>* subtree);//�ݹ�������  ��

	void Preorder(BinTreeNode<T>* subtree);//ǰ������ķǵݹ����  ��
	void Inorder(BinTreeNode<T>* subtree);//��������ķǵݹ����  ��
	void Postorder(BinTreeNode<T>* subtree);//��������ķǵݹ����  ��
	int ReadFile(string str,BinTreeNode<T>* &subtree);//�ļ���
	int WriteFile(char *str1, string str);//�ļ�д
};
template <class T>
T* BinTree<T>::px = NULL;

template <class T>
void BinTree<T>::visit(BinTreeNode<T> *rt)//���ʽڵ����ݵĺ���
{
	if (rt != NULL)
		cout << rt->data << " ";
}

/*�Թ������������ ������ ��2����3��4����*/
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
BinTreeNode<T> * BinTree<T>::copy(BinTreeNode<T>* orignode)//�ݹ����copy��������
{
	if (orignode == NULL)
		return NULL;
	BinTreeNode<T> *t = new BinTreeNode<T>();
	t->data = orignode->data;
	t->left = copy(orignode->left);//Ҫ�ݹ���ã�����ֱ�Ӹ�ֵ����Ϊ��Ҫ�����µĽڵ�ռ�
	t->right = copy(orignode->right);//ͬ��
	return t;
}

template <class T>
int BinTree<T>::Size(BinTreeNode<T> *subtree)const//�ݹ����size����
{
	if (subtree == NULL)
		return 0;
	else
		return 1 + Size(subtree->left) + Size(subtree->right);//�ֱ����������Ľڵ���Ŀ���������Ľڵ���Ŀ
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
int BinTree<T>::Height(BinTreeNode<T> *subtree)const//�ݹ����height����
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
			return a;//��������������ĸ߶ȱȽϣ�����Ϊ�����ܸ߶�
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
		cout << "û���ҵ�������Ů" << endl;
	else
	{
		if (p->left == NULL&&p->right != NULL)
			cout << "��û������Ů"<< " " << "��������Ů�ǣ�" << p->right->data << endl;
		else if (p->left != NULL&&p->right == NULL)
			cout << "��������Ů�ǣ�" << p->left->data << " " << "��û������Ů" << endl;
		else
			cout << "��������Ů�ǣ�" << p->left->data << " " << "��������Ů�ǣ�" << p->right->data << endl;
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
		cout << "����ɹ���" << endl;
		return 0;
}
