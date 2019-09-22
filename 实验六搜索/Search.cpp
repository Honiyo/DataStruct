#include <iostream>
#include <string>
using namespace std;
#include "Search.h"
void main()
{
	cout << "              本程序产生1000个随机数为测试数据。" << endl;
	cout << "              本程序以double类为测试类型。未做容错处理。" << endl;
	cout << "              将顺序搜索和折半搜索以链表的形式完成" << endl;
	cout << "              顺序搜索、折半搜索、二叉搜索三部分功能分开" << endl;
	BinTreeNode<double> *p, *t;//二叉搜索树的根节点
	List<double> list;//链表对象
	double c;//在二叉搜索树中查找节点c和查找节点c的子女
	char msg;//判断是链表操作还是二叉树操作
	int  flag, num, y, loca, d = 0;//end为结束标志，flag为switch分支变量，num为折半搜索的链表中数据个数
										//y为二叉搜索树需要搜索的值d为计数变量，loca为折半搜索记录元素位置的变量，记录查找的值为链表中第几个元素
	cout << "顺序搜索与折半搜索(y)  二叉树搜索(n)" << endl;
	cin >> msg;
	switch (msg)
	{
	case 'Y':
	case 'y':
		list.input();
		cout << "         1.顺序搜索" << endl;
		cout << "         2.折半搜索" << endl;
		cout << "         0.退出" << endl;
		cout << "请输入选择：" << endl;
		while (cin >> flag)
		{
			switch (flag)
			{
			case 1:
				cout << "请输入需要查找的元素:";
				cin >> list.a.data;
				if (list.Search(list.a.data, d))
				{
					cout << "查找成功！该数据位置是：" << list.Search(list.a.data, d) << endl;
					cout << "查找元素在第" << d << "个位置" << endl;
				}
				else
					cout << "查找失败！" << endl;
				break;
			case 2:
				loca = list.HalfSearch(list);
				if (loca)
				{
					cout << "搜索成功！该元素位于第" << loca - 1 << "个位置" << endl;
				}
				else
					cout << "搜索失败！" << endl;
				break;
			case 0:
				exit(1);
			}
		}
		break;
	case 'N':
	case 'n':
		cout << "请建立二叉搜索树：" << endl;
		list.CreateBinTree(p);
		cout << "         1.二叉搜索树搜索" << endl;
		cout << "         2.查找节点" << endl;
		cout << "         3.找某节点的子女" << endl;
		cout << "         4.删除某节点" << endl;
		cout << "         0.退出" << endl;
		cout << "请输入选择：" << endl;
		while (cin >> flag)
		{
			switch (flag)
			{
			case 1:
				cout << "请输入你要搜索的值：";
				cin >> y;
				list.FindNode(p, y);
				if (list.FindNode(p, y) != NULL)
				{
					t = list.BinTreeSearch(p, y);
					cout << "搜索成功！该值地址是：" << t << endl;
					cout << "该地址指向的值是：" << t->data << endl;
				}
				else
					cout << "搜索失败！" << endl;
				break;
			case 2:
				cout << "请输入需要查找的节点值：";
				cin >> c;
				t = list.FindNode(p, c);
				if (t != NULL)
				{
					cout << "查找地址是：" << t << endl;
					cout << "该地址指向的节点数据为：" << t->data << endl;
				}
				else
					cout << "没有找到该节点！" << endl;
				break;
			case 3:
				cout << "请输入你需要寻找子女的节点：";
				cin >> c;
				list.child(p, c);
				break;
			case 4:
				cout << "请输入你需要删除的节点：";
				cin >> c;
				if (list.dele(p, c))
					cout << "删除成功！" << endl;
				else
					cout << "删除失败！" << endl;
				break;
			case 0:
				exit(1);
			}
		}
	}
}