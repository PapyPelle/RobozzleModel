#pragma once

#include <string>
#include <vector>

using namespace std;

class Generator
{
private:
	static const int moveLen = 7;
	static const int execLen = 9;

	int counter[moveLen] = { 0,0,0,0,0,0,0 };
	const int max_counter[moveLen] = {
		1,
		2,1,2,
		2,
		2,1
	};
	const string possible_moves[moveLen] = {
		"RL RL ",
		"BF ", "GF ", "UF ",
		"GL ",
		"GC ", "BC "
	};
	
	bool trigger[execLen][moveLen];

	int execution[execLen];

	int choseNextMove(int i);
	void initTrigger(int i);
	
public:
	Generator();
	int generateNextExecution();
	string getExecution() const;
	void reset();

	void printCounter();

};

