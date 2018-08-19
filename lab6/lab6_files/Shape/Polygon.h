#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "Shape.h"
#include "easygl.h"

class Polygon : public Shape {
private:
   // t_point is a structure defined in easygl.h.  It has two members,
   // .x and .y, storing a 2D point.  We store 3 points in relVertex;
   // each is the (x,y) offset of one triangle vertex from the shape
   // center.
   t_point vertices[100];

   int nPoint;

   // Private helper functions.
public:
   Polygon (string _name, string _colour, int _nPoint, t_point _vertices[100]);

   // virtual keyword is optional in all the function declarations below, since
   // the base class Shape already declared them virtual. But it is good
   // practice to repeat it again here, for clarity.
   virtual ~Polygon();
   virtual int getpoint();
   virtual t_point getVecBetweenPoints (t_point start, t_point end) const;

   virtual void print () const;
   virtual void scale (float scaleFac);
   virtual float computeArea () const;
   virtual float computePerimeter () const;
   virtual void draw (easygl* window) const;
   virtual bool pointInside (float x, float y) const;
};


#endif // POLYGON_H_INCLUDED
