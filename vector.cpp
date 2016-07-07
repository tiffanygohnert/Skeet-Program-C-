/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    This file sets positions and speeds. 
 ***********************************************************************/
#include "vector.h"

/*********************************************
 * DEFAULT CONSTRUCTOR
 *********************************************/
Vector::Vector(float x, float y, float dx, float dy)
{
   setX(x);
   setY(y);

   setDx(dx);
   setDy(dy);
}

/*******************************************
 * COPY CONSTRUTCTOR
 *******************************************/
Vector::Vector(Vector & vectorOrig)
{
   setX(vectorOrig.getX());
   setY(vectorOrig.getY());
	setDx(vectorOrig.getDx());
   setDy(vectorOrig.getDy());
}

/***********************************************
 * DESTRUCTOR
 ***********************************************/
Vector::~Vector()
{
}

/************************************************
 * SET DX
 ************************************************/
void Vector::setDx(float dx)
{
   this->dx = dx;
   return;
}

/*************************************************
 * SET DY
 *************************************************/
void Vector::setDy(float dy)
{
   this->dy = dy;
   return;
}

/***************************************************
 * ADVANCE
 ***************************************************/
void Vector::advance()
{
   addX(getDx());
   addY(getDy());

   return;
}


