#ifndef LAB10_H
#define LAB10_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab10 : public Scene
{
    public:
        Lab10();
        ~Lab10();

        void inputVariables();
        void drawScene();
        void drawEjes(int dimension);

        void drawEsfera();
        void drawRayo();

    protected:
    private:
};

#endif // LAB10_H
