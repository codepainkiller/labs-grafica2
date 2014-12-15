#include "Lab3.h"

Lab3::Lab3()
{
    this->setViewMode(VIEW_ORTHOGONAL);

    this->inputVariables();
}

Lab3::~Lab3()
{
    //dtor
}

void Lab3::inputVariables()
{
    cout << endl;
    cout << " Punto inicial: \n";
    cout << "\t x: "; cin >> m_point1.x;
    cout << "\t y: "; cin >> m_point1.y;
    cout << "\t y: "; cin >> m_point1.z;

    cout << "Punto final: \n  ";
    cout << "\t x: "; cin >> m_point2.x;
    cout << "\t y: "; cin >> m_point2.y;
    cout << "\t z: "; cin >> m_point2.z;
}

void Lab3::drawScene()
{
    this->drawEjes(600);

    this->bresenham3D(  m_point1.x, m_point1.y, m_point1.z,
                        m_point2.x, m_point2.y, m_point2.z);
}

void Lab3::bresenham3D(int x1, int y1, int z1, const int x2, const int y2, const int z2)
{
    int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;
    int point[3];

    point[0] = x1;
    point[1] = y1;
    point[2] = z1;
    dx = x2 - x1;
    dy = y2 - y1;
    dz = z2 - z1;
    x_inc = (dx < 0) ? -1 : 1;
    l = abs(dx);
    y_inc = (dy < 0) ? -1 : 1;
    m = abs(dy);
    z_inc = (dz < 0) ? -1 : 1;
    n = abs(dz);
    dx2 = l << 1;
    dy2 = m << 1;
    dz2 = n << 1;

    if ((l >= m) && (l >= n))
    {
        err_1 = dy2 - l;
        err_2 = dz2 - l;

        for (i = 0; i < l; i++)
        {
            drawPoint3D(point[0], point[1], point[2]);

            if (err_1 > 0)
            {
                point[1] += y_inc;
                err_1 -= dx2;
            }
            if (err_2 > 0)
            {
                point[2] += z_inc;
                err_2 -= dx2;
            }
            err_1 += dy2;
            err_2 += dz2;
            point[0] += x_inc;
        }
    }
    else if ((m >= l) && (m >= n))
    {
        err_1 = dx2 - m;
        err_2 = dz2 - m;

        for (i = 0; i < m; i++)
        {
            drawPoint3D(point[0], point[1], point[2]);

            if (err_1 > 0)
            {
                point[0] += x_inc;
                err_1 -= dy2;
            }
            if (err_2 > 0)
            {
                point[2] += z_inc;
                err_2 -= dy2;
            }
            err_1 += dx2;
            err_2 += dz2;
            point[1] += y_inc;
        }
    }
    else
    {
        err_1 = dy2 - n;
        err_2 = dx2 - n;

        for (i = 0; i < n; i++)
        {
            drawPoint3D(point[0], point[1], point[2]);

            if (err_1 > 0)
            {
                point[1] += y_inc;
                err_1 -= dz2;
            }
            if (err_2 > 0)
            {
                point[0] += x_inc;
                err_2 -= dz2;
            }
            err_1 += dy2;
            err_2 += dx2;
            point[2] += z_inc;
        }
    }

    drawPoint3D(point[0], point[1], point[2]);
}

void Lab3::drawEjes(int dimension)
{
    glPointSize(3);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(-dimension, 0, 0);
        glVertex3f( dimension, 0, 0);

        glColor3f(0, 1, 0);
        glVertex3f(0, -dimension, 0);
        glVertex3f(0,  dimension, 0);

        glColor3f(0, 0, 1);
        glVertex3f(0, 0, -dimension);
        glVertex3f(0, 0, dimension);
    glEnd();
}

void Lab3::drawPoint3D(float x, float y, float z)
{
    glColor3f(1, 0, 0);
    glPointSize(2);

    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}
