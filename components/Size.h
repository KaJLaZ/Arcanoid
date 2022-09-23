#pragma once
#include <tuple>

class Size {
public:
	Size(int weigth, int heigth)
		: weigth(weigth),
		  heigth(heigth){}

	int getWeigth() {
		return weigth;
	}

	int getHeigth() {
		return heigth;
	}

	void setWeigth(int weigth)
	{
		this->weigth = weigth;
	}

	void setHeigth(int heigth)
	{
		this->heigth = heigth;
	}

	friend bool operator==(const Size& lhs, const Size& rhs)
	{
		return std::tie(lhs.weigth, lhs.heigth) == std::tie(rhs.weigth, rhs.heigth);
	}

private:
	int weigth;
	int heigth;
};
