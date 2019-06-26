#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif // MATRIX_H
#ifndef MATH_H
 #define MATH_H
 #include <math.h>
#endif

Matrix::Matrix()
{
    zeroVector3D();
    loadIdentity3D();
}
Matrix::Matriz(const Matrix &m2)
{
	*this = m2;
}
Matrix::~Matrix(){}

void Matrix::setPosition(int i, int j,int f, GLdouble value)
{
  if(f == 0)//matriz
    this->matrix[i][j] = value;
  else
    this->vector[i] = value;
}
GLdouble Matrix::getPosition(int i,int j,int f)
{
  GLdouble aux;
  if(f == 0)
    aux = this->matrix[i][j];
  else
    aux = this->vector[i];

  return aux;
}

void Matrix::sumPosition(int i, int j,int f, GLdouble value)
{
  if(f == 0)
    this->matrix[i][j] += value;
  else
    this->vector[i] += value;
}

void Matrix::zeroVector3D()
{
	for(int i=0; i<4; i++)
		this->vector[i] = 0;
}

void Matrix::zeroMatrix3D()
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			this->matrix[i][j] = 0;
	}
}

void Matrix::loadVertex(Point3D vertex)
{
  loadIdentity3D();
  this->matrix[0][3] = vertex.getValue(XPOS);
  this->matrix[1][3] = vertex.getValue(YPOS);
  this->matrix[2][3] = vertex.getValue(ZPOS);
}

void Matrix::loadOrigin3D(Point3D tras)
{
  loadIdentity3D();
    this->matrix[0][3] = -1*tras.getValue(XPOS);
    this->matrix[1][3] = -1*tras.getValue(YPOS);
    this->matrix[2][3] = -1*tras.getValue(ZPOS);
}

void Matrix::loadIdentity3D()
{
  for(int i=0; i<4; i ++)
  {
      for(int j=0; j<4; j++)
      {
          if(i == j)
              this->matrix[i][j] = 1;
          else
              this->matrix[i][j] = 0;
      }
  }
}

void Matrix::loadPoint3D(Point3D origin)
{
    this->vector[0] = origin.getValue(XPOS);
    this->vector[1] = origin.getValue(YPOS);
    this->vector[2] = origin.getValue(ZPOS);
    this->vector[3] = 1;//BIEN
}

void Matrix::loadTranslation3D( Point3D destiny)
{
    loadIdentity3D();
    matrix[0][3] = destiny.getValue(XPOS);
    matrix[1][3] = destiny.getValue(YPOS);
    matrix[2][3] = destiny.getValue(ZPOS);
}

void Matrix::loadScale3D(Point3D scalar)
{
    loadIdentity3D();
    this->matrix[0][0] = scalar.getValue(XPOS);
    this->matrix[1][1] = scalar.getValue(YPOS);
    this->matrix[2][2] = scalar.getValue(ZPOS);
}

void Matrix::loadRotationX3D(GLdouble angle)
{
  loadIdentity3D();
	this->matrix[1][1] = cos(angle);
	this->matrix[1][2] = sin(angle);

	this->matrix[2][1] = -sin(angle);
	this->matrix[2][2] = cos(angle);

}

void Matrix::loadRotationY3D(GLdouble angle)
{
    loadIdentity3D();

  this->matrix[0][0] = cos(angle);
  this->matrix[0][2] = -sin(angle);

  this->matrix[2][0] = sin(angle);
  this->matrix[2][2] = cos(angle);

}

void Matrix::loadRotationZ3D(GLdouble angle)
{
  loadIdentity3D();
  this->matrix[0][0] = cos(angle);
  this->matrix[0][1] = sin(angle);
  this->matrix[1][0] = -sin(angle);
  this->matrix[1][1] = cos(angle);
}

void Matrix::multiplyVector( Matrix matrixP, Matrix &matrixC)
{//matrixP[3][1], double matrixC[3][1]
    for(int i = 0; i < 4; i++)
		{
    	for(int j = 0; j < 4; j++)
      		matrixC.sumPosition(i,0,1, this->matrix[i][j] * matrixP.getPosition(j,0,1));
    }
}

void Matrix::multiply(Matrix matrixI, Matrix &matrizM)
{
	for(int i=0; i<4; i++)
	{
    	for(int j=0; j<4; j++)
			{
      		for(int k=0; k<4; k++)
       			matrizM.sumPosition(i,j,0,this->matrix[i][k] * matrixI.getPosition(k,j,0));
    	}
  	}
}

void Matrix::printVector()
{
  for(int i = 0; i < 4; i++)
  printf("\t[%i] = %f", i,vector[i]);
printf("\n");
}
void Matrix::printMatrix()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j= 0; j <4; j++)
      { printf("[%d][%d] = %f\t", i,j,matrix[i][j]);}
    printf("\n");
  }
}
