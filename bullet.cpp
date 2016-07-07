/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    This file puts the bullet on the screen. 
 ***********************************************************************/
#include "bullet.h"
#include "uiDraw.h"
#include <cmath>
#define SPEED 10
#define deg2rad(value) ((M_PI / 180) * (value))

/*******************************************************
 * CONSTRUCTOR
 *******************************************************/
Bullet::Bullet()
{
gone();
position.setCheck(true);//false????? If false it doesn't fire. 
}

/*********************************************************
 * SHOOT: Loads rifle
 **********************************************************/
void Bullet::shoot(Rifle & rifle)
{
   position.setX(position.getXMax() - 1);
   position.setY(position.getYMin() + 1);

   position.setDx(-cos(deg2rad((float)rifle.getAngle())) * SPEED);
   position.setDy( sin(deg2rad((float)rifle.getAngle())) * SPEED);
   position.setDead(false);   
return;
}

/************************************************************
 * UPDATE: Updates the board if bird dies. 
 ************************************************************/
void Bullet::update()
{
   if (isDead())
      return;
position.advance();

if (position.isDead())
      gone();
}

/*************************************************************
 * DRAW: Puts the bullets on the screen. 
 *************************************************************/
void Bullet::draw()
{
   if (isDead())
      return;

   //sets a new bullet
   drawDot(Point(position.getX(),position.getY()));
return;
}   
/**************************************************************
 * GONE: The bullet's gone. 
 **************************************************************/
void Bullet::gone()
{
position.setDead(true);
}   



