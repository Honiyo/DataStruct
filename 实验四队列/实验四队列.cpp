#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Queue.h"
void main()
{
	Queue<double>q;
	int n;
	double m;
	cout << "ÐÐÊý:" << endl;
	cin >> n;
	int i = 1, j, u;
	int s = 0;
	int g = n;
	q.push(i);
	q.push(i);
	for (i = 1; i <= n; i++)
	{
		g--;	
		cout << endl;	
		for (int k = g - 1; k >= 0; k--)
		{			
			cout.width(4);
			cout<<" ";					
		}	
		q.push(0);
		for (j = 1; j <= i + 2; j++)
		{
			q.pop(m);
			u = s + m;
			q.push(u);
			s = m;
			if (j != i + 2)
			{
				cout.width(8);
				cout << s;
			}
		}
		cout << endl;
	}
}