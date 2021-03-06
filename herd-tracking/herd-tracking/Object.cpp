#include "Object.h"

Object::Object()
{
	//set values for default constructor
	setType("Object");
	setColor(Scalar(0,0,0));

}

Object::Object(string name){

	setType(name);
	
	if(name=="blue"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

		setHSVmin(Scalar(0, 100, 83));
		setHSVmax(Scalar(32, 172, 168));

		//BGR value for Green:
		setColor(Scalar(255,0,0));

	}
	if(name=="green"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

		setHSVmin(Scalar(162, 26, 198));
		setHSVmax(Scalar(218, 94, 256));

		//BGR value for Yellow:
		setColor(Scalar(0,255,0));

	}
	if(name=="yellow"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

        setHSVmin(Scalar(29, 70, 159));
        setHSVmax(Scalar(68, 170, 211));

		//BGR value for Red:
		setColor(Scalar(0,255,255));

	}
	if(name=="red"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

		setHSVmin(Scalar(0, 179, 33));
        setHSVmax(Scalar(4, 256, 137));

		//BGR value for Red:
		setColor(Scalar(0,0,255));

	}
}



Object::~Object(void)
{
}

Point2f Object::getPos() {
    return Object::curPos;
}

void Object::setPos(float x, float y) {
    Object::setXPos(x);
    Object::setYPos(y);
}


float Object::getXPos(){

	return Object::curPos.x;

}

void Object::setXPos(float x){

	Object::curPos.x = x;

}

float Object::getYPos(){

	return Object::curPos.y;

}

void Object::setYPos(float y){

	Object::curPos.y = y;

}

Scalar Object::getHSVmin(){

	return Object::HSVmin;

}
Scalar Object::getHSVmax(){

	return Object::HSVmax;
}

void Object::setHSVmin(Scalar min){

	Object::HSVmin = min;
}


void Object::setHSVmax(Scalar max){

	Object::HSVmax = max;
}

void Object::setOnScreen (bool is) {
    if (is) {
        Object::isOnScreen = true;
        screenThreshold = OFF_SCREEN_THRESHOLD;
    } else {
        if (screenThreshold == 0) {
            Object::isOnScreen = false;
        } else {
            screenThreshold--;
        }
    }
}