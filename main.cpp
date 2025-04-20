#include <iostream>
using namespace std;
#include "maze.h"
#include "joystick.h"
#include "view.h"

int main() {
	Maze m;
	//ViewLab* labirint = new ViewLab(cout);
	WhatHeroSees* v = new WhatHeroSees(cout);
	ViewCharacteristics* ch = new ViewCharacteristics(cout);

	Joystick control(&m);
	//m.addObserver(labirint);
	m.addObserver(v);
	m.addObserver(ch);
	control.go();
	return 0;
}