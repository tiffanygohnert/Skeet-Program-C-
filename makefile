###############################################################
# Program:
#     Project 2, Skeet	
#     Brother McCracken, CS165
# Author:
#     Tiffany Gohnert
# Summary:
#     This is the game of Skeet. The user must shot the rifle
# and try to hit the bird. 
#
#     Estimated:  10.0 hrs
#     Actual:     15.0 hrs
#       I couldn't figure out how to get the rifle to register 
# when it hit the bird. I tried several methods. 
###############################################################

###############################################################
# Programs:
#    Skeet:         The game
#    uiTest:       Simple driver program for the drawing interface
###############################################################
skeet : skeet.o uiInteract.o uiDraw.o point.o bird.o rifle.o vector.o bullet.o
	g++ -o skeet skeet.o uiInteract.o uiDraw.o point.o vector.o bird.o rifle.o bullet.o -lglut -lGLU
	tar -cf projct2.tar *.cpp *.h makefile

uiTest : uiTest.o uiDraw.o uiInteract.o point.o
	g++ -o uiTest uiTest.o uiDraw.o uiInteract.o point.o -lglut -lGLU

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    uiTest.o      Driver program for uiDraw and uiTest
#    skeet.o        Only the greatest game ever! (and it was for 20 years)  
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

vector.o : vector.cpp vector.h point.h
	g++ -c vector.cpp

uiTest.o : uiTest.cpp point.h uiDraw.h uiInteract.h
	g++ -c uiTest.cpp

skeet.o : skeet.cpp uiDraw.h uiInteract.h point.h
	g++ -c skeet.cpp

bird.o : bird.h bird.cpp point.h uiDraw.h
	g++ -c bird.cpp

rifle.o : rifle.cpp rifle.h point.h
	g++ -c rifle.cpp

bullet.o : bullet.cpp bullet.h
	g++ -c bullet.cpp

###############################################################
# General rules
###############################################################
clean :
	rm uiTest project2 *.o *.tar

all :  uiTest skeet

