#pragma once
#include "Pair.h"
class List
{
public:
	Pair data;
	List* next;
	void insert(List** head_ref, Pair new_data);
	float mean(float a, float b);
	List();
	~List();
};

