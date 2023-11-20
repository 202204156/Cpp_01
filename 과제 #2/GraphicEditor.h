#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "Shape.h"

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = pLast= NULL; }
	void insertItem(int num);
	void deleteItem(int num);
	void show();
	void run();
};

#endif