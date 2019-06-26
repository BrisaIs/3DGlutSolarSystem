#ifndef SPHERE_H
  #define SPHERE_H
  #include "Sphere3D.h"
#endif

Sphere3D::Sphere3D( GLdouble r , Matrix te )
{
    Point3D t;
    pos = Matrix(te);
    GLdouble phi[25],theta[25];
    for( int i = 1 ; i <= 20 ; i++ )
    {
        phi[i] = GLdouble(2)*M_PI*i / GLdouble(20);
        theta[i] = M_PI*i / GLdouble(20) ;
    }

    for (int i = 1 , p = 0 ; i <= 20 ; i++)
    {
        for (int j = 1; j <= 20 ; j++, p++)
        {
            t.polarValues(phi[j],theta[i]);
            t.multValue(r);
            spherePoints[p].setPoint3D(t.getValue(0), t.getValue(1), t.getValue(2));

		     }
	  }

}

void Sphere3D::drawSphere3D()
{
    for (int i = 0; i< 19 ; i++)
    {
  		glBegin(GL_LINE_LOOP);
  		for (int j = 0 ; j < 20 ; j++)
        glVertex3d( spherePoints[20*i+j].getValue(0) , spherePoints[20*i+j].getValue(1) , spherePoints[20*i+j].getValue(2) );
      glEnd();
        //printf("\nPuntos esfera\n" );
        //spherePoints[20*i+j].printValues();
	   }
}

void Sphere3D::operate( Matrix op )
{
  //op = mRotacion * posSphere => ubicacion
  Matrix res,mPoint;
	for( int i = 0 ; i < 380 ; i++ )
  {
    res.zeroVector3D();
    mPoint.loadPoint3D(spherePoints[i]);
    op.multiplyVector(mPoint,res);
    spherePoints[i].setPoint3D(res.getPosition(0,0,1),res.getPosition(1,0,1),res.getPosition(2,0,1));

  }
}
