/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    This file move the initiates the rifle and moves it right and left. 
 ***********************************************************************/
#include "rifle.h"
#include "uiDraw.h"
#define RIFLE_WIDTH 8
#define RIFLE_HEIGHT 35

/*************************************************
 * RIFLE
 *************************************************/
Rifle::Rifle()
{
//sets the angle of the rifle at 45 degrees. 
   angle = 45;
move(0, 0);
   
}


void Rifle::update()
{   
}

/**************************************************
 * MOVE
 ***************************************************/
void Rifle::move(int left, int right)
{
//moves rifle to the right or to the left
   if (right)
      angle += right;
   if (left)
      angle -= left;

   if (angle < 0)
      angle = 0;
   if (angle > 90)
      angle = 90;
return;
   
}

/****************************************************
 * DRAW
 ****************************************************/
void Rifle::draw()
{
   Point pt = Point();

   //Puts the rifle in the left bottom corner
   pt.setX(pt.getXMax());
   pt.setY(pt.getYMin());
   drawRect(pt, RIFLE_WIDTH, RIFLE_HEIGHT, 90 - this->angle);
return;
   
}
