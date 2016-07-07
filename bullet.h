/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    H file for bullet. 
 ***********************************************************************/
#ifndef BULLET_H
#define BULLET_h
#include "vector.h"
#include "rifle.h"

/**************************************************
 * BULLET Class
 **************************************************/
class Bullet
{
  private:
   Vector position;
   
   public:
   Bullet();
   const bool isDead() const { return position.isDead(); };  
   void shoot(Rifle & rifle);
   void update();
   void draw();
   void gone();
};

#endif
