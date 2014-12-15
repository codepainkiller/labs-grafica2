#ifndef LAB15_H
#define LAB15_H

#include "Scene.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Lab15 : public Scene
{
    public:
        Lab15();
        ~Lab15();

        void drawScene();
        void inputVariables();

        void drawEjes(int dimension);
        void drawPoint3D(float x, float y, float z);

    protected:
    private:

};

#endif // LAB15_H
