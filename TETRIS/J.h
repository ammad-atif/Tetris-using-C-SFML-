#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class j :public tetrominos
{
private:
	int xj;
	int yj;
	int rot;
	RectangleShape rec_j;
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
	j()
	{
		xj = 0;
		yj = 0;
		rot = 0;
		rec_j.setSize(Vector2f(30, 30));
		rec_j.setFillColor(Color::Blue);
		rec_j.setOutlineColor(Color::Black);
		rec_j.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot % 4 == 0)
		{
			rec_j.setPosition(xj+30, yj);
			window.draw(rec_j);
			rec_j.setPosition(xj+30, yj + 30);
			window.draw(rec_j);
			rec_j.setPosition(xj+30, yj + 60);
			window.draw(rec_j);
			rec_j.setPosition(xj , yj + 60);
			window.draw(rec_j);
		}
		if (rot % 4 == 1)
		{
			rec_j.setPosition(xj, yj);
			window.draw(rec_j);
			rec_j.setPosition(xj, yj+30);
			window.draw(rec_j);
			rec_j.setPosition(xj + 30, yj+30);
			window.draw(rec_j);
			rec_j.setPosition(xj+60, yj + 30);
			window.draw(rec_j);
		}
		if (rot % 4 == 2)
		{
			rec_j.setPosition(xj, yj);
			window.draw(rec_j);
			rec_j.setPosition(xj + 30, yj);
			window.draw(rec_j);
			rec_j.setPosition(xj, yj + 30);
			window.draw(rec_j);
			rec_j.setPosition(xj , yj + 60);
			window.draw(rec_j);

		}
		if (rot % 4 == 3)
		{
			rec_j.setPosition(xj , yj);
			window.draw(rec_j);
			rec_j.setPosition(xj+30, yj );
			window.draw(rec_j);
			rec_j.setPosition(xj + 60, yj );
			window.draw(rec_j);
			rec_j.setPosition(xj + 60, yj + 30);
			window.draw(rec_j);
		}
	}
	void movedown(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((yj < 660) && check0(b, xj, yj + 90) /*(b[i + 3][j] == 0)*/ && check0(b, xj + 30, yj + 90) /*(b[i + 3][j+1] == 0)*/)
			{
				yj += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((yj < 690) && check0(b, xj, yj + 60) /*(b[i + 2][j] == 0)*/ && check0(b, xj + 30, yj + 60) /*(b[i + 2][j +1] == 0)*/ && check0(b, xj + 60, yj + 60) /*(b[i + 2][j + 2] == 0)*/)
			{
				yj += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((yj < 660) && check0(b, xj+30, yj + 30)/*(b[i+1][j+1]==0)*/ && check0(b, xj , yj + 90)/*(b[i+3][j]==0)*/)
			{
				yj += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yj < 690) && check0(b, xj, yj + 30) /*(b[i + 1][j] == 0)*/ && check0(b, xj + 30, yj + 30) /*(b[i + 1][j +1] == 0)*/ && check0(b, xj + 60, yj + 60) /*(b[i + 2][j + 2] == 0)*/)
			{
				yj += 30;
			}
		}
	}
	void moveright(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xj < 240) && (yj < 660) && check0(b, xj + 60, yj) /*(b[i][j + 2] == 0)*/ && check0(b, xj + 60, yj + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xj + 60, yj + 60)/* (b[i +2][j + 2] == 0)*/)
			{
				xj += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xj < 210) && (yj < 690) && check0(b, xj + 30, yj)/*(b[i][j+1]==0)*/ && check0(b, xj + 90, yj + 30)/*(b[i+1][j+3]==0)*/)
			{
				xj += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xj < 240) && (yj < 660) && check0(b, xj + 60, yj) /*(b[i][j + 2] == 0)*/ && check0(b, xj + 30, yj + 30) /*(b[i +1 ][j + 1] == 0)*/ && check0(b, xj + 30, yj + 60)/* (b[i +2][j + 1] == 0)*/)
			{
				xj += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xj < 230) && (yj < 690) && check0(b, xj + 90, yj)/*(b[i][j+3]==0)*/ && check0(b, xj + 90, yj + 30)/*(b[i+1][j+3]==0)*/)
			{
				xj += 30;
			}
		}
	}
	void moveleft(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xj > 0) && (yj < 660) && check0(b, xj , yj) /*(b[i][j] == 0)*/ && check0(b, xj, yj + 30)/*(b[i + 1][j] == 0)*/ && check0(b, xj - 30, yj + 60)/*(b[i + 2][j - 1] == 0)*/)
			{
				xj -= 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xj > 0) && (yj < 690) && check0(b, xj - 30, yj)/*(b[i][j-1]==0)*/ && check0(b, xj - 30, yj + 30)/*(b[i+1][j-1]==0)*/)
			{
				xj -= 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xj > 0) && (yj < 660) && check0(b, xj - 30, yj) /*(b[i][j - 1] == 0)*/ && check0(b, xj - 30, yj + 30)/*(b[i + 1][j - 1] == 0)*/ && check0(b, xj - 30, yj + 60)/*(b[i + 2][j - 1] == 0)*/)
			{
				xj -= 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xj > 0) && (yj < 690) && check0(b, xj + 30, yj + 30)/*b[i+1][j+1]==0*/ && check0(b, xj - 30, yj)/*b[i][j-1]==0*/)
			{
				xj -= 30;
			}
		}
	}
	int rotate(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xj <= 210) && check0(b, xj , yj) /*(b[i][j] == 0)*/ && check0(b, xj , yj+30) /*(b[i+1][j] == 0)*/ && check0(b, xj+30, yj + 30) /*(b[i+1][j+1] == 0)*/ && check0(b, xj + 60, yj + 30) /*(b[i+1][j+2] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 1)
		{
			if (yj <= 660 && check0(b, xj , yj+60)/*(b[i+2][j] == 0)*/ && check0(b, xj + 30, yj) /*(b[i][j+1 ] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xj >= 0) && check0(b, xj + 60, yj)/*b[i][j +2] == 0*/  &&(b, xj + 60, yj + 30)/*b[i+1][j+2]==0*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yj <= 660) && check0(b, xj+30, yj+30) /*(b[i+1][j+1] == 0)*/ && check0(b, xj+30, yj + 60) /*(b[i + 2][j+1] == 0)*/ && check0(b, xj, yj + 60)/*(b[i + 2][j] == 0)*/ )
			{
				rot++;
				return 1;
			}
		}
	}
	int getx()
	{
		return xj;
	}
	int gety()
	{
		return yj;
	}
	int cond(int** b)
	{
		if (yj >= 150)
		{
			if (rot % 4 == 0)
			{
				if ((yj == 660) || check1(b, xj, yj + 90)/*(b[i + 3][j] >= 1)*/ || check1(b, xj + 30, yj + 90)/*(b[i + 3][j+1] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yj == 690) || check1(b, xj, yj + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xj + 30, yj + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xj + 60, yj + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yj == 660) || check1(b, xj+30, yj + 30) /*(b[i + 1][j+1] >= 1)*/ || check1(b, xj , yj + 90) /*(b[i +3][j] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yj == 690) || check1(b, xj, yj + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xj + 30, yj + 30)/* (b[i + 1][j + 1] >= 1)*/ || check1(b, xj + 60, yj + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (yj < 150)
		{
			if (rot % 4 == 0)
			{
				if ((yj == 660) || check1(b, xj, yj + 90)/*(b[i + 3][j] >= 1)*/ || check1(b, xj + 30, yj + 90)/*(b[i + 3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yj == 690) || check1(b, xj, yj + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xj + 30, yj + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xj + 60, yj + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yj == 660) || check1(b, xj + 30, yj + 30) /*(b[i + 1][j+1] >= 1)*/ || check1(b, xj, yj + 90) /*(b[i +3][j] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yj == 690) || check1(b, xj, yj + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xj + 30, yj + 30)/* (b[i + 1][j + 1] >= 1)*/ || check1(b, xj + 60, yj + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};