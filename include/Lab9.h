#ifndef LAB9_H
#define LAB9_H

#include "Scene.h"
#include <cmath>
#include <iostream>

class Lab9 : public Scene
{
    public:
        Lab9();
        ~Lab9();

        void inputVariables();
        void drawScene();
        void drawEjes(int dimension);

    protected:
    private:
};

#endif // LAB9_H
