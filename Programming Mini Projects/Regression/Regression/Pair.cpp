#include "Pair.h"



Pair::Pair()
{
}

Pair::Pair(float x, float y)
{
	x = get_x();
	y = get_y();
}


float Pair::get_x()
{
	return x;
}

float Pair::get_y()
{
	return y;
}

int Pair::get_objectcount()
{
	return objectcount;
}

Pair::~Pair()
{
}
