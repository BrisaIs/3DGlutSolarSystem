#define XPOS 0
#define YPOS 1
#define ZPOS 2

#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef MATH_H
    #define MATH_H
    #include <math.h>
  #endif

#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
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

class Matrix
{
    private:
      GLdouble matrix[4][4];
      GLdouble vector [4];
    public:
    	Matrix();
      Matriz(const Matrix&);      
    	~Matrix();

      void setPosition(int,int,int,GLdouble);
      GLdouble getPosition(int,int,int);

      void sumPosition(int,int,int,GLdouble);

      void zeroVector3D();
      void zeroMatrix3D();

      void loadVertex(Point3D);
      void loadOrigin3D(Point3D);
      void loadIdentity3D();
      void loadPoint3D(Point3D);

      void loadTranslation3D(Point3D);
      void loadScale3D(Point3D);
      void loadRotationX3D(GLdouble);
      void loadRotationY3D(GLdouble);
      void loadRotationZ3D(GLdouble);


      void multiplyVector(Matrix,Matrix&);
      void multiply(Matrix,Matrix&);

      void printVector();
      void printMatrix();

};
