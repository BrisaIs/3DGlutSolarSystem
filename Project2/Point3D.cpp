#define XPOS 0
#define YPOS 1
#define ZPOS 2

#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

#ifndef MATH_H
 #define MATH_H
 #include <math.h>
#endif
Point3D::Point3D()
{
	this->point[XPOS] = 0.0;
   this->point[YPOS] = 0.0;
   this->point[ZPOS] = 0.0;
}

Point3D::Point3D(GLdouble x, GLdouble y, GLdouble z)
{
  this->point[XPOS] = x;
  this->point[YPOS] = y;
  this->point[ZPOS] = z;
};

void Point3D::setPx(int px){this->px = px;};
void Point3D::setValue(int i,GLdouble value){this->point[i] = value;};
void Point3D::setPoint3D(GLdouble x, GLdouble y, GLdouble z)
{
	this->point[XPOS] = x;
   this->point[YPOS] = y;
   this->point[ZPOS] = z;
};

int Point3D::getPx(){return px;};
GLdouble* Point3D::getPoint3D(){ return this->point;};
GLdouble Point3D::getValue(int i){return this->point[i];};

void Point3D::polarValues(GLdouble phi, GLdouble theta)
{
  this->point[XPOS] = cos(phi) * sin(theta);
  this->point[YPOS] = sin(phi)*sin(theta);
  this->point[ZPOS] = cos(theta);
}

void Point3D::multValue(GLdouble value)
{
  this->point[XPOS] *= value;
  this->point[YPOS] *= value;
  this->point[ZPOS] *= value;
}

void Point3D::printValues()
{
  printf("% f %f %f\n",this->point[XPOS],this->point[YPOS],this->point[ZPOS] );
}

void Point3D::drawPoint3D(int px)
{
  glPointSize(px);
  glBegin(GL_POINTS);
  	glVertex3d( getValue(XPOS) , getValue(YPOS) , getValue(ZPOS) );
  glEnd();
};

void Point3D::drawPoint3D()
{
  //glColor3f(0.5, 0.5, 0.5);
  glPointSize(this->px);
  glBegin(GL_POINTS);
    glVertex3d( getValue(XPOS) , getValue(YPOS) , getValue(ZPOS) );
  glEnd();
};
