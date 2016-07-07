/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    This file creates and displays the bird on the screen. 
 ***********************************************************************/
#include "bird.h"
#include "uiDraw.h"

/***********************************************************************
 * CONSTRUCTOR
 ***********************************************************************/
Bird::Bird()
{
   position.setX(position.getXMin());                               
   position.setY(random(position.getXMin(), position.getXMax()));   

   // position of birdie. 
   position.setDx(random(3.0, 6.0));
   if (position.getY() > 0)         
      position.setDy(random(-4.0, 0.0)); 
	  
   else                             
      position.setDy(random(0.0, 4.0));
}

/***********************************************************************
 * UPDATE: Updates birds location. 
 ***********************************************************************/
void Bird::update()
{
   if (position.getDx() == 0) 
      ResetB();

   position.advance();

   return;
}

/*************************************************************************
 * DRAW: Draws bird to board. 
 *************************************************************************/
void Bird::draw()
{
   
   int x = position.getX();
   int y = position.getY();
	//bird
   drawCircle(Point(x, y), BIRDIE_SIZE, BIRDIE_SIZE, 0); 
  

   return;
}

/***************************************************************************
 * ResetB: Resets bird. 
 ****************************************************************************/
void Bird::ResetB()
{
   
   position.setX(position.getXMin());                              
   position.setY(random(position.getXMin(), position.getXMax()));   

   
   position.setDx(random(3.0, 6.0));
   if (position.getY() > 0)        
      position.setDy(random(-4.0, 0.0)); 
   
   else                             
   
      position.setDy(random(0.0, 4.0));

   return;
}

/***************************************************************************
 * newBird: Makes sure the bird stays on board. 
 ***************************************************************************/
bool Bird::newBird()
{
   int padding = random(50, 100); 

  
   return (
         (position.getX() > position.getXMax() + padding) ||
         (position.getY() > position.getYMax() + padding) ||
         (position.getY() < position.getYMin() - padding)
   );
}

