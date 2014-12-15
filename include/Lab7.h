#ifndef LAB7_H
#define LAB7_H

#include "Scene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <stack>

#define PI  3.14159265358979323846
#define DEGTORAD PI/180.0f  // Grados a radianes

using namespace std;

// Estructura para guardar posicion y angulo cuando recorremos el axioma
struct Nodo {
    float x_;
    float y_;
    float angle_;
};

class Lab7 : public Scene
{
    public:
        Lab7();
        ~Lab7();

        void inputVariables();
        void drawScene();

    protected:
    private:
        // Dibuja texto en pantalla
        void    DrawString(string message);

        // Dibuja una linea en una posicion pasada como parametro
        void    DrawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

        // Dibuja un L-System en 2D
        void    LSystem(string w, float inicioX, float inicioY);

        // Genera la palabra con una UNA sola regla
        string  GenerarPalabra(string axioma, string F, unsigned nivelProduccion);

        // Genera la palabra con DOS reglas
        string GenerarPalabra(string axioma, string Z, string X, unsigned nivelProduccion);

        // Genera la palabra para un L-System ESTOCASTICO
        string GenerarPalabra(string axioma, vector<string> F, unsigned nivelProduccion);

        float           m_angle;
        unsigned        m_levelProduction;
        string          m_axiom;
        string          m_rule1;
        string          m_rule2;
        vector<string>  m_rulesF;
        vector<string>  m_LSEstocasticos;
        string          m_word;
};

#endif // LAB7_H