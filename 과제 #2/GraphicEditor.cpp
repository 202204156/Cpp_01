#include <iostream>
using namespace std;

#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "GraphicEditor.h"
#include "UI.h"

void GraphicEditor::insertItem(int num) {
	Shape* p = NULL;
	switch (num) {
	case 1:
		p = new Line();
		break;
	case 2:
		p = new Circle();
		break;
	case 3:
		p = new Rect();
		break;
	default:
		break;
	}
	if (pStart == NULL) {
		pStart = p;
		pLast = p;
		return;
	}
	pLast->add(p);
	pLast = pLast->getNext();
}
void GraphicEditor::deleteItem(int num) {
	Shape* pre = pStart;
	Shape* temp = pStart;

	if (pStart == NULL) {
		cout << "도형이 없습니다!" << endl;
		return;
	}
	for (int i = 0; i < num; i++) {
		pre = temp;
		temp = temp->getNext();
	}
	if (temp == pStart) {			
		pStart = temp->getNext();
		delete temp;
	}
	else {
		pre->add(temp->getNext());
		delete temp;
	}
}
void GraphicEditor::show() {
	Shape* tmp = pStart;
	int i = 0;
	while (tmp != NULL) {
		cout << i++ << ": ";
		tmp->paint();
		tmp = tmp->getNext();
	}
}
void GraphicEditor::run() {
	cout << "그래픽 에디터입니다." << endl;
	int menu, index, type;
	while (true) {
		menu = UI::getMenu();
		switch (menu) {
		case 1:
			type = UI::getShapeTypeToInsert();
			insertItem(type);
			break;
		case 2:
			index = UI::getShapeIndexToDelete();
			deleteItem(index);
			break;
		case 3:
			show();
			break;
		default:
			return;
		}
	}
}