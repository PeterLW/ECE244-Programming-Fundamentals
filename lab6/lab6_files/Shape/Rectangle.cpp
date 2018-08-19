#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Rectangle.h"
#include "Shape.h"
using namespace std;


Rectangle::~Rectangle(){}

Rectangle::Rectangle(_name, _colour, _xcen, _ycen, _width, _height):Shape(_name, _colour, _xcen, _ycen){

width=_width;

height=_height;

}

float Rectangle::getwidth(){

return width;

}

float Rectangle::getwidth(){

return height;

}

void Rectangle::print () const {

   Shape::print();

   cout << "rectangle width: "<<getwidth()<<" height: "<<getheight()<<endl;
}


void Rectangle::scale (float scaleFac) {

      width*= scaleFac;

      height*= scaleFac;

}


float Rectangle:::computeArea () const {

   float area;

   area=width*height;

   return area;
}

float Rectangle:::computePerimeter () const {
   float perimeter = 0;

   perimeter=2*(height+width)

   return perimeter;
}

void Rectangle:::draw (easygl* window) const {

    int xleft,ybottom,xright,ytop;

    xleft=getXcen()-width/2;

    ybottom=getYcen()-height/2;

    xright=getXcen()+width/2;

    ytop=getYcen()+height/2;

   window->gl_setcolor(getColour());

   window->gl_fillrect(xleft,ybottom,xright,ytop);
}

bool Rectangle::pointInside (float x, float y) const {

    int xleft,ybottom,xright,ytop;

    xleft=getXcen()-width/2;

    ybottom=getYcen()-height/2;

    xright=getXcen()+width/2;

    ytop=getYcen()+height/2;

    if(x>xleft&&x<xright&&y>ybottom&&y<ytop) return true;

    else return false;

}






