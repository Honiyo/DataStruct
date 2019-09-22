#include <iostream>
using namespace std;
#include "graphmtx.h"
void main()
{
	int n;
	cout << "请输入顶点数目：";
	cin >> n;
	Graphmtx<int, int>g(n);
	MinSpanTree<int, int>mst(n);
	MinSpanTree<int, int>mst1(n);
	int *dist=new int[n-1];
	int *path=new int[n-1];
	int flag;
	int x;
	cout << "           1.建立无向邻接表" << endl;
	cout << "           2.建立有向邻接表" << endl;
	cout << "           3.输出邻接表" << endl;
	cout << "           4.计算节点的度" << endl;
	cout << "           5.图的深度优先遍历" << endl;
	cout << "           6.图的广度优先遍历" << endl;
	cout << "           7.Kruskal求最小生成树" << endl;
	cout << "           8.Prim算法求最小生成树" << endl;
	cout << "           9.求单源最短路径" << endl;
	cout << "           0.退出" << endl;
	cout << "请选择：" << endl;
	while (cin >> flag)
	{
		switch (flag)
		{
		case 1:cin >> g; break;
		case 2:g.DirectionGraph(g); break;
		case 3:cout << g; break;
		case 4:
			cout << "输入你要计算度的节点值：";
			cin >> x;
			cout << g.Degree(x) << endl;
			break;
		case 5:
			cout << "您想从那个顶点开始：";
			cin >> x;
			g.DFS(g, x);
			cout << endl;
			break;
		case 6:
			cout << "你想从那个点开始：";
			cin >> x;
			g.BFS(g, x);
			cout << endl;
			break;
		case 7:
			g.Kruskal(g, mst);
			mst.Show(mst);
			break;
		case 8:
			cout << "你想从那个点开始：";
			cin >> x;
			g.Prim(g, x, mst1);
			mst1.Show(mst1);
			break;
		case 9:
			cout << "你想从那个点开始：";
			cin >> x;
			g.ShortPath(g, x, dist, path);
			g.ShowPath(g, x, dist, path);
			break;
		case 0:exit(1);
		}
	}
}