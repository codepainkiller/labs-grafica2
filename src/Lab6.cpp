#include "Lab6.h"

int  bandera=0;
int A1=0,B1=0, C1=0, A2=0, B2=0,C2=0;
float pcontrol[10][2];

int N,paso=0;

Lab6::Lab6()
{
    this->inputVariables();
}

Lab6::~Lab6()
{
    //dtor
}

void Lab6::inputVariables()
{
    cout<<"\n\n Cantidad de puntos >  ";
    cin>> N;
    cout << endl;

    int i=0;

    while (i < N)
    {
        if(i==0)
            cout<<" Punto inicial \n";

        else
        {
            if(i==(N-1))
            {
                cout<<" Punto final \n ";
                bandera=1;
            }
            else
            {
                cout<<" Puntos de la curva \n ";
            }
        }

        cout<<" Punto  "<< i <<" : " << endl;
        cout<<" x = ";
        cin>>pcontrol[i][0];

        cout<<" y = ";
        cin>>pcontrol[i][1];

        cout<<endl;

        i=i+1;
    }
}

void Lab6::drawScene()
{
    this->drawEjes(50);
    this->Bezier();
}


float Lab6::factorial(int n)
{
    float p=1;
    int i=1;

    while(i<=n)
    {
        p=p*(float)i;
        i=i+1;
    }

    return p;
}

float Lab6::CoeficienteNewton(int n,int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

float Lab6::Casteljau(float u,int coordenada)
{
    float suma=0.0;
    int i=0;
    while(i<N)
    {
        suma=suma+pcontrol[i][coordenada]*CoeficienteNewton(N-1,i)*pow(u,N-1-i)*pow(1.0-u,i);
        i=i+1;
    }
    return suma;
}

void Lab6::Bezier(void)
{
    float x,y;
    int i=0;

    glPointSize(2);

    // LIenas que unen los puntos de control
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    while(i<N)
    {
        glVertex3f(pcontrol[i][0],pcontrol[i][1],  0.0f);
        i=i+1;
    }
    glEnd();

    // Püntos e la curva
    glBegin(GL_LINE_STRIP);
    glColor3f(0.8f, 0.3f, 0.6f);
    glLineWidth(2);
    for(float u=0.0; u<=1; u+=0.01)
    {
        x = Casteljau(u,0);
        y = Casteljau(u,1);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void Lab6::drawEjes(int dimension)
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
