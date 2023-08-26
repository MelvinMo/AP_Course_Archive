#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip> 

using namespace std;

class Triangle
{
private:
	double x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Triangle()
	{
		cin >> color >> dp;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dab = sqrt(pow((x1 - y1), 2.00) + pow((x2 - y2), 2.00));
		double dbc = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double dac = sqrt(pow((x1 - z1), 2.00) + pow((x2 - z2), 2.00));
		double perres = dab + dbc + dac;
		return perres;
	}
	double a()
	{
		double arres = abs((x1*(y2 - z2) + y1 * (z2 - x2) + z1 * (x2 - y2)) / 2);
		return arres;
	}
	void triprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << endl;
	}
};

class Rectangle
{
private:
	double w1, w2, x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Rectangle()
	{
		cin >> color >> dp;
		cin >> w1 >> dp >> w2;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dab = sqrt(pow((w1 - x1), 2.00) + pow((w2 - x2), 2.00));
		double dbc = sqrt(pow((x1 - y1), 2.00) + pow((x2 - y2), 2.00));
		double dcd = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double dad = sqrt(pow((w1 - z1), 2.00) + pow((w2 - z2), 2.00));
		double perres = dab + dbc + dcd + dad;
		return perres;
	}
	double a()
	{
		double dcd = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double dad = sqrt(pow((w1 - z1), 2.00) + pow((w2 - z2), 2.00));
		double arres = dad * dcd;
		return arres;
	}
	double d()
	{
		double dac = sqrt(pow((w1 - y1), 2.00) + pow((w2 - y2), 2.00));
		double diares = dac;
		return diares;
	}
	void recprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << " " << d() << " " << d() << endl;
	}
};

class Rhombus
{
private:
	double w1, w2, x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Rhombus()
	{
		cin >> color >> dp;
		cin >> w1 >> dp >> w2;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dab = sqrt(pow((w1 - x1), 2.00) + pow((w2 - x2), 2.00));
		double dbc = sqrt(pow((x1 - y1), 2.00) + pow((x2 - y2), 2.00));
		double dcd = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double dad = sqrt(pow((w1 - z1), 2.00) + pow((w2 - z2), 2.00));
		double perres = dab + dbc + dcd + dad;
		return perres;
	}
	double a()
	{
		double dac = sqrt(pow((w1 - y1), 2.00) + pow((w2 - y2), 2.00));
		double dbd = sqrt(pow((x1 - z1), 2.00) + pow((x2 - z2), 2.00));
		double arres = ((dac * dbd) / 2);
		return arres;
	}
	double d()
	{
		double dac = sqrt(pow((w1 - y1), 2.00) + pow((w2 - y2), 2.00));
		double dbd = sqrt(pow((x1 - z1), 2.00) + pow((x2 - z2), 2.00));
		if (dac > dbd)
		{
			cout << dac << " " << dbd << endl;
		}
		else if (dac < dbd)
		{
			cout << dbd << " " << dac << endl;
		}
		else if (dac = dbd)
		{
			cout << dbd << " " << dbd << endl;
		}
		return 0;
	}
	void rhoprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << " ";
		d();
	}
};

class Square
{
private:
	double w1, w2, x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Square()
	{
		cin >> color >> dp;
		cin >> w1 >> dp >> w2;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dcd = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double perres = 4 * dcd;
		return perres;
	}
	double a()
	{
		double dcd = sqrt(pow((y1 - z1), 2.00) + pow((y2 - z2), 2.00));
		double arres = dcd * dcd;
		return arres;
	}
	double d()
	{
		double dac = sqrt(pow((w1 - y1), 2.00) + pow((w2 - y2), 2.00));
		double diares = dac;
		return diares;
	}
	void squprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << " " << d() << " " << d() << endl;
	}
};

class Hexagon
{
private:
	double u1, u2, v1, v2, w1, w2, x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Hexagon()
	{
		cin >> color >> dp;
		cin >> u1 >> dp >> u2;
		cin >> v1 >> dp >> v2;
		cin >> w1 >> dp >> w2;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dab = sqrt(pow((u1 - v1), 2.00) + pow((u2 - v2), 2.00));
		double perres = 6 * dab;
		return perres;
	}
	double a()
	{
		double dab = sqrt(pow((u1 - v1), 2.00) + pow((u2 - v2), 2.00));
		double arres = ((pow(dab, 2.00) * 3 * sqrt(3)) / 2);
		return arres;
	}
	double d()
	{
		double dac = sqrt(pow((u1 - w1), 2.00) + pow((u2 - w2), 2.00));
		double diares = dac;
		return diares;
	}
	void hexprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << endl;
	}
};

class Octagon
{
private:
	double s1, s2, t1, t2, u1, u2, v1, v2, w1, w2, x1, x2, y1, y2, z1, z2;
public:
	char color[17];
	char dp = ':';
	Octagon()
	{
		cin >> color >> dp;
		cin >> s1 >> dp >> s2;
		cin >> t1 >> dp >> t2;
		cin >> u1 >> dp >> u2;
		cin >> v1 >> dp >> v2;
		cin >> w1 >> dp >> w2;
		cin >> x1 >> dp >> x2;
		cin >> y1 >> dp >> y2;
		cin >> z1 >> dp >> z2;
	}
	double p()
	{
		double dab = sqrt(pow((u1 - v1), 2.00) + pow((u2 - v2), 2.00));
		double perres = 8 * dab;
		return perres;
	}
	double a()
	{
		double dab = sqrt(pow((u1 - v1), 2.00) + pow((u2 - v2), 2.00));
		double arres = (pow(dab, 2.00) * 2 * (sqrt(2)+1));
		return arres;
	}
	double d()
	{
		double dac = sqrt(pow((u1 - w1), 2.00) + pow((u2 - w2), 2.00));
		double diares = dac;
		return diares;
	}
	void octprint()
	{
		cout << color << " : " << fixed << setprecision(2) << p() << " " << a() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << " " << d() << endl;
	}
};

int main()
{
	int n = 0, i = 0, type[6];
	cin >> n;
	while (i < n)
	{
		cin >> type[i];
		i++;
	}
	for (i = 0; i < n; i++)
	{
		if (type[i] == 1)
		{
			Triangle tri;
			tri.triprint();
		}
		if (type[i] == 2)
		{
			Rectangle rec;
			rec.recprint();
		}
		if (type[i] == 3)
		{
			Rhombus rho;
			rho.rhoprint();
		}
		if (type[i] == 4)
		{
			Square squ;
			squ.squprint();
		}
		if (type[i] == 5)
		{
			Hexagon hex;
			hex.hexprint();
		}
		if (type[i] == 6)
		{
			Octagon oct;
			oct.octprint();
		}
	}
	return 0;
}