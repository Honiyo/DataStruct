#include <iostream>
using namespace std;
#include "Sort.h"
void main()
{
	int flag;
	cout << "�������򡢽�������ѡ���������õ����������£�" << endl;
	cout << endl;
	dataList<int>d(100);
	cout << endl;
	cout << "�鲢�������õ����������£�" << endl;
	cout << endl;
	dataList<int>d1(100);
	cout << endl;
	dataList<int>d2;
	cout << "                  ��ѡ�����" << endl;
	cout << "                 1.��������" << endl;
	cout << "                 2.ѡ������" << endl;
	cout << "                 3.��������" << endl;
	cout << "                 4.�鲢����" << endl;
	cout << "                 5.�˳�" << endl;
	while (cin >> flag)
	{
		switch (flag)
		{
		case 1:d.InsertSort(d, 0, 99); d.Show(d,100); break;
		case 2:d.SelectSort(d, 0, 99); d.Show(d,100); break;
		case 3:d.Exchange(d, 100); d.Show(d, 100); break;
		case 4:d.mergeSort(d1, d2, 0, 99); d2.Show(d1, 100); break;
		case 5:exit(1);break;
		}
	}
}