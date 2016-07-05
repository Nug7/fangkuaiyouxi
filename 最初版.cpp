#include<iostream>
#include<stdio.h>
#include<string>
#include<ctime>
using namespace std;

class player{
public:
	string name;
	int grade;
	player()
	{
		cout << "请输入姓名：";
		cin >> name;
		grade = 0;
	}
};

class boundary:public player{
public:
	static int max;
	static int high;
	static int down;
	char bound[25][30];
	boundary()
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				bound[i][j] = ' ';
			}
		}
	}
	void print()
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			cout << "                                |";
			for (int j = 0; j < 30; j++)
			{
				cout << bound[i][j];
			}
			cout << '|';
			if (i == 15)cout << "姓名：" << name;
			if (i == 17)cout << "分数：" << grade;
			cout << endl;
		}
	}
	void build()
	{
		int i, j;
		i = time(0) % 25;
		j = time(0) % 5;
		if (j == 0)
		{
			bound[0][i] = '*';
			bound[0][i + 1] = '*';
			bound[1][i] = '*';
			bound[1][i + 1] = '*';
		}
		if (j == 1)
		{
			for (int m = 0; m < 4; m++)
				bound[0][i + m] = '*';
		}
		if (j == 2)
		{
			bound[0][i] = '*';
			bound[0][i + 1] = '*';
			bound[1][i + 1] = '*';
			bound[2][i + 1] = '*';
		}
		if (j == 3)
		{
			bound[0][i+1] = '*';
			bound[1][i+1] = '*';
			bound[1][i] = '*';
			bound[1][i + 2] = '*';
		}
		if (j == 4)
		{
			bound[0][i] = '*';
			bound[0][i - 1] = '*';
			bound[1][i - 1] = '*';
			bound[2][i - 1] = '*';
		}
		high = 0;
		print();
	}
	void shift_down()
	{
		int h = high;
		if (down < max)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					bound[h + 4 - i][j] = bound[h + 3 - i][j];
				}
			}
		}

		for (int j = 0; j < 30; j++)
			bound[h][j] = ' ';
		print();
	}
};
int boundary::max = 25;
int boundary::high = 0;

int main()
{
	boundary a;
	a.print();
	a.build();
	a.shift_down();
	a.shift_down();
}



