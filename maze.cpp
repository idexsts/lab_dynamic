#include "maze.h"
#include <conio.h>
#include <fstream>
#include "view.h"
#include "exepts.h"
//#include <chrono>
//#include <thread>




void Maze::heroPosition(int i, int j) {
	if (((i < 0) || (j < 0) || (i >= h) || (j >= w))) {
		return;
	}
	else {
		try {
			Tile* new_cell = *lab[i][j] + v;
			if (new_cell != lab[i][j]) {
				delete lab[i][j];
				lab[i][j] = new_cell;
			}
			Tile* old_cell = *lab[v.getX()][v.getY()] - v;
			if (old_cell != lab[v.getX()][v.getY()]) {
				delete lab[v.getX()][v.getY()];
				lab[v.getX()][v.getY()] = old_cell;
			}
			v.move(i, j);
		}
		catch (Error* err) {
			update();
			err->showErr();
			delete err;
		}
	}
	update();
	
}

Maze& Maze::operator=(const Maze& m) {
	if (this == &m) return  *this;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			delete lab[i][j];
		}
		delete lab[i];
	}
	delete[] lab;
	h = m.h;
	w = m.w;

	lab = new  Tile * *[h];
	for (int i = 0; i < h; i++) {
		lab[i] = new Tile * [w];
		for (int j = 0; j < w; j++) {

			lab[i][j] = m.lab[i][j]->copyElem();
		}
	}
	return *this;
}
Maze::Maze(const Maze& m) {
	h = m.h;
	w = m.w;
	lab = new Tile * *[h];
	for (int i = 0; i < h; i++) {
		lab[i] = new Tile * [w];
		for (int j = 0; j < w; j++) {
			lab[i][j] = m.lab[i][j]->copyElem();
		}
	}
}

Maze::Maze()
{
	ifstream file("lab.txt");
	if (!file.is_open()) {
		cout << "it doesn't open";
	}
	file >> h;
	file >> w;
	lab = new Tile * *[h];
	for (int i = 0; i < h; i++) {
		lab[i] = new Tile * [w];	
	}
	//update();
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			file >> c;
			if (c == '.') {
				lab[i][j] = new Cell();
			}
			if (c == '$') {
				lab[i][j] = new Coin();
			}
			if (c == 'X') {
				lab[i][j] = new Wall();
			}
			if (c == '#') {
				lab[i][j] = new Door();
			}
		}
	}
	lab[0][0] = new HeroCell();
}
Maze::~Maze() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			delete[] lab[i][j];
		}
		delete[] lab[i];
	}
	delete[] lab;
}
void Maze::move(Direction d)
{
	int ip = v.getX();
	int jp = v.getY();
	switch (d) {
	case UP:
		ip--;
		break;
	case DOWN:
		ip++;
		break;
	case LEFT:
		jp--;
		break;
	case RIGHT:
		jp++;
		break;
	}
	heroPosition(ip, jp);

}
ostream& operator << (ostream& out, Maze& m)
{
	//int ip = m.v.getX();
	//int jp = m.v.getY();
	for (int i=0; i <m.h; i++)
	{
		for (int j = 0; j <m.w; j++)
		{
			//if ((i < 0) || (j < 0) || (i >= m.h) || (j >= m.w))
			//{
			//	out << 'X';
			//}
			//else
			//{
				out << m.lab[i][j]<<" ";

			//}
		}
		out << endl;
	}
	return out;
}

void Maze::update() {
	system("cls");
	for (View* o : allObservers) {
		o->event(*this);
	}
}

void Maze::addObserver(View* o) {
	
		allObservers.push_back(o);
		update();
}

void Maze::printView(ostream&out) {
	int ip = v.getX();
	int jp = v.getY();
	for (int i = ip - 1; i <= ip + 1; i++)
	{
		for (int j = jp - 1; j <= jp + 1; j++)
		{
			if ((i < 0) || (j < 0) || (i >= h) || (j >= w))
			{
				out << "//";
			}
			else
			{
				out << getTile(i, j)<<" ";

			}
		}
		out << endl;
	}
}