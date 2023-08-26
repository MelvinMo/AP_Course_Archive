#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Polynomial {
private:
	int size;
	double * coefs;
public:
	Polynomial();
	Polynomial(double coefficients[], int number);
	Polynomial(const Polynomial & rhs);
	explicit Polynomial(double const_term);
	~Polynomial();
	int degree() const { return size - 1; }
	void print(ostream & out = cout) const;
	Polynomial & operator= (const Polynomial & rhs);
	Polynomial & operator+= (const Polynomial & rhs);
	Polynomial & operator*= (double rhs);
	friend bool operator==(const Polynomial & lhs, const Polynomial & rhs);
};

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);
Polynomial operator*(const Polynomial & lhs, double rhs);
Polynomial operator*(double lhs, const Polynomial & rhs);
ostream & operator<<(ostream & out, const Polynomial & p);

Polynomial::Polynomial() : size(1), coefs(new double[1])
{
	coefs[0] = 0.0;
}

Polynomial::Polynomial(double coefficients[], int number) :	size(number), coefs(new double[number])
{
	for (int i = 0; i < size; i++)
	{
		coefs[i] = coefficients[i];
	}
}

Polynomial::Polynomial(const Polynomial & rhs):	size(rhs.size), coefs(new double[rhs.size])
{
	for (int i = 0; i < size; i++) 
	{
		coefs[i] = rhs.coefs[i];
	}
}

Polynomial::Polynomial(double const_term) : size(1), coefs(new double[1])
{
	coefs[0] = const_term;
}

Polynomial::~Polynomial()
{
	delete[] coefs;
}

void Polynomial::print(ostream & out) const 
{
	if (size == 0) 
	{
		return;
	}
	for (int i = size - 1; i > 0; i--)
		out << coefs[i] << "x^" << i << " + ";
	out << coefs[0];
}

Polynomial & Polynomial::operator=(const Polynomial & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else {
		delete[] coefs;
		coefs = new double[rhs.size];
		size = rhs.size;
		for (int i = 0; i < size; i++) 
		{
			coefs[i] = rhs.coefs[i];
		}
	}
	return *this;
}

Polynomial & Polynomial::operator+=(const Polynomial & rhs)
{
	int newSize = (rhs.size > size) ? rhs.size : size;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++)
	{
		newCoef[i] = 0;
	}
	for (int i = 0; i < rhs.size; i++)
	{
		newCoef[i] += rhs.coefs[i];
	}
	for (int i = 0; i < size; i++)
	{
		newCoef[i] += coefs[i];
	}
	delete[] coefs;
	coefs = newCoef;
	size = newSize;
	return *this;
}

Polynomial & Polynomial::operator*=(double rhs)
{
	for (int i = 0; i < size; i++)
	{
		coefs[i] *= rhs;
	}
	return *this;
}

bool operator==(const Polynomial & lhs, const Polynomial & rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}
	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.coefs[i] != rhs.coefs[i]) 
		{
			return false;
		}
	}
	return true;
}

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs) 
{
	Polynomial answer(lhs);
	answer += rhs;
	return answer;
}

Polynomial operator*(const Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer *= rhs;
	return answer;
}

Polynomial operator*(double lhs, const Polynomial & rhs)
{
	Polynomial answer(rhs);
	answer *= lhs;
	return answer;
}

ostream & operator<<(ostream & out, const Polynomial & p)
{
	p.print(out);
	return out;
}

int main()
{
	double a[] = { 1.1, 2.2, 3.3, 4.4 };
	Polynomial p1(a, 4);
	Polynomial p2(p1);
	cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;
	Polynomial p3 = p1 + p2;
	p1 += p3;
	cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;
	cout << "p3 is " << p3 << endl;
	double a4[] = { 3, 3, 3, 3, 3 };
	Polynomial p4(a4, 5);
	cout << p4 << endl;
	p4 += Polynomial(8);
	cout << p4 << endl;
	Polynomial p5 = p4 * 0.5;
	Polynomial p6 = 4 * p5;
	cout << p5 << endl << p6 << endl;
	if (p4 == p4)
		cout << "p4 == p4" << endl;
	if (p4 == p6)
		cout << "p4 == p6" << endl;
	cout << p1 + p2 << endl;
	cout << p4 << endl;
	cout << p3 << endl;
	cout << p2 * 3 << endl;
	return 0;
}