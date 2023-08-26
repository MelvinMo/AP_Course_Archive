#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

template <typename T, typename F>
T add(T a, F b)
{
	strcat(a, b);
	return a;
}

template <typename F>
char add(char a, F b)
{
	strcat(a, b);
	return a;
}

template <>
int add(int a, int b)
{
	return a + b;
}

template <>
float add(float a, float b)
{
	return a + b;
}

template <>
bool add(bool a, bool b)
{
	return a && b;
}

int add(int a[], int b[], int size1, int size2)
{
	int size, i, k, merge[100];
	for (int i = 0; i < size1; i++)
		merge[i] = a[i];
	size = size1 + size2;
	for (i = 0, k = size1; k < size && i < size2; i++, k++)
		merge[k] = b[i];
	for (i = 0; i < size; i++)
		cout << merge[i] << " ";
	return 0;
}

float add(float a[], float b[], int size1, int size2)
{
	int size, i, k;
	float merge[100];
	for (i = 0; i < size1; i++)
		merge[i] = a[i];
	size = size1 + size2;
	for (i = 0, k = size1; k < size && i < size2; i++, k++)
		merge[k] = b[i];
	for (i = 0; i < size; i++)
		cout << merge[i] << " ";
	return 0;
}

int main()
{
	bool ab, bb;
	char ca[50], cb[50];
	int size1, size2, i, ai[50], bi[50], sia, sib;
	float af[50], bf[50], sfa, sfb;
	char typeofdata1[20], typeofdata2[20], arraytype[20];
	cout << "Please determine first data's type:int/float/bool/array" << endl;
	cout << "If it is an array of integer or float data, please just type array." << endl;
	cin >> typeofdata1;
	cout << "Please determine second data's type:int/float/bool/array" << endl;
	cout << "If it is an array of integer or float data, please just type array." << endl;
	cin >> typeofdata2;
	system("cls");
	if ((strcmp(typeofdata1, "char") == 0) || (strcmp(typeofdata2, "char") == 0))
	{
		cout << "Enter first member's Data:";
		cin >> ca;
		cout << "Enter second member's Data:";
		cin >> cb;
		cout << add(ca, cb);
	}
	else if ((strcmp(typeofdata1, "array") == 0) || (strcmp(typeofdata2, "array") == 0))
	{
		cout << "What is the array's type?" << endl << "Array of integers or array of float data, please type the data type:" << endl;
		cin >> arraytype;
		if (strcmp(arraytype, "float") == 0)
		{
			cout << "Enter Array 1 Size :" << endl;
			cin >> size1;
			cout << "Enter Array 1 Elements :" << endl;
			for (i = 0; i < size1; i++)
				cin >> af[i];
			cout << "Enter Array 2 Size :" << endl;
			cin >> size2;
			cout << "Enter Array 2 Elements :" << endl;
			for (i = 0; i < size2; i++)
				cin >> bf[i];
			add(af, bf, size1, size2);
		}
		else if (strcmp(arraytype, "int") == 0)
		{
			cout << "Enter Array 1 Size :" << endl;
			cin >> size1;
			cout << "Enter Array 1 Elements :" << endl;
			for (i = 0; i < size1; i++)
				cin >> ai[i];
			cout << "Enter Array 2 Size :" << endl;
			cin >> size2;
			cout << "Enter Array 2 Elements :" << endl;
			for (i = 0; i < size2; i++)
				cin >> bi[i];
			add(ai, bi, size1, size2);
		}
	}
	else if ((strcmp(typeofdata1, "bool") == 0) && (strcmp(typeofdata2, "bool") == 0))
	{
		cout << "Enter first member's Data:";
		cin >> ab;
		cout << "Enter second member's Data:";
		cin >> bb;
		cout << add(ab, bb);
	}
	else if ((strcmp(typeofdata1, "int") == 0) && (strcmp(typeofdata2, "int") == 0))
	{
		cout << "Enter first member's Data:";
		cin >> sia;
		cout << "Enter second member's Data:";
		cin >> sib;
		cout << add(sia, sib);
	}
	else if ((strcmp(typeofdata1, "float") == 0) && (strcmp(typeofdata2, "float") == 0))
	{
		cout << "Enter first member's Data:";
		cin >> sfa;
		cout << "Enter second member's Data:";
		cin >> sfb;
		cout << add(sfa, sfb);
	}
	return 0;
}