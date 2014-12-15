#ifndef LAB3_H
#define LAB3_H

#include "Scene.h"
#include <iostream>

using namespace std;

struct Point3D
{
    int x, y, z;
};

class Lab3 : public Scene
{
    public:
        Lab3();
        ~Lab3();

        void inputVariables();

        void drawScene();

        void bresenham3D(int x1, int y1, int z1, const int x2, const int y2, const int z2);

        void drawEjes(int dimension);

        void drawPoint3D(float x, float y, float z);

    protected:
    private:
        Point3D m_point1;
        Point3D m_point2;
};

#endif // LAB3_H
