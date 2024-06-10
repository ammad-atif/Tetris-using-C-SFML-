#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class s :public tetrominos
{
private:
	int xs;
	int ys;
	int rot;
	RectangleShape rec_s;
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
	s()
	{
		xs = 0;
		ys = 0;
		rot = 0;
		rec_s.setSize(Vector2f(30, 30));
		rec_s.setFillColor(Color::Green);
		rec_s.setOutlineColor(Color::Black);
		rec_s.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot % 4 == 0)
		{
			rec_s.setPosition(xs, ys+30);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 60, ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 30);
			window.draw(rec_s);
		}
		if (rot % 4 == 1)
		{
			rec_s.setPosition(xs , ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 30);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 60);
			window.draw(rec_s);
			rec_s.setPosition(xs, ys + 30);
			window.draw(rec_s);
		}
		if (rot % 4 == 2)
		{
			rec_s.setPosition(xs, ys + 30);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 60, ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 30);
			window.draw(rec_s);

		}
		if (rot % 4 == 3)
		{
			rec_s.setPosition(xs, ys);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 30);
			window.draw(rec_s);
			rec_s.setPosition(xs + 30, ys + 60);
			window.draw(rec_s);
			rec_s.setPosition(xs, ys + 30);
			window.draw(rec_s);
		}
	}
	void movedown(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((ys < 690) && check0(b, xs, ys + 60)/*b[i + 2][j] == 0*/ && check0(b, xs + 30, ys + 60) /*b[i + 2][j + 1] == 0*/&& check0(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] == 0*/)
			{
				ys += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((ys < 660) && check0(b, xs, ys + 60)/*(b[i+2][j]==0)*/ && check0(b, xs + 30, ys + 90)/*(b[i+3][j+1]==0)*/)
			{
				ys += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((ys < 690) && check0(b, xs, ys + 60)/*b[i + 2][j] == 0*/ && check0(b, xs + 30, ys + 60) /*b[i + 2][j + 1] == 0*/ && check0(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] == 0*/)
			{
				ys += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((ys < 660) && check0(b, xs, ys + 60)/*(b[i+2][j]==0)*/ && check0(b, xs + 30, ys + 90)/*(b[i+3][j+1]==0)*/)
			{
				ys += 30;
			}
		}
	}
	void moveright(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xs < 210) && (ys < 690) && check0(b, xs + 90, ys)/*(b[i][j+3]==0)*/ && check0(b, xs + 60, ys + 30)/*(b[i+1][j+2]==0)*/)
			{
				xs += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xs < 240) && (ys < 660) && check0(b, xs + 30, ys) /*(b[i][j + 1] == 0)*/ && check0(b, xs + 60, ys + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xs + 60, ys + 60)/* (b[i +2][j + 2] == 0)*/)
			{
				xs += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xs < 210) && (ys < 690) && check0(b, xs + 90, ys)/*(b[i][j+3]==0)*/ && check0(b, xs + 60, ys + 30)/*(b[i+1][j+2]==0)*/)
			{
				xs += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xs < 240) && (ys < 660) && check0(b, xs + 30, ys) /*(b[i][j + 1] == 0)*/ && check0(b, xs + 60, ys + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xs + 60, ys + 60)/* (b[i +2][j + 2] == 0)*/)
			{
				xs += 30;
			}
		}
	}
	void moveleft(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xs > 0) && (ys < 690) && check0(b, xs, ys)/*(b[i][j]==0)*/ && check0(b, xs - 30, ys + 30)/*(b[i+1][j-1]==0)*/)
			{
				xs -= 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xs > 0) && (ys < 660) && check0(b, xs-30, ys) /*(b[i][j-1] == 0)*/ && check0(b, xs - 30, ys + 30)/*(b[i +1][j-1 ] == 0)*/ && check0(b, xs, ys + 60) /*(b[i + 2][j ] == 0)*/)
			{
				xs -= 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xs > 0) && (ys < 690) && check0(b, xs, ys)/*(b[i][j]==0)*/ && check0(b, xs - 30, ys + 30)/*(b[i+1][j-1]==0)*/)
			{
				xs -= 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xs > 0) && (ys < 660) && check0(b, xs - 30, ys) /*(b[i][j-1] == 0)*/ && check0(b, xs - 30, ys + 30)/*(b[i +1][j-1 ] == 0)*/ && check0(b, xs, ys + 60) /*(b[i + 2][j ] == 0)*/)
			{
				xs -= 30;
			}
		}
	}
	int rotate(int** b)
	{
		if (rot % 4 == 0)
		{
			if (ys <= 660 && check0(b, xs, ys ) /*(b[i][j] == 0)*/ && check0(b, xs + 30, ys + 60) /*(b[i+2][j +1] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 1)
		{
			if (xs <= 210 && check0(b, xs + 60, ys)/*(b[i][j+2] == 0)*/ && check0(b, xs + 30, ys)/*(b[i][j+1] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 2)
		{
			if (ys <= 660 && check0(b, xs, ys) /*(b[i][j] == 0)*/ && check0(b, xs + 30, ys + 60) /*(b[i+2][j +1] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 3)
		{
			if (xs <= 210 && check0(b, xs + 60, ys)/*(b[i][j+2] == 0)*/ && check0(b, xs + 30, ys)/*(b[i][j+1] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
	}
	int getx()
	{
		return xs;
	}
	int gety()
	{
		return ys;
	}
	int cond(int** b)
	{
		if (ys >= 150)
		{
			if (rot % 4 == 0)
			{
				if (ys == 690 || check1(b, xs, ys + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 60) /*(b[i + 2][j + 1] >= 1)*/ || check1(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((ys == 660) || check1(b, xs, ys + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if (ys == 690 || check1(b, xs, ys + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 60) /*(b[i + 2][j + 1] >= 1)*/ || check1(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((ys == 660) || check1(b, xs, ys + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (ys<150)
		{
			if (rot % 4 == 0)
			{
				if (ys == 690 || check1(b, xs, ys + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 60) /*(b[i + 2][j + 1] >= 1)*/ || check1(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((ys == 660) || check1(b, xs, ys + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if (ys == 690 || check1(b, xs, ys + 60)/*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 60) /*(b[i + 2][j + 1] >= 1)*/ || check1(b, xs + 60, ys + 30) /*(b[i + 1][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((ys == 660) || check1(b, xs, ys + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xs + 30, ys + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};
