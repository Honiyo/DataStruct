
#include "List.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
void main()
{
	int c;
	cout << "建立新表！请选择新表类型  " << endl;
	cout << "          1.int" << endl;
	cout << "          2.char" << endl;
	cout << "          3.string" << endl;
	cout << "          4.double" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
	{
			  SeqList<int>seq;
			  seq.input();
			  int a;
			  cout << "---------请选择需要的操作----------" << endl;
			  cout << "            1.插入" << endl;
			  cout << "            2.删除" << endl;
			  cout << "            3.查找" << endl;
			  cout << "            4.定位" << endl;
			  cout << "            5.更新" << endl;
			  cout << "            6.显示" << endl;
			  cout << "            7.排序" << endl;
			  cout << "            8.保存" << endl;
			  cout << "            9.显示文件内容" << endl;
			  cout << "            0.退出" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
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
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素前:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
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
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素后:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
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
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
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
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "删除成功！删除数据为：" << seq.b << endl;
										  seq.output();
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
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "删除成功！" << endl;
										  seq.output();
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
				  case 3:{
						 A:
							 cout << "请输入需要查找的元素:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "查找成功！该数据位置是：" << seq.Search(seq.a) << endl;
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
				  case 4:{
						 B:
							 cout << "请输入需要定位的元素:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "定位成功！该数据位置是：" << seq.Location(seq.a) << endl;
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
				  case 5: {
						  C:
							  cout << "请输入需要更新的元素:";
							  cin >> seq.a;
							  cout << "请输入用以更新的数字:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
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
				  case 6: seq.output(); break;
				  case 7: {
							  if (seq.Sort())
							  {
								  cout << "排序成功！" << endl;
								  seq.output();
							  }
							  else
								  cout << "排序失败！" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "输入保存的文件名:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "请输入要显示的文件名:" << endl;
							 cin >> str;
							 seq.Readfile(str, seq.b);
				  }break;
				  case 0: exit(0);

				  }
			  }

	}break;
	case 2:
	{
			  SeqList<char>seq;
			  seq.input();
			  int a;
			  cout << "---------请选择需要的操作----------" << endl;
			  cout << "            1.插入" << endl;
			  cout << "            2.删除" << endl;
			  cout << "            3.查找" << endl;
			  cout << "            4.定位" << endl;
			  cout << "            5.更新" << endl;
			  cout << "            6.显示" << endl;
			  cout << "            7.排序" << endl;
			  cout << "            8.保存" << endl;
			  cout << "            9.显示文件内容" << endl;
			  cout << "            0.退出" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.在指定元素前插入----" << endl;
							cout << "----2.在指定元素后插入----" << endl;
							cout << "----3.在指定位置插入------" << endl;
						H:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素前:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto H; break;
									  case 'n':
									  case 'N':
										  break;
									  }

							}break;
							case 2:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素后:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto H; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 3:
							{
									  int a;
									  cout << "请输入需要插入的位置:" << endl;
									  cin >> a;
									  cout << "请输入需要插入元素:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto H; break;
									  case 'n':
									  case 'N':
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
						K:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "请输入待删除的元素位置:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "删除成功！删除数据为：" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto K; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 2:
							{

									  cout << "请输入需要删除的元素:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "删除成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto K; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							}
				  }break;
				  case 3:{
						 D:
							 cout << "请输入需要查找的元素:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "查找成功！该数据位置是：" << seq.Search(seq.a) << endl;
							 else
								 cout << "查找失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto D; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  } break;
				  case 4:{
						 E:
							 cout << "请输入需要定位的元素:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "定位成功！该数据位置是：" << seq.Location(seq.a) << endl;
							 else
								 cout << "定位失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto E; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  }break;
				  case 5: {
						  F:
							  cout << "请输入需要更新的元素:";
							  cin >> seq.a;
							  cout << "请输入用以更新的数字:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "是否继续当前操作？(y/n)" << endl;
							  char ch;
							  cin >> ch;
							  switch (ch)
							  {
							  case 'y':
							  case 'Y':goto F; break;
							  case 'n':
							  case 'N':
								  break;
							  }
				  } break;
				  case 6: seq.output(); break;
				  case 7: {
							  if (seq.Sort())
							  {
								  cout << "排序成功！" << endl;
								  seq.output();
							  }
							  else
								  cout << "排序失败！" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "输入保存的文件名:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "请输入要显示的文件名:" << endl;
							 cin >> str;
							 seq.Readfile(str, seq.b);
				  }break;
				  case 0: exit(0);

				  }
			  }

	}break;
	case 3:
	{
			  SeqList<string>seq;
			  seq.input();
			  int a;
			  cout << "---------请选择需要的操作----------" << endl;
			  cout << "            1.插入" << endl;
			  cout << "            2.删除" << endl;
			  cout << "            3.查找" << endl;
			  cout << "            4.定位" << endl;
			  cout << "            5.更新" << endl;
			  cout << "            6.显示" << endl;
			  cout << "            7.排序" << endl;
			  cout << "            8.保存" << endl;
			  cout << "            9.显示文件内容" << endl;
			  cout << "            0.退出" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.在指定元素前插入----" << endl;
							cout << "----2.在指定元素后插入----" << endl;
							cout << "----3.在指定位置插入------" << endl;
						G:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素前:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto G; break;
									  case 'n':
									  case 'N':
										  break;
									  }

							}break;
							case 2:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素后:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto G; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 3:
							{
									  int a;
									  cout << "请输入需要插入的位置:" << endl;
									  cin >> a;
									  cout << "请输入需要插入元素:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto G; break;
									  case 'n':
									  case 'N':
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
						I:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "请输入待删除的元素位置:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "删除成功！删除数据为：" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto I; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 2:
							{

									  cout << "请输入需要删除的元素:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "删除成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto I; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							}
				  }break;
				  case 3:{
						 J:
							 cout << "请输入需要查找的元素:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "查找成功！该数据位置是：" << seq.Search(seq.a) << endl;
							 else
								 cout << "查找失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto J; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  } break;
				  case 4:{
						 N:
							 cout << "请输入需要定位的元素:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "定位成功！该数据位置是：" << seq.Location(seq.a) << endl;
							 else
								 cout << "定位失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto N; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  }break;
				  case 5: {
						  O:
							  cout << "请输入需要更新的元素:";
							  cin >> seq.a;
							  cout << "请输入用以更新的数字:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "是否继续当前操作？(y/n)" << endl;
							  char ch;
							  cin >> ch;
							  switch (ch)
							  {
							  case 'y':
							  case 'Y':goto O; break;
							  case 'n':
							  case 'N':
								  break;
							  }
				  } break;
				  case 6: seq.output(); break;
				  case 7: {
							  if (seq.Sort())
							  {
								  cout << "排序成功！" << endl;
								  seq.output();
							  }
							  else
								  cout << "排序失败！" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "输入保存的文件名:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "请输入要显示的文件名:" << endl;
							 cin >> str;
							 seq.Readfile(str, seq.b);
				  }break;
				  case 0: exit(0);

				  }
			  }

	}break;
	case 4:
	{
			  SeqList<double>seq;
			  seq.input();
			  int a;
			  cout << "---------请选择需要的操作----------" << endl;
			  cout << "            1.插入" << endl;
			  cout << "            2.删除" << endl;
			  cout << "            3.查找" << endl;
			  cout << "            4.定位" << endl;
			  cout << "            5.更新" << endl;
			  cout << "            6.显示" << endl;
			  cout << "            7.排序" << endl;
			  cout << "            8.保存" << endl;
			  cout << "            9.显示文件内容" << endl;
			  cout << "            0.退出" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.在指定元素前插入----" << endl;
							cout << "----2.在指定元素后插入----" << endl;
							cout << "----3.在指定位置插入------" << endl;
						P:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素前:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto P; break;
									  case 'n':
									  case 'N':
										  break;
									  }

							}break;
							case 2:
							{
									  cout << "请输入需要插入的数:" << endl;
									  cin >> seq.a;
									  cout << "请输入插入在哪个元素后:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto P; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 3:
							{
									  int a;
									  cout << "请输入需要插入的位置:" << endl;
									  cin >> a;
									  cout << "请输入需要插入元素:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "插入成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "插入失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto P; break;
									  case 'n':
									  case 'N':
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
						Q:  cout << "请输入你想要的操作:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "请输入待删除的元素位置:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "删除成功！删除数据为：" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto Q; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							case 2:
							{

									  cout << "请输入需要删除的元素:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "删除成功！" << endl;
										  seq.output();
									  }
									  else
										  cout << "删除失败！" << endl;
									  cout << "是否继续当前操作？(y/n)" << endl;
									  char ch;
									  cin >> ch;
									  switch (ch)
									  {
									  case 'y':
									  case 'Y':goto Q; break;
									  case 'n':
									  case 'N':
										  break;
									  }
							}break;
							}
				  }break;
				  case 3:{
						 R:
							 cout << "请输入需要查找的元素:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "查找成功！该数据位置是：" << seq.Search(seq.a) << endl;
							 else
								 cout << "查找失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto R; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  } break;
				  case 4:{
						 S:
							 cout << "请输入需要定位的元素:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "定位成功！该数据位置是：" << seq.Location(seq.a) << endl;
							 else
								 cout << "定位失败！" << endl;
							 cout << "是否继续当前操作？(y/n)" << endl;
							 char ch;
							 cin >> ch;
							 switch (ch)
							 {
							 case 'y':
							 case 'Y':goto S; break;
							 case 'n':
							 case 'N':
								 break;
							 }
				  }break;
				  case 5: {
						  W:
							  cout << "请输入需要更新的元素:";
							  cin >> seq.a;
							  cout << "请输入用以更新的数字:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "是否继续当前操作？(y/n)" << endl;
							  char ch;
							  cin >> ch;
							  switch (ch)
							  {
							  case 'y':
							  case 'Y':goto W; break;
							  case 'n':
							  case 'N':
								  break;
							  }
				  } break;
				  case 6: seq.output(); break;
				  case 7: {
							  if (seq.Sort())
							  {
								  cout << "排序成功！" << endl;
								  seq.output();
							  }
							  else
								  cout << "排序失败！" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "输入保存的文件名:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "请输入要显示的文件名:" << endl;
							 cin >> str;
							 seq.Readfile(str, seq.b);
				  }break;
				  case 0: exit(0);

				  }
			  }

	}break;
	}
}

/*	int a;
	cout << "---------请选择需要的操作----------" << endl;
	cout << "            1.插入" << endl;
	cout << "            2.删除" << endl;
	cout << "            3.查找" << endl;
	cout << "            4.定位" << endl;
	cout << "            5.更新" << endl;
	cout << "            6.显示" << endl;
	cout << "            7.排序" << endl;
	cout << "            8.保存" << endl;
	cout << "            9.显示文件内容" << endl;
	cout << "            0.退出" << endl;
	while (1)
	{
		cin >> a;
		switch (a)
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
							cin >> seq.a;
							cout << "请输入插入在哪个元素前:" << endl;
							cin >> seq.b;
							if (seq.Insertbefore(seq.a, seq.b))
							{
								cout << "插入成功！" << endl;
								seq.output();
							}
							else
								cout << "插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								break;
							}

				  }break;
				  case 2:
				  {
							cout << "请输入需要插入的数:" << endl;
							cin >> seq.a;
							cout << "请输入插入在哪个元素后:" << endl;
							cin >> seq.b;
							if (seq.Insertafter(seq.a, seq.b))
							{
								cout << "插入成功！" << endl;
								seq.output();
							}
							else
								cout << "插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								break;
							}
				  }break;
				  case 3:
				  {
							int a;
							cout << "请输入需要插入的位置:" << endl;
							cin >> a;
							cout << "请输入需要插入元素:" << endl;
							cin >> seq.b;
							if (seq.Insert(a, seq.b))
							{
								cout << "插入成功！" << endl;
								seq.output();
							}
							else
								cout << "插入失败！" << endl;
							cout << "是否继续当前操作？(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
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
							if (seq.Remove(a, seq.b))
							{
								cout << "删除成功！删除数据为：" << seq.b << endl;
								seq.output();
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
								break;
							}
				  }break;
				  case 2:
				  {

							cout << "请输入需要删除的元素:";
							cin >> seq.a;
							if (seq.Removepoint(seq.a))
							{
								cout << "删除成功！" << endl;
								seq.output();
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
								break;
							}
				  }break;
				  }
		}break;
		case 3:{
			   A:
				   cout << "请输入需要查找的元素:";
				   cin >> seq.a;
				   if (seq.Search(seq.a))
					   cout << "查找成功！该数据位置是：" << seq.Search(seq.a) << endl;
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
					   break;
				   }
		} break;
		case 4:{
			   B:
				   cout << "请输入需要定位的元素:";
				   cin >> seq.a;
				   if (seq.Location(seq.a))
					   cout << "定位成功！该数据位置是：" << seq.Location(seq.a) << endl;
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
					   break;
				   }
		}break;
		case 5: {
				C:
					cout << "请输入需要更新的元素:";
					cin >> seq.a;
					cout << "请输入用以更新的数字:";
					cin >> seq.b;
					seq.Updata(seq.a, seq.b);
					seq.output();
					cout << "是否继续当前操作？(y/n)" << endl;
					char ch;
					cin >> ch;
					switch (ch)
					{
					case 'y':
					case 'Y':goto C; break;
					case 'n':
					case 'N':
						break;
					}
		} break;
		case 6: seq.output(); break;
		case 7: {
					if (seq.Sort())
					{
						cout << "排序成功！" << endl;
						seq.output();
					}
					else
						cout << "排序失败！" << endl;
		}break;
		case 8:{
				   string str = "";
				   cout << "输入保存的文件名:" << endl;
				   cin >> str;
				   seq.Writefile(str);
		}break;
		case 9:{
				   string str = "";
				   cout << "请输入要显示的文件名:" << endl;
				   cin >> str;
				   seq.Readfile(str);
		}break;
		case 0: exit(0);

		}
	}*/
