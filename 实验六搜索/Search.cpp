#include <iostream>
#include <string>
using namespace std;
#include "Search.h"
void main()
{
	cout << "              ���������1000�������Ϊ�������ݡ�" << endl;
	cout << "              ��������double��Ϊ�������͡�δ���ݴ���" << endl;
	cout << "              ��˳���������۰��������������ʽ���" << endl;
	cout << "              ˳���������۰��������������������ֹ��ֿܷ�" << endl;
	BinTreeNode<double> *p, *t;//�����������ĸ��ڵ�
	List<double> list;//�������
	double c;//�ڶ����������в��ҽڵ�c�Ͳ��ҽڵ�c����Ů
	char msg;//�ж�������������Ƕ���������
	int  flag, num, y, loca, d = 0;//endΪ������־��flagΪswitch��֧������numΪ�۰����������������ݸ���
										//yΪ������������Ҫ������ֵdΪ����������locaΪ�۰�������¼Ԫ��λ�õı�������¼���ҵ�ֵΪ�����еڼ���Ԫ��
	cout << "˳���������۰�����(y)  ����������(n)" << endl;
	cin >> msg;
	switch (msg)
	{
	case 'Y':
	case 'y':
		list.input();
		cout << "         1.˳������" << endl;
		cout << "         2.�۰�����" << endl;
		cout << "         0.�˳�" << endl;
		cout << "������ѡ��" << endl;
		while (cin >> flag)
		{
			switch (flag)
			{
			case 1:
				cout << "��������Ҫ���ҵ�Ԫ��:";
				cin >> list.a.data;
				if (list.Search(list.a.data, d))
				{
					cout << "���ҳɹ���������λ���ǣ�" << list.Search(list.a.data, d) << endl;
					cout << "����Ԫ���ڵ�" << d << "��λ��" << endl;
				}
				else
					cout << "����ʧ�ܣ�" << endl;
				break;
			case 2:
				loca = list.HalfSearch(list);
				if (loca)
				{
					cout << "�����ɹ�����Ԫ��λ�ڵ�" << loca - 1 << "��λ��" << endl;
				}
				else
					cout << "����ʧ�ܣ�" << endl;
				break;
			case 0:
				exit(1);
			}
		}
		break;
	case 'N':
	case 'n':
		cout << "�뽨��������������" << endl;
		list.CreateBinTree(p);
		cout << "         1.��������������" << endl;
		cout << "         2.���ҽڵ�" << endl;
		cout << "         3.��ĳ�ڵ����Ů" << endl;
		cout << "         4.ɾ��ĳ�ڵ�" << endl;
		cout << "         0.�˳�" << endl;
		cout << "������ѡ��" << endl;
		while (cin >> flag)
		{
			switch (flag)
			{
			case 1:
				cout << "��������Ҫ������ֵ��";
				cin >> y;
				list.FindNode(p, y);
				if (list.FindNode(p, y) != NULL)
				{
					t = list.BinTreeSearch(p, y);
					cout << "�����ɹ�����ֵ��ַ�ǣ�" << t << endl;
					cout << "�õ�ַָ���ֵ�ǣ�" << t->data << endl;
				}
				else
					cout << "����ʧ�ܣ�" << endl;
				break;
			case 2:
				cout << "��������Ҫ���ҵĽڵ�ֵ��";
				cin >> c;
				t = list.FindNode(p, c);
				if (t != NULL)
				{
					cout << "���ҵ�ַ�ǣ�" << t << endl;
					cout << "�õ�ַָ��Ľڵ�����Ϊ��" << t->data << endl;
				}
				else
					cout << "û���ҵ��ýڵ㣡" << endl;
				break;
			case 3:
				cout << "����������ҪѰ����Ů�Ľڵ㣺";
				cin >> c;
				list.child(p, c);
				break;
			case 4:
				cout << "����������Ҫɾ���Ľڵ㣺";
				cin >> c;
				if (list.dele(p, c))
					cout << "ɾ���ɹ���" << endl;
				else
					cout << "ɾ��ʧ�ܣ�" << endl;
				break;
			case 0:
				exit(1);
			}
		}
	}
}