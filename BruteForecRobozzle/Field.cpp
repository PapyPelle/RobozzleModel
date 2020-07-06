#include "Field.h"

#include <iostream>

/**
 * Get the grid, stars, length, width and startPoint infos
 * Parse string one char by one to fill Field attributes
 */
void Field::parseField(const string &data)
{
	Star newStar;
	newStar.isTaken = false;
	int i = 0; int j = 0;
	for (const char c : data) {
		switch (c) {
		case 'W' :
			grid.emplace_back(Cell::wall);
			j += 1;
			break;
		case 'B':
			grid.emplace_back(Cell::blue);
			j += 1;
			break;
		case 'G':
			grid.emplace_back(Cell::green);
			j += 1;
			break;
		case 'R':
			grid.emplace_back(Cell::red);
			j += 1;
			break;
		case 'S' :
			newStar.p.x = j;
			newStar.p.y = i;
			stars.emplace_back(newStar);
			break;
		case 'E' :
			startPoint.x = j;
			startPoint.y = i;
			break;
		case '\n':
			width = j;
			j = 0;
			i += 1;
		default:
			continue;
		}
	}
	length = i;
}

/**
 * Constructor, everything go to 0 or empty;
 */
Field::Field() : stars(), grid()
{
	startPoint.x = startPoint.y = length = width = 0;
}


/**
 * Return the color of the corresponding cell
 */
Cell Field::getColor(Point const &p) const
{
	if (p.x == -1 || p.y == -1)
	{
		std::cout << "WRONG MOVEMENT" << std::endl;
		return Cell::wall;
	}
	return grid[p.x + p.y * width];
}


/**
 * return 0 if a star is found and not taken at this place
 * return 1 if already clamed
 * return -1 if no star are found for this position
 */
int Field::tryTakeStar(Point const &p)
{
	for (Star& s : stars)
	{
		if ((s.p.x == p.x) && (s.p.y == p.y))
		{
			if (s.isTaken)
			{
				return 1;
			}
			else
			{
				s.isTaken = true;
				return 0;
			}
		}
	}
	return -1;
}


/**
 * Return true if all stars have been taken
 */
bool Field::checkStars() const
{
	for (const Star& s : stars)
	{
		if (!s.isTaken)
		{
			return false;
		}
	}
	return true;
}

/**
 * Set back all stars to not taken
 */
void Field::resetStars()
{
	for (Star& s : stars)
	{
		s.isTaken = false;
	}
}

void Field::printStars()
{
	int i = 0;
	for (Star& s : stars)
	{
		i++;
		std::cout << "star " << i << " (" << s.p.x << "," << s.p.y << ")," << s.isTaken << std::endl;
	}
}