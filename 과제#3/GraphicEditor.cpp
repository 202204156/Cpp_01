#include <iostream>
#include "GraphicEditor.h"
#include "UI.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GraphicEditor::GraphicEditor() {}

GraphicEditor::~GraphicEditor() {
    for (const auto& shape : v) {
        delete shape;
    }
    v.clear();
}

void GraphicEditor::insertItem(int num) {
    Shape* p = nullptr;
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

    if (p != nullptr) {
        v.push_back(p);
    }
}

void GraphicEditor::deleteItem(int num) {
    if (num >= 0 && num < v.size()) {
        delete v[num];
        v.erase(v.begin() + num);
    }
    else {
        std::cout << "잘못된 인덱스입니다." << std::endl;
    }
}

void GraphicEditor::show() {
    int i = 0;
    for (const auto& shape : v) {
        std::cout << i++ << ": ";
        shape->paint();
    }
}

void GraphicEditor::run() {
    std::cout << "그래픽 에디터입니다." << std::endl;
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
