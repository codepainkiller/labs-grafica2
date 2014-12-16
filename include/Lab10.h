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
        double x_0,y_0,z_0,xd,yd,zd,xdn,xc,yc,zc,ydn,zdn,sr,sc,v_A,v_B,v_C,disc, t0,t1,xi,yi,zi,x_n,y_n,z_n,xi2,yi2,zi2;
};

#endif // LAB10_H
