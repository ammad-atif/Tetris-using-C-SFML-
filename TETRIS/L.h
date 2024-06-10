#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class l :public tetrominos
{
private:
	int xl;
	int yl;
	int rot;
	RectangleShape rec_l;
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
	l()
	{
		xl = 0;
		yl = 0;
		rot = 0;
		rec_l.setSize(Vector2f(30, 30));
		rec_l.setFillColor(Color(255,165,0));
		rec_l.setOutlineColor(Color::Black);
		rec_l.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot % 4 == 0)
		{
			rec_l.setPosition(xl, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl, yl + 30);
			window.draw(rec_l);
			rec_l.setPosition(xl, yl + 60);
			window.draw(rec_l);
			rec_l.setPosition(xl+30, yl + 60);
			window.draw(rec_l);
		}
		if (rot % 4 == 1)
		{
			rec_l.setPosition(xl, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl + 30, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl + 60, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl , yl+30);
			window.draw(rec_l);
		}
		if (rot % 4 == 2)
		{
			rec_l.setPosition(xl, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl+30, yl );
			window.draw(rec_l);
			rec_l.setPosition(xl+30, yl + 30);
			window.draw(rec_l);
			rec_l.setPosition(xl+30, yl +60);
			window.draw(rec_l);

		}
		if (rot % 4 == 3)
		{
			rec_l.setPosition(xl + 60, yl);
			window.draw(rec_l);
			rec_l.setPosition(xl, yl+30);
			window.draw(rec_l);
			rec_l.setPosition(xl+30, yl+30);
			window.draw(rec_l);
			rec_l.setPosition(xl + 60, yl+30);
			window.draw(rec_l);
		}
	}
	void movedown(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((yl < 660) && check0(b, xl, yl + 90) /*(b[i + 3][j] == 0)*/&& check0(b, xl+30, yl + 90) /*(b[i + 3][j+1] == 0)*/)
			{
				yl += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((yl < 690) && check0(b, xl, yl + 60)/*(b[i+2][j]==0)*/ && check0(b, xl + 30, yl + 30)/*(b[i+1][j+1]==0)*/ && check0(b, xl + 60, yl + 30)/*(b[i+1][j+2]==0)*/ )
			{
				yl += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((yl < 660) && check0(b, xl, yl + 30)/*(b[i+1][j]==0)*/ && check0(b, xl+30, yl + 90)/*(b[i+3][j+1]==0)*/)
			{
				yl += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yl < 690) && check0(b, xl, yl + 60) /*(b[i + 2][j] == 0)*/ && check0(b, xl + 30, yl + 60) /*(b[i + 2][j +1] == 0)*/ && check0(b, xl + 60, yl + 60) /*(b[i + 2][j + 2] == 0)*/ )
			{
				yl += 30;
			}
		}
	}
	void moveright(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xl < 240) && (yl < 660) && check0(b, xl + 30, yl)/*(b[i][j + 1] == 0)*/ && check0(b, xl + 30, yl + 30)/* (b[i + 1][j + 1] == 0)*/  && check0(b, xl + 60, yl + 60) /*(b[i + 2][j + 2] == 0)*/)
			{
				xl += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xl < 210) && (yl < 690) && check0(b, xl + 90, yl)/*(b[i][j+3]==0)*/ && check0(b, xl +30, yl+30)/*(b[i+1][j+1]==0)*/)
			{
				xl += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xl < 240) && (yl < 660) && check0(b, xl + 60, yl) /*(b[i][j + 2] == 0)*/ && check0(b, xl + 60, yl + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xl + 60, yl + 60)/* (b[i +2][j + 2] == 0)*/ )
			{
				xl += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xl < 230) && (yl < 690) && check0(b, xl + 90, yl)/*(b[i][j+3]==0)*/ && check0(b, xl + 90, yl+30)/*(b[i+1][j+3]==0)*/)
			{
				xl += 30;
			}
		}
	}
	void moveleft(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xl > 0) && (yl < 660) && check0(b, xl - 30, yl) /*(b[i][j - 1] == 0)*/ && check0(b, xl - 30, yl + 30)/*(b[i + 1][j - 1] == 0)*/ && check0(b, xl - 30, yl + 60)/*(b[i + 2][j - 1] == 0)*/ )
			{
				xl -= 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xl > 0) && (yl < 690) && check0(b, xl - 30, yl)/*(b[i][j-1]==0)*/ && check0(b, xl - 30, yl+30)/*(b[i+1][j-1]==0)*/)
			{
				xl -= 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xl > 0) && (yl < 660) && check0(b, xl - 30, yl) /*(b[i][j - 1] == 0)*/ && check0(b, xl , yl+ 30)/*(b[i + 1][j ] == 0)*/ && check0(b, xl , yl + 60) /*(b[i + 2][j ] == 0)*/ )
			{
				xl -= 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xl > 0) && (yl < 690) && check0(b, xl - 30, yl+30)/*b[i+1][j-1]==0*/ && check0(b, xl + 30, yl)/*b[i][j+1]==0*/)
			{
				xl -= 30;
			}
		}
	}
	int rotate(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xl <= 210) && check0(b, xl + 30, yl) /*(b[i][j + 1] == 0)*/ && check0(b, xl + 60, yl) /*(b[i][j + 2] == 0)*/ && check0(b, xl , yl+30) /*(b[i+1][j] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 1)
		{
			if (yl <= 660 && check0(b, xl+30, yl + 30)/*(b[i+1][j+1] == 0)*/ && check0(b, xl+30, yl + 60) /*(b[i +2][j+1 ] == 0)*/ )
			{	
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xl >= 0) && check0(b, xl + 60, yl)/*b[i][j +2] == 0*/ && check0(b, xl , yl+30)/*b[i+1][j]==0*/ && check0(b, xl + 30, yl + 30)/*b[i+1][j+1]==0*/ && check0(b, xl + 60, yl+30)/*b[i+1][j+2]==0*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yl <= 660) && check0(b, xl, yl) /*(b[i][j] == 0)*/ && check0(b, xl, yl + 30) /*(b[i + 1][j] == 0)*/ && check0(b, xl, yl + 60)/*(b[i + 2][j] == 0)*/ && check0(b, xl+30, yl + 60)/*(b[i + 2][j+1] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
	}
	int getx()
	{
		return xl;
	}
	int gety()
	{
		return yl;
	}
	int cond(int** b)
	{
		if (yl >= 150)
		{
			if (rot % 4 == 0)
			{
				if ((yl == 660) || check1(b, xl, yl + 90)/*(b[i + 3][j] >= 1)*/ || check1(b, xl + 30, yl + 90)/*(b[i + 3][j+1] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yl == 690) || check1(b, xl, yl + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xl + 30, yl + 30)/*(b[i + 1][j + 1] >= 1)*/ || check1(b, xl + 60, yl + 30)/*(b[i + 1][j + 2] >= 1)*/ )
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yl == 660) || check1(b, xl, yl + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xl+30, yl + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yl == 690) || check1(b, xl, yl + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xl + 30, yl + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xl + 60, yl + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (yl < 150)
		{
			if (rot % 4 == 0)
			{
				if ((yl == 660) || check1(b, xl, yl + 90)/*(b[i + 3][j] >= 1)*/ || check1(b, xl + 30, yl + 90)/*(b[i + 3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yl == 690) || check1(b, xl, yl + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xl + 30, yl + 30)/*(b[i + 1][j + 1] >= 1)*/ || check1(b, xl + 60, yl + 30)/*(b[i + 1][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yl == 660) || check1(b, xl, yl + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xl + 30, yl + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yl == 690) || check1(b, xl, yl + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xl + 30, yl + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xl + 60, yl + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};