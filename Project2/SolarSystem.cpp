#ifndef SOLARSYSTEM_H
  #define SOLARSYSTEM_H
  #include "SolarSystem.h"
#endif
SolarSystem::SolarSystem()
{
  this->anS = 0.0;
  this->anM = 0.0;
  this->anV = 0.0;
  this->anT = 0.0;
  this->anMa = 0.0;
  this->anJ = 0.0;
  this->anSa = 0.0;
  this->anLu = 0.0;
}
SolarSystem::~SolarSystem(){}

void SolarSystem::moon()
{
    Sphere3D luna( 0.4 ,this->mGlobal );
    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anT);
    luna.operate( op.rotateSphere( rot , luna.pos ) );
    glColor3f(0.6,0.6,0.6);
    luna.drawSphere3D();
}

void SolarSystem::moonM1()
{
    Sphere3D luna( 0.4 ,this->mGlobal );
    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anMa);
    luna.operate( op.rotateSphere( rot , luna.pos ) );
    glColor3f(0.6,0.6,0.6);
    luna.drawSphere3D();
}

void SolarSystem::mercury()
{
    Sphere3D mercurio( 1.0 , this->mGlobal );
    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anM);
    mercurio.operate( op.rotateSphere( rot , mercurio.pos ) );
    glColor3f(0.3,0.3,0.3);
    mercurio.drawSphere3D();
}

void SolarSystem::venus()
{
    Sphere3D v( 1.3 ,this->mGlobal );
    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anV);
    v.operate( op.rotateSphere( rot , v.pos ) );
    glColor3f(0.9,0.3,0.2);
    v.drawSphere3D();
}

void SolarSystem::earth()
{
    Point3D aux;
    Sphere3D tierra( 2.0 ,this->mGlobal );
    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anT);
    tierra.operate( op.rotateSphere( rot , tierra.pos ) );
    glColor3f(0.0,0.8,0.8);
    tierra.drawSphere3D();

    //mGlobal.printMatrix();

    pila.push(mGlobal);
    aux.setPoint3D(3.0,0.0,0.0);
   this->mGlobal = op.translateSphere(aux , tierra.pos );
    moon();
   this->mGlobal = pila.top();
    pila.pop();
}

void SolarSystem::mars()
{
    Point3D aux;
    Sphere3D marte( 2.5 ,this->mGlobal );

    Matrix rot;
    Operators3D op;
    rot.loadRotationY3D(anMa);
    marte.operate( op.rotateSphere( rot , marte.pos ) );
    glColor3f(3.0,0.0,0.0);
    marte.drawSphere3D();

    pila.push(mGlobal);
    aux.setPoint3D(3.7,0.5,0.0);
   this->mGlobal = op.translateSphere( aux, marte.pos );

    moonM1();
   this->mGlobal = pila.top();
    pila.pop();

    pila.push(mGlobal);
    aux.setPoint3D(-3.7,0.5,0.0);
   this->mGlobal = op.translateSphere(aux , marte.pos );

    moonM1();
   this->mGlobal = pila.top();
    pila.pop();
}

void SolarSystem::sun()
{
    Point3D aux;
    Sphere3D sol( 4.0 ,this->mGlobal );
    Matrix rot;
    Operators3D op;

    rot.loadRotationY3D(anS);
    sol.operate( op.rotateSphere( rot , sol.pos ) );
    glColor3f(0.9,0.9,0.0);
    sol.drawSphere3D();
    pila.push(this->mGlobal);

    aux.setPoint3D(6.0 , 0.0 , 0.0);
   this->mGlobal.loadTranslation3D( aux );
    mercury();
   this->mGlobal = pila.top();
    pila.pop();

    pila.push(this->mGlobal);
    aux.setPoint3D( 9.0 , 0.0 , 0.0 );
   this->mGlobal.loadTranslation3D(aux);
    venus();
   this->mGlobal = pila.top();
    pila.pop();

    pila.push(mGlobal);
    aux.setPoint3D( 12.0 , 0.0 , 0.0);
   this->mGlobal.loadTranslation3D( aux );
    earth();
   this->mGlobal = pila.top();
    pila.pop();

    pila.push(this->mGlobal);
    aux.setPoint3D( 17.0 , 0.0 , 0.0 );
   this->mGlobal.loadTranslation3D( aux);
    mars();
   this->mGlobal = pila.top();
    pila.pop();

}

void SolarSystem::sumAngles()
{
  this->anS += .01;
  this->anM += .04;
  this->anV += .02;
  this->anT += .015;
  this->anLu += .01;
  this->anMa += .012;
}
