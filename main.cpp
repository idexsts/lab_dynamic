#include <iostream>
using namespace std;
#include "maze.h"
#include "joystick.h"

int main() {
	Maze m;
	
	Joystick control(m);
	cout << m;
	control.start();
	return 0;
}