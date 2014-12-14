#include "Lab1.h"

Lab1::Lab1()
{
    cout << "Constructor Lab1" << endl;
}

Lab1::~Lab1()
{
}

void Lab1::inputVariables()
{

}

void Lab1::drawScene()
{
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, -20.0f);
        glVertex3f(10.0f, 10.0f, -20.0f);
    glEnd();
}
