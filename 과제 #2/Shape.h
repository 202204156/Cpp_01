#ifndef SHAPE_H
#define SHAPE_H

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p);
	void paint();
	Shape* getNext() { return next; }
};

#endif