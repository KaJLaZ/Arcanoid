#pragma once
#include <tuple>

class Size {
public:
	Size(int width, int height)
		: width(width),
		  height(height){}

	int getWidth() {
		return width;
	}

	int getHeigth() {
		return height;
	}

	void setWidth(int weigth)
	{
		this->width = weigth;
	}

	void setHeigth(int heigth)
	{
		this->height = heigth;
	}

	friend bool operator==(const Size& lhs, const Size& rhs)
	{
		return std::tie(lhs.width, lhs.height) == std::tie(rhs.width, rhs.height);
	}

private:
	int width;
	int height;
};
