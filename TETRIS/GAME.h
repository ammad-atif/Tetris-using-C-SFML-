#pragma once
#include<iostream>  
#include<fstream>
#include <SFML/Graphics.hpp>
#include<time.h>
#include"well.h"
#include"tetrominos.h"
#include"I.h"
#include"O.h"
#include"L.h"
#include"J.h"
#include"T.h"
#include"S.h"
#include"Z.h"
using namespace std;
using namespace sf;
class game
{
private:
    int set(tetrominos** obj)
    {
        srand(time(0));
        int num = (rand() % 7) + 1;
        if (num == 1)
        {
            *obj = new o;
        }
        if (num == 2)
        {
            *obj = new i;
        }
        if (num == 3)
        {
            *obj = new l;
        }
        if (num == 4)
        {
            *obj = new j;
        }
        if (num == 5)
        {
            *obj = new t;
        }
        if (num == 6)
        {
            *obj = new s;
        }
        if (num == 7)
        {
            *obj = new z;
        }
        return num;
    }
    Font font;
    Text nameText; 
    Text outputText;
    Text lines, levels, names, scores;
    string name;
    RectangleShape rectangle1; 
    Vector2<float> lines_scale;
    well a;
    tetrominos* obj;
    int num;
    int cTime = 1000;  
    int sDelayTime = 100; 
    int delayTime = cTime;
    Clock clock;
    int score = 0;
    int line = 0;
    int lline = 0;
    int level = 1;
public:
    game()
    {
        font.loadFromFile("arial.ttf");

        nameText.setString("Please enter your name: ");
        nameText.setFont(font);
        nameText.setCharacterSize(20);
        nameText.setPosition(10, 10);

        outputText.setString("");
        outputText.setFont(font);
        outputText.setCharacterSize(20);
        outputText.setPosition(10, 90);

        lines.setFont(font); levels.setFont(font); names.setFont(font); scores.setFont(font);
        lines.setCharacterSize(10); levels.setCharacterSize(10); names.setCharacterSize(10); scores.setCharacterSize(10);
        lines.setStyle(Text::Bold); levels.setStyle(Text::Bold); names.setStyle(Text::Bold); scores.setStyle(Text::Bold);
        lines.setFillColor(Color::Black); levels.setFillColor(Color::Black); names.setFillColor(Color::Black); scores.setFillColor(Color::Black);
        lines.setPosition(400, 110); levels.setPosition(400, 220); names.setPosition(400, 330); scores.setPosition(400, 440);
    
        rectangle1.setSize(Vector2f(450, 450));
        rectangle1.setOutlineThickness(10); 
        rectangle1.setOutlineColor(Color(0, 0, 0));
        rectangle1.setPosition(350, 100);

        lines_scale.x = 4.f;
        lines_scale.y = 4.f;
        lines.setScale(lines_scale); levels.setScale(lines_scale); names.setScale(lines_scale); scores.setScale(lines_scale);

        num = set(&obj);
        cTime = 1000;  
        sDelayTime = 100; 
        delayTime = cTime;
        score = 0;
        line = 0;
        lline = 0;
        level = 1;
    }
    void getnamefromuser()
    {
        RenderWindow Window(VideoMode(800, 750), "TETRIS");
        while (Window.isOpen())
        {
            Event event;
            while (Window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    Window.close();
                }
                if (event.type == Event::TextEntered)
                {
                    if (event.text.unicode == 13) // Enter key pressed
                    {
                        if (name.empty())
                        {
                            outputText.setString("Please enter a valid name.");
                        }
                        else
                        {
                            Window.close();
                        }
                    }
                    else if (event.text.unicode >= 'a' && event.text.unicode <= 'z')
                    {
                        name += static_cast<char>(event.text.unicode);
                    }
                    else if (event.text.unicode >= 'A' && event.text.unicode <= 'Z')
                    {
                        name += static_cast<char>(event.text.unicode);
                    }
                }
            }
            Window.clear();
            Window.draw(nameText);
            Window.draw(outputText);
            Window.display();
        }
    }
    void play()
    {
        RenderWindow window(VideoMode(800, 750), "TETRIS");
        while (window.isOpen())
        {
            if (line > 80)
            {
                lline = 0;
            }
            if (lline < 10)
            {
                level = 1;
                cTime = 1000;
            }
            if (lline > 10)
            {
                level = 2;
                cTime = 900;
            }
            if (lline > 20)
            {
                level = 3;
                cTime = 800;
            }
            if (lline > 30)
            {
                level = 4;
                cTime = 700;
            }
            if (lline > 40)
            {
                level = 5;
                cTime = 600;
            }
            if (lline > 50)
            {
                level = 6;
                cTime = 500;
            }
            if (lline > 60)
            {
                level = 7;
                cTime = 400;
            }
            if (lline > 70)
            {
                level = 8;
                cTime = 300;
            }
            Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case (Event::Closed):
                    window.close();
                    break;
                case(Event::MouseButtonPressed):
                    cout << "X: " << Mouse::getPosition(window).x << " Y: " << Mouse::getPosition(window).y << endl;
                    break;
                case(Event::KeyPressed):
                    if (event.key.code == Keyboard::Down)
                    {
                        delayTime = sDelayTime; // change the delay time to move the tetromino faster
                    }
                    if (event.key.code == Keyboard::Right)
                    {
                        obj->moveright(a.bord());
                    }
                    if (event.key.code == Keyboard::Left)
                    {
                        obj->moveleft(a.bord());
                    }
                    if (event.key.code == Keyboard::Up)
                    {
                        obj->rotate(a.bord());
                    }
                    break;
                }
            }
            lines.setString("LINES: " + to_string(line)); levels.setString("LEVEL: " + to_string(level)); names.setString("NAME: " + name); scores.setString("SCORE: " + to_string(score));
            window.clear();
            a.draw(window);
            if (clock.getElapsedTime().asMilliseconds() >= delayTime)
            {
                obj->movedown(a.bord());
                clock.restart(); // reset the clock
                delayTime = cTime;
            }
            obj->drawtetromino(window);
            window.draw(rectangle1);
            window.draw(lines); window.draw(levels); window.draw(names); window.draw(scores);
            window.display();
            if (obj->cond(a.bord()) != 0 && obj->cond(a.bord()) != 5)
            {
                a.updtaeboard(obj->getx(), obj->gety(), num, obj->cond(a.bord()));
                line += a.linepop();
                lline += a.linepop();
                score = line * 100;
                delete obj;
                num = set(&obj);
            }
            else if (obj->cond(a.bord()) == 5)
            {
                window.close();
                cout << "GAME OVER" << endl;
            }
        }
    }
    void filehandle()
    {
        int count = 0;
        string checkname[5];
        int checkscore[5];
        ifstream ab;
        ab.open("SCORE.txt");
        while (!ab.eof())
        {
            ab >> checkname[count];
            ab >> checkscore[count];
            ++count;
        }
        ab.close();
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (checkscore[k] > checkscore[j])
                {
                    swap(checkname[k], checkname[j]);
                    swap(checkscore[k], checkscore[j]);
                }
            }
        }
        if (score > checkscore[0])
        {
            checkscore[0] = score;
            checkname[0] = name;
        }
        ofstream ba;
        ba.open("SCORE.txt");
        for (int j = 0; j < 5; j++)
        {
            ba << checkname[j] << " " << checkscore[j] << endl;
        }
        ba.close();
    }
    ~game()
    {
        delete obj;
    }
};
