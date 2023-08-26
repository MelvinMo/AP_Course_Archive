#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

template <class T>
class Sum 
{
	T arg1;
	T arg2;
public:
	void Getnums() { cin >> arg1 >> arg2; }
	T printsum_fi() 
	{ 
		cout << arg1 + arg2 << endl;
		return 0;
	}
};

template <>
class Sum<char>
{
	char arg1[50];
	char arg2[50];
public:
	void Getnums() { cin >> arg1 >> arg2; }
	char printsum_ch() 
	{ 
		strcat(arg1, arg2);
		char result[11];
		cout << arg1 << endl;
		return 0;
	}
};

int main()
{
	Sum<int> obj_i[10];
	Sum<float> obj_f[10];
	Sum<char> obj_c[10];
	int num;
	char dataType[20];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> dataType;
		if (strcmp(dataType, "string") == 0)
		{
			obj_c[i].Getnums();
			obj_c[i].printsum_ch();
		}
		else if (strcmp(dataType, "int") == 0)
		{
			obj_i[i].Getnums();
			obj_i[i].printsum_fi();
		}
		else if (strcmp(dataType, "float") == 0)
		{
			obj_f[i].Getnums();
			obj_f[i].printsum_fi();
		}
	}
	return 0;
}