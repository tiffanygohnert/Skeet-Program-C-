/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    H file for Vector.  
 ***********************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"
#include <iostream>

/**************************************************
 * VECTOR Class
 **************************************************/
class Vector : public Point
{
private:
   float dx;
   float dy;
   
   public:
   Vector(float x = 0, float y = 0, float dx = 0, float dy = 0);
   Vector(Vector & vectorOrig);
   ~Vector();
   
   const Point & getPoint() const;
   const float getDx() const { return dx; };
   const float getDy() const { return dy; };
   
   const float getMag() const;
   const float getAngle() const;
   
   void setDx(float dx);
   void setDy(float dy);
   //bool hit(Point & rhs);
   void advance();
};

#endif
