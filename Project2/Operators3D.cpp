#ifndef OPERATORS3D_H
  #define OPERATORS3D_H
  #include "Operators3D.h"
#endif

Operators3D::Operators3D(){}
Operators3D::~Operators3D(){}

void Operators3D::translation3D(Polygon3D &poli, Point3D pT)
{
    Point3D aux;
   Matrix matrixT, matrixP, matrixC;

   matrixT.loadTranslation3D(pT);

   for(int i = 0; i < poli.getSides(); i++)
   {
     matrixP.loadPoint3D(poli.getVertex(i));
     matrixC.zeroVector3D();
     matrixT.multiplyVector(matrixP,matrixC);
     //matrixC.printVector();
     aux.setPoint3D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1), matrixC.getPosition(2,0,1));
     poli.setVertex(i,aux);
   }

}

void Operators3D::scale3D(Polygon3D &poli, Point3D scalar)
{
    Point3D aux;
   Matrix matrixO, matrixI, matrixE,matrixM, matrixR,matrixP, matrixC;

   matrixE.loadScale3D(scalar);
   //matrixE.printMatrix();
   for(int i = 0; i < poli.getSides(); i++)
   {
       matrixO.loadOrigin3D(poli.getVertex(i));
       //printf("Origen %d\n",i );
       //matrixO.printMatrix();

       matrixI.loadVertex(poli.getVertex(i));
       //printf("Original %d\n",i );
       //matrixI.printMatrix();

       matrixR.zeroMatrix3D();
       matrixO.multiply(matrixE, matrixR);
       //printf("Origen x Escalar %d\n",i );
       //matrixR.printMatrix();

       matrixM.zeroMatrix3D();
       matrixR.multiply(matrixI, matrixM);
       //printf("Resultado x original %d\n",i );
       //matrixM.printMatrix();

       matrixP.loadPoint3D(poli.getVertex(i));
       //printf("Vertice %d\n",i );
       //matrixP.printVector();

       matrixC.zeroVector3D();
       matrixM.multiplyVector(matrixP, matrixC);
       //printf("Escalado %d\n",i );
      // matrixC.printVector();
       aux.setPoint3D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1), matrixC.getPosition(2,0,1));
       poli.setVertex(i,aux);

   }
   //poli.generateLines2D();
}

void Operators3D::rotation3D(int axis , Polygon3D &poli, GLdouble angle)
{
    Point3D aux;
   Matrix matrixO, matrixI, matrixRotation, matrixM, matrixR, matrixP, matrixC;

   switch(axis)
   {
     case 0:
        matrixRotation.loadRotationX3D(angle);
        break;

      case 1:
         matrixRotation.loadRotationY3D(angle);
         break;

       case 2:
          matrixRotation.loadRotationZ3D(angle);
          break;
   }

   for(int i = 0; i < poli.getSides(); i++)
   {
     matrixO.loadOrigin3D(poli.getVertex(i));
     matrixI.loadVertex( poli.getVertex(i));

     matrixR.zeroMatrix3D();
     matrixRotation.multiply(matrixO, matrixR);

     matrixM.zeroMatrix3D();
     matrixR.multiply(matrixI, matrixM);

     matrixP.loadPoint3D(poli.getVertex(i));
     matrixC.zeroVector3D();
     matrixM.multiplyVector(matrixP, matrixC);

     aux.setPoint3D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1), matrixC.getPosition(2,0,1));
     poli.setVertex(i,aux);
   }
}


Matrix Operators3D::translateSphere( Point3D pT , Matrix base)
{
  Matrix trans, res;
  res.zeroMatrix3D();
  trans.loadTranslation3D(pT);
  trans.multiply(base,res);

  return res;

}

Matrix Operators3D::scaleSphere(  Point3D pS , Matrix base)
{
  Matrix es, res;
  res.zeroMatrix3D();
  es.loadScale3D(pS);
  es.multiply(base,res);

  return res;
}

Matrix Operators3D::rotateSphere( Matrix rot, Matrix base )
{
  Matrix res;
  res.zeroMatrix3D();
  rot.multiply(base,res);

  return res;
}
