#include <iostream>
using namespace std;
#include "graphmtx.h"
void main()
{
	int n;
	cout << "�����붥����Ŀ��";
	cin >> n;
	Graphmtx<int, int>g(n);
	MinSpanTree<int, int>mst(n);
	MinSpanTree<int, int>mst1(n);
	int *dist=new int[n-1];
	int *path=new int[n-1];
	int flag;
	int x;
	cout << "           1.���������ڽӱ�" << endl;
	cout << "           2.���������ڽӱ�" << endl;
	cout << "           3.����ڽӱ�" << endl;
	cout << "           4.����ڵ�Ķ�" << endl;
	cout << "           5.ͼ��������ȱ���" << endl;
	cout << "           6.ͼ�Ĺ�����ȱ���" << endl;
	cout << "           7.Kruskal����С������" << endl;
	cout << "           8.Prim�㷨����С������" << endl;
	cout << "           9.��Դ���·��" << endl;
	cout << "           0.�˳�" << endl;
	cout << "��ѡ��" << endl;
	while (cin >> flag)
	{
		switch (flag)
		{
		case 1:cin >> g; break;
		case 2:g.DirectionGraph(g); break;
		case 3:cout << g; break;
		case 4:
			cout << "������Ҫ����ȵĽڵ�ֵ��";
			cin >> x;
			cout << g.Degree(x) << endl;
			break;
		case 5:
			cout << "������Ǹ����㿪ʼ��";
			cin >> x;
			g.DFS(g, x);
			cout << endl;
			break;
		case 6:
			cout << "������Ǹ��㿪ʼ��";
			cin >> x;
			g.BFS(g, x);
			cout << endl;
			break;
		case 7:
			g.Kruskal(g, mst);
			mst.Show(mst);
			break;
		case 8:
			cout << "������Ǹ��㿪ʼ��";
			cin >> x;
			g.Prim(g, x, mst1);
			mst1.Show(mst1);
			break;
		case 9:
			cout << "������Ǹ��㿪ʼ��";
			cin >> x;
			g.ShortPath(g, x, dist, path);
			g.ShowPath(g, x, dist, path);
			break;
		case 0:exit(1);
		}
	}
}