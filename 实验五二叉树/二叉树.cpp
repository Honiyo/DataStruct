#include <iostream>

#include <string>
using namespace std;
#include "������.h"
void main()
{
	cout << "            ����ʵ����char������Ϊ��������" << endl;
	cout << "            δʹ���ݴ���" << endl;
	BinTree<char>bt;
	bt.endflag = '#';//���������
	BinTreeNode<char> *btn, *p = NULL, *m;//btnָ��������ĸ���p�ǲ���ָ�룬mΪ����˫��ʱ�Ĳ���ָ��
	int flag;       //�û�ѡ��Ĳ���
	char str[100], *pt, c;//�洢����������str��ָ�������ָ��pt��cʱ�û�������Ҫִ�в�������
	string str1;//�ļ���
	char dataflag;//�û�����ѡ����
	cout << "��ѹ��������һ���Ѿ�������ݵ��ļ�a.txt" << endl;
	cout << "��������?��y/n��" << endl;
	cin >> dataflag;
	switch (dataflag)
	{
	case 'y':
	case 'Y':
		cout << "�������ļ�����" << endl;
		cin >> str1;
		bt.ReadFile(str1, btn);
		goto L;
		break;
	case 'n':
	case 'N':
		goto M;
		break;
	}
M:	cout << "���ֶ��ù��������������" << endl;
	cin >> str;   //��������
	pt = str; //��ptָ��ָ��str����
	bt.CreateBinTree(btn,pt);
L:	cout << "---------��ѡ�����---------" << endl;
	cout << "         1.����ڵ����ڲ��" << endl; //  �̡�
	cout << "         2.ͳ�ƽڵ�����" << endl;   //�̡�
	cout << "         3.ͳ��Ҷ�ڵ�����" << endl;  //�̡�
	cout << "         4.����������߶�" << endl;  //�̡�
	cout << "         5.����ĳ�ڵ�Ķ�" << endl;  //�̡�
	cout << "         6.��ĳ�ڵ��˫��" << endl;  //�̡�
	cout << "         7.��ĳ�ڵ����Ů" << endl;   //�̡�
	cout << "         8.�������ĵݹ�ǰ�����򡢺������" << endl;  //��
	cout << "         9.�������ķǵݹ�ǰ�����򡢺������" << endl; //���
	cout << "         10.�������Ĳ�α���" << endl;  //��
	cout << "         11.�������ĸ���" << endl;  //��
	cout << "         12.���ҽڵ�" << endl; // �̡�
	cout << "         13.��������" << endl;
	cout << "         14.��������" << endl;
	cout << "         0.�˳�" << endl; //�̡�
	while (cin >> flag)
	{
		switch (flag)
		{
		case 1:
			cout << "����������Ҫȷ����εĽڵ㣺";
			cin >> c;
			cout << "�ýڵ���Ϊ��" << bt.Level(btn, c)<< endl;
			break;
		case 2:
			cout << "�����Ľڵ�����Ϊ��" << bt.Size(btn) << endl;
			break;
		case 3:
			cout << "������Ҷ�ڵ�����Ϊ��" << bt.Leaf(btn) << endl;
			break;
		case 4:
			cout << "�����ĸ߶�Ϊ��" << bt.Height(btn) << endl;
			break;
		case 5:
			cout << "����������Ҫȷ�������Ľڵ㣺";
			cin >> c;
			cout << "�ýڵ�Ķ���Ϊ��" << bt.Degree(btn,c) << endl;
			break;
		case 6:
			cout << "����������Ҫȷ��˫�׵Ľڵ㣺" << endl;
			cin >> c;
			m = bt.FindNode(btn, c);
			cout << "�ýڵ��˫���ǣ�" << bt.parent(btn, m)->data << endl;	
			break;
		case 7:
			cout << "����������ҪѰ����Ů�Ľڵ㣺";
			cin >> c;
			bt.child(btn, c);
			break;
		case 8:
			cout << "�ݹ��ǰ����������" << endl;
			bt.preOrder(btn);
			cout << endl;
			cout << "�ݹ��������������" << endl;
			bt.inOrder(btn);
			cout << endl;
			cout << "�ݹ�ĺ�����������" << endl;
			bt.postOrder(btn);
			cout << endl;
			break;
		case 9:
			cout << "�ǵݹ��ǰ����������" << endl;
			bt.Preorder(btn);
			cout << endl;
			cout << "�ǵݹ��������������" << endl;
			bt.Inorder(btn);
			cout << endl;
			cout << "�ǵݹ�ĺ�����������" << endl;
			bt.Postorder(btn);
			cout << endl;
			break;
		case 10:
			cout << "��α��������" << endl;
			bt.LevelOrder();
			cout << endl;
			break;
		case 11:
			cout << "�������ĸ��ƽ����ǰ����������" << endl;
			bt.preOrder(bt.copy(btn));
			cout << endl;
			break;
		case 12:
			cout << "��������Ҫ���ҵĽڵ�ֵ��";
			cin >> c;
			cout << "���ҵ�ַ�ǣ�" << bt.FindNode(btn, c) << endl;
			cout << "�õ�ַָ��Ľڵ�����Ϊ��" << bt.FindNode(btn, c)->data << endl;
			break;
		case 13:
			cout << "�������ļ�����" << endl;
			cin >> str1;
			bt.ReadFile(str1, btn);
			break;
		case 14:
			cout << "�����뱣����ļ�����" << endl;
			cin >> str1;
			bt.WriteFile(pt, str1);
			break;
		case 0:
			exit(1);
			break;
		}
	}

}