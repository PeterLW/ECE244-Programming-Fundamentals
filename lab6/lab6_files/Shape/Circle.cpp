#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Circle.h"
#include "Shape.h"
using namespace std;

#define pi 3.1415926

Circle::~Circle(){}

Circle::Circle(){}


Circle::Circle(string _name, string _colour, float _xcen, float _ycen, float _radius):Shape(_name, _colour, _xcen, _ycen){

radius=_radius;

}



float Circle::getradius()const{

return radius;

}


void Circle::print () const {

   Shape::print();

   cout << "circle radius: "<<getradius()<<endl;
}

void Circle::scale (float scaleFac) {

radius*=scaleFac;

}

float Circle::computeArea () const {

   float area;

   area=pi*radius*radius;

   return area;
}

float Circle::computePerimeter () const {
   float perimeter = 0;

   perimeter=2*pi*radius;

   return perimeter;
}

void Circle::draw (easygl* window) const {

    int xcen,ycen,r;

    xcen=getXcen();

    ycen=getYcen();

    r=getradius();

   window->gl_setcolor(getColour());

   window->gl_fillarc(xcen,ycen,r,0,360);
}


bool Circle::pointInside (float x, float y) const {

if(sqrt((x-getXcen())*(x-getXcen())+(y-getYcen())*(y-getYcen()))<radius) return true;

else return false;

}
