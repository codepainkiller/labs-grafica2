#ifndef LAB1_H
#define LAB1_H

#include "Scene.h"
#include <iostream>

using namespace std;

class Lab1 : public Scene
{
    public:
        Lab1();
        ~Lab1();

        void inputVariables();

        void drawScene();
        void drawSnowMan();

    protected:
    private:

};

#endif // LAB1_H
