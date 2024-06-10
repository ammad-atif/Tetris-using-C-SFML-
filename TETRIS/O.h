#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"tetrominos.h"
#include"well.h"
using namespace std;
using namespace sf;
class o :public tetrominos
{
private:
	int xo;
	int yo;
	RectangleShape rec_o;
	int hcf(int num)
	{
		return (num / 30);
	}
	bool check0(int** b, int x, int y)
	{
		if (y >= 150)
		{
			int i = hcf((y - 150));
			int j = hcf(x);
			if (b[i][j] == 0)
			{
				return 1;
			}
		}
		if (y < 150)
		{
			return 1;
		}
		return 0;
	}
	bool check1(int** b, int x, int y)
	{
		if (y >= 150)
		{
			int i = hcf((y - 150));
			int j = hcf(x);
			if (b[i][j] != 0)
			{
				return 1;
			}
		}
		return 0;
	}
public:
	o()
	{
		xo = 0;
		yo = 0;
		rec_o.setSize(Vector2f(30, 30));
		rec_o.setFillColor(Color::Yellow);
		rec_o.setOutlineColor(Color::Black);
		rec_o.setOutlineThickness(3);
	}
	 void drawtetromino(RenderWindow& window)
	 {
		rec_o.setPosition(xo, yo);
		window.draw(rec_o);
		rec_o.setPosition(xo+30, yo);
		window.draw(rec_o);
		rec_o.setPosition(xo, yo+30);
		window.draw(rec_o);
		rec_o.setPosition(xo+30, yo+30);
		window.draw(rec_o);
	 }
	void movedown(int **b)
	{
			if ((yo < 690) && check0(b,xo,yo+60)/*b[i + 2][j] == 0*/ && check0(b,xo+30,yo+60) /*b[i + 2][j + 1] == 0*/)
			{
				yo += 30;
			}
	}
	void moveright(int **b)
	{
			if ((xo < 240) && (yo < 690) && check0(b,xo+60,yo)/*b[i][j + 2] ==0 */ && check0(b,xo+60,yo+30)/*b[i + 1][j + 2] == 0*/)
			{
				xo += 30;
			}
	}
	void moveleft(int **b)
	{
			if ((xo > 0) && (yo < 690) && check0(b,xo-30,yo)/*b[i][j - 1] == 0*/ && check0(b,xo-30,yo+30)/*b[i + 1][j - 1] == 0*/)
			{
				xo -= 30;
			}
	}
	int rotate(int **b)
	{
		xo = xo;
		yo = yo;
		return 1;
	}
	int getx()
	{
		return xo;
	}
	int gety()
	{
		return yo;
	}
	int cond(int **b)
	{
		if (yo>=150)
		{
			if (yo == 690 || check1(b, xo, yo + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xo + 30, yo + 60) /*(b[i + 2][j + 1] >= 1)*/)
			{
				return 1;
			}
		}
		if (yo<150)
		{
			if (yo == 690 || check1(b, xo, yo + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xo + 30, yo + 60) /*(b[i + 2][j + 1] >= 1)*/)
			{
				return 5;
			}
		}
			return 0;
	}
};