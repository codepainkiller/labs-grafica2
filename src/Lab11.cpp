#include "Lab11.h"

double Sn1,Sn2,Sn3,Sp1,Sp2,Sp3 ,Se1,Se2,Se3 ,fi,p,q , v,u, pl ,S ,Spe1,Spe2,Spe3,r ;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

Lab11::Lab11()
{

    this->inputVariables();
}

Lab11::~Lab11()
{
    //dtor
}

void Lab11::drawScene()
{
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

    glTranslatef(6, 0, 30);

    this->drawEjes(100);
    this->drawPuntoInterseccion();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0);
    glScalef(1, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
}

void Lab11::inputVariables()
{
    cout<<"\n\t--> ingresar coordenadas de S normal: ";
    cout<<"\n -->PUNTO XS: ";cin>>Sn1;
    cout<<"\n -->PUNTO YS: ";cin>>Sn2;
    cout<<"\n -->PUNTO ZS: ";cin>>Sn3;

    cout<<"\n\t--> ingresar coordenadas de S polar: ";
    cout<<"\n -->PUNTO XP: ";cin>>Sp1;
    cout<<"\n -->PUNTO YP: ";cin>>Sp2;
    cout<<"\n -->PUNTO ZP: ";cin>>Sp3;


    cout<<"\n\t ingresar coordenadas de S ecuatorial: ";
     cout<<"\n -->PUNTO XE: ";cin>>Se1;
     cout<<"\n -->PUNTO YE: ";cin>>Se2;
     cout<<"\n -->PUNTO ZE: ";cin>>Se3;

    cout<<"\n\t calculando fi: ";
    p=-(Sn1*Sp1 + Sn2*Sp2 + Sn3*Sp3);
    fi = acos(p);
    cout<<fi<<endl;

    cout<<"\n\t hallando el parametro v : ";
    v = fi / 3.1415;
    cout<<v<<endl;

    if(v==0 || v==1)
    {
        u=0;
    }
    else
    {
        cout<<"\n\t parametro longitudinal: ";

        q= ((Se1*Sn1 + Se2*Sn2 + Se3*Sn3)/sin(fi));
        r= acos(q);;
        pl=  r / 6.283 ;
        cout<<pl<<endl;

        //prducto Sp * Se
        Spe1= Sp1*(Sp2*Se3 - Sp3*Se2);
        Spe2= -(Sp2*(Sp1*Se3 - Sp3*Se1));
        Spe3= Sp3*(Sp1*Se2 - Sp2*Se1);

        //producto (Spe . Sn)
        S= Spe1*Sn1 + Spe2*Sn2 + Spe3*Sn3;

        if(S>0)
            u=pl;

        else
            u=1-pl;
    }
    cout<<"\n\t los parametros son:("<< u <<";"<< v <<")"<<endl;
}

void Lab11::drawEjes(int dimension)
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


void Lab11::drawPuntoInterseccion()
{
    glColor3f(1, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex3f(u,v,0);
    glEnd();
}
