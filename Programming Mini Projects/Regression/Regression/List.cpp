#include "List.h"



void List::insert(List ** head_ref, Pair new_data)
{
	List* new_node = new List();
	List *last = *head_ref;
	new_node->data = new_data;
	new_node->next = '\0';
	if (*head_ref == '\0')
	{
		*head_ref = new_node;
		return;
	}
	while (last->next != '\0')
		last = last->next;
	last->next = new_node;
	return;
}

float List::mean(float a, float b)
{
	return *Pair;
}

List::List()
{
}


List::~List()
{
}
