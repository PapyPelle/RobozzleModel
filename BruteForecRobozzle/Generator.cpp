#include "Generator.h"

#include <iostream>

Generator::Generator() 
{
	reset();
	int i, ret;
	for (i = 0; i < execLen; i++) {
		initTrigger(i);
		ret = choseNextMove(i);
		if (ret != 1)
		{
			std::cerr << "ERROR impossible to initialize execution tab" << std::endl;
			return;
		}
	}
}

string Generator::getExecution() const
{
	string ret = "";
	for (int m : execution)
	{
		if (m >= 0 && m < moveLen)
			ret += possible_moves[m];
	}
	return ret;
}

void Generator::reset()
{
	for (int i = 0; i < execLen; i++)
	{
		execution[i] = -1;
	}
	for (int i = 0; i < execLen; i++)
	{
		for (int j = 0; j < moveLen; j++)
		{
			trigger[i][j] = false;
		}
	}
	for (int j = 0; j < moveLen; j++)
	{
		counter[j] = 0;
	}
}


// return 0 while there is still possibilities
int Generator::generateNextExecution()
{
	int ret = choseNextMove(execLen-1);
	if (ret == 0)
	{
		std::cerr << "end of the research" << std::endl;
		return 1;
	}
	return 0;
}

// if next move is found, return 1
// if there is no more moves available at execution 0 , return 0
int Generator::choseNextMove(int i)
{
	if (execution[i] != -1)
	{
		counter[execution[i]] -= 1;
	}
	for (int k = 0; k < moveLen; k++)
	{
		if (!trigger[i][k] && counter[k] < max_counter[k])
		{
			execution[i] = k;
			trigger[i][k] = true;
			counter[execution[i]] += 1;
			return 1;
		}
	}
	// if no moves are available (ie all have been tested or not possible)
	execution[i] = -1;
	if (i > 0)
	{
		if (choseNextMove(i - 1) == 0)
			return 0;
		initTrigger(i);
		return choseNextMove(i);
	}
	else
	{
		return 0; // end of the research
	}
}


void Generator::initTrigger(int i)
{
	if (i >= execLen)
	{
		std::cerr << "wtf dans intTrigger" << std::endl;
		return;
	}

	for (int k = 0; k < moveLen; k++)
	{
		trigger[i][k] = false;
	}


	// don't cycle on first move
	if (i == 0)
	{
		trigger[0][5] = true;
		trigger[0][6] = true;
	}
	
}

void Generator::printCounter()
{
	for (int i = 0; i < moveLen; i++)
	{
		std::cout << possible_moves[i] << " : " << counter[i] << "    ";
	}
	std::cout << std::endl;
}