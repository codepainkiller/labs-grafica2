#include "Lab3.h"

Lab3::Lab3()
{
    //ctor
}

Lab3::~Lab3()
{
    //dtor
}

void Lab3::inputVariables()
{

}

void Lab3::drawScene()
{
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, -20.0f);
        glVertex3f(10.0f, 10.0f, -20.0f);
    glEnd();
}
