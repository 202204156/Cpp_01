#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include "Shape.h"
#include <vector>

class GraphicEditor {
private:
    std::vector<Shape*> v;

public:
    GraphicEditor();
    ~GraphicEditor();
    void insertItem(int num);
    void deleteItem(int num);
    void show();
    void run();
};

#endif // GRAPHICEDITOR_H
