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
	cout << "���ļ��������ݣ�(y/n)" << endl;
	cin >> ch;
	switch (ch)
	{
	case 'y':
	case 'Y':
	{
				string str = "";
				cout << "������Ҫ��ʾ���ļ���:" << endl;
				cin >> str;
				list.Readfile(str);
	}break;
	case 'n':
	case 'N':
	{
				cout << "���������ݲ���-1������" << endl;
				list.input(x); break;
	}
	}
//	int x = -1;
//	list.input(-1);
	int c;
	cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
	cout << "            1.����" << endl;
	cout << "            2.ɾ��" << endl;
	cout << "            3.����" << endl;
	cout << "            4.��λ" << endl;
	cout << "            5.����" << endl;
	cout << "            6.��ʾ" << endl;
	cout << "            7.����" << endl;
	cout << "            8.����" << endl;
	cout << "            9.���ļ�" << endl;
	cout << "            0.�˳�" << endl;
	while (1)
	{
		cin >> c;
		switch (c)
		{
		case 1:
		{
				  int k;
				  cout << "----1.��ָ��Ԫ��ǰ����----" << endl;
				  cout << "----2.��ָ��Ԫ�غ����----" << endl;
				  cout << "----3.��ָ��λ�ò���------" << endl;
			  M:  cout << "����������Ҫ�Ĳ���:";
				  cin >> k;
				  switch (k)
				  {
				  case 1:
				  {
							cout << "��������Ҫ�������:" << endl;
							cin >> list.a.data;
							cout << "������������ĸ�Ԫ��ǰ:" << endl;
							cin >> list.b.data;
							if (list.Insertbefore(list.a.data, list.b.data))
							{
								cout << "����ɹ���" << endl;
								list.output();
							}
							else
								cout << "δ�ҵ�Ŀ��Ԫ�أ�����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "��ѡ��������Ĳ���:";
								break;
							}

				  }break;
				  case 2:
				  {
							cout << "��������Ҫ�������:" << endl;
							cin >> list.a.data;
							cout << "������������ĸ�Ԫ�غ�:" << endl;
							cin >> list.b.data;
							if (list.Insertafter(list.a.data, list.b.data))
							{
								cout << "����ɹ���" << endl;
								list.output();
							}
							else
								cout << "δ�ҵ�Ŀ��Ԫ�أ�����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "��ѡ��������Ĳ���:";
								break;
							}
				  }break;
				  case 3:
				  {
							int a;
							cout << "��������Ҫ�����λ��:" << endl;
							cin >> a;
							cout << "��������Ҫ����Ԫ��:" << endl;
							cin >> list.b.data;
							if (list.InsertLocate(a, list.b.data))
							{
								cout << "����ɹ���" << endl;
								list.output();
							}
							else
								cout << "δ�ҵ�Ŀ��λ�ã�����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto M; break;
							case 'n':
							case 'N':
								cout << "��ѡ��������Ĳ���:";
								break;
							}
				  }break;
				  }
		}break;
		case 2:
		{
				  int k;
				  cout << "----1.ɾ��ָ��λ��Ԫ��----" << endl;
				  cout << "----2.ɾ��ָ��Ԫ��--------" << endl;
			  L:  cout << "����������Ҫ�Ĳ���:";
				  cin >> k;
				  switch (k)
				  {
				  case 1:
				  {
							int a;
							cout << "�������ɾ����Ԫ��λ��:";
							cin >> a;
							if (list.RemoveLocate(a, list.b.data))
							{
								cout << "ɾ���ɹ���ɾ������Ϊ��" << list.b.data << endl;
								list.output();
							}
							else
								cout << "ɾ��ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto L; break;
							case 'n':
							case 'N':
								cout << "��ѡ��������Ĳ���:";
								break;
							}
				  }break;
				  case 2:
				  {

							cout << "��������Ҫɾ����Ԫ��:";
							cin >> list.a.data;
							if (list.Remove(list.a.data,list.b.data))
							{
								cout << "ɾ���ɹ���ɾ��Ԫ��Ϊ��" << list.b.data << endl;
								list.output();
							}
							else
								cout << "ɾ��ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
							char ch;
							cin >> ch;
							switch (ch)
							{
							case 'y':
							case 'Y':goto L; break;
							case 'n':
							case 'N':
								cout << "��ѡ��������Ĳ���:";
								break;
							}
				  }break;
				  }
		}break;
		case 3:
		{
			  A:
				  
				  cout << "��������Ҫ���ҵ�Ԫ��:";
				  cin >> list.a.data;
				  int d=0;
				  if (list.Search(list.a.data, d))
				  {
					  cout << "���ҳɹ���������λ���ǣ�" << list.Search(list.a.data, d) << endl;
					  cout << "����Ԫ���ڵ�" << d << "��λ��" << endl;
				  }
				  else
					  cout << "����ʧ�ܣ�" << endl;
				  cout << "�Ƿ������ǰ������(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto A; break;
				  case 'n':
				  case 'N':
					  cout << "��ѡ��������Ĳ���:";
					  break;
				  }
		} break;
		case 4:
		{
			  B:
				  int xo;
				  cout << "��������Ҫ��λ���ǵڼ���Ԫ��:";
				  cin >> xo;
				  if (list.Locate(xo,list.a.data))
					  cout << "��λ�ɹ���������λ���ǣ�" << list.a.data << endl;
				  else
					  cout << "��λʧ�ܣ�" << endl;
				  cout << "�Ƿ������ǰ������(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto B; break;
				  case 'n':
				  case 'N':
					  cout << "��ѡ��������Ĳ���:";
					  break;
				  }
		}break;
		case 5:
		{
			  C:
				  cout << "��������Ҫ���µ�Ԫ��:";
				  cin >> list.a.data;
				  cout << "���������Ը��µ�����:";
				  cin >> list.b.data;
				  list.Updata(list.a.data, list.b.data);
				  list.output();
				  cout << "�Ƿ������ǰ������(y/n)" << endl;
				  char ch;
				  cin >> ch;
				  switch (ch)
				  {
				  case 'y':
				  case 'Y':goto C; break;
				  case 'n':
				  case 'N':
					  cout << "��ѡ��������Ĳ���:";
					  break;
				  }
		} break;
		case 6:list.output(); break;
		case 7:
		{
				   if (list.Sort())
				   {
					   cout << "����ɹ���" << endl;
					   list.output();
				   }
				   else
					   cout << "����ʧ�ܣ�" << endl;
		}break;
		case 8:
		{
				  string str = "";
				  cout << "���뱣����ļ���:" << endl;
				  cin >> str;
				  list.Writefile(str);
		}break;
		case 9:
		{
				  string str = "";
				  cout << "������Ҫ��ʾ���ļ���:" << endl;
				  cin >> str;
				  list.Readfile(str);
		}break;
		case 0:exit(0);
		}
	}
}