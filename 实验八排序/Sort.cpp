#include <iostream>
using namespace std;
#include "Sort.h"
void main()
{
	int flag;
	cout << "插入排序、交换排序、选择排序所用到的数据如下：" << endl;
	cout << endl;
	dataList<int>d(100);
	cout << endl;
	cout << "归并排序所用到的数据如下：" << endl;
	cout << endl;
	dataList<int>d1(100);
	cout << endl;
	dataList<int>d2;
	cout << "                  请选择操作" << endl;
	cout << "                 1.插入排序" << endl;
	cout << "                 2.选择排序" << endl;
	cout << "                 3.交换排序" << endl;
	cout << "                 4.归并排序" << endl;
	cout << "                 5.退出" << endl;
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