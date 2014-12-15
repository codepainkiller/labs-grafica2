#include "Lab9.h"

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

Lab9::Lab9()
{
    //ctor
}

Lab9::~Lab9()
{
    //dtor
}
void Lab9::inputVariables()
{

}

void Lab9::drawScene()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    //glTranslatef(0, 0, 10);
    glScalef(0.3, 0.3, 0.3);

    // Parel izquierda
    glColor3f(1, 0, 0);
    glPushMatrix();
        glTranslatef(-50, 0, 0);
        glScalef(0.5, 10, 10);
        glutSolidCube(10);
    glPopMatrix();

    // Parel derecha
    glColor3f(0, 0, 1);
    glPushMatrix();
        glTranslatef(50, 0, 0);
        glScalef(0.5, 10, 10);
        glutSolidCube(10);
    glPopMatrix();


    // Parel trasera
    glColor3f(255/138, 255/138, 255/138);
    glPushMatrix();
        glTranslatef(0, 0, -52.5);
        glRotatef(90, 0, 1, 0);
        glScalef(0.5, 10, 10.5);
        glutSolidCube(10);
    glPopMatrix();

    // Parel trasera
    glColor3f(255/138, 255/138, 255/138);
    glPushMatrix();
        glTranslatef(0, 0, -52.5);
        //glRotatef(90, 0, 1, 0);
        glScalef(10, 10, 0.5);
        glutSolidCube(10);
    glPopMatrix();

    // Piso
    glPushMatrix();
        glTranslatef(0, -50, 0);
        glScalef(10, 0.5, 10);
        glutSolidCube(10);
    glPopMatrix();

    // Techo
    glColor3f(0, 0, 0);
    glPushMatrix();
        glTranslatef(0, 50, 0);
        glScalef(10, 0.5, 10);
        glutSolidCube(10);
    glPopMatrix();

    // Esfera
    glColor3f(0, 0, 0);
    glPushMatrix();
        glTranslatef(-20, -35, -12);
        //glScalef(2, 4, 2);
        glutSolidSphere(15, 30, 30);
    glPopMatrix();

    // Cubo
    glPushMatrix();
        glTranslatef(10, -30, -10);
        glRotatef(60, 0, 1, 0);
        glScalef(2, 4, 2);
        glutSolidCube(10);
    glPopMatrix();

    // Foco
    glColor3f(1, 1, 1);
    glPushMatrix();
        glTranslatef(0, 49, 0);
        glScalef(3, 0.5, 3);
        glutSolidCube(10);
    glPopMatrix();


    glFlush();
}

void Lab9::drawEjes(int dimension)
{
    glPointSize(1);

    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(-dimension, 0.0f, 0);
    glVertex3f( dimension, 0.0f, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, -dimension, 0);
    glVertex3f(0,  dimension, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0.0f, -dimension);
    glVertex3f(0, 0.0f, dimension);
    glEnd();
}
