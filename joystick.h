#pragma once
#include "maze.h"
#include<iostream>

#include <conio.h>

using namespace std;

class Joystick {
	Maze& m;
public:
	Joystick(Maze& _m) : m(_m) {}
	void start() {
		unsigned char val = 0;
		while (val != 'q')
		{

			val = _getch();
			
			switch (val)
			{
			case 's':
				m.move(DOWN);
				break;
			case 'w':
				m.move(UP);
				break;
			case 'a':
				m.move(LEFT);
				break;
			case 'd':
				m.move(RIGHT);
				break;
			}
		}

	}
};