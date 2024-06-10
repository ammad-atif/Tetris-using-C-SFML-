#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class tetrominos
{   private:
	int num;
    public:
		virtual void drawtetromino(RenderWindow & window) = 0;
		virtual void movedown(int **b) = 0;
		virtual void moveright(int** b) = 0;
		virtual void moveleft(int** b) = 0;
		virtual int rotate(int** b) = 0;
		virtual int getx() = 0;
		virtual int gety() = 0;
		virtual int cond(int** b) = 0;
};