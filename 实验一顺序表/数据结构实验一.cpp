
#include "List.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
void main()
{
	int c;
	cout << "�����±���ѡ���±�����  " << endl;
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
			  cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
			  cout << "            1.����" << endl;
			  cout << "            2.ɾ��" << endl;
			  cout << "            3.����" << endl;
			  cout << "            4.��λ" << endl;
			  cout << "            5.����" << endl;
			  cout << "            6.��ʾ" << endl;
			  cout << "            7.����" << endl;
			  cout << "            8.����" << endl;
			  cout << "            9.��ʾ�ļ�����" << endl;
			  cout << "            0.�˳�" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
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
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ��ǰ:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
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
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ�غ�:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
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
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
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
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "ɾ���ɹ���ɾ������Ϊ��" << seq.b << endl;
										  seq.output();
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
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "ɾ���ɹ���" << endl;
										  seq.output();
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
				  case 3:{
						 A:
							 cout << "��������Ҫ���ҵ�Ԫ��:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "���ҳɹ���������λ���ǣ�" << seq.Search(seq.a) << endl;
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
				  case 4:{
						 B:
							 cout << "��������Ҫ��λ��Ԫ��:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "��λ�ɹ���������λ���ǣ�" << seq.Location(seq.a) << endl;
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
				  case 5: {
						  C:
							  cout << "��������Ҫ���µ�Ԫ��:";
							  cin >> seq.a;
							  cout << "���������Ը��µ�����:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
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
				  case 6: seq.output(); break;
				  case 7: {
							  if (seq.Sort())
							  {
								  cout << "����ɹ���" << endl;
								  seq.output();
							  }
							  else
								  cout << "����ʧ�ܣ�" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "���뱣����ļ���:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "������Ҫ��ʾ���ļ���:" << endl;
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
			  cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
			  cout << "            1.����" << endl;
			  cout << "            2.ɾ��" << endl;
			  cout << "            3.����" << endl;
			  cout << "            4.��λ" << endl;
			  cout << "            5.����" << endl;
			  cout << "            6.��ʾ" << endl;
			  cout << "            7.����" << endl;
			  cout << "            8.����" << endl;
			  cout << "            9.��ʾ�ļ�����" << endl;
			  cout << "            0.�˳�" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.��ָ��Ԫ��ǰ����----" << endl;
							cout << "----2.��ָ��Ԫ�غ����----" << endl;
							cout << "----3.��ָ��λ�ò���------" << endl;
						H:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ��ǰ:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ�غ�:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�����λ��:" << endl;
									  cin >> a;
									  cout << "��������Ҫ����Ԫ��:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							cout << "----1.ɾ��ָ��λ��Ԫ��----" << endl;
							cout << "----2.ɾ��ָ��Ԫ��--------" << endl;
						K:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "�������ɾ����Ԫ��λ��:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "ɾ���ɹ���ɾ������Ϊ��" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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

									  cout << "��������Ҫɾ����Ԫ��:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "ɾ���ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ���ҵ�Ԫ��:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "���ҳɹ���������λ���ǣ�" << seq.Search(seq.a) << endl;
							 else
								 cout << "����ʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ��λ��Ԫ��:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "��λ�ɹ���������λ���ǣ�" << seq.Location(seq.a) << endl;
							 else
								 cout << "��λʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							  cout << "��������Ҫ���µ�Ԫ��:";
							  cin >> seq.a;
							  cout << "���������Ը��µ�����:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
								  cout << "����ɹ���" << endl;
								  seq.output();
							  }
							  else
								  cout << "����ʧ�ܣ�" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "���뱣����ļ���:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "������Ҫ��ʾ���ļ���:" << endl;
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
			  cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
			  cout << "            1.����" << endl;
			  cout << "            2.ɾ��" << endl;
			  cout << "            3.����" << endl;
			  cout << "            4.��λ" << endl;
			  cout << "            5.����" << endl;
			  cout << "            6.��ʾ" << endl;
			  cout << "            7.����" << endl;
			  cout << "            8.����" << endl;
			  cout << "            9.��ʾ�ļ�����" << endl;
			  cout << "            0.�˳�" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.��ָ��Ԫ��ǰ����----" << endl;
							cout << "----2.��ָ��Ԫ�غ����----" << endl;
							cout << "----3.��ָ��λ�ò���------" << endl;
						G:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ��ǰ:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ�غ�:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�����λ��:" << endl;
									  cin >> a;
									  cout << "��������Ҫ����Ԫ��:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							cout << "----1.ɾ��ָ��λ��Ԫ��----" << endl;
							cout << "----2.ɾ��ָ��Ԫ��--------" << endl;
						I:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "�������ɾ����Ԫ��λ��:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "ɾ���ɹ���ɾ������Ϊ��" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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

									  cout << "��������Ҫɾ����Ԫ��:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "ɾ���ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ���ҵ�Ԫ��:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "���ҳɹ���������λ���ǣ�" << seq.Search(seq.a) << endl;
							 else
								 cout << "����ʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ��λ��Ԫ��:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "��λ�ɹ���������λ���ǣ�" << seq.Location(seq.a) << endl;
							 else
								 cout << "��λʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							  cout << "��������Ҫ���µ�Ԫ��:";
							  cin >> seq.a;
							  cout << "���������Ը��µ�����:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
								  cout << "����ɹ���" << endl;
								  seq.output();
							  }
							  else
								  cout << "����ʧ�ܣ�" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "���뱣����ļ���:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "������Ҫ��ʾ���ļ���:" << endl;
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
			  cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
			  cout << "            1.����" << endl;
			  cout << "            2.ɾ��" << endl;
			  cout << "            3.����" << endl;
			  cout << "            4.��λ" << endl;
			  cout << "            5.����" << endl;
			  cout << "            6.��ʾ" << endl;
			  cout << "            7.����" << endl;
			  cout << "            8.����" << endl;
			  cout << "            9.��ʾ�ļ�����" << endl;
			  cout << "            0.�˳�" << endl;
			  while (1)
			  {
				  cin >> a;
				  switch (a)
				  {
				  case 1:
				  {
							int k;
							cout << "----1.��ָ��Ԫ��ǰ����----" << endl;
							cout << "----2.��ָ��Ԫ�غ����----" << endl;
							cout << "----3.��ָ��λ�ò���------" << endl;
						P:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ��ǰ:" << endl;
									  cin >> seq.b;
									  if (seq.Insertbefore(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�������:" << endl;
									  cin >> seq.a;
									  cout << "������������ĸ�Ԫ�غ�:" << endl;
									  cin >> seq.b;
									  if (seq.Insertafter(seq.a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
									  cout << "��������Ҫ�����λ��:" << endl;
									  cin >> a;
									  cout << "��������Ҫ����Ԫ��:" << endl;
									  cin >> seq.b;
									  if (seq.Insert(a, seq.b))
									  {
										  cout << "����ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "����ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							cout << "----1.ɾ��ָ��λ��Ԫ��----" << endl;
							cout << "----2.ɾ��ָ��Ԫ��--------" << endl;
						Q:  cout << "����������Ҫ�Ĳ���:";
							cin >> k;
							switch (k)
							{
							case 1:
							{
									  int a;
									  cout << "�������ɾ����Ԫ��λ��:";
									  cin >> a;
									  if (seq.Remove(a, seq.b))
									  {
										  cout << "ɾ���ɹ���ɾ������Ϊ��" << seq.b << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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

									  cout << "��������Ҫɾ����Ԫ��:";
									  cin >> seq.a;
									  if (seq.Removepoint(seq.a))
									  {
										  cout << "ɾ���ɹ���" << endl;
										  seq.output();
									  }
									  else
										  cout << "ɾ��ʧ�ܣ�" << endl;
									  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ���ҵ�Ԫ��:";
							 cin >> seq.a;
							 if (seq.Search(seq.a))
								 cout << "���ҳɹ���������λ���ǣ�" << seq.Search(seq.a) << endl;
							 else
								 cout << "����ʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							 cout << "��������Ҫ��λ��Ԫ��:";
							 cin >> seq.a;
							 if (seq.Location(seq.a))
								 cout << "��λ�ɹ���������λ���ǣ�" << seq.Location(seq.a) << endl;
							 else
								 cout << "��λʧ�ܣ�" << endl;
							 cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							  cout << "��������Ҫ���µ�Ԫ��:";
							  cin >> seq.a;
							  cout << "���������Ը��µ�����:";
							  cin >> seq.b;
							  seq.Updata(seq.a, seq.b);
							  seq.output();
							  cout << "�Ƿ������ǰ������(y/n)" << endl;
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
								  cout << "����ɹ���" << endl;
								  seq.output();
							  }
							  else
								  cout << "����ʧ�ܣ�" << endl;
				  }break;
				  case 8:{
							 string str = "";
							 cout << "���뱣����ļ���:" << endl;
							 cin >> str;
							 seq.Writefile(str);
				  }break;
				  case 9:{
							 string str = "";
							 cout << "������Ҫ��ʾ���ļ���:" << endl;
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
	cout << "---------��ѡ����Ҫ�Ĳ���----------" << endl;
	cout << "            1.����" << endl;
	cout << "            2.ɾ��" << endl;
	cout << "            3.����" << endl;
	cout << "            4.��λ" << endl;
	cout << "            5.����" << endl;
	cout << "            6.��ʾ" << endl;
	cout << "            7.����" << endl;
	cout << "            8.����" << endl;
	cout << "            9.��ʾ�ļ�����" << endl;
	cout << "            0.�˳�" << endl;
	while (1)
	{
		cin >> a;
		switch (a)
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
							cin >> seq.a;
							cout << "������������ĸ�Ԫ��ǰ:" << endl;
							cin >> seq.b;
							if (seq.Insertbefore(seq.a, seq.b))
							{
								cout << "����ɹ���" << endl;
								seq.output();
							}
							else
								cout << "����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							cout << "��������Ҫ�������:" << endl;
							cin >> seq.a;
							cout << "������������ĸ�Ԫ�غ�:" << endl;
							cin >> seq.b;
							if (seq.Insertafter(seq.a, seq.b))
							{
								cout << "����ɹ���" << endl;
								seq.output();
							}
							else
								cout << "����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							cout << "��������Ҫ�����λ��:" << endl;
							cin >> a;
							cout << "��������Ҫ����Ԫ��:" << endl;
							cin >> seq.b;
							if (seq.Insert(a, seq.b))
							{
								cout << "����ɹ���" << endl;
								seq.output();
							}
							else
								cout << "����ʧ�ܣ�" << endl;
							cout << "�Ƿ������ǰ������(y/n)" << endl;
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
							if (seq.Remove(a, seq.b))
							{
								cout << "ɾ���ɹ���ɾ������Ϊ��" << seq.b << endl;
								seq.output();
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
								break;
							}
				  }break;
				  case 2:
				  {

							cout << "��������Ҫɾ����Ԫ��:";
							cin >> seq.a;
							if (seq.Removepoint(seq.a))
							{
								cout << "ɾ���ɹ���" << endl;
								seq.output();
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
								break;
							}
				  }break;
				  }
		}break;
		case 3:{
			   A:
				   cout << "��������Ҫ���ҵ�Ԫ��:";
				   cin >> seq.a;
				   if (seq.Search(seq.a))
					   cout << "���ҳɹ���������λ���ǣ�" << seq.Search(seq.a) << endl;
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
					   break;
				   }
		} break;
		case 4:{
			   B:
				   cout << "��������Ҫ��λ��Ԫ��:";
				   cin >> seq.a;
				   if (seq.Location(seq.a))
					   cout << "��λ�ɹ���������λ���ǣ�" << seq.Location(seq.a) << endl;
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
					   break;
				   }
		}break;
		case 5: {
				C:
					cout << "��������Ҫ���µ�Ԫ��:";
					cin >> seq.a;
					cout << "���������Ը��µ�����:";
					cin >> seq.b;
					seq.Updata(seq.a, seq.b);
					seq.output();
					cout << "�Ƿ������ǰ������(y/n)" << endl;
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
						cout << "����ɹ���" << endl;
						seq.output();
					}
					else
						cout << "����ʧ�ܣ�" << endl;
		}break;
		case 8:{
				   string str = "";
				   cout << "���뱣����ļ���:" << endl;
				   cin >> str;
				   seq.Writefile(str);
		}break;
		case 9:{
				   string str = "";
				   cout << "������Ҫ��ʾ���ļ���:" << endl;
				   cin >> str;
				   seq.Readfile(str);
		}break;
		case 0: exit(0);

		}
	}*/
