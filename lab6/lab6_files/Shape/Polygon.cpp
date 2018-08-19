#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Polygon.h"
#include "Shape.h"
using namespace std;

#define pi 3.1415926

Polygon::~Polygon(){}

Polygon::Polygon(string _name, string _colour, int _nPoint, t_point _vertices[100]){

Shape::setName(_name);

Shape::setColour(_colour);

nPoint=_nPoint;

for(int i=0;i<_nPoint;i++){

    vertices[i].x=_vertices[i].x;
    vertices[i].y=_vertices[i].y;
}

}

int Polygon::getpoint(){

return nPoint;

}


void Polygon::print () const {

   Shape::print();

   cout << "polygon";
   for (int i = 0; i < nPoint; i++) {
      cout << " (" << vertices[i].x << ","
              << vertices[i].y << ")";
   }
   cout << endl;
}

void Polygon::scale (float scaleFac) {

   for (int i = 0; i < nPoint; i++) {
      vertices[i].x *= scaleFac;
      vertices[i].y *= scaleFac;
   }

}

float Polygon::computeArea () const {

   float area;

   //area=

   return area;
}

float Polygon::computePerimeter () const {

   float perimeter = 0;

   perimeter=sqrt((vertices[0].x-vertices[nPoint-1].x)*(vertices[0].x-vertices[nPoint-1].x)-(vertices[0].y-vertices[nPoint-1].y)*(vertices[0].y-vertices[nPoint-1].y));

   for(int i=0;i<nPoint-1;i++){

   perimeter+=sqrt((vertices[i+1].x-vertices[i].x)*(vertices[i+1].x-vertices[i].x)-(vertices[i+1].y-vertices[i].y)*(vertices[i+1].y-vertices[i].y));
}
   return perimeter;
}

void Polygon::draw (easygl* window) const {

   window->gl_setcolor(getColour());

   window->gl_fillpoly(vertices,nPoint);
}


bool Polygon::pointInside (float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the triangle center, it is more convenient
   // to also shift the click point so it is an offset from the triangle
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();

   // The test is that a horizontal line (ray) from x = -infinity to the click point
   // will cross (intersect) only one side of triangle to the left of the
   // click point.  If the point is above or below the triangle, the ray will not
   // intersect any triangle sides. If the point is to the left of the triangle
   // the ray will also not intersect any sides to the left of the point.
   // If the point is to the right of the triangle, the ray will intersect
   // two sides of the triangle to its left. Only if the point is inside the
   // triangle will the ray intersect exactly one side to the left of the point.

   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;

   for (int istart = 0; istart < nPoint; istart++) {
      endIndex = (istart + 1) % 3; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (vertices[istart], vertices[endIndex]);
      yDistance = (click.y - vertices[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }

      // We intersect this side if the distance (scaling) along the side vector to
      // get to our "click" y point is between 0 and 1.  Count the first
      // endpoint of the side as being part of the line (distanceAlongVector = 0)
      // but don't count the second endPoint; we'll intersect that point later
      // when we check the next side.
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = vertices[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x )
             sidesToLeft++;
      }
   }

   return (sidesToLeft == 1);
}


// Private helper functions below.  Working out triangle area etc.
// requires some vector math, so these helper functions are useful.

// Return the (x,y) vector between start and end points.
t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}
