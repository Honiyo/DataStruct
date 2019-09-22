#include <iostream>

#include <string>
using namespace std;
#include "二叉树.h"
void main()
{
	cout << "            本次实验用char类型作为测试类型" << endl;
	cout << "            未使用容错处理" << endl;
	BinTree<char>bt;
	bt.endflag = '#';//输入结束符
	BinTreeNode<char> *btn, *p = NULL, *m;//btn指向二叉树的根，p是操作指针，m为查找双亲时的操作指针
	int flag;       //用户选择的操作
	char str[100], *pt, c;//存储广义表的数组str和指向数组的指针pt，c时用户输入需要执行操作的数
	string str1;//文件名
	char dataflag;//用户操作选择数
	cout << "该压缩包下有一个已经存好数据的文件a.txt" << endl;
	cout << "导入数据?（y/n）" << endl;
	cin >> dataflag;
	switch (dataflag)
	{
	case 'y':
	case 'Y':
		cout << "请输入文件名：" << endl;
		cin >> str1;
		bt.ReadFile(str1, btn);
		goto L;
		break;
	case 'n':
	case 'N':
		goto M;
		break;
	}
M:	cout << "请手动用广义表建立二叉树：" << endl;
	cin >> str;   //输入广义表
	pt = str; //用pt指针指向str数组
	bt.CreateBinTree(btn,pt);
L:	cout << "---------请选择操作---------" << endl;
	cout << "         1.计算节点所在层次" << endl; //  √√
	cout << "         2.统计节点数量" << endl;   //√√
	cout << "         3.统计叶节点数量" << endl;  //√√
	cout << "         4.计算二叉树高度" << endl;  //√√
	cout << "         5.计算某节点的度" << endl;  //√√
	cout << "         6.找某节点的双亲" << endl;  //√√
	cout << "         7.找某节点的子女" << endl;   //√√
	cout << "         8.二叉树的递归前序、中序、后序遍历" << endl;  //√
	cout << "         9.二叉树的非递归前序、中序、后序遍历" << endl; //半√
	cout << "         10.二叉树的层次遍历" << endl;  //√
	cout << "         11.二叉树的复制" << endl;  //√
	cout << "         12.查找节点" << endl; // √√
	cout << "         13.导入数据" << endl;
	cout << "         14.保存数据" << endl;
	cout << "         0.退出" << endl; //√√
	while (cin >> flag)
	{
		switch (flag)
		{
		case 1:
			cout << "请输入你需要确定层次的节点：";
			cin >> c;
			cout << "该节点层次为：" << bt.Level(btn, c)<< endl;
			break;
		case 2:
			cout << "该树的节点数量为：" << bt.Size(btn) << endl;
			break;
		case 3:
			cout << "该树的叶节点数量为：" << bt.Leaf(btn) << endl;
			break;
		case 4:
			cout << "该树的高度为：" << bt.Height(btn) << endl;
			break;
		case 5:
			cout << "请输入你需要确定度数的节点：";
			cin >> c;
			cout << "该节点的度数为：" << bt.Degree(btn,c) << endl;
			break;
		case 6:
			cout << "请输入你需要确定双亲的节点：" << endl;
			cin >> c;
			m = bt.FindNode(btn, c);
			cout << "该节点的双亲是：" << bt.parent(btn, m)->data << endl;	
			break;
		case 7:
			cout << "请输入你需要寻找子女的节点：";
			cin >> c;
			bt.child(btn, c);
			break;
		case 8:
			cout << "递归的前序遍历结果：" << endl;
			bt.preOrder(btn);
			cout << endl;
			cout << "递归的中序遍历结果：" << endl;
			bt.inOrder(btn);
			cout << endl;
			cout << "递归的后序遍历结果：" << endl;
			bt.postOrder(btn);
			cout << endl;
			break;
		case 9:
			cout << "非递归的前序遍历结果：" << endl;
			bt.Preorder(btn);
			cout << endl;
			cout << "非递归的中序遍历结果：" << endl;
			bt.Inorder(btn);
			cout << endl;
			cout << "非递归的后序遍历结果：" << endl;
			bt.Postorder(btn);
			cout << endl;
			break;
		case 10:
			cout << "层次遍历结果：" << endl;
			bt.LevelOrder();
			cout << endl;
			break;
		case 11:
			cout << "二叉树的复制结果的前序遍历结果：" << endl;
			bt.preOrder(bt.copy(btn));
			cout << endl;
			break;
		case 12:
			cout << "请输入需要查找的节点值：";
			cin >> c;
			cout << "查找地址是：" << bt.FindNode(btn, c) << endl;
			cout << "该地址指向的节点数据为：" << bt.FindNode(btn, c)->data << endl;
			break;
		case 13:
			cout << "请输入文件名：" << endl;
			cin >> str1;
			bt.ReadFile(str1, btn);
			break;
		case 14:
			cout << "请输入保存的文件名：" << endl;
			cin >> str1;
			bt.WriteFile(pt, str1);
			break;
		case 0:
			exit(1);
			break;
		}
	}

}