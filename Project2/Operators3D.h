#ifndef POINT3D_H
  #define POINT3D_H
  #include "Point3D.h"
#endif

#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif

#ifndef MATH_H
 #define MATH_H
 #include <math.h>
#endif

#ifndef POLYGON3D_H
	#include "Polygon3D.h"
	#define POLYGON3D_H
#endif

class Operators3D
{
	public:
    Operators3D();
		~Operators3D();

    void translation3D(Polygon3D&, Point3D);
    void scale3D(Polygon3D&, Point3D);
    void rotation3D(int,Polygon3D&, GLdouble);
    //void reflexX3D(Polygon3D&);
    //void reflexY3D(Polygon3D&);
    //void reflexXY3D(Polygon3D&);

		Matrix translateSphere( Point3D , Matrix );
		Matrix scaleSphere( Point3D , Matrix );
		Matrix rotateSphere( Matrix , Matrix );
};
