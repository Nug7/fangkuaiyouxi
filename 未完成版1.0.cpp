#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
#include<conio.h>
using namespace std;

class Player{
public:
	string name;
	int score;
public:
	Player()
	{
		cout << "请输入姓名：";
		cin >> name;
		score = 0;
	}
	void playGame();
	void endGame();
};

void Player::playGame()
{
	View v;
	long long int ms;
	while (true)
	if (ms % 500 == 0)
		v.printView();
}

void Player::endGame()
{
	cout << name << ",您的最终得分为：" << score;
	exit(0);
}

class View{
public:
	int hight;
	int weight;
	char view[30][25];
	int m[25];
	Wood w;
public:
	View()
	{
		hight = 30;
		weight = 25;
		for (int i = 0; i < hight; i++)
		for (int j = 0; j < weight; j++)
			view[i][j] = ' ';
		for (int i = 0; i < weight; i++)
			m[i] = 0;
	}
	void printView(Player p);
};

void View::printView(Player p)
{
	system("cls");
	for (int i = 0; i < hight; i++)
	{
		cout << "|";
		for (int j = -1; j < weight; j++)
		{
			if (i == -1 || i == hight) cout << "-";
			else cout << view[i][j];
		}
		cout << "|";
		if (i == 2) cout << "游戏说明：";
		if (i == 3) cout << "↑ 方块旋转";
		if (i == 4) cout << "↓ 方块下降";
		if (i == 5) cout << "← 方块左移";
		if (i == 6) cout << "→ 方块右移";
		if (i == 20) cout << "姓名：" << p.name;
		if (i == 22) cout << "分数：" << p.score;
		cout << endl;
	}
	char x;
	x = _getch();
	if (x == 75) w.left();
	if (x == 77) w.right();
	if (x == 72) w.down();
	if (x == 80) w.up();
	v.printview();
}

class Wood{
public:
	char wood[2][4];
public:
	Wood();
	void up();//旋转
	void down();//速降
	void left();//左移
	void right();//右移
	void times();//随时间落下，每0.5s落一次
};
