#include "Player.h"

Player::Player(Point startPosition, int startOrientation, int length, int width) :
	fieldLength(length), fieldWidth(width),
	orientation(startOrientation), position(startPosition)
{}

/**
 * The position become (-1, -1) if it is out of grid bounds
 */
void Player::goForward()
{
	switch (orientation)
	{
	case Orientation::N:
		position.y -= 1;
		break;
	case Orientation::S:
		position.y += 1;
		break;
	case Orientation::W:
		position.x -= 1;
		break;
	case Orientation::E:
		position.x += 1;
		break;
	default:
		position.x = position.y = -1;
		break;
	}
	if (position.x < 0 || position.x >= fieldWidth
		|| position.y < 0 || position.y >= fieldLength)
	{
		position.x = position.y = -1;
	}
}

void Player::rotateLeft()
{
	orientation = (orientation + Orientation::size - 1) % Orientation::size;
}

void Player::rotateRight()
{
	orientation = (orientation + 1) % Orientation::size;
}

Point& Player::getPosition()
{
	return position;
}

void Player::setPositioin(Point& p)
{
	if (p.x >= 0 && p.x < fieldWidth
		&& p.y >= 0 && p.y < fieldLength)
	{
		position = p;
	}
	else
	{
		return;
	}
}

void Player::setOrientation(int o)
{
	if (o >= 0 && o < Orientation::size)
	{
		orientation = o;
	}
	else
	{
		return;
	}
}