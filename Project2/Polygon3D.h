#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef ESSE
    #define ESSE
    #include <stdio.h>
    #include <stdlib.h>
#endif

#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

class Polygon3D
{
	private:
		int sides;
		//double distance; //Se asume que se trabaja con poligonos regulares
		Point3D centroid;
		//int distances[sides];
		Point3D *mainPoints3D;
		//Line3D *awns;
    GLdouble *points;
	public:
    //Polygon3D();
		Polygon3D(int,Point3D[]);
		~Polygon3D();

    void setVertex(int,Point3D);
    void setCentroid();

    Point3D getVertex(int);
    Point3D getCentroid();
    int getSides();

	 void printMainPoints();
	 void generateArray();
   void printPointsArray();
	 void drawPolygon3D();
};
