#pragma once

#include "Common.h"


class Player
{
private:
	int fieldLength, fieldWidth;
	int orientation;
	Point position;
	
public:
	Player(Point startPosition, int startOrientation,
		int length, int width);

	void rotateLeft();
	void rotateRight();
	void goForward();

	Point& getPosition();
	void setPositioin(Point &p);
	void setOrientation(int o);
};

