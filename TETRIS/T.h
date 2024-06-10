#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class t :public tetrominos
{
private:
	int xt;
	int yt;
	int rot;
	RectangleShape rec_t;
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
	t()
	{
		xt = 0;
		yt = 0;
		rot = 0;
		rec_t.setSize(Vector2f(30, 30));
		rec_t.setFillColor(Color(160,32,240) );
		rec_t.setOutlineColor(Color::Black);
		rec_t.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot % 4 == 0)
		{
			rec_t.setPosition(xt, yt);
			window.draw(rec_t);
			rec_t.setPosition(xt+30, yt);
			window.draw(rec_t);
			rec_t.setPosition(xt+60, yt );
			window.draw(rec_t);
			rec_t.setPosition(xt + 30, yt + 30);
			window.draw(rec_t);
		}
		if (rot % 4 == 1)
		{
			rec_t.setPosition(xt+30, yt);
			window.draw(rec_t);
			rec_t.setPosition(xt + 30, yt+30);
			window.draw(rec_t);
			rec_t.setPosition(xt + 30, yt+60);
			window.draw(rec_t);
			rec_t.setPosition(xt, yt + 30);
			window.draw(rec_t);
		}
		if (rot % 4 == 2)
		{
			rec_t.setPosition(xt+30, yt);
			window.draw(rec_t);
			rec_t.setPosition(xt , yt+30);
			window.draw(rec_t);
			rec_t.setPosition(xt + 30, yt + 30);
			window.draw(rec_t);
			rec_t.setPosition(xt + 60, yt + 30);
			window.draw(rec_t);

		}
		if (rot % 4 == 3)
		{
			rec_t.setPosition(xt , yt);
			window.draw(rec_t);
			rec_t.setPosition(xt, yt + 30);
			window.draw(rec_t);
			rec_t.setPosition(xt , yt + 60);
			window.draw(rec_t);
			rec_t.setPosition(xt + 30, yt + 30);
			window.draw(rec_t);
		}
	}
	void movedown(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((yt < 690) && check0(b, xt, yt + 30)/*(b[i+1][j]==0)*/  && check0(b, xt + 60, yt + 30)/*(b[i+1][j+2]==0)*/&& check0(b, xt + 30, yt + 60)/*(b[i+2][j+1]==0)*/)
			{
				yt += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((yt < 660) && check0(b, xt, yt + 60)/*(b[i+2][j]==0)*/ && check0(b, xt + 30, yt + 90)/*(b[i+3][j+1]==0)*/)
			{
				yt += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((yt < 690) && check0(b, xt, yt + 60) /*(b[i + 2][j] == 0)*/ && check0(b, xt + 30, yt + 60) /*(b[i + 2][j +1] == 0)*/ && check0(b, xt + 60, yt + 60) /*(b[i + 2][j + 2] == 0)*/)
			{
				yt += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yt < 660) && check0(b, xt, yt + 90)/*(b[i+3][j]==0)*/ && check0(b, xt + 30, yt + 60)/*(b[i+2][j+1]==0)*/)
			{
				yt += 30;
			}
		}
	}
	void moveright(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xt < 210) && (yt < 690) && check0(b, xt + 90, yt)/*(b[i][j+3]==0)*/ && check0(b, xt + 60, yt + 30)/*(b[i+1][j+2]==0)*/)
			{
				xt += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xt < 240) && (yt < 660) && check0(b, xt + 60, yt) /*(b[i][j + 2] == 0)*/ && check0(b, xt + 60, yt + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xt + 60, yt + 60)/* (b[i +2][j + 2] == 0)*/)
			{
				xt += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xt < 210) && (yt < 690) && check0(b, xt + 60, yt)/*(b[i][j+2]==0)*/ && check0(b, xt + 90, yt + 30)/*(b[i+1][j+3]==0)*/)
			{
				xt += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xt < 240) && (yt < 660) && check0(b, xt + 30, yt) /*(b[i][j + 1] == 0)*/ && check0(b, xt + 60, yt + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xt + 30, yt + 60)/* (b[i +2][j + 1] == 0)*/)
			{
				xt += 30;
			}
		}
	}
	void moveleft(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xt > 0) && (yt < 690) && check0(b, xt - 30, yt)/*(b[i][j-1]==0)*/ && check0(b, xt , yt + 30)/*(b[i+1][j]==0)*/)
			{
				xt -= 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xt > 0) && (yt < 660) && check0(b, xt, yt) /*(b[i][j] == 0)*/ && check0(b, xt-30, yt + 30)/*(b[i +1][j-1 ] == 0)*/ && check0(b, xt, yt + 60) /*(b[i + 2][j ] == 0)*/)
			{
				xt -= 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xt > 0) && (yt < 690) && check0(b, xt , yt)/*(b[i][j]==0)*/ && check0(b, xt-30, yt + 30)/*(b[i+1][j-1]==0)*/)
			{
				xt -= 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xt > 0) && (yt < 660) && check0(b, xt - 30, yt) /*(b[i][j - 1] == 0)*/ && check0(b, xt - 30, yt + 30)/*(b[i + 1][j - 1] == 0)*/ && check0(b, xt - 30, yt + 60)/*(b[i + 2][j - 1] == 0)*/)
			{
				xt -= 30;
			}
		}
	}
	int rotate(int** b)
	{
		if (rot % 4 == 0)
		{
			if (yt<=660 && check0(b, xt , yt+30) /*(b[i+1][j] == 0)*/ && check0(b, xt + 30, yt+60) /*(b[i+2][j +1] == 0)*/ )
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 1)
		{
			if (xt <= 210 && check0(b, xt + 60, yt + 30)/*(b[i+1][j+2] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 2)
		{
			if (yt<=660 && check0(b, xt, yt)/*b[i][j] == 0*/ && check0(b, xt, yt + 60)/*b[i+2][j]==0*/ )
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 3)
		{
			if (xt <= 210 && check0(b, xt+30, yt) /*(b[i][j+1] == 0)*/ && check0(b, xt+60 , yt ) /*(b[i][j+2] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
	}
	int getx()
	{
		return xt;
	}
	int gety()
	{
		return yt;
	}
	int cond(int** b)
	{
		if (yt >= 150)
		{
			if (rot % 4 == 0)
			{
				if ((yt == 690) || check1(b, xt, yt + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xt + 60, yt + 30)/*(b[i + 1][j + 2] >= 1)*/ || check1(b, xt + 30, yt + 60)/*(b[i + 2][j + 1] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yt == 660) || check1(b, xt, yt + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xt + 30, yt + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yt == 690) || check1(b, xt, yt + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xt + 30, yt + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xt + 60, yt + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yt == 660) || check1(b, xt, yt + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xt + 30, yt + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (yt < 150)
		{
			if (rot % 4 == 0)
			{
				if ((yt == 690) || check1(b, xt, yt + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xt + 60, yt + 30)/*(b[i + 1][j + 2] >= 1)*/ || check1(b, xt + 30, yt + 60)/*(b[i + 2][j + 1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yt == 660) || check1(b, xt, yt + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xt + 30, yt + 90) /*(b[i +3][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yt == 690) || check1(b, xt, yt + 60) /*(b[i + 2][j] >= 1)*/ || check1(b, xt + 30, yt + 60)/* (b[i + 2][j + 1] >= 1)*/ || check1(b, xt + 60, yt + 60)/*(b[i + 2][j + 2] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yt == 660) || check1(b, xt, yt + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xt + 30, yt + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};
