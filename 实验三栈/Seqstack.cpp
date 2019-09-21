#include <iostream>
#include <string>
using namespace std;
#include "stack.h"
void main()
{
	Seqstack<string> s;
	Seqstack<char> c;
	int i;
	cout << "       1.压入元素" << endl;
	cout << "       2.弹出元素" << endl;
	cout << "       3.取栈顶元素" << endl;
	cout << "       4.计算栈元素个数" << endl;
	cout << "       5.显示" << endl;
	cout << "       6.字符串逆序" << endl;
	cout << "       7.括号匹配" << endl;
	cout << "       8.算术表达式求值" << endl;
	cout << "       0.退出" << endl;
	while (true)
	{
		string x, m, n;
	L:	cout << "请选择操作：";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "请输入压入元素：";
			cin >> x;
			if (s.Push(x))
				cout << s << endl;
			else
				goto L;
			break;
		case 2:
			if (s.Pop(m))
			{
				cout << "弹出元素为：" << m << endl;
				cout << s << endl;
			}
			break;
		case 3:
			if (s.Peek(n))
			{
				cout << "栈顶元素为：" << n << endl;
				cout << s << endl;
			}
			break;
		case 4:
			cout << "目前栈元素个数为：" << s.getnum() << endl;
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