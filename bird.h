/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    H file for bird. 
 ***********************************************************************/
#include "point.h"
#include "vector.h"

#define BIRDIE_SIZE 20
/**************************************************
 * BIRD Class
 **************************************************/
class Bird
{
  private:
   Vector position;
     public:
   Bird();           
   void update();    
   void draw();
   void ResetB();
   bool newBird();
};
