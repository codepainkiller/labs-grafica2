#ifndef LAB6_H
#define LAB6_H

#include "Scene.h"
#include <cmath>
#include <iostream>

using namespace std;

class Lab6 : public Scene
{
    public:
        Lab6();
        ~Lab6();

        void inputVariables();
        void drawScene();

        void Bezier(void);
        float Casteljau(float u,int coordenada);
        float CoeficienteNewton(int n,int k);
        float factorial(int n);

        void drawEjes(int dimension);

    protected:
    private:
};

#endif // LAB6_H
