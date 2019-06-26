#ifndef POLYGON3D_H
	#include "Polygon3D.h"
	#define POLYGON3D_H
#endif

#ifndef UTILITIES_H
	#define UTILITIES_H
	#include "Utilities.h"
#endif

Polygon3D::Polygon3D(int sides, Point3D mainPoints3D[])
{

	int i;
	this->sides = sides;

	/*Se crea la memoria para los puntos base del polígono y se copian
	los valores del arreglo dado*/
	this->mainPoints3D = new Point3D[this->sides];
	this->points = new GLdouble[this->sides * 3];

	for( i = 0; i < this->sides; i++)
		this->mainPoints3D[i] = mainPoints3D[i];

	for( i = 0; i < this->sides * 3; i++)
		this->points[i] = 0.0;
}


void Polygon3D::setVertex(int i,Point3D vertex){this->mainPoints3D[i] = vertex;}

void Polygon3D::setCentroid()
{
/*
	GLdouble x = (getVertex(0).getValue(X)+ getVertex(1).getValue(X)+getVertex(2).getValue(X))/3;
	GLdouble y = (getVertex(0).getValue(Y)+ getVertex(1).getValue(Y)+getVertex(2).getValue(Y))/3;
	GLdouble z = (getVertex(0).getValue(Z)+ getVertex(1).getValue(Z)+getVertex(2).getValue(Z))/3;

	this->centroid.setPoint3D(x,y,z);
*/
/*
	 double signedArea = 0.0;
    double x0 = 0.0; // Current vertex X
    double y0 = 0.0; // Current vertex Y
    double x1 = 0.0; // Next vertex X
    double y1 = 0.0; // Next vertex Y
    double a = 0.0;  // Partial signed area

    // For all vertices except last
    int i=0;
    for (i=0; i< sides-1; ++i)
    {
        x0 = mainPoints3D[i].getX();
        y0 = mainPoints3D[i].getY();
        x1 = mainPoints3D[i+1].getX();
        y1 = mainPoints3D[i+1].getY();

				a = x0*y1 - x1*y0;
        signedArea += a;

        this->centroid.setX((double)this->centroid.getX() + (x0 + x1)*a);
        this->centroid.setY((double)this->centroid.getY()+ (y0 + y1)*a);
    }

    // Do last vertex separately to avoid performing an expensive
    // modulus operation in each iteration.
    x0 = mainPoints3D[i].getX();
    y0 = mainPoints3D[i].getY();
    x1 = mainPoints3D[0].getX();
    y1 = mainPoints3D[0].getY();

    a = x0*y1 - x1*y0;
    signedArea += a;

		this->centroid.setX((double)this->centroid.getX() + (x0 + x1)*a);
		this->centroid.setY((double)this->centroid.getY()+ (y0 + y1)*a);

    signedArea *= 0.5;
    centroid.setX((double)this->centroid.getX() / (6.0*signedArea));
    centroid.setY((double)this->centroid.getY()/ (6.0*signedArea));
*/
}

Point3D Polygon3D::getCentroid(){return this->centroid;}
Point3D Polygon3D::getVertex(int i){return this->mainPoints3D[i];}
int Polygon3D::getSides(){return this->sides;}

void Polygon3D::printMainPoints()
{
	int i;
	for(i = 0; i < this->sides; i++)
        printf("[%f, %f, %f]\n ",mainPoints3D[i].getValue(0), mainPoints3D[i].getValue(1),mainPoints3D[i].getValue(2));


		/*printf("x[%f] y[%f] z[%f]\n", this->getVertex(i).getValue(X),
		this->getVertex(i).getValue(Y),this->getVertex(i).getValue(Z) );*/
}

void Polygon3D::generateArray()
{
	int k = 0;
	for(int i = 0; i < this->sides; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			this->points[k] = mainPoints3D[i].getValue(j);
			//printf("%f\n", mainPoints3D[i].getValue(j));
			k++;
		}
	}
}
void Polygon3D::printPointsArray()
{
	for(int i = 0; i < this->sides * 3; i++)
		printf("[%d] = %f\n",i,this->points[i] );
}

void Polygon3D::drawPolygon3D()
{
	glColor3f(0.5, 0.5, 0.5);
	generateArray();
	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_DOUBLE, 0, points);
	   glDrawArrays(GL_LINE_LOOP, 0, this->sides);
	glDisableClientState(GL_VERTEX_ARRAY);
}

Polygon3D::~Polygon3D()
{
	delete[] mainPoints3D;
	delete[] points;
}
