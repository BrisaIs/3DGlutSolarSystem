#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
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

class Point3D
{

  private:
    int px;
    GLdouble point[3];

  public:

    Point3D();
    Point3D(GLdouble, GLdouble, GLdouble);

	 void setPx(int);
	 void setValue(int,GLdouble);
   void setPoint3D(GLdouble, GLdouble, GLdouble);
   //void setPoint3D(Point3D);

	  int getPx();
    GLdouble* getPoint3D();
    GLdouble getValue(int);

    void polarValues(GLdouble, GLdouble);
    void multValue(GLdouble);
    void printValues();

   void drawPoint3D(int);
   void drawPoint3D();

};
