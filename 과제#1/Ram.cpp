#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

void Ram::write(int address, char value) {
	if (address >= 0 && address < size) {
		mem[address] = value;
	}
	else {

	}
}

char Ram::read(int address) {
	if (address >= 0 && address < size) {
		return mem[address];
	}
	else {
		return 0;
	}
}