#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
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
	List(){ first = new LinkNode<T>; }//
	List(const T& x){ first = new LinkNode<T>(x); }//
	~List(){ makeEmpty();}//
	void makeEmpty();//
	int Length()const;//
	LinkNode<T> *Search(T &x,int &m);//
	LinkNode<T> *Locate(int i,T &x);//
	void Updata(T &x, T &p);//
	bool InsertLocate(int i, T &p);//
	bool Insertbefore(T &x, T &p);//
	bool Insertafter(T &x, T &p);//
	bool RemoveLocate(int i, T &p);//
	bool Remove(T &p,T &x);//
	bool IsEmpty()const
	{
		return first.link == NULL ? true : false;
	}
	bool IsFull()const
	{
		return false;
	}
	int Readfile(string str);
	int Writefile(string str);
	bool Sort();//
	void input(T end);//
	void output();//
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
LinkNode<T> *List<T>::Search(T &x,int &m)
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
LinkNode<T> *List<T>::Locate(int i,T &p)
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
void List<T>::Updata(T &x, T &p)
{
	LinkNode<T> *curr = first->link;
	for (int j = 0; j < Length(); j++)
	{
		if (curr == NULL)
			return;
		else if (curr->data == x)
		{
			curr->data = p; curr = curr->link;
		}
		else
			curr=curr->link;
	}
}

template <class T>
bool List<T>::InsertLocate(int i, T &p)
{
	T d;
	LinkNode<T> *curr = Locate(i-1,d);
	if (curr == NULL)return false;
	LinkNode<T> *newnode = new LinkNode<T>(p);
	if (newnode == NULL)
	{
		cerr << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << endl; exit(1);
	}
	newnode->link = curr->link;
	curr->link = newnode;
	return true;
}

template <class T>
bool List<T>::Insertbefore(T &x, T &p)
{
	int a;
	LinkNode<T> *curr = Search(p,a);
	LinkNode<T> *po = first;
	if (curr == NULL)return false;
	LinkNode<T> *newnode = new LinkNode<T>(x);
	if (newnode == NULL)
	{
		cerr << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << endl; exit(1);
	}
	for (int i = 0; i < Length(); i++)
	{
		if (po->link == curr)
			break;
		else
			po = po->link;
	}
	newnode->link = po->link;
	po->link = newnode;
	return true;
}

template <class T>
bool List<T>::Insertafter(T &x, T &p)
{
	int b ;
	LinkNode<T> *curr = Search(p,b);
	if (curr == NULL)return false;
	LinkNode<T> *newnode = new LinkNode<T>(x);
	if (newnode == NULL)
	{
		cerr << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << endl; exit(1);
	}
	newnode->link = curr->link;
	curr->link = newnode;
	return true;
}

template <class T>
bool List<T>::RemoveLocate(int i, T &p)
{
	T d;
	LinkNode<T> *curr = Locate(i -1,d);
	if (curr == NULL || curr->link == NULL)return false;
	LinkNode<T> *del = curr->link;
	curr->link = del->link;
	p = del->data;
	delete del;
	return true;
}

template <class T>
bool List<T>::Remove(T &p,T &x)
{
/*	int c ;
	LinkNode<T> *xo = first;
	LinkNode<T> *curr = Search(p,c);
	if (curr == NULL)return false;
	LinkNode<T> *del = curr;
	for (int i = 0; i < Length(); i++)
	{
		if (xo->link == curr)
			break;
		else
			xo = xo->link;
	}
	xo->link = del->link;
	x = del->data;
	delete del;
	return true;
*/
	LinkNode<T> *cur = NULL;
/*	while (NULL != first)
	{
		if (p != first->data)
			break;
		cur = first;
		first = first->link;
		x = cur->data;
		delete cur;
	}*/
	cur = first;
	LinkNode<T> *pre = first;
	while (NULL != cur)
	{
		if (p == cur->data)
		{
			x = cur->data;
			pre->link = cur->link;
			delete cur;
		}
		else
			pre = cur;
		cur = pre->link;
	}
	return true;
/*	LinkNode<T> *curr = first->link;
	LinkNode<T> *xo = first;
	int c;
	LinkNode<T> *q = Search(p, c);
	if (c == 0)
		return false;
	for (int j = c; j <= Length(); j++)
	{
		LinkNode<T> *del = curr;
		if (curr->data == p&&curr->link == NULL)
		{
			x = del->data;
			delete del;
			xo->link = NULL;
		}
		else if (curr->data == p)
		{
			xo->link = del->link;
			curr = curr->link;
			x = del->data;
			delete del;
		}
		else
		{
			curr = curr->link;
			xo = xo->link;
		}
	}
	return true;
*/
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
void List<T>::input(T end)
{
	LinkNode<T> *newnode, *last; T val;
	makeEmpty();
	cin >> val; 
	last = first;
	while (val != end)
	{
		newnode = new LinkNode<T>(val);
		if (newnode == NULL)
		{
			cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << endl;
			exit(1);
		}
		last->link = newnode; last = newnode;
		cin >> val;
	}
	last->link = NULL;
}


template <class T>
void List<T>::output()
{
	LinkNode<T> *curr = first->link;
	for (int i = 0; i < Length();i++)
	{
		cout << i + 1 << "    " << curr->data << endl;
		curr = curr->link;
	}
}


template <class T>
int List<T>::Readfile(string str)
{
	LinkNode<T> *newnode, *last;
	last = first;
	ifstream fin(str.c_str(), ios::in);
	if (!fin)
	{
		cout << "Cannot open input file!" << endl;
		return 1;
	}
	LinkNode<T> ds = new LinkNode<T>();
	while (fin >> ds.data)
	{	
		newnode = new LinkNode<T>(ds.data);
		last->link = newnode; last = newnode;
		cout << ds.data << " ";
	}
	cout << endl;
	fin.close();
	return 0;
}


template <class T>
int List<T>::Writefile(string str)
{
	LinkNode<T> *curr = first->link;
	ofstream fout(str.c_str(), ios::out);
	if (!fout)
	{
		cout << "Cannot open output file!" << endl;
		return 1;
	}
	for (int i = 0; i < Length(); i++, curr = curr->link)
		fout << curr->data << " ";
	fout.close();
	cout << "±£´æ³É¹¦£¡" << endl;
	return 0;
}