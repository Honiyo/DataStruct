#include "List1.h"
//#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
void main()
{
	List<int> list;
//	Student si = Student();
	char ch;
	int x = -1;
	cout << "从文件导入数据？(y/n)" << endl;
	cin >> ch;
	switch (ch)
	{
	case 'y':
	case 'Y':
	{
				string str = "";
				cout << "请输入要显示的文件名:" << endl;
				cin >> str;
				list.Readfile(str);
	}break;
	case 'n':
	case 'N':
	{
				cout << "请输入数据并以-1结束：" << endl;
				list.input(x); break;
	}
	}
//	int x = -1;
//	list.input(-1);
	int c;
	cout << "---------请选择需要的操作----------" << endl;
	cout << "            1.插入" << endl;
	cout << "            2.删除" << endl;
	cout << "            3.查找" << endl;
	cout << "            4.定位" << endl;
	cout << "            5.更新" << endl;
	cout << "            6.显示" << endl;
	cout << "            7.排序" << endl;
	cout << "            8.保存" << endl;
	cout << "            9.打开文件" << endl;
	cout << "            0.退出" << endl;
	while (1)
	{
		cin >> c;
		switch (c)
		{
		case 1:
		{
				  int k;
				  cout << "----1.在指定元素前插入----" << endl;
				  cout << "----2.在指定元素后插入----" << endl;
				  cout << "----3.在指定位置插入------" << endl;
			  M:  cout << "请输入你想要的操作:";
				  cin >> k;
				  switch (k)
				  {
				  case 1:
				  {
							cout << "请输入需要插入的数:" << endl;
							cin >> list.a.data;
							cout << "请输入插入在哪个元素前:" << endl;
							cin >> list.b.data;
							if (list.Insertbefore(list.a.data, list.b.data))
							{
								cout << "插入成功！" << endl;
								list.output();
							}
							else
								cout << "未找到目标元素！插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "请选择接下来的操作:";
								break;
							}

				  }break;
				  case 2:
				  {
							cout << "请输入需要插入的数:" << endl;
							cin >> list.a.data;
							cout << "请输入插入在哪个元素后:" << endl;
							cin >> list.b.data;
							if (list.Insertafter(list.a.data, list.b.data))
							{
								cout << "插入成功！" << endl;
								list.output();
							}
							else
								cout << "未找到目标元素！插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "请选择接下来的操作:";
								break;
							}
				  }break;
				  case 3:
				  {
							int a;
							cout << "请输入需要插入的位置:" << endl;
							cin >> a;
							cout << "请输入需要插入元素:" << endl;
							cin >> list.b.data;
							if (list.InsertLocate(a, list.b.data))
							{
								cout << "插入成功！" << endl;
								list.output();
							}
							else
								cout << "未找到目标位置！插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "请选择接下来的操作:";
								break;
							}
				  }break;
				  }
		}break;
		case 2:
		{
				  int k;
				  cout << "----1.删除指定位置元素----" << endl;
				  cout << "----2.删除指定元素--------" << endl;
			  L:  cout << "请输入你想要的操作:";
				  cin >> k;
				  switch (k)
				  {
				  case 1:
				  {
							int a;
							cout << "请输入待删除的元素位置:";
							cin >> a;
							if (list.RemoveLocate(a, list.b.data))
							{
								cout << "删除成功！删除数据为：" << list.b.data << endl;
								list.output();
							}
							else
								cout << "删除失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto L; break;
							case 'n':
							case 'N':
								cout << "请选择接下来的操作:";
								break;
							}
				  }break;
				  case 2:
				  {

							cout << "请输入需要删除的元素:";
							cin >> list.a.data;
							if (list.Remove(list.a.data,list.b.data))
							{
								cout << "删除成功！删除元素为：" << list.b.data << endl;
								list.output();
							}
							else
								cout << "删除失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto L; break;
							case 'n':
							case 'N':
								cout << "请选择接下来的操作:";
								break;
							}
				  }break;
				  }
		}break;
		case 3:
		{
			  A:
				  
				  cout << "请输入需要查找的元素:";
				  cin >> list.a.data;
				  int d=0;
				  if (list.Search(list.a.data, d))
				  {
					  cout << "查找成功！该数据位置是：" << list.Search(list.a.data, d) << endl;
					  cout << "查找元素在第" << d << "个位置" << endl;
				  }
				  else
					  cout << "查找失败！" << endl;
				  cout << "是否继续当前操作？(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto A; break;
				  case 'n':
				  case 'N':
					  cout << "请选择接下来的操作:";
					  break;
				  }
		} break;
		case 4:
		{
			  B:
				  int xo;
				  cout << "请输入需要定位的是第几个元素:";
				  cin >> xo;
				  if (list.Locate(xo,list.a.data))
					  cout << "定位成功！该数据位置是：" << list.a.data << endl;
				  else
					  cout << "定位失败！" << endl;
				  cout << "是否继续当前操作？(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto B; break;
				  case 'n':
				  case 'N':
					  cout << "请选择接下来的操作:";
					  break;
				  }
		}break;
		case 5:
		{
			  C:
				  cout << "请输入需要更新的元素:";
				  cin >> list.a.data;
				  cout << "请输入用以更新的数字:";
				  cin >> list.b.data;
				  list.Updata(list.a.data, list.b.data);
				  list.output();
				  cout << "是否继续当前操作？(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto C; break;
				  case 'n':
				  case 'N':
					  cout << "请选择接下来的操作:";
					  break;
				  }
		} break;
		case 6:list.output(); break;
		case 7:
		{
				   if (list.Sort())
				   {
					   cout << "排序成功！" << endl;
					   list.output();
				   }
				   else
					   cout << "排序失败！" << endl;
		}break;
		case 8:
		{
				  string str = "";
				  cout << "输入保存的文件名:" << endl;
				  cin >> str;
				  list.Writefile(str);
		}break;
		case 9:
		{
				  string str = "";
				  cout << "请输入要显示的文件名:" << endl;
				  cin >> str;
				  list.Readfile(str);
		}break;
		case 0:exit(0);
		}
	}
}