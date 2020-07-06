#pragma once

struct Point
{
    int x, y;
};

enum class Cell: char { wall=0, blue=1, red=2, green=3 };

enum Orientation : int { N, E, S, W, size };
