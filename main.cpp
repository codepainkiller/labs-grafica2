#include "SceneManager.h"
#include "Scene.h"
#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int WIN_WIDTH = 1300;
int WIN_HEIGHT = 750;
int ORTHO_SIZE = 100;

// Ortogonal = 1,
// Isometrico = 2
int VIEW_MODE = 2;

// Movimiento de camara en 2D
int cameraX = 0;
int cameraY = 0;
int cameraZ = 0;

// LookAt
float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 5.0f, z = 45.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;

// Manager scenes
SceneManager* manager;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (VIEW_MODE == 1)
        glOrtho(-ORTHO_SIZE, ORTHO_SIZE,-ORTHO_SIZE,ORTHO_SIZE,ORTHO_SIZE,-ORTHO_SIZE);
    else if (VIEW_MODE == 2)
        glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

static void display(void)
{
    VIEW_MODE = manager->getCurrentScene()->getViewMode();

    if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(	x, 1.0f, z,
				x+lx, 1.0f,  z+lz,
				0.0f, 1.0f,  0.0f);

    manager->getCurrentScene()->drawScene();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case 'w':
        cameraY -= 2.5f;
        break;

    case 's':
        cameraY += 2.5f;
        break;

    case 'a':
        cameraX += 2.5f;
        break;

    case 'd':
        cameraX -= 2.5f;
        break;
    }

    glutPostRedisplay();
}


void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char *argv[])
{
    manager = new SceneManager();

    glutInit(&argc, argv);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("CD - Computacion Grafica II");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutSpecialFunc(pressKey);
	//glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

    glClearColor(0, 0, 0, 1);

    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    /*
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
    */

    glutMainLoop();

    return EXIT_SUCCESS;
}
