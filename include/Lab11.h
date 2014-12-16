#ifndef LAB11_H
#define LAB11_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab11 : public Scene
{
    public:
        Lab11();
        ~Lab11();

        void inputVariables();
        void drawScene();
        void drawEjes(int dimension);
        void drawPuntoInterseccion();

    protected:
    private:
};

#endif // LAB11_H
