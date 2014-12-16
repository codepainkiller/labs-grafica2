#include "Lab12.h"


Lab12::Lab12()
{
    this->inputVariables();
}

Lab12::~Lab12()
{
    //dtor
}
void Lab12::drawScene()
{
    this->drawEjes(100);

    dibujar();
    dibujarPlano();
    line();
}

void Lab12::inputVariables()
{
    cout << "\t Interseccion Rayo plano " << endl << endl;

    cout << "\t ORIGEN: " << endl;
    cout << "\t X0: ";
    cin >> xo;
    cout << "\t Y0: ";
    cin >> yo;
    cout << "\t Z0: ";
    cin >> zo;

    cout << "\t DIRECCION: " << endl;
    cout << "\t Xd: ";
    cin >> xd;
    cout << "\t Yd: ";
    cin >> yd;
    cout << "\t Zd: ";
    cin >> zd;

    cout << "\n\t Normalizando la direccion: \n\n";
    xdn = xd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));
    ydn = yd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));
    zdn = zd / sqrt(pow(xd,2)+pow(yd,2)+pow(zd,2));

    cout << "\t Xdn: " << xdn;
    cout << "\t Ydn: " << ydn;
    cout << "\t Zdn: " << zdn;

    cout << "\n\t Ecuacion del plano: " << endl;
    cout << "\t A: ";
    cin >> A;
    cout << "\t B: ";
    cin >> B;
    cout << "\t C: ";
    cin >> C;
    cout << "\t D: ";
    cin >> D;
    cout << "\n\t La ecuacion del plano : " << A << "x + "
         << B << "y + "
         << C << "z + "
         << D << " = 0" << endl;

    sum = A*A + B*B + C*C;

    if(sum == 1)
    {
        cout << "\n\t Vector normal " << endl;
        cout << "\n\t P normal = [ " << A << B << C << " ] " << endl;

        vd = A*xdn + B*ydn + C*zdn;
        cout << "vector direccional: " << vd;
        vo = -1*(A*xo + B*yo + C*zo + D ) ;
        cout << "Vector orign: " << vo;

        if(vd==0)
        {
            cout<<"\n\t No existe interseccion"<<endl;
            cout << "\n\t Calculando t: " << t << endl;
        }
        if(vd>0)
        {
            // cout << "\n\t Calculando t: " << endl;
            t = vo / vd ;
            //cout << t;

            if(t>0)
            {
                cout<<"\n\t El rayo intercepta con el plano detras del origen"<<endl;
                cout<<"\n\t Punto de intercepccion : "<<endl;

                xi = xo + xd*t;
                yi = yo + yd*t;
                zi = zo + zd*t;
                cout << "\n\t ri =  [ " << xi  <<yi  <<zi << " ]"<<endl;
            }
        }
        if( vd < 0 )
        {
            cout << "\n\t rn = [ " << A << B << C << " ] " << endl;
            cout << "\n\t Calculando t: " << t << endl;
        }

        else
            cout << "\n\t rn = [ -" << A << "-" << B << "-" << C << " ] " << endl;

        cout << "\n\t Calculando t: " << t << endl;
    }
}

void Lab12::line()
{
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(xo,yo,zo);
    glVertex3f(xi,yi,zi);
    glEnd();
}

void Lab12::dibujar(void)
{
    glBegin(GL_LINES);       //cara abajo
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 400.0f,0.0f, 0.0f);
    glVertex3f( -400.0f,0.0f,  0.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f,400.0f,  0.0f);
    glVertex3f(0.0f,-400.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f,0.0f,  400.0f);
    glVertex3f(0.0f,0.0f, -400.0f);
    glEnd();
}


void Lab12::drawEjes(int dimension)
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

void Lab12::dibujarPlano()
{
    glPushMatrix();
    if( D>0)
    {
        glTranslatef(D+(xo+A),D+(yo-B),0);
    }
    else
    {
        glTranslatef((-1*D)+(xo+A),(-1*D)+(yo-B),0);
    }
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f((A+10),(B+10),zo);
    glVertex3f((A-10),(B+10),zo);
    glVertex3f((A-10),(B-10),zo);
    glVertex3f((A+10),(B-10),zo);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
