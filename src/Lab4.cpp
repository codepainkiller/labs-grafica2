#include "Lab4.h"

Lab4::Lab4()
{
    this->setViewMode(1);
    //this->setOrthoSize(20);
}

Lab4::~Lab4()
{
    //dtor
}

void Lab4::inputVariables()
{

}

void Lab4::drawScene()
{
    this->drawEjes(50);

    glColor3f(182/255.0f, 245/255.0f, 159/255.0f);
    glPushMatrix();
    glTranslatef(-15, 10, 0);
    glRotatef(180, 1, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    this->cono();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0, 10, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    this->esfera();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 0, 0);
    glRotatef(86, 1, 0, 1);
    glScalef(0.2f, 0.2f, 0.2f);
    this->cilindro();
    glPopMatrix();

}


void Lab4::esfera()
{
    float phi = 0;
    float pi = 3.141516;
    float teta = 0;
    float x, y, z;
    glBegin(GL_POINTS);
    for (teta = 0; teta <=pi; teta=teta+0.08) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (phi=0; phi <=(2*pi); phi=phi+0.08) // bucle interono para dibujar la esfera
        {
            x = 20* cos(phi) * sin(teta);
            y =20*sin(phi)*sin(teta);
            z = 20* cos(teta);
            glVertex3f(x,y,z);
        }
    }
    glEnd();
}

void Lab4::cilindro()
{
    float phi = 0;
    float pi = 3.141516;
    float teta = 0;
    float x, y, z;
    glBegin(GL_POINTS);
    for (teta = -20; teta <=19; teta=teta+0.2) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (phi=0; phi <=(2*pi); phi=phi+0.08) // bucle interono para dibujar la esfera
        {
            x = 20* cos(phi);
            y =20*sin(phi);
            z = teta;
            glVertex3f(x,y,z);
        }
    }
    glEnd();
}

void Lab4::cono()
{
    float phi = 0;
    float pi = 3.141516;
    float teta = 0;
    float x, y, z;
    glBegin(GL_POINTS);
    for (teta =-20; teta <=0; teta=teta+0.2) //  bucles externo para graficar la circunferencia deacuerdo a la esfera
    {
        for (phi=0; phi <=(2*pi); phi=phi+0.08) // bucle interono para dibujar la esfera
        {
            x = 4* cos(teta) * phi;
            y =10*phi ;
            z = 4 * sin(teta) * phi;
            glVertex3f(x,y,z);
        }
    }
    glEnd();
}

void Lab4::drawEjes(int dimension)
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

void Lab4::drawPoint3D(float x, float y, float z)
{
    glPointSize(1);
    glColor3f(1, 0, 0);
    glPointSize(2);

    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}
