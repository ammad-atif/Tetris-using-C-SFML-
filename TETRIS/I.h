#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class i:public tetrominos
{
private:
	int xi;
	int yi;
	int rot;
	RectangleShape rec_i;
	int hcf(int num)
	{
		return (num / 30);
	}
	bool check0(int **b,int x,int y)
	{
		if (y>=150)
		{
			int i = hcf((y - 150));
			int j = hcf(x);
			if (b[i][j]==0)
			{
				return 1;
			}
		}
		if (y<150)
		{
			return 1;
		}
		return 0;
	}
	bool check1(int **b,int x, int y)
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
	i()
	{
		xi = 0;
		yi = 0;
		rot = 0;
		rec_i.setSize(Vector2f(30, 30));
		rec_i.setFillColor(Color::Cyan);
		rec_i.setOutlineColor(Color::Black);
		rec_i.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot%4==0)
		{
			rec_i.setPosition(xi, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi, yi + 30);
			window.draw(rec_i);
			rec_i.setPosition(xi, yi + 60);
			window.draw(rec_i);
			rec_i.setPosition(xi, yi + 90);
			window.draw(rec_i);
		}
		if (rot%4==1)
		{
			rec_i.setPosition(xi, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi+30, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi+60, yi  );
			window.draw(rec_i);
			rec_i.setPosition(xi+90, yi );
			window.draw(rec_i);
		}
		if (rot%4==2)
		{
			rec_i.setPosition(xi, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi , yi-30);
			window.draw(rec_i);
			rec_i.setPosition(xi , yi-60);
			window.draw(rec_i);
			rec_i.setPosition(xi , yi-90);
			window.draw(rec_i);

		}
		if (rot%4==3)
		{
			rec_i.setPosition(xi, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi - 30, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi - 60, yi);
			window.draw(rec_i);
			rec_i.setPosition(xi - 90, yi);
			window.draw(rec_i);
		}
	}
	void movedown(int** b)
	{
			if (rot%4==0)
			{
				if ((yi < 630) && check0(b,xi,yi+120) /*(b[i + 4][j] == 0)*/)
				{
					yi += 30;
				}
			}
			if (rot%4==1)
			{
				if ((yi < 720)&& check0(b,xi,yi+30)/*(b[i+1][j]==0)*/&& check0(b, xi+30,yi +30)/*(b[i+1][j+1]==0)*/&& check0(b, xi+60, yi + 30)/*(b[i+1][j+2]==0)*/&& check0(b, xi+90, yi + 30)/*(b[i+1][j+3]==0)*/)
				{
					yi += 30;
				}
			}
			if (rot%4==2)
			{
				if ((yi < 720)&& check0(b, xi, yi + 30)/*(b[i+1][j]==0)*/)
				{
					yi += 30;
				}
			}
			if (rot%4==3)
			{
				if ((yi < 720)&& check0(b, xi, yi + 30) /*(b[i + 1][j] == 0)*/ && check0(b, xi-30, yi + 30) /*(b[i + 1][j -1] == 0)*/ && check0(b, xi-60, yi + 30) /*(b[i + 1][j - 2] == 0)*/ && check0(b, xi-90, yi + 30) /*(b[i + 1][j - 3] == 0)*/)
				{
					yi += 30;
				}
			}
	}
	void moveright(int** b)
	{
			if (rot%4==0)
			{
				if ((xi < 270) && (yi < 630) && check0(b, xi+30, yi)/*(b[i][j + 1] == 0)*/ && check0(b, xi+30, yi + 30)/* (b[i + 1][j + 1] == 0)*/ && check0(b, xi+30, yi + 60)/*(b[i + 2][j + 1] == 0)*/ && check0(b, xi+30, yi + 90) /*(b[i + 3][j + 1] == 0)*/)
				{
					xi += 30;
				}
			}
			if (rot%4==1)
			{
					if ((xi < 180) && (yi < 720)&& check0(b, xi+120, yi)/*(b[i][j+4]==0)*/)
					{
						xi += 30;
					}
			}
			if (rot % 4 == 2)
			{
				if ((xi < 270) && (yi < 720)&& check0(b, xi+30, yi ) /*(b[i][j + 1] == 0)*/ && check0(b, xi+30, yi - 30) /*(b[i - 1][j + 1] == 0)*/ && check0(b, xi+30, yi - 60)/* (b[i - 2][j + 1] == 0)*/ && check0(b, xi+30, yi - 90) /*(b[i - 3][j + 1] == 0)*/)
				{
					xi += 30;
				}
			}
			if (rot % 4 == 3)
			{
				if ((xi < 270) && (yi < 720)&& check0(b, xi+30, yi )/*(b[i][j+1]==0)*/)
				{
					xi += 30;
				}
			}
	}
	void moveleft(int** b)
	{
			if (rot%4==0)
			{
				if ((xi > 0) && (yi < 630) && check0(b, xi-30, yi ) /*(b[i][j - 1] == 0)*/ && check0(b, xi-30, yi + 30)/*(b[i + 1][j - 1] == 0)*/ && check0(b, xi-30, yi + 60)/*(b[i + 2][j - 1] == 0)*/ && check0(b, xi-30, yi + 90) /*(b[i + 3][j - 1] == 0)*/)
				{
					xi -= 30;
				}
			}
			if (rot % 4 == 1)
			{
				if ((xi > 0) && (yi < 720)&& check0(b, xi-30, yi)/*(b[i][j-1]==0)*/)
				{
					xi -= 30;
				}
			}
			if (rot % 4 == 2)
			{
				if ((xi > 0) && (yi < 720) && check0(b, xi-30, yi) /*(b[i][j - 1] == 0)*/ && check0(b, xi-30, yi -30)/*(b[i - 1][j - 1] == 0)*/ && check0(b, xi-30, yi - 60) /*(b[i - 2][j - 1] == 0)*/ && check0(b, xi-30, yi - 90)/*(b[i - 3][j - 1] == 0)*/)
				{
					xi -= 30;
				}
			}
			if (rot % 4 == 3)
			{
				if ((xi > 90) && (yi < 720)&& check0(b, xi-120, yi )/*b[i][j-4]==0*/)
				{
					xi -= 30;
				}
			}
	}
	int rotate(int** b)
	{ 
		if (rot%4==0)
		{
				if ((xi < 210) && check0(b, xi + 30, yi) /*(b[i][j + 1] == 0)*/ && check0(b, xi + 60, yi) /*(b[i][j + 2] == 0)*/ && check0(b, xi + 90, yi) /*(b[i][j + 3] == 0)*/)
				{
					rot++;
					return 1;
				}
		}
		if (rot%4==1)
		{
				if (yi>=90&&check0(b, xi , yi-30)/*(b[i-1][j] == 0)*/ && check0(b, xi , yi-60) /*(b[i - 2][j ] == 0)*/ && check0(b, xi , yi-90)/*(b[i - 3][j] == 0)*/ )
				{
					rot++;
					return 1;
				}
		}
		if (rot%4==2)
		{
				if ((xi >= 90) && check0(b, xi - 30, yi)/*b[i][j -1] == 0*/&& check0(b, xi - 60, yi)/*b[i][j-2]==0*/&& check0(b, xi - 90, yi)/*b[i][j-3]==0*/)
				{
					rot++;
					return 1;
				}
		}
		if (rot%4==3)
		{
				if ((yi <= 630) && check0(b, xi , yi+30) /*(b[i + 1][j] == 0)*/ && check0(b, xi , yi+60) /*(b[i + 2][j] == 0)*/ && check0(b, xi , yi+90)/*(b[i + 3][j] == 0)*/)
				{
					rot++;
					return 1;
				}
		}
	}
	int getx()
	{
		return xi;
	}
	int gety()
	{
		return yi;
	}
	int cond(int** b)
	{
		if (yi >= 150)
		{
			if (rot % 4 == 0)
			{
				if ((yi == 630) || check1(b, xi, yi + 120)/*(b[i + 4][j] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xi + 30, yi + 30)/*(b[i + 1][j + 1] >= 1)*/ || check1(b, xi + 60, yi + 30)/*(b[i + 1][j + 2] >= 1)*/ || check1(b, xi + 90, yi + 30) /*(b[i + 1][j + 3] >= 1)*/)
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xi - 30, yi + 30)/* (b[i + 1][j - 1] >= 1)*/ || check1(b, xi - 60, yi + 30)/*(b[i + 1][j - 2] >= 1)*/ || check1(b, xi - 90, yi + 30) /*(b[i + 1][j - 3] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (yi < 150)
		{
			if (rot % 4 == 0)
			{
				if ((yi == 630) || check1(b, xi, yi + 120)/*(b[i + 4][j] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xi + 30, yi + 30)/*(b[i + 1][j + 1] >= 1)*/ || check1(b, xi + 60, yi + 30)/*(b[i + 1][j + 2] >= 1)*/ || check1(b, xi + 90, yi + 30) /*(b[i + 1][j + 3] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yi == 720) || check1(b, xi, yi + 30) /*(b[i + 1][j] >= 1)*/ || check1(b, xi - 30, yi + 30)/* (b[i + 1][j - 1] >= 1)*/ || check1(b, xi - 60, yi + 30)/*(b[i + 1][j - 2] >= 1)*/ || check1(b, xi - 90, yi + 30) /*(b[i + 1][j - 3] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};