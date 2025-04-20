#pragma once
#include <iostream>
using namespace std;
#include <chrono>
#include <thread>

class Error {
public:
	
	virtual void showErr() = 0;
};

class WallError:public Error {
public:
	void showErr() {
		cout << "wall!";
		this_thread::sleep_for(chrono::milliseconds(300));
	}
};

class HpError : public Error{
public:
	void showErr() {
		cout << "you died.";
		this_thread::sleep_for(chrono::milliseconds(300));
		exit(0);
	}
};

class CoinsError : public Error {
public:
	void showErr() {
		cout << "need more coins to get out!";
		this_thread::sleep_for(chrono::milliseconds(300));
	}
};

class Win :public Error {
	void showErr() {
		system("cls");
		cout << "congrats,you won!";
		//this_thread::sleep_for(chrono::milliseconds(300));
		
		exit(0);
	}
};