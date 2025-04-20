#pragma once
#include <iostream>
using namespace std;
#include "maze.h"


class View {
public:
	virtual void event(Maze&m) = 0;
};

class ViewLab :public View {
	ostream& out;
public:
	ViewLab(ostream& _out) : out(_out){}
	void event(Maze&m) {
		out << m <<endl;
		
	}
};

class ViewCharacteristics : public View {
	ostream& out;
public:
	ViewCharacteristics(ostream&_out):out(_out){}
	void event(Maze& m) {
		out << "COINS:" << m.getHero().stock() << endl;
		out << "LIVES: " << m.getHero().lives() << endl;
	}
};

class WhatHeroSees : public View {
	ostream& out;
public:
	WhatHeroSees(ostream& _out) :out(_out) {}
	void event(Maze& m) {
		out << endl;
		out << "Look where you are carefully :"<< endl;
		m.printView(out);
	}
};