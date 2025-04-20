#pragma once
#include "maze.h"
#include<iostream>

#include <conio.h>

using namespace std;

class Joystick {
	Maze* m;
public:
	Joystick(Maze* _m) : m(_m) {}
	void go() {
		unsigned char val = 0;
		while (val != 'q')
		{

			val = _getch();
			
			switch (val)
			{
			case 80:
				m->move(DOWN);
				break;
			case 72:
				m->move(UP);
				break;
			case 75:
				m->move(LEFT);
				break;
			case 77:
				m->move(RIGHT);
				break;
			}
		}

	}
};