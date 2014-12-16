#ifndef LAB13_H
#define LAB13_H


#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab13 : public Scene
{
    public:
        Lab13();
        ~Lab13();

        void drawScene();
        void inputVariables();
        void drawEjes(int dimension);

        void Plano();
        void leemat(int ma[10],int col);
        void presmat(int ma[10],int col);
        int borracol(int ma[10],int col,int cb);
        void rest(int ma[10],int ma1[10],int col,int col1);
        void ingresar();
        void Line();
        int algrt(int A[10],int B[10],int col,int col1);

    protected:
    private:
        double x,y,x2,y2,x3,y3,xi,yi,Rox,Roy,Roz;
};

#endif // LAB13_H
