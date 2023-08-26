#pragma once
class Pair
{
	float x, y;
public:
	static int objectcount;
	float get_x();
	float get_y();
	static int get_objectcount();
	Pair();
	Pair(float x, float y);
	~Pair();
};

