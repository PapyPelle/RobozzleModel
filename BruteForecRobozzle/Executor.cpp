#include "Executor.h"

#include <iostream>

void Executor::reset()
{
	player.setOrientation(startOrientation);
	player.setPositioin(field.startPoint);
	field.resetStars();
}


Executor::Executor(int o, Field& f) :
	execution(""), startOrientation(o), field(f),
	player(f.startPoint, o, f.length, f.width)
{}

void Executor::setExecution(const string &e)
{
	reset();
	execution = e;
}


/**
 * 1st symbol : {B, R, G, U}
 * 2nd symbol : {L, F, C}
 * Blue, Red, Green, Uncolor, Left, Forward, Cycle
 */
int Executor::execute() { return execute(0, field.width * field.length, false); }


/**
 * Return 1 if the car hit a wall, 0 if it didn't
 * Return 2 if all stars are collected
 * Return -1 if any error appears
 */
int Executor::execute(int recursivCount, int recursivCap, bool verbose)
{
	if (verbose)
	{
		std::cout << "---- recursion with pos (" << player.getPosition().x
			<< "," << player.getPosition().y << ")" << std::endl;
	}
	if (recursivCount >= recursivCap)
	{
		std::cerr << "ABORTION execute() : too many recursion" << std::endl;
		return -1;
	}
	int execRet = 0;
	int len = execution.size();
	int i = 0;
	while (i < len) {
		Cell color = Cell::wall;
		switch (execution[i])
		{
		case 'B':
			color = Cell::blue;
			break;
		case 'R':
			color = Cell::red;
			break;
		case 'G':
			color = Cell::green;
			break;
		case 'U':
			break;
		case ' ':
			i++;
			continue; break;
		default:
			std::cerr << "ERROR IN Executor : invalid or missing first trace char" << std::endl;
			return -1;
		}
		if (color == Cell::wall || field.getColor(player.getPosition()) == color)
		{
			i += 1;
			if (i >= len)
			{
				std::cerr << "ERROR IN Executor : missing second char, end of the string" << std::endl;
				return -1;
			}
			int isStarFound;
			switch(execution[i])
			{
			case 'F':
				player.goForward();
				if (player.getPosition().x == -1 || player.getPosition().y == -1)
				{
					std::cout << "FELL OFF GRID" << std::endl;
					return 1;
				}
				if (field.getColor(player.getPosition()) == Cell::wall)
				{
					std::cerr << "HIT A WALL" << std::endl;
					return 1;
				}
				isStarFound = field.tryTakeStar(player.getPosition());
				if (verbose && isStarFound == 0) {
					std::cerr << "  found a star" << std::endl;
					field.printStars();
				}
				if (isStarFound == 0 && field.checkStars())
				{
					std::cout << "WIN" << std::endl;
					return 2;
				}
				break;
			case 'L':
				player.rotateLeft();
				break;
			case 'C':
				execRet = execute(++recursivCount, recursivCap, verbose);
				if (execRet == 1 || execRet == -1 || execRet == 2)
				{
					return execRet;
				}
				break;
			default:
				std::cerr << "ERROR IN Executor : invalid or missing second trace char" << std::endl;
				return -1;
			}
			i += 1;
		}
		else if (player.getPosition().x == -1 || field.getColor(player.getPosition()) == Cell::wall)
		{
			return 1;
		}
		else if (field.getColor(player.getPosition()) != color)
		{
			i += 2;
		}
		else
		{
			std::cerr << "We shouldn't be here in executor.execute()" << std::endl;
			return -1;
		
		}

		if (verbose)
		{
			std::cout << "New Position : (" << player.getPosition().x
				<< "," << player.getPosition().y << ")" << std::endl;
		}

	}

	return 0;

}
