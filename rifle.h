/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    H file for the rifle. 
 ***********************************************************************/
#ifndef RIFLE_H
#define RIFLE_H
#include "point.h"

/**************************************************
 * RIFLE Class
 **************************************************/
class Rifle
{
  private:
   int angle;

  public:
   Rifle();
   void update();
   void draw();
   void move(int left, int right);
   const int getAngle() const { return angle; };
};

#endif
