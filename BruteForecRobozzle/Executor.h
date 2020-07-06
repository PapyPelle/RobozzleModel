#pragma once

#include <string>

#include "Common.h"
#include "Field.h"
#include "Player.h"

using namespace std;

class Executor
{
private:
	string execution;
	int startOrientation;
	Field &field;
	Player player;

	void reset();
	int execute(int count, int cap, bool verbose);

public:
	Executor(int orientation, Field &field);

	void setExecution(const string &execution);

	int execute();
};

