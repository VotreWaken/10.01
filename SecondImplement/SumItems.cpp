#include <iostream>
#include <type_traits>
#include <memory>
#include <algorithm>
#include "Vector.h"
using namespace std;
struct Point
{
	int x;
	int y;

	Point(int ValueX, int ValueY)
	{
		x = ValueX;
		y = ValueY;
	}

	Point()
	{
		x = 0;
		y = 0;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}
};

int main()
{
	Vector<Point> TestVec{ Point(5,6), Point(3,1), Point(5,11) };
	Vector<float> floatVec{ 1.23,5.64,7.8,55.134 };
	std::cout << "Float Sum: " << floatVec.Sum() << "\n";
	Vector<int> intVec{ 1,2,5,3,1 };
	std::cout << "Int Sum: " << intVec.Sum() << "\n";
	std::cout << "Point Sum: " << TestVec.Sum();
}