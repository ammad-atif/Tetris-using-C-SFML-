#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"well.h"
using namespace std;
using namespace sf;
class z :public tetrominos
{
private:
	int xz;
	int yz;
	int rot;
	RectangleShape rec_z;
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
	z()
	{
		xz = 0;
		yz = 0;
		rot = 0;
		rec_z.setSize(Vector2f(30, 30));
		rec_z.setFillColor(Color::Red);
		rec_z.setOutlineColor(Color::Black);
		rec_z.setOutlineThickness(3);
	}
	void drawtetromino(RenderWindow& window)
	{
		if (rot % 4 == 0)
		{
			rec_z.setPosition(xz, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz + 30, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz+30 , yz+30);
			window.draw(rec_z);
			rec_z.setPosition(xz + 60, yz + 30);
			window.draw(rec_z);
		}
		if (rot % 4 == 1)
		{
			rec_z.setPosition(xz+30, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz + 30, yz + 30);
			window.draw(rec_z);
			rec_z.setPosition(xz , yz + 60);
			window.draw(rec_z);
			rec_z.setPosition(xz, yz + 30);
			window.draw(rec_z);
		}
		if (rot % 4 == 2)
		{
			rec_z.setPosition(xz, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz + 30, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz + 30, yz + 30);
			window.draw(rec_z);
			rec_z.setPosition(xz + 60, yz + 30);
			window.draw(rec_z);
		}
		if (rot % 4 == 3)
		{
			rec_z.setPosition(xz + 30, yz);
			window.draw(rec_z);
			rec_z.setPosition(xz + 30, yz + 30);
			window.draw(rec_z);
			rec_z.setPosition(xz, yz + 60);
			window.draw(rec_z);
			rec_z.setPosition(xz, yz + 30);
			window.draw(rec_z);
		}
	}
	void movedown(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((yz < 690) && check0(b, xz+60, yz + 60)/*b[i + 2][j+2] == 0*/ && check0(b, xz + 30, yz + 60) /*b[i + 2][j + 1] == 0*/ && check0(b, xz , yz + 30) /*(b[i + 1][j] == 0*/)
			{
				yz += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((yz < 660) && check0(b, xz, yz + 90)/*(b[i+3][j]==0)*/ && check0(b, xz + 30, yz + 60)/*(b[i+2][j+1]==0)*/)
			{
				yz += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((yz < 690) && check0(b, xz + 60, yz + 60)/*b[i + 2][j+2] == 0*/ && check0(b, xz + 30, yz + 60) /*b[i + 2][j + 1] == 0*/ && check0(b, xz, yz + 30) /*(b[i + 1][j] == 0*/)
			{
				yz += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((yz < 660) && check0(b, xz, yz + 90)/*(b[i+3][j]==0)*/ && check0(b, xz + 30, yz + 60)/*(b[i+2][j+1]==0)*/)
			{
				yz += 30;
			}
		}
	}
	void moveright(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xz < 210) && (yz < 690) && check0(b, xz + 60, yz)/*(b[i][j+2]==0)*/ && check0(b, xz + 90, yz + 30)/*(b[i+1][j+3]==0)*/)
			{
				xz += 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xz < 240) && (yz < 660) && check0(b, xz + 60, yz) /*(b[i][j + 2] == 0)*/ && check0(b, xz + 60, yz + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xz + 30, yz + 60)/* (b[i +2][j + 1] == 0)*/)
			{
				xz += 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xz < 210) && (yz < 690) && check0(b, xz + 60, yz)/*(b[i][j+2]==0)*/ && check0(b, xz + 90, yz + 30)/*(b[i+1][j+3]==0)*/)
			{
				xz += 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xz < 240) && (yz < 660) && check0(b, xz + 60, yz) /*(b[i][j + 2] == 0)*/ && check0(b, xz + 60, yz + 30) /*(b[i +1 ][j + 2] == 0)*/ && check0(b, xz + 30, yz + 60)/* (b[i +2][j + 1] == 0)*/)
			{
				xz += 30;
			}
		}
	}
	void moveleft(int** b)
	{
		if (rot % 4 == 0)
		{
			if ((xz > 0) && (yz < 690) && check0(b, xz-30, yz)/*(b[i][j-1]==0)*/ && check0(b, xz , yz + 30)/*(b[i+1][j]==0)*/)
			{
				xz -= 30;
			}
		}
		if (rot % 4 == 1)
		{
			if ((xz > 0) && (yz < 660) && check0(b, xz , yz) /*(b[i][j] == 0)*/ && check0(b, xz - 30, yz + 30)/*(b[i +1][j-1 ] == 0)*/ && check0(b, xz-30, yz + 60) /*(b[i + 2][j-1] == 0)*/)
			{
				xz -= 30;
			}
		}
		if (rot % 4 == 2)
		{
			if ((xz > 0) && (yz < 690) && check0(b, xz - 30, yz)/*(b[i][j-1]==0)*/ && check0(b, xz, yz + 30)/*(b[i+1][j]==0)*/)
			{
				xz -= 30;
			}
		}
		if (rot % 4 == 3)
		{
			if ((xz > 0) && (yz < 660) && check0(b, xz, yz) /*(b[i][j] == 0)*/ && check0(b, xz - 30, yz + 30)/*(b[i +1][j-1 ] == 0)*/ && check0(b, xz - 30, yz + 60) /*(b[i + 2][j-1] == 0)*/)
			{
				xz -= 30;
			}
		}
	}
	int rotate(int** b)
	{
		if (rot % 4 == 0)
		{
			if (yz <= 660  && check0(b, xz , yz + 60) /*(b[i+2][j] == 0)*/ && check0(b, xz, yz + 30) /*(b[i+1][j] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 1)
		{
			if (xz <= 210 && check0(b, xz , yz)/*(b[i][j] == 0)*/ && check0(b, xz + 60, yz)/*(b[i+1][j+2] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 2)
		{
			if (yz <= 660 && check0(b, xz, yz + 60) /*(b[i+2][j] == 0)*/ && check0(b, xz, yz + 30) /*(b[i+1][j] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
		if (rot % 4 == 3)
		{
			if (xz <= 210 && check0(b, xz, yz)/*(b[i][j] == 0)*/ && check0(b, xz + 60, yz)/*(b[i+1][j+2] == 0)*/)
			{
				rot++;
				return 1;
			}
		}
	}
	int getx()
	{
		return xz;
	}
	int gety()
	{
		return yz;
	}
	int cond(int** b)
	{
		if (yz >= 150)
		{
			if (rot % 4 == 0)
			{
				if (yz == 690 || check1(b, xz+30, yz + 60)/*(b[i + 2][j+1] >= 1)*/ || check1(b, xz + 60, yz + 60) /*(b[i + 2][j + 2] >= 1)*/ || check1(b, xz , yz + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 1;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yz == 660) || check1(b, xz, yz + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xz + 30, yz + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 2;
				}
			}
			if (rot % 4 == 2)
			{
				if (yz == 690 || check1(b, xz + 30, yz + 60)/*(b[i + 2][j+1] >= 1)*/ || check1(b, xz + 60, yz + 60) /*(b[i + 2][j + 2] >= 1)*/ || check1(b, xz, yz + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 3;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yz == 660) || check1(b, xz, yz + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xz + 30, yz + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 4;
				}
			}
		}
		if (yz<150)
		{
			if (rot % 4 == 0)
			{
				if (yz == 690 || check1(b, xz + 30, yz + 60)/*(b[i + 2][j+1] >= 1)*/ || check1(b, xz + 60, yz + 60) /*(b[i + 2][j + 2] >= 1)*/ || check1(b, xz, yz + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 1)
			{
				if ((yz == 660) || check1(b, xz, yz + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xz + 30, yz + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 2)
			{
				if (yz == 690 || check1(b, xz + 30, yz + 60)/*(b[i + 2][j+1] >= 1)*/ || check1(b, xz + 60, yz + 60) /*(b[i + 2][j + 2] >= 1)*/ || check1(b, xz, yz + 30) /*(b[i + 1][j] >= 1)*/)
				{
					return 5;
				}
			}
			if (rot % 4 == 3)
			{
				if ((yz == 660) || check1(b, xz, yz + 90) /*(b[i + 3][j] >= 1)*/ || check1(b, xz + 30, yz + 60) /*(b[i +2][j+1] >= 1)*/)
				{
					return 5;
				}
			}
		}
		return 0;
	}
};
