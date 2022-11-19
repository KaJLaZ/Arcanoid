#pragma once
#include <tuple>

class Coord {
public:
	Coord(int& x, int& y): x(x), y(y){}
	Coord(double&& x, double&& y): x(x), y(y){}

	double getX() {
		return x;
	}

	void setX(double x)
	{
		this->x = x;
	}

	double getY() {
		return y;
	}

	void setY(double y)
	{
		this->y = y;
	}

private:
	double x;
	double y;
};
