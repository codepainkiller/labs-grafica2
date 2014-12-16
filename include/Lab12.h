#ifndef LAB12_H
#define LAB12_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab12 : public Scene
{
    public:
        Lab12();
        ~Lab12();

        void drawScene();
        void inputVariables();
        void drawEjes(int dimension);
        void line();
        void dibujar();
        void dibujarPlano();

    protected:
    private:
        double xo,yo,zo,xd,yd,zd,xdn,ydn,zdn,A,B,C,D,sum,vd,vo,t,xi,yi,zi,PR;
};

#endif // LAB12_H
