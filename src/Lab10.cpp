#include "Lab10.h"



Lab10::Lab10()
{
    this->inputVariables();
}

Lab10::~Lab10()
{
    //dtor
}
void Lab10::inputVariables()
{

    cout<<"\n\n ORIGEN: " << endl << endl;
    cout<<"\t X0: ";
    cin >>x_0;

    cout<<"\t Y0: ";
    cin >>y_0;

    cout<<"\t Z0: ";
    cin >>z_0;

    cout<<"\n DIRECCION: " << endl << endl;
    cout<<"\t Xd: ";
    cin >>xd;

    cout<<"\t Yd: ";
    cin >>yd;

    cout<<"\t Zd: ";
    cin >>zd;

    cout<<"\n ESFERA: " << endl << endl;
    cout<<"\t radio: ";
    cin >>sr;

    cout<<"\t Xc: ";
    cin >>xc;

    cout<<"\t Yc: ";
    cin >>yc;

    cout<<"\t Zc: ";
    cin >>zc;

    cout<<"\n NORMALIZANDO...  \n\n";

    xdn = xd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));
    ydn = yd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));
    zdn = zd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));

    cout<<"\t Xdn: " << xdn;
    cout<<"\t Ydn: " << ydn;
    cout<<"\t Zdn: " << zdn;

    cout<<"\n\n VALORES A, B, C \n\n ";

    v_A = 1;
    v_B = 2*(xdn*(x_0-xc)+ydn*(y_0-yc)+zdn*(z_0-zc));
    v_C = pow((x_0-xc),2)+pow((y_0-yc),2)+pow((z_0-zc),2)-pow(sr,2);

    cout<<"\t A: " << v_A;
    cout<<"\t B: " << v_B;
    cout<<"\t C: " << v_C;


    cout<<"\n\n DISCRIMINANTE  ";
    disc = pow(v_B,2) - 4*(v_C);
    if(disc<0)
    {
        cout << "\n La discriminante es negativa, por ende el rayo no colisiona con la esfera \n";
    }
    else
    {
        cout<<"\n\n Discriminate: " << disc;


        t0 = -(v_B+(sqrt(pow(v_B,2) - 4*(v_A)*(v_C))))/2;
        t1 = -(v_B-(sqrt(pow(v_B,2) - 4*(v_A)*(v_C))))/2;
        cout<<"\n\t T0:  " <<t0;
        cout<<"\n\t T1:  " <<t1;

        if(((t0>0)&&(t1<0))||((t0<0)&&(t1>1)))
        {
            if(t1>0)
                t0=t1;
        }
        if(t0>0 &&t1>0)
        {
            if(t1<t0)
                t0=t1;
        }

        cout<<"\n PUNTO DE INTERSECCION: ";
        xi = x_0+xdn*t0;
        yi = y_0+ydn*t0;
        zi = z_0+zdn*t0;
        cout << "( " << xi << ", " << yi << ", " << zi << " ) " << endl;

        cout<<"\n VECTOR NORMAL:";
        x_n = (xi-xc)/sr;
        y_n = (yi-yc)/sr;
        z_n = (zi-zc)/sr;
        cout << "( " << x_n << ", " << y_n << ", " << z_n << " ) " << endl;

        cout<<"\n 2DO PUNTO DE INTERSECCION: ";
        xi2 = x_0+xdn*t1;
        yi2 = y_0+ydn*t1;
        zi2 = z_0+zdn*t1;

        cout << "( " << xi2 << ", " << yi2 << ", " << zi2 << " ) " << endl;

    }
}

void Lab10::drawScene()
{
    glPushMatrix();
    glScaled(1.5f, 1.5f, 1.5f);
    this->drawEjes(100);
    this->drawEsfera();
    this->drawRayo();
    glPopMatrix();
}

void Lab10::drawEjes(int dimension)
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

void Lab10::drawEsfera()
{
    glColor3f(0.6f, 0.6f, 0.6f);
    glPushMatrix();
    glTranslatef(xc, yc, zc);
    glutWireSphere(sr,20,20);
    glPopMatrix();
}

void Lab10::drawRayo()
{
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(x_0,y_0,z_0);
    glVertex3f(xi,yi,zi);
    glEnd();
}
