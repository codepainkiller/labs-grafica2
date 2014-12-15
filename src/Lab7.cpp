#include "Lab7.h"


Lab7::Lab7()
{
    srand(time(0));
    this->inputVariables();
}

Lab7::~Lab7()
{
}

int inline selectLSystem()
{
    int option;

    do
    {
        cout << "\n Seleccione un L-System: "   << endl << endl;
        cout << " 1. FF-[-F+F+F]+[+F-F-F]"      << endl;
        cout << " 2. F[+F]F[-F]F"               << endl;
        cout << " 3. F[+F]F[-F][F]"             << endl;
        cout << " 4. L-System con 2 gramaticas" << endl;
        cout << " 5. L-System esctocastico"     << endl << endl;
        cout << " Opcion > ";
        cin >> option;

    }
    while (option > 5 || option < 1 );

    return option;
}

void Lab7::inputVariables()
{
    int select = selectLSystem();

    if (select == 1)
    {
        m_levelProduction = 3;
        m_angle = 22.5f;
        m_axiom = "F";
        m_rule1 = "FF-[-F+F+F]+[+F-F-F]";

        m_word = this->GenerarPalabra(m_axiom, m_rule1, m_levelProduction);
    }
    else if (select == 2)
    {
        m_levelProduction = 2;
        m_angle = 25.7f;
        m_axiom = "F";
        m_rule1 = "F[+F]F[-F]F";

        m_word = this->GenerarPalabra(m_axiom, m_rule1, m_levelProduction);
    }
    else if (select == 3)
    {
        m_levelProduction = 3;
        m_angle = 20.7f;
        m_axiom = "F";
        m_rule1 = "F[+F]F[-F][F]";

        m_word = this->GenerarPalabra(m_axiom, m_rule1, m_levelProduction);
    }
    else if (select == 4)
    {
        m_levelProduction = 4;
        m_angle = 20.0f;
        m_axiom = "Z";
        m_rule1 = "X[+Z]X[-Z]+Z";
        m_rule2 = "XX";

        m_word = this->GenerarPalabra(m_axiom, m_rule1, m_rule2, m_levelProduction);
    }
    else if (select == 5)
    {
        m_levelProduction = 3;
        m_angle = 25.7f;
        m_axiom = "F";
        m_rulesF.push_back("F[+F]F[-F]F");  // F[0]
        m_rulesF.push_back("F[+F]F");       // F[1]
        m_rulesF.push_back("F[-F]F");       // F[2]

        // Creando 7 plantas
        for (unsigned i = 0; i < 5; i++)
        {
            m_word = this->GenerarPalabra(m_axiom, m_rulesF, m_levelProduction);
            m_LSEstocasticos.push_back(m_word);
        }
    }

    cout << endl << "Nivel de Produccion: " << m_levelProduction << endl;
    cout << endl << m_word << endl;
}

void Lab7::drawScene()
{
    glPushMatrix();
    glScalef(0.8f, 0.8f, 0.8f);

    if ( m_rulesF.empty())
        this->LSystem(m_word, 0, -25);
    else
        for(int i = 0; i < m_LSEstocasticos.size(); i++)
            LSystem(m_LSEstocasticos.at(i), (i*15) -30, -25);

    glPopMatrix();
}

void Lab7::DrawString(string message)
{
    string::iterator it = message.begin();

    for (; it != message.end(); ++it)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *it);

}

void Lab7::DrawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 1, 0);
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);
    glEnd();
}

void Lab7::LSystem(string w, float inicioX, float inicioY)
{
    unsigned i = 0;

    float xo = inicioX;
    float yo = inicioY;
    float xf = xo;
    float yf = yo;

    stack<Nodo> nodos;
    Nodo nodoActual;

    float angleRot = 90.0f;  // Inicia en vertical

    while ( i < w.size() )
    {
        switch (w[i])
        {
        case 'F' :
            xf = xo + 1.0f * cos( angleRot * DEGTORAD );
            yf = yo + 1.0f * sin( angleRot * DEGTORAD );
            DrawLine(xo, yo, xf, yf);
            xo = xf;
            yo = yf;
            break;
        case 'Z' :
                // Se suma 90 grados para para ponerlo en vertical. Ademas no olvidar que
                // angleRot ha sufrido varias modificaciones debido a los simbolos caracteres + -
                xf = xo + 0.7f * cos( (angleRot+90) * DEGTORAD );
                yf = yo + 0.7f * sin( (angleRot+90) * DEGTORAD );
                DrawLine(xo, yo, xf, yf);
                xo = xf;
                yo = yf;
                break;

            case 'X':
                xf = xo + 0.7f * cos( angleRot * DEGTORAD );
                yf = yo + 0.7f * sin( angleRot * DEGTORAD );
                DrawLine(xo, yo, xf, yf);
                xo = xf;
                yo = yf;
                break;

        case '[' :
            nodoActual.x_ = xf;
            nodoActual.y_ = yf;
            nodoActual.angle_ = angleRot;
            nodos.push(nodoActual);
            break;

        case ']' :
            xo = nodos.top().x_;
            yo = nodos.top().y_;
            xf = xo;
            yf = yo;
            angleRot = nodos.top().angle_;
            nodos.pop();
            break;

        case '+' :
            angleRot += m_angle;
            break;

        case '-' :
            angleRot -= m_angle;
            break;
        }

        i++;
    }
}

string Lab7::GenerarPalabra(string axioma, string F, unsigned nivelProduccion)
{
    // Cuenta la posici�n de la cadena (axioma) donde se ecuentra
    unsigned n = 0;

    while (n <= nivelProduccion)
    {
        int cont = 0;

        while ( cont < axioma.size() )
        {
            if ( axioma[cont]== 'F' )
            {
                axioma.insert(cont, F);  // Insertamos la cadena, es decir regla F
                cont += F.size();        // Se actualiza la posicion al aumentar el tama�o del axioma
                axioma.erase(cont, 1);   // Se elimina el F anterior
            }
            else
            {
                cont++;
            }
        }

        n++;
    }

    return axioma;
}

string Lab7::GenerarPalabra(string axioma, string Z, string X, unsigned nivelProduccion)
{
    // Cuenta la posici�n de la cadena (axioma) donde se ecuentra
    unsigned n = 0;

    while (n <= nivelProduccion)
    {
        int cont = 0;

        while ( cont < axioma.size() )
        {
            if ( axioma[cont]== 'Z' )
            {
                axioma.insert(cont, Z); // Insertamos la cadena, es decir regla Z
                cont += Z.size();       // Se actualiza la posicion al aumentar el tama�o del axioma
                axioma.erase(cont, 1);  // Se elimina el Z anterior
            }
            else if (axioma[cont]== 'X')
            {
                axioma.insert(cont, X);  // Insertamos la cadena, es decir regla X
                cont += X.size();        // Se actualiza la posicion al aumentar el tama�o del axioma
                axioma.erase(cont, 1);   // Borramos el X anterior
            }
            else
            {
                cont++;
            }
        }

        n++;
    }

    return axioma;
}

string Lab7::GenerarPalabra(string axioma, vector<string> F, unsigned nivelProduccion)
{
    // Contador del nivel de producci�n
    unsigned n = 0;

    // La regla se escojera de acuerdo al numero que se asigne pn, que sera aleatorio
    // [0.00 - 0.33] --> p1 es decir F[0]
    // [0.34 - 0.66] --> p2 es decir F[1]
    // [0.67 - 1.00] --> p3 es decir F[2]
    float    pn = 0.0f;

    while (n <= nivelProduccion)
    {
        // Cuenta la posici�n de la cadena (axioma) donde se ecuentra
        int cont = 0;

        while ( cont < axioma.size() )
        {
            if ( axioma[cont]== 'F' )
            {
                // Numero aleatorio entre 0.0 - 1.0
                pn = float(rand() % 101) / 100;

                if (pn > 0 && pn <= 0.33f)
                {
                    axioma.insert(cont, F.at(0));  // Insertamos la cadena, es decir regla F[0]
                    cont += F.at(0).size();        // Se actualiza la posicion al aumentar el tama�o del axioma
                    axioma.erase(cont, 1);         // Borramos el F anterior
                }
                else if (pn > 0.33f && pn <= 0.66f)
                {
                    axioma.insert(cont, F.at(1));  // Insertamos la cadena, es decir regla F[1]
                    cont += F.at(1).size();        // Se actualiza la posicion al aumentar el tama�o del axioma
                    axioma.erase(cont, 1);         // Borramos el F anterior
                }
                else if(pn > 0.66f && pn <= 1.0f)
                {
                    axioma.insert(cont, F.at(2));  // Insertamos la cadena, es decir regla F[2]
                    cont += F.at(2).size();        // Se actualiza la posicion al aumentar el tama�o del axioma
                    axioma.erase(cont, 1);         // Borramos el F anterior
                }
            }
            else
            {
                cont++;
            }
        }

        n++;
    }

    return axioma;
}
