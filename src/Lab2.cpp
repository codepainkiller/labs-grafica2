#include "Lab2.h"

Lab2::Lab2()
{
    //ctor
}

Lab2::~Lab2()
{
    //dtor
}

void Lab2::inputVariables()
{

}

void Lab2::drawScene()
{
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, -20.0f);
        glVertex3f(10.0f, 10.0f, -20.0f);
    glEnd();
}
