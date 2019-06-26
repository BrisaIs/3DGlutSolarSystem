/*#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif
*/
#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

#ifndef POLYGON3D_H
	#define POLYGON3D_H
	#include "Polygon3D.h"
#endif

#ifndef GLUT
 #define GLUT
 #include <GL/glut.h>
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

#ifndef SOLARSYSTEM_H
  #define SOLARSYSTEM_H
  #include "SolarSystem.h"
#endif

int width = 500;
int heigth = 500;

SolarSystem viaLactea;

 void init();
 void idle(void);
 void reshape(int width, int heigth);

 void drawAxis();
 void draw();

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowPosition(250, 120);
    glutInitWindowSize(width, heigth);
    glutCreateWindow("Proyecto 2");

    init();
    glutDisplayFunc(draw);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective(110,width/heigth, 0.01,100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(15,15,15,0,0,0,0,1,0);
}

void idle(void)
{
    Sleep(20);
    glutPostRedisplay();
}

void reshape(int width, int heigth)
{
  glViewport(0,0,width,heigth);
}

void drawAxis()
{
  glLineWidth(1);
  glColor3f(0.0, 0.5, 1.0);
  glBegin(GL_LINES);
    glVertex3d(-1000.0, 0.0, 0.0);
    glVertex3d(1000.0, 0.0, 0.0);
  glEnd();

  glColor3f(1.0, 0.0, 1.0);
  glBegin(GL_LINES);
    glVertex3d(0.0, -1000.0, 0.0);
    glVertex3d(0.0, 1000.0, 0.0);
  glEnd();

  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, -1000.0);
    glVertex3d(0.0, 0.0, 1000.0);
  glEnd();
}

void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);

    Point3D mainPoints3D[3], pT,pS;
     Operators3D op;

  mainPoints3D[0].setPoint3D((GLdouble) 0, (GLdouble) 0, (GLdouble) 0);
  mainPoints3D[1].setPoint3D((GLdouble) 7, (GLdouble) 0, (GLdouble) 0);
  mainPoints3D[2].setPoint3D((GLdouble) 3, (GLdouble) 6, (GLdouble) 0);

  Polygon3D p1(3, mainPoints3D);

  pT.setPoint3D(1.0,1.0,1.0);
  pS.setPoint3D(2.0,2.0,2.0);

  drawAxis();

  //p1.drawPolygon3D();
  /*
    //p1.printPointsArray();
    //Sleep(300);

    glutPostRedisplay();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
*/

    //op.translation3D(p1,pT);
    //op.scale3D(p1,pS);
    //op.rotation2D(p1,90.0);
    //op.reflexX2D(p1);
    //op.reflexY2D(p1);
    //op.reflexXY2D(p1);
  //  p1.drawPolygon3D();
  //p1.printMainPoints();

  //printf("Translate OK C: !\n");


  drawAxis();
  viaLactea.sun();
  viaLactea.sumAngles();

  glFlush();
  glutSwapBuffers();

}
