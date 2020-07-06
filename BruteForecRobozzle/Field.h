#pragma once

#include <vector>
#include <string>

#include "Common.h"

using namespace std;

struct Star
{
    Point p;
    bool isTaken;
};

/**
* Depict the field for the player
* (x,y) : x go right, y go down ; (0,0) top left corner
*/
class Field
{
public:
    int length;
    int width;
    Point startPoint;
private:
    vector<Star> stars;
    vector<Cell> grid;

public:
    Field();

    void parseField(const string &data);

    Cell getColor(Point const &point) const;

    int tryTakeStar(Point const &point);

    bool checkStars() const;

    void resetStars();

    void printStars();


};