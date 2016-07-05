#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
using namespace std;

class Player{
public:
	string name;
	int code;
public:
	Player()
	{
		cout << "请输入姓名：";
		cin >> name;
		code = 0;
	}
	void playGame();
	void endGame();
};

class View{
public:
	int hight;
	int weight;
	char view[30][25];
	int m[25];
public:
	View()
	{
		hight = 30;
		weight = 25;
		for (int i = 0; i < hight;i++)
		  for (int j = 0; j < weight; j++)
			  view[i][j] = ' ';
		  for (int i = 0; i < weight; i++)
			  m[i] = 0;
	}
	void printView();
};

class Wood{
public:
	char wood[2][4];
public:
	Wood();
	void up();//旋转
	void down();//速降
	void times();//随时间落下，每0.5s落一次
};
