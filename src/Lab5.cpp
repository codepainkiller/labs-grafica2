#include "Lab5.h"

Lab5::Lab5()
{
    //ctor
}

Lab5::~Lab5()
{
    //dtor
}

void Lab5::inputVariables()
{

}

void Lab5::drawScene()
{
    this->drawEjes(50);

    glColor3f(182/255.0f, 245/255.0f, 159/255.0f);
    glPushMatrix();
    glTranslatef(-20, 0, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    this->drawParaboloide_1hoja();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(-20, 0, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.3f, 0.2f, 0.2f);
    this->drawElipsoide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, 0, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.2f, 0.2f, 0.2f);
    this->drawParaboloide_2hojas();
    glPopMatrix();
}

void Lab5::drawParaboloide_1hoja()
{
    float phi = 0;
    float teta = 0;
    float x, y, z;
    glBegin(GL_POINTS);
    for (teta =-2.5; teta < 2.5; teta=teta+0.05) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (phi = 0; phi < 360; phi++) // bucle interono para dibujar la esfera
        {
            x=7*cosh(teta) *cos(phi);
            y=7*cosh(teta)*sin(phi);
            z=7*sinh(teta);
            glVertex3f(x,y,z);  /// u =teta ,v=phi
        }
    }
    glEnd();
}
void Lab5::drawParaboloide_2hojas()
{
    float u= 0;
    float v= 0;
    float x, y, z, x1,y1,z1;
    glBegin(GL_POINTS);
    for (v=0; v < 3.0; v=v+0.05) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (u= 0; u < 360; u++) // bucle interono para dibujar la esfera
        {
            x=7*cosh(v);
            y=4*cos(u)*sinh(v);
            z=5*sin(u)*sinh(v);
            x1=-7*cosh(v);
            y1=4*cos(u)*sinh(v);
            z1=5*sin(u)*sinh(v);
            glVertex3f(x,y,z);  /// u =teta ,v=phi
            glVertex3f(x1,y1,z1);
        }
    }
    glEnd();
}
void Lab5::drawElipsoide()
{
    float phi = 0;
    float pi = 3.141516f;
    float teta = 0;
    float x, y, z;
    glBegin(GL_POINTS);
    for (teta =-20; teta <=0; teta=teta+0.2) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (phi=0; phi <=(2*pi); phi=phi+0.08) // bucle interono para dibujar la esfera
        {
            x = 40 * cos(phi)*cos(teta);
            y = 55 * cos(phi)*sin(teta);
            z = 40 * sin(phi);
            glVertex3f(x,y,z);
        }
    }
    glEnd();
}



void Lab5::drawEjes(int dimension)
{
    glPointSize(1);

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

void Lab5::drawPoint3D(float x, float y, float z)
{
    glPointSize(1);
    glColor3f(1, 0, 0);
    glPointSize(2);

    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}
