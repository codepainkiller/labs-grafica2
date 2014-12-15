#ifndef LAB8_H
#define LAB8_H

#include "Scene.h"
#include <cmath>
#include <iostream>

class Lab8 : public Scene
{
    public:
        Lab8();
        ~Lab8();

        void inputVariables();
        void drawScene();

        void drawEjes(int dimension);

        void drawSnowMan();

    protected:
    private:
};

#endif // LAB8_H
