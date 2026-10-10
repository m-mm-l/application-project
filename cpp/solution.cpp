
#include "solution.hpp"

#include <ostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

// generic main robot setters/getters def's

float Robot::getCenterX() const{
	return this->centerPosX;
}
float Robot::getCenterY() const{
	return this->centerPosY;
}
bool Robot::getCircular() const
{
    return isCircular;
}

void Robot::getAttributes(float* const attr1, float* const attr2) const
{
    // useless, really .. just a standin to be overridden. has to exist though :P or else g++ gets Mad
}

void Robot::setCenter(float centerPosX, float centerPosY)
{
    this->centerPosX = centerPosX;
    this->centerPosY = centerPosY;
}

void Robot::setCircular(bool c)
{
    this->isCircular = c;
}

// == rect robot setters/getters def

void RectangularRobot::setDimensions(float width, float height)
{
    this->wid = width;
    this->h = height;
}

void RectangularRobot::getAttributes(float* const rectWidth, float* const rectHeight) const
{
    *rectWidth = wid;
    *rectHeight = h;
}


// circular robot setters/getters def
void CircularRobot::setRadius(float rad)
{
    this->rad = rad;
}

// replaces getRadius with definition for virtual function getAttributes, shouldddd make calculating collisions easier (or, actually possible .. )
// const keyword necessary :p ist been a while since i took cs1b
void  CircularRobot::getAttributes(float* const radius, float* const na) const
{
    *radius = rad;
    // nothing just a stand-in to override getAttributes generic :P
}


// will determine if each robot is circular, performs different Things if so
bool isColliding(const Robot& a, const Robot& b)
{
	if(a.getCircular() && b.getCircular()) // both circular; create a vector of both circle's X,Y coords, take magnitude, check if <= radii added together.
	{
	    float aX = a.getCenterX();
		float aY = a.getCenterY();

		float bX = b.getCenterX();
		float bY = b.getCenterY();

		float* const aRadPtr = new float;
		float* const bRadPtr = new float;

		float aRadius = 0.0;
		float bRadius = 0.0;

		std::vector<float> vecCoordDiff = {}; // will resolve to the average of the x values and y values, the magnitude will be taken, and compared to the sum of the two radii
		float vecCoordDiffMag;                // magnitude of the (math) vector of the coordinates of both circles

		a.getAttributes(aRadPtr, aRadPtr); // arad will be overwritten, ignore the second attribute, currently cant figure out how to navigate this w/o virtual function overriding
		aRadius = *aRadPtr;           // reassigning the pointer to a static variable, so it can be deleted. A's Radius now stored in aRadius
		delete aRadPtr;

		b.getAttributes(bRadPtr, bRadPtr); // bRad now overwritten
		bRadius = *bRadPtr;
		delete bRadPtr;

		// now the math can actually happen :)

		vecCoordDiff= {fabsf(bX-aX), fabsf(bY-aY)};
		vecCoordDiffMag = sqrt(pow(vecCoordDiff[0], 2) + pow(vecCoordDiff[1], 2));   // something pythagorean is afoot, very inefficient but thats Fine

		// basically, if the magnitude of the vector made between the (center of the) two circles is less than the radii of the two circles added together, they have collided.
		if(vecCoordDiffMag <= (aRadius + bRadius)) return true;
		else return false;
	}
	else if(a.getCircular() && !b.getCircular())	// a is circular, b is rectangular
	{// treat A as above, treat B as something different
	    float aX = a.getCenterX();
		float aY = a.getCenterY();

		float bX = b.getCenterX();
		float bY = b.getCenterY();


		float* const aRadPtr = new float;
		float aRadius = 0.0;

		a.getAttributes(aRadPtr, aRadPtr);      // gets the radius from the circular robot, stores in aradptr, saves value of aradptr to aRadius
		aRadius = *aRadPtr;
		delete aRadPtr;

		std::vector<float> rectCoords = {};     // will store the coordinates for the corners of the rectangle.
		float rectWidth = 0.0;
		float rectHeight = 0.0;

		float* const rectWPtr = new float;
		float* const rectHPtr = new float;
		b.getAttributes(rectWPtr, rectHPtr);
		rectWidth = *rectWPtr;
		rectHeight = *rectHPtr;
		delete rectWPtr;
		delete rectHPtr;



		rectCoords = drawRectCoords(bX, bY, rectWidth, rectHeight); //

		return checkCircleRect(rectCoords, aX, aY, aRadius); // logic for if the circle falls within the rectangle
	}


	else if (!a.getCircular() && b.getCircular()){   // a is rectangular, b is circular

        float aX = a.getCenterX();
        float aY = a.getCenterY();

        float bX = b.getCenterX();
        float bY = b.getCenterY();

        float* const bRadPtr = new float;
        float bRadius = 0.0;

        std::vector<float> rectCoords = {};     // will store the coordinates for the corners of the rectangle.
		float rectWidth = 0.0;
		float rectHeight = 0.0;

		float* const rectWPtr = new float;      // gets the rectangular width/height info from A
		float* const rectHPtr = new float;
		a.getAttributes(rectWPtr, rectHPtr);
		rectWidth = *rectWPtr;
		rectHeight = *rectHPtr;         // more pointer funnies to adhere to const requirements
		delete rectWPtr;
		delete rectHPtr;

        b.getAttributes(bRadPtr, bRadPtr);      // gets the radius from the circular robot, stores in aradptr, saves value of aradptr to aRadius
        bRadius = *bRadPtr;
        delete bRadPtr;
        rectCoords = drawRectCoords(aX, aY, rectWidth, rectHeight); //

        return checkCircleRect(rectCoords, bX, bY, bRadius); // logic for if the circle falls within the rectangle
	}

	else{		// both are rectangular,
        float aX = a.getCenterX();
        float aY = a.getCenterY();

        float bX = b.getCenterX();
        float bY = b.getCenterY();

        std::vector<float> aRectCoords = {};
        std::vector<float> bRectCoords = {};
        // same ptr(s) can be used twice
        float* const rectWPtr = new float;      // gets the rectangular width/height info from A
		float* const rectHPtr = new float;
		a.getAttributes(rectWPtr, rectHPtr);
		float aRectWidth = *rectWPtr;
		float aRectHeight = *rectHPtr;

		// time for b
		b.getAttributes(rectWPtr, rectHPtr);
		float bRectWidth = *rectWPtr;
		float bRectHeight = *rectHPtr;

		delete rectHPtr;
		delete rectWPtr;

		aRectCoords = drawRectCoords(aX, aY, aRectWidth, aRectHeight);      // draws the coords of both to the given vecs
		bRectCoords = drawRectCoords(bX, bY, bRectWidth, bRectHeight);


		// isOverlapping = (x1min < x2max AND x2min < x1max AND y1min < y2max AND y2min < y1max)
		// interface for rectCoords. (xmin, ymin, xmax, ymax)
		return (aRectCoords[0] <= bRectCoords[2] && bRectCoords[0] <= aRectCoords[2] && aRectCoords[1] <= bRectCoords[3] && bRectCoords[1] <= aRectCoords[3]);

        // TODO: write a function to detect the collision of two rectangles. shouldnt be Too bad
	}

}

std::vector<float>drawRectCoords (float centerx, float centery, float wid, float h)
{
	float x1 = (centerx - (0.5*wid));
	float y1 = (centery - (0.5*h));
	float x2 = (centerx + (0.5*wid));
	float y2 = (centery + (0.5*h));

	return {x1, y1, x2,y2}; // bottom left and top right of rectangle.
}

bool checkCircleRect(std::vector<float> rectCoords, float cX, float cY, float cR){
    // clamp is supposed to be lo -> high, adjust.
    float closestX = std::clamp(cX, rectCoords[0], rectCoords[2]);
    float closestY = std::clamp(cY, rectCoords[1], rectCoords[3]);  // uses clamp to find the closest x and y values to the circle on the rectangle
    float dX = cX - closestX;
    float dY = cY - closestY;
    return (sqrt((dX*dX)+(dY*dY)) <= cR);// pythag to determine if the distance from the closest point on the rectangle to  the center of the circle is less than the radius of the circle :)
}
