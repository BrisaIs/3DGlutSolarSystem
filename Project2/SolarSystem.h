#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif

#ifndef SPHERE_H
  #define SPHERE_H
  #include "Sphere3D.h"
#endif

#ifndef OPERATORS3D_H
  #define OPERATORS3D_H
  #include "Operators3D.h"
#endif

#include <cstdio>
#include <stack>

using namespace std;

class SolarSystem
{
  private:
    GLdouble anS;
    GLdouble anM;
    GLdouble anV;
    GLdouble anT;
    GLdouble anMa;
    GLdouble anJ;
    GLdouble anSa;
    GLdouble anLu;

  public:
    SolarSystem();
    ~SolarSystem();

    stack<Matrix> pila;
    Matrix mGlobal;

    void moon();
    void moonM1();
    void mercury();
    void venus();
    void earth();
    void mars();
    void sun();

    void sumAngles();
};
