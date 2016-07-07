/***********************************************************************
 * Program:
 *    Project 2, Skeet
 * Author:
 *    Tiffany Gohnert
 * Summary:
 *    This is a simple game that allows the user to shot a bird. 
 ***********************************************************************/

#include <iostream>
#include <vector>
#include "uiInteract.h"  
#include "uiDraw.h"      
#include "point.h"       
#include "bird.h"        
#include "bullet.h" 
#include "rifle.h"
       
#define number_B 5          //Max of 5 bullets on the screen
//#define SKEETRADIUS 10		// Radius of the bird
//#define BULLETRADIUS 2		// Radius of the bullet     


/**************************************************
 * SKEET Class
 **************************************************/
class Skeet
{
  private:
   Rifle rifle;                  
   Bird bird;                    
   Bullet bullets[number_B];  
   unsigned int bam;             
   unsigned int miss;  
	
	public:
   Skeet();                      
   ~Skeet();                     
   void setup();
   void update(const Interface *pUI);
   void draw();
   void setBam(unsigned int value) {bam = value;}
   void setMiss(unsigned int value) {miss = value;}
   
   
};

/****************************************************
 * CONSTRUCTOR
 ****************************************************/
Skeet::Skeet()
{
   bam = 0;
   miss = 0;
}

/****************************************************
 * DESTRUCTOR
 ****************************************************/
Skeet::~Skeet()
{
}
/******************************************************
 * UPDATE: Causes everything to move to the next frame. 
 *******************************************************/
void Skeet::update(const Interface *pUI)
{
   bird.update();
   if (bird.newBird())
   {
      bird.ResetB();
      miss++;
   }

   rifle.update();
for(int i = 0; i < number_B; ++i)
   {
      bullets[i].update();
   }
//can't shoot more than 5 bullets
   if (pUI->isSpace())
      for(int i = 0; i < number_B; ++i)
         if (bullets[i].isDead())
         {
            bullets[i].shoot(rifle);
            i = number_B;
         }

   //moves rifle left and right
   if (pUI->isLeft() || pUI->isRight())
      rifle.move(pUI->isLeft(),pUI->isRight());
 return;
  
}
/******************************************************
 * DRAW: Draws game. 
 *******************************************************/
void Skeet::draw()
{
   bird.draw();
   rifle.draw();

   for(int i = 0; i < number_B; ++i)
   {
      if (!bullets[i].isDead())  
         bullets[i].draw();
   }

   
   Point pt1 = Point(pt1.getXMin()+10,pt1.getYMax()-10);
   drawNumber(pt1,bam);   
   Point pt2 = Point(pt2.getXMax()-100,pt2.getYMax()-10);
   drawNumber(pt2,miss);  
}

/*********************************************
 * CALL: Creates the interface pointer and void 
 * pointer.
 *********************************************/
void call(const Interface *pUI, void *p)
{
   Skeet *game = (Skeet *)p;
   game->update(pUI);
   game->draw();

   return;
}

/*********************************
 * HIT: Hits the bird.  
 *********************************/
//bool Point::hit(Point & rhs)
//{
  //   if ((std::abs(getX() - this->getX()) <= SKEETRADIUS &&
    //     std::abs(getY() - this->getY()) <= SKEETRADIUS) ||
      //   (std::abs(getX() - this->getX()) <= BULLETRADIUS &&
        // std::abs(getY() - this->getY()) <= BULLETRADIUS ))
      //return true;
   //else
     //return false;}

/*********************************
 * MAIN: Runs skeet.  
 *********************************/
int main(int argc, char **argv)
{
   Interface ui(argc, argv, "Skeet Game");
   Skeet game;
   
   ui.run(call, (void *)&game);
   
   return 0;
}


