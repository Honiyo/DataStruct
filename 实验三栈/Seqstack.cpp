#include <iostream>
#include <string>
using namespace std;
#include "stack.h"
void main()
{
	Seqstack<string> s;
	Seqstack<char> c;
	int i;
	cout << "       1.ѹ��Ԫ��" << endl;
	cout << "       2.����Ԫ��" << endl;
	cout << "       3.ȡջ��Ԫ��" << endl;
	cout << "       4.����ջԪ�ظ���" << endl;
	cout << "       5.��ʾ" << endl;
	cout << "       6.�ַ�������" << endl;
	cout << "       7.����ƥ��" << endl;
	cout << "       8.�������ʽ��ֵ" << endl;
	cout << "       0.�˳�" << endl;
	while (true)
	{
		string x, m, n;
	L:	cout << "��ѡ�������";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "������ѹ��Ԫ�أ�";
			cin >> x;
			if (s.Push(x))
				cout << s << endl;
			else
				goto L;
			break;
		case 2:
			if (s.Pop(m))
			{
				cout << "����Ԫ��Ϊ��" << m << endl;
				cout << s << endl;
			}
			break;
		case 3:
			if (s.Peek(n))
			{
				cout << "ջ��Ԫ��Ϊ��" << n << endl;
				cout << s << endl;
			}
			break;
		case 4:
			cout << "ĿǰջԪ�ظ���Ϊ��" << s.getnum() << endl;
			cout << endl;
			break;
		case 5:
			cout << s << endl;
			break;
		case 6:c.reversestring(); break;
		case 7:c.match(); break;
		case 8:c.calculate(); break;
		case 0:exit(1); break;
		}
	}
}