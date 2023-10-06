#pragma once
#include <iostream>
#ifndef RAM_H
#define RAM_H
using namespace std;


class Ram {
	char mem[ 100 * 1024 ];
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
};

#endif