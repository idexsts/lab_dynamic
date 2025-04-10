#pragma once
#include <iostream>
using namespace std;
#include "empty_cell.h"
#include"hero_cell.h"
#include"coin.h"
#include"wall.h"
#include"door.h"
#include<iostream>


enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Maze {
	int h;
	int w;
	Hero v;
	void heroPosition(int i, int j);
	Tile* ** lab;
	
public:
	void update() {
		system("cls");
	}
	
	
	Maze();
	Maze(const Maze& m);
	~Maze();
	void move(Direction d);
	friend ostream& operator << (ostream& out, Maze& m);
	Maze& operator=(const Maze& m);
	Hero getHero() const { return h; }
};