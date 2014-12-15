#include "Lab15.h"

struct Color {
    int R, G, B;
};

struct Punto {
    int x, y, z;
};

int width = 800;
int height = 600;

int zbuffer[600][800];
Color screen[600][800];

vector<Punto> cuandrado1;
vector<Punto> cuandrado2;

Lab15::Lab15()
{

    // Inicialzando zbuffer profuncidad
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            zbuffer[i][j] = -100;  // profundidad 100
        }
    }

    // Inicializando Screen
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screen[i][j].R = 0;
            screen[i][j].G = 0;
            screen[i][j].B = 0;
        }
    }

    // Calculando dimensiones de cuadrados
    Punto p1 = {0, 0, -40};

    int alto = 20;
    int ancho = 30;

    cout << "alto" << alto << endl;
    cout << "ancho: " << ancho << endl;

    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < alto; j++)
        {
            Punto p;
            p.x = p1.x + i;
            p.y = p1.y + j;
            p.z = p1.z;

            cuandrado1.push_back(p);
        }
    }

    // Cuadrado 2
    Punto p2 = {-10, -10, -5};

    alto = 30;
    ancho = 40;

    cout << "alto" << alto << endl;
    cout << "ancho: " << ancho << endl;

    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < alto; j++)
        {
            Punto p;
            p.x = p2.x + i;
            p.y = p2.y + j;
            p.z = p2.z;

            cuandrado2.push_back(p);
        }
    }

    // Algoritmo de Zbuffer
    Color color1 = {1, 1, 0};
    for (int i = 0; i < cuandrado1.size(); i++)
    {
        int x_ = cuandrado1.at(i).x;
        int y_ = cuandrado1.at(i).y;
        int z_ = cuandrado1.at(i).z;

        if (z_ < zbuffer[y_][x_]) {
            zbuffer[y_][x_] = z_;
            screen[y_][x_] = color1;
            /*
            screen[y_][x_].R = 1;
            screen[y_][x_].G = 1;
            screen[y_][x_].B = 0; */
        }

    }

    for (int i = 0; i < cuandrado2.size(); i++)
    {

    }


}

Lab15::~Lab15()
{
    //dtor
}
void Lab15::drawScene()
{
    glPushMatrix();
    glScalef(0.3f, 0.3f, 0.3f);

    this->drawEjes(50);

    for (int i = 0; i < cuandrado1.size(); i++)
    {
        glColor3f(1, 1, 0);
        this->drawPoint3D(cuandrado1.at(i).x,
                          cuandrado1.at(i).y,
                          cuandrado1.at(i).z);

        glColor3f(0, 1, 1);
        this->drawPoint3D(cuandrado2.at(i).x,
                          cuandrado2.at(i).y,
                          cuandrado2.at(i).z);
    }

    glPopMatrix();

}

void Lab15::inputVariables()
{

}

void Lab15::drawEjes(int dimension)
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

void Lab15::drawPoint3D(float x, float y, float z)
{
    glPointSize(2);

    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}
