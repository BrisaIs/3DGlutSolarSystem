#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif

#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef MATH_H
    #define MATH_H
    #include <math.h>
  #endif

  #ifndef GLUT
    #define GLUT
    #include <GL/glut.h>
  #endif

  #ifndef ESSE
      #define ESSE
      #include <stdio.h>
      #include <stdlib.h>
  #endif

#define M_PI		3.14159265358979323846

class Sphere3D
{
	public:
	    Point3D spherePoints[500];
	    Matrix pos;
	    Sphere3D(GLdouble , Matrix );
      void drawSphere3D();
      void operate( Matrix );
};
