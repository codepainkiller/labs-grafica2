#ifndef LAB14_H
#define LAB14_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab14 : public Scene
{
    public:
        Lab14();
        ~Lab14();

        void drawScene();
        void inputVariables();
        void drawEjes(int dimension);
        void drawSnowMan();

    protected:
    private:
};

#endif // LAB14_H
