#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"o.h"
#include"tetrominos.h"
using namespace std;
using namespace sf;
class well
{
private:
	int** board;
	RectangleShape rec;
	int hcf(int num)
	{
		return (num / 30);
	}
	friend class o;
public:
	well()
	{
		board = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			board[i] = new int[10];
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[i][j] = 0;
			}
		}
	    rec.setSize( Vector2f(30.f, 30.f) );
		rec.setOutlineColor(Color::Black);
		rec.setOutlineThickness(3);
	}
	~well()
	{
		for (int i = 0; i < 20; i++)
		{
			delete[]board[i];
		}
		delete[]board;
	}
	void draw(RenderWindow& window)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == 0)
				{
					rec.setPosition(j * 30, (i * 30)+150);
					rec.setFillColor(Color::White);
					window.draw(rec);
				}
				if (board[i][j]==1)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color::Yellow);
					window.draw(rec);
				}
				if (board[i][j] == 2)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color::Cyan);
					window.draw(rec);
				}
				if (board[i][j] == 3)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color(255, 165, 0));
					window.draw(rec);
				}
				if (board[i][j] == 4)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color::Blue);
					window.draw(rec);
				}
				if (board[i][j] == 5)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color(160, 32, 240));
					window.draw(rec);
				}
				if (board[i][j] == 6)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color::Green);
					window.draw(rec);
				}
				if (board[i][j] == 7)
				{
					rec.setPosition(j * 30, (i * 30) + 150);
					rec.setFillColor(Color::Red);
					window.draw(rec);
				}
			}
		}
	}
	void updtaeboard(int x,int y,int select,int rot)
	{
		y -= 150 ;
		int i;
		int j;
		j = hcf(x);
		i = hcf(y);

		if (select==1)
		{
			if (rot==1)
			{
				board[i][j] = 1;
				board[i][j + 1] = 1;
				board[i + 1][j] = 1;
				board[i + 1][j + 1] = 1;
			}
		}
		if (select==2)
		{
			if (rot==1)
			{
				board[i][j] = 2;
				board[i + 1][j] = 2;
				board[i + 2][j] = 2;
				board[i + 3][j] = 2;
			}
			if (rot==2)
			{
				board[i][j] = 2;
				board[i ][j+1] = 2;
				board[i ][j+2] = 2;
				board[i ][j+3] = 2;
			}
			if (rot==3)
			{
				board[i][j] = 2;
				board[i - 1][j] = 2;
				board[i - 2][j] = 2;
				board[i - 3][j] = 2;
			}
			if (rot==4)
			{
				board[i][j] = 2;
				board[i][j - 1] = 2;
				board[i][j - 2] = 2;
				board[i][j - 3] = 2;
			}
		}
		if (select == 3)
		{
			if (rot == 1)
			{
				board[i][j] = 3;
				board[i + 1][j] = 3;
				board[i + 2][j] = 3;
				board[i + 2][j+1] = 3;
			}
			if (rot == 2)
			{
				board[i][j] = 3;
				board[i][j + 1] = 3;
				board[i][j + 2] = 3;
				board[i+1][j ] = 3;
			}
			if (rot == 3)
			{
				board[i][j] = 3;
				board[i ][j+1] = 3;
				board[i + 1][j+1] = 3;
				board[i +2][j+1] = 3;
			}
			if (rot == 4)
			{
				board[i][j+2] = 3;
				board[i+1][j] = 3;
				board[i+1][j + 1] = 3;
				board[i+1][j + 2] = 3;
			}
		}
		if (select == 4)
		{
			if (rot == 1)
			{
				board[i][j+1] = 4;
				board[i + 1][j+1] = 4;
				board[i + 2][j+1] = 4;
				board[i + 2][j] = 4;
			}
			if (rot == 2)
			{
				board[i][j] = 4;
				board[i + 1][j] = 4;
				board[i + 1][j + 1] = 4;
				board[i + 1][j + 2] = 4;
			}
			if (rot == 3)
			{
				board[i][j] = 4;
				board[i][j + 1] = 4;
				board[i + 1][j] = 4;
				board[i + 2][j] = 4;
			}
			if (rot == 4)
			{
				board[i][j] = 4;
				board[i][j + 1] = 4;
				board[i][j + 2] = 4;
				board[i + 1][j + 2] = 4;
			}
		}
		if (select == 5)
		{
			if (rot == 1)
			{
				board[i][j] = 5;
				board[i][j + 1] = 5;
				board[i][j + 2] = 5;
				board[i + 1][j+1] = 5;
			}
			if (rot == 2)
			{
				board[i][j+1] = 5;
				board[i+1][j+1] = 5;
				board[i+2][j + 1] = 5;
				board[i + 1][j ] = 5;
			}
			if (rot == 3)
			{
				board[i][j+1] = 5;
				board[i+1][j] = 5;
				board[i + 1][j+1] = 5;
				board[i + 1][j+2] = 5;
			}
			if (rot == 4)
			{
				board[i][j] = 5;
				board[i+1][j] = 5;
				board[i+2][j] = 5;
				board[i + 1][j + 1] = 5;
			}
		}
		if (select == 6)
		{
			if (rot == 1)
			{
				board[i+1][j] = 6;
				board[i][j + 1] = 6;
				board[i][j + 2] = 6;
				board[i + 1][j + 1] = 6;
			}
			if (rot == 2)
			{
				board[i][j] = 6;
				board[i + 1][j + 1] = 6;
				board[i + 2][j + 1] = 6;
				board[i + 1][j] = 6;
			}
			if (rot == 3)
			{
				board[i + 1][j] = 6;
				board[i][j + 1] = 6;
				board[i][j + 2] = 6;
				board[i + 1][j + 1] = 6;
			}
			if (rot == 4)
			{
				board[i][j] = 6;
				board[i + 1][j + 1] = 6;
				board[i + 2][j + 1] = 6;
				board[i + 1][j] = 6;
			}
		}
		if (select == 7)
		{
			if (rot == 1)
			{
				board[i ][j] = 7;
				board[i][j + 1] = 7;
				board[i+1][j + 2] = 7;
				board[i + 1][j + 1] = 7;
			}
			if (rot == 2)
			{
				board[i][j+1] = 7;
				board[i + 1][j] = 7;
				board[i + 1][j + 1] = 7;
				board[i + 2][j] = 7;
			}
			if (rot == 3)
			{
				board[i][j] = 7;
				board[i][j + 1] = 7;
				board[i + 1][j + 2] = 7;
				board[i + 1][j + 1] = 7;
			}
			if (rot == 4)
			{
				board[i][j + 1] = 7;
				board[i + 1][j] = 7;
				board[i + 1][j + 1] = 7;
				board[i + 2][j] = 7;
			}
		}
	}
	int linepop()
	{
		int flag = 1;
		int count = 0;
		for (int i = 19; i >=0; i--)
		{
			for (int j = 0; j < 10&&flag==1; j++)
			{
				if (board[i][j]==0)
				{
					flag = 0;
				}
			}
			if (flag==1)
			{
				count++;
				for (int k =i; k >0; k--)
				{
					for (int l= 0; l < 10; l++)
					{
						board[k][l] = board[k - 1][l];
						board[0][l] = 0;
					}
				}
			}
			flag = 1;
		}
		return count;
	}
	int** bord()
	{
		return board;
	}
};