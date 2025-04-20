#pragma once
#include <iostream>
using namespace std;
#include "empty_cell.h"
#include"hero_cell.h"
#include"coin.h"
#include"wall.h"
#include"door.h"
#include<iostream>
class View;
#include <vector>


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
	Tile*** lab;
	vector <View*> allObservers;
	
public:
	void update();
	void addObserver(View* o);
	int getH() { return h; }
	int getW() { return w; }
	char getTile(int i, int j) {
		return lab[i][j]->getSymbol();
	}
	void printView(ostream&out);
	
	Maze();
	Maze(const Maze& m);
	~Maze();
	void move(Direction d);
	friend ostream& operator << (ostream& out, Maze& m);
	Maze& operator=(const Maze& m);
	Hero getHero() const { return v; }
};