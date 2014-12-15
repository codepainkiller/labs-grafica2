#ifndef LAB5_H
#define LAB5_H

#include "Scene.h"
#include <cmath>

using namespace std;

class Lab5 : public Scene
{
    public:
        Lab5();
        ~Lab5();

        void inputVariables();
        void drawScene();

        void drawParaboloide_1hoja();
        void drawParaboloide_2hojas();
        void drawElipsoide();

        void drawEjes(int dimension);
        void drawPoint3D(float x, float y, float z);

    protected:
    private:
};

#endif // LAB5_H


