#pragma once
#include <tuple>

class Coord {
public:
	Coord(double& x, double& y): x(x), y(y){}
	Coord(int& x, int& y): x(x), y(y){}
	Coord(double&& x, double&& y): x(x), y(y){}

	double& getX() {
		return x;
	}

	void setX(double x)
	{
		this->x = x;
	}

	double& getY() {
		return y;
	}

	void setY(double y)
	{
		this->y = y;
	}

	friend bool operator==(const Coord& lhs, const Coord& rhs)
	{
		return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y);
	}

private:
	double x;
	double y;
};
