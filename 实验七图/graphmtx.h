#include <iostream>
using namespace std;
#include "Queue.h"
#include "heap.h"
#include "UFSets.h"
const int dsize = 30;
const int maxWeight = 100000;
template<class T,class E>
class MSTEdgeNode
{
public:
	int tail, head;
	E key;
	MSTEdgeNode()
	{
		tail = -1;
		head = -1;
		key = 0;
	}
	bool operator<=(MSTEdgeNode<T, E>& R)
	{
		return key <= R.key;
	}
	bool operator>(MSTEdgeNode<T, E>& R)
	{
		return key > R.key;
	}

};

template <class T,class E>
class MinSpanTree
{
protected:
	MSTEdgeNode<T, E>* edgevalue;
	int maxsize, n;
public:
	MinSpanTree(int sz)
	{
		maxsize = sz;
		n = 0;
		edgevalue = new MSTEdgeNode<T, E>[maxsize];
	}
	void Insert(MSTEdgeNode<T,E>& item);
	void Show(MinSpanTree<T, E>& subtree);
};

template <class T,class E>
void MinSpanTree<T, E>::Insert(MSTEdgeNode<T,E>& item)
{
	edgevalue[n] = item;
	n++;
}

template <class T,class E>
void MinSpanTree<T, E>::Show(MinSpanTree<T, E>& subtree)
{
	for (int i = 0; i < maxsize-1; i++)//七个顶点由六条边
		cout << "第" << i + 1 << "条边:" << edgevalue[i].head << " " << edgevalue[i].tail << " " << endl;
}

template <class T,class E>
class Graphmtx
{
	friend istream& operator>>(istream& in, Graphmtx<T, E>& G);
	friend ostream& operator<<(istream& out, Graphmtx<T, E>& G);
public:
	Graphmtx(int sz);
	~Graphmtx(){ delete[]VerticesList; delete[]Edge; }
	T getValue(T i);//获取在顶点表中第i个位置的顶点值
	E getWeight(int v1, int v2);//取边（v1，v2）的权值
	int NumberOfVertices(){ return numVertices; }//当前节点数量
	int NumberOfEdges(){ return numEdges; }//当前边数
	int getFirstNei(int v);//取顶点v的第一个邻接节点
	int getNextNei(int v,int w);
	bool insertVertex(const T& vertex);//插入一个顶点vertex
	bool insertEdge(int v1, int v2, E cost);//插入一条边
	bool removeVertex(T v1);//删除顶点v1
	bool removeEdge(int v1, int v2);//删除一条边
	int findVertex(T v);//查找顶点v在顶点表中的位置
	int Degree(T v);//计算指定顶点的度
	void DirectionGraph(Graphmtx<T, E>& G);//有向图的存储结构
	bool insertDirectionEdge(int v1, int v2, E cost);//在有向图中插入边信息
	void DFS(Graphmtx<T, E>& G, const T& v);//深度优先
	void DFS(Graphmtx<T, E>& G, int v, bool visited[]);
	void BFS(Graphmtx<T, E>& G, const T& v);//广度优先
	void Kruskal(Graphmtx<T, E>& G, MinSpanTree<T, E>& MST);//Kruskal算法
	void Prim(Graphmtx<T, E>& G, const T u0, MinSpanTree<T, E>& MST);//Prim算法
	void ShortPath(Graphmtx<T, E>& G, T v1, E dist[], int path[]);//单源最短路径
	void ShowPath(Graphmtx<T, E>& G, T v1, E dist[], int path[]);//显示路径
private:
	T *VerticesList;//顶点表
	E * * Edge;//无向邻接矩阵
	int maxVertices;//最大可容纳的顶点数
	int numEdges;//边数
	int numVertices;//当前顶点数
};

template <class T,class E>
Graphmtx<T, E>::Graphmtx(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];//创建顶点表数组
	Edge = (E * *)new E *[maxVertices];//创建邻接矩阵数组
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new E[maxVertices];//二维数组的初始化
	for (i = 0; i < maxVertices; i++)
	for (j = 0; j < maxVertices; j++)
	{
		if (i == j)
			Edge[i][j] = 0;
		else
			Edge[i][j] = maxWeight;
	}
}

template <class T,class E>
T Graphmtx<T, E>::getValue(T i)
{
	if (i >= 0 && i <= numVertices)
		return VerticesList[i];
	else
		return NULL;
}

template <class T,class E>
E Graphmtx<T, E>::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
		return Edge[v1][v2];
	else
		return -1;
}

template <class T,class E>
int Graphmtx<T, E>::getFirstNei(int v)
{
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
		if (Edge[v][col]>0 && Edge[v][col] < maxWeight)//两节点间存在权值，且权值不为无穷大
			return col;
	}
	return -1;
}

template <class T, class E>
int Graphmtx<T, E>::getNextNei(int v,int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < numVertices; col++)
		if (Edge[v][col]>0 && Edge[v][col] < maxWeight)//两节点间存在权值，且权值不为无穷大
			return col;
	}
	return -1;
}

template <class T,class E>
bool Graphmtx<T,E>::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)
		return false;//表满，不插入
	VerticesList[numVertices] = vertex;
	numVertices++;
	return true;
}

template <class T,class E>
bool Graphmtx<T, E>::removeVertex(T v1)
{
	int v = findVertex(v1);
	if (v < 0 || v >= maxVertices)
		return false;
	if (numVertices == 1)
		return false;
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];
	for (i = 0; i < numVertices;i++)
	if (Edge[i][v]>0 && Edge[i][v] < maxWeight)
		numEdges--;
	for (i = 0; i < numVertices; i++)
		Edge[i][v] = Edeg[i][numVertices - 1];//用最后一列填补v列
	numVertices--;
	for (j = 0; j < numVertices; j++)//用最后一行填补v行
		Edge[v][j] = Edge[numVertices][j];
	return true;
}

template <class T, class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)
{
	if (v1>-1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
}

template <class T,class E>
bool Graphmtx<T, E>::insertDirectionEdge(int v1, int v2, E cost)
{
	if (v1>-1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
}

template <class T,class E>
bool Graphmtx<T, E>::removeEdge(int v1, int v2)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else
		return false;
}

template <class T,class E>
int Graphmtx<T, E>::findVertex(T v)
{
	for (int k = 0; k < numVertices; k++)
	{
		if (VerticesList[k] == v)
			return k;
	}
	return -1;
}

template <class T,class E>
int Graphmtx<T, E>::Degree(T v)
{
	int count = 0;
	int x = findVertex(v);
	for (int j = 0; j < numVertices; j++)
	{
		if (Edge[x][j]>0 && Edge[x][j] < maxWeight)
			count++;
	}
	return count;
}

template <class T,class E>
void Graphmtx<T, E>::DirectionGraph(Graphmtx<T, E>& G)
{
	int i, j, k, n, m;
	T e1, e2; E weight;
	cout << "请分别输入顶点数n和边数m：" << endl;
	cin >> n >> m;//顶点数n，边数m
	cout << "请输入顶点值：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	cout << "输入边值信息，如 3 5 15：" << endl;
	while (i < m)
	{
		cin >> e1 >> e2 >> weight;
		j = G.findVertex(e1);
		k = G.findVertex(e2);
		if (j == -1 || k == -1)
		{
			cout << "边两端点的信息有误，重新输入！" << endl;
			m = m + 1;
		}
		else
		{
			G.insertDirectionEdge(j, k, weight);
			i++;
		}
	}
}

template <class T,class E>
istream& operator>>(istream& in, Graphmtx<T, E>& G)
{
	int i, j, k, n, m;
	T e1, e2;
	E weight;
	cout << "请分别输入顶点数n和边数m：" << endl;
	in >> n >> m;//顶点数n，边数m
	cout << "请输入顶点值：" << endl;
	for (i = 0; i < n; i++)
	{
		in >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	cout << "输入边值信息，如 3 5 15：" << endl;
	while (i < m)
	{
		in >> e1 >> e2 >> weight;
		j = G.findVertex(e1);
		k = G.findVertex(e2);
		if (j == -1 || k == -1)
		{
			cout << "边两端点的信息有误，重新输入！" << endl;
			m = m + 1;
		}
		else
		{
			G.insertEdge(j, k, weight);
			i++;
		}
	}
	return in;
}

template <class T,class E>
ostream& operator<<(ostream& out, Graphmtx<T, E>& G)
{
	int i, j, n, m;
	T e1, e2;
	E w;
	n = G.NumberOfVertices();
	m = G.NumberOfEdges();
	out << n << " " << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			w = G.getWeight(i, j);
			if (w>0 && w < maxWeight)
			{
				e1 = G.getValue(i);
				e2 = G.getValue(j);
				out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
			}
		}
	}
	return out;
}

template <class T,class E>
void Graphmtx<T, E>::DFS(Graphmtx<T, E>& G, const T& v)
{
	int i, loc, n = G.NumberOfVertices();
	bool * visited = new bool[n];
	for (i = 0; i < n; i++)
		visited[i] = false;
	loc = G.findVertex(v);
	DFS(G, loc, visited);
	delete[]visited;
}

template <class T,class E>
void Graphmtx<T, E>::DFS(Graphmtx<T, E>& G, int v, bool visited[])
{
	cout << G.getValue(v) << " ";
	visited[v] = true;
	int w = G.getFirstNei(v);
	while (w != -1)
	{
		if (visited[w] == false)
			DFS(G, w, visited);
		w = G.getNextNei(v, w);
	}
}

template <class T, class E>
void Graphmtx<T, E>::BFS(Graphmtx<T, E>& G, const T& v)
{
	int i, w, n = G.NumberOfVertices();
	bool * visited = new bool[n];
	for (i = 0; i < n; i++)
		visited[i] = false;
	int loc = G.findVertex(v);
	cout << G.getValue(loc) << " ";
	visited[loc] = true;
	Queue<int>Q;
	Q.push(loc);
	while (!Q.Isempty())
	{
		Q.pop(loc);
		w = G.getFirstNei(loc);
		while (w!= -1)
		{
			if (visited[w] == false)
			{
				cout << G.getValue(w) << " ";
				visited[w] = true;
				Q.push(w);
			}
			w = G.getNextNei(loc, w);
		}
	}
	delete[] visited;
}

template <class T,class E>
void Graphmtx<T, E>::Kruskal(Graphmtx<T, E>& G, MinSpanTree<T, E>& MST)
{
	MSTEdgeNode<T, E>ed;//边节点辅助单元
	int u, v, count;
	int n = G.NumberOfVertices();//顶点数
	int m = G.NumberOfEdges();//边数
	MinHeap<MSTEdgeNode<T, E> >H(m);
	UFSets<T> F(n);
	for (u = 0; u < n; u++)
	{
		for (v = u + 1; v < n; v++)
		{
			if (G.getWeight(u, v) != maxWeight)
			{
				ed.tail = u;
				ed.head = v;
				ed.key = G.getWeight(u, v);
				H.Insert(ed);
			}
		}
	}
	count = 1;
	while (count < n)
	{
		H.RemoveMin(ed);
		u = F.Find(ed.tail);
		v = F.Find(ed.head);
		if (u != v)
		{
			F.Union(u, v);
			MST.Insert(ed);
			count++;
		}
	}
}

template <class T,class E>
void Graphmtx<T,E>::Prim(Graphmtx<T, E>& G, const T u0, MinSpanTree<T, E>& MST)
{
	MSTEdgeNode<T, E>ed;
	int i, v, count;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	int u = G.findVertex(u0);
	MinHeap<MSTEdgeNode<T, E> >H(m);
	bool *Vmst = new bool[n];
	for (i = 0; i < n; i++)
		Vmst[i] = false;
	Vmst[u] = true;
	count = 1;
	do{
		v = G.getFirstNei(u);
		while (v != -1)
		{
			if (Vmst[v] == false)
			{
				ed.tail = u;
				ed.head = v;
				ed.key = G.getWeight(u, v);
				H.Insert(ed);
			}
			v = G.getNextNei(u, v);
		}
		while (H.IsEmpty() == false && count < n)
		{
			H.RemoveMin(ed);
			if (Vmst[ed.head] == false)
			{
				MST.Insert(ed);
				u = ed.head;
				Vmst[u] = true;
				count++;
				break;
			}
		}
	} while (count < n);
}

template <class T,class E>
void Graphmtx<T, E>::ShortPath(Graphmtx<T, E>& G, T v1, E dist[], int path[])
{
	int v = findVertex(v1);
	int n = G.NumberOfVertices();//获取图中的节点数目
	bool *S = new bool[n];//辅助数组，路径的顶点集合
	int i, j, k; E w, min;
	for (i = 0; i < n; i++)
	{
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v&&dist[i] < maxWeight)
			path[i] = v;
		else
			path[i] = -1;
	}
	S[v] = true; dist[v] = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = maxWeight;
		int u = v;
		for (j = 0; j < n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k < n; k++)
		{
			w = G.getWeight(u, k);
			if (S[k] == false && w < maxWeight && dist[u] + w < dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}

template <class T, class E>
void Graphmtx<T, E>::ShowPath(Graphmtx<T, E>& G, T v1, E dist[], int path[])
{
	int v = findVertex(v1);
	cout << "从顶点" << G.getValue(v) << "到其他各顶点的最短路径为：" << endl;
	int i, j, k, n = G.NumberOfVertices();
	int *d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (i != v)
		{
			j = i; k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			cout << "顶点" << G.getValue(i) << "的最短路径为：" << G.getValue(v) << " ";
			while (k > 0)
			{
				cout << G.getValue(d[--k]) << " ";
			}
				cout << "最短路径长度为：" << dist[i] << endl;
			
		}
	}
	delete[]d;
}