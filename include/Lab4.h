#ifndef LAB4_H
#define LAB4_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab4 : public Scene
{
    public:
        Lab4();
        ~Lab4();

        void inputVariables();
        void drawScene();

        void drawEjes(int dimension);
        void drawPoint3D(float x, float y, float z);

        void esfera();
        void cilindro();
        void cono();


    protected:
    private:
};

#endif // LAB4_H
