#include "Lab13.h"

Lab13::Lab13()
{
    this->inputVariables();
}

Lab13::~Lab13()
{
    //dtor
}

void Lab13::drawScene()
{
    this->drawEjes(100);
    this->Plano();
    this->Line();
}

void Lab13::inputVariables()
{
    this->ingresar();
}

void Lab13::drawEjes(int dimension)
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

void Lab13::Plano()
{
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(x,y,0);
    glVertex3f(x2,y2,0);
    glVertex3f(x3,y3,0);
    //glVertex3f(8,0,10);
    glEnd();
}

void Lab13::leemat(int ma[10],int col)
{
    for(int j=0;j<col;j++)
    {
        if(j==0)
        {
            cout<<"\t\t X = ";
            cin>>ma[j];
        }
        if(j==1)
        {
            cout<<"\t\t Y = ";
            cin>>ma[j];
        }
        if(j==2)
        {
            cout<<"\t\t Z = ";
            cin>>ma[j];
        }
        if(j==3)
        {
            cout<<"\t\t U = ";
            cin>>ma[j];
        }
    }
}

void Lab13::presmat(int ma[10],int col)
{
    for(int j=0;j<col;j++)
        cout<<" "<<ma[j];
    cout<<endl;
}

int Lab13::borracol(int ma[10],int col,int cb)
{
    for(int j=cb;j<col-1;j++)
        ma[j]=ma[j+1];
    col--;
    return col;
}

void Lab13::rest(int ma[10],int ma1[10],int col,int col1)
{
    for(int i=0;i<3;i++)
    {
        ma[i]=ma[i]-ma1[i];
    }
}

int Lab13::algrt(int A[10],int B[10],int col,int col1)
{
    int NSH=0,SH=0,NC=0,intr;
    if(A[1]>=0)
        SH=1;
    else
        SH=-1;

    if(B[1]>=0)
        NSH=1;
    else
        NSH=-1;

    if(SH!= NSH)
    {
        if(A[0]>=0 && B[0]>=0)
            NC++;
        else
        {
            if(A[0]>=0 || B[0]>=0)
            {
                intr=A[0]-( A[1]*(B[0]-A[0])/(B[1]-A[1]) );
                if(intr>0)
                    NC++;
            }
        }
    }
    return NC;
}

void Lab13::ingresar()
{
    int A[3],f,c=3,i,may=0,B[3],C[3],P[4],R[3],cb,c1=3,c2=3,c3=4,c4=3,c5=3,I[3],SH=0, NSH=0, NC=0,m,n,p;
    cout<<"\t\t DADO LOS PUNTOS DE UN TRIAUNGULO \n\n";
    cout<<"\t Ingresar coordenadas del punto A \n";
    leemat(A,c);
    cout<<"\t\tA : ";
    presmat(A,c);

    cout<<"\n\t Ingresar coordenadas del punto B \n";
    leemat(B,c1);
    cout<<"\t\tB : ";
    presmat(B,c1);

    cout<<"\n\t Ingresar coordenadas del punto C \n";
    leemat(C,c2);
    cout<<"\t\tC : ";
    presmat(C,c2);

    cout<<"\n\t ingresar coordenadas de interseccion  \n";
    leemat(I,c4);
    cout<<"\t\tRi : ";
    presmat(I,c4);

    cout<<"\n\t ingresar PLANO  \n";
    leemat(P,c3);
    cout<<"\t\tsus elementos son: ";
    presmat(P,c3);

    cout<<"\n\t ingresar coordenadas Rayo Origen  \n";
    leemat(R,c5);
    cout<<"\t\tRo : ";
    presmat(R,c5);           Rox =A[0] ;   Roy =A[1];    Roz =A[2] ;

    for(i=0;i<3;i++)
    {
        if(P[i]>may)
        {
            may=P[i];
            cb=i;
        }
    }
    cout<<"\n\tborrar columna: "<<cb+1;

    //Eliminando coordenada dominante
    cout<<"\n\tNuevos valores \n";
    cout<<"\tPunto A: ";
    c=borracol(A,c,cb);
    presmat(A,c);           x =A[0] ;   y =A[1];// cout<<x1<<","<<y1;
    cout<<"\tPunto B: ";
    c1=borracol(B,c1,cb);
    presmat(B,c1);          x2 =B[0] ;   y2 =B[1];
    cout<<"\tPunto C: ";
    c2=borracol(C,c2,cb);
    presmat(C,c2);          x3 =C[0] ;   y3 =C[1];
    cout<<"\tPunto I: ";
    c4=borracol(I,c4,cb);   xi =I[0] ;   yi =I[1];
    presmat(I,c4);

    //Trasladando el triangulo
    cout<<"\n\tNuevos valores de Traslado \n";
    cout<<"\tPunto A: ";
    rest(A,I,c,c4);
    presmat(A,c);
    cout<<"\tPunto B: ";
    rest(B,I,c,c4);
    presmat(B,c1);
    cout<<"\tPunto C: ";
    rest(C,I,c,c4);
    presmat(C,c2);

    //Calculando NC
    //AB
    m=algrt(A,B,c,c1);
    //cout<<"el valor de nc:"<<m;
    n=algrt(B,C,c,c1);
    //cout<<"el valor de nc:"<<n;
    p=algrt(C,A,c,c1);
    //cout<<"el valor de nc:"<<p;
    NC= m+n+p;
    cout<<"\n\t El valor de NC: "<<NC;
    if(NC%2!=0)
        cout<<"\t (si hay interseccion)";
    else
        cout<<"\t (no hay interseccion)";
}

void Lab13::Line()
{
    glColor3f(1,1,1);

    glBegin(GL_LINES);
    glVertex3f(xi,yi,0);
    glVertex3f(Rox,Roy,Roz);
    glEnd();
}
