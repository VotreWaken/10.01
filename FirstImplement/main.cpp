#include <iostream>
#include "Vector.h"
#include <type_traits>
using namespace std;

// Class Point
class Point
{
public:

	// Constructor with parametres
	Point(int xValue, int yValue) : x(xValue), y(yValue)
	{
		
	};
	// Default Constructor
	Point()
	{
		x = 0;
		y = 0;
	};

	// Print Method 
	void Print()
	{
		std::cout << "X: " << x << " Y: " << y << "\n";
	}

	// Get X field 
	int GetX()
	{
		return x;
	}

	// Get Y field 
	int GetY()
	{
		return y;
	}

	// Operator += Overloading 
	Point& operator+=(Point& obj)
	{
		this->x += obj.GetX();
		this->y += obj.GetY();
		return *this;
	}

private:
	int x;
	int y;
};

// Global Overload << operator for output Lvalue Point
std::ostream& operator<<(std::ostream& out, Point& obj)
{
	out << "\nX: " << obj.GetX() << " Y: " << obj.GetY() << '\n';
	return out;
}

// Global Overload << operator for output Rvalue Point
std::ostream& operator<<(std::ostream& out, Point&& obj)
{
	out << "X: " << obj.GetX() << " Y: " << obj.GetY();
	return out;
}


// Fill Vector with objects of Point
template <typename T>
void FillPoints(Vector<T>& Container)
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		Point temp(rand() % 10, rand() % 10);
		Container.push_back(temp);
	}
}

int main()
{
	// Int Value 
	std::cout << "Int: " << '\n';
	Vector<int> intVec{ 1,5,3,2,5 };
	for (int i = 0; i < intVec.VectorSize(); i++)
	{
		cout << intVec[i] << " ";
	}
	std::cout << "\nInt Sum: " << intVec.Sum() << "\n";


	// Double Value
	std::cout << "\nDouble: " << '\n';
	Vector<double> doubleVec{ 1.11,5.2,3.56,2.22,2.1 };
	for (int i = 0; i < doubleVec.VectorSize(); i++)
	{
		cout << doubleVec[i] << " ";
	}
	std::cout << "\nDouble Sum: " << doubleVec.Sum() << "\n";

	// Char Value
	std::cout << "\nChar: " << '\n';
	Vector<char> charVec{ 5,2,11,54,22 };
	for (int i = 0; i < charVec.VectorSize(); i++)
	{
		cout << charVec[i] << " ";
	}

	// Cast Sum to Int Value
	std::cout << "\nChar Sum (With cast to Int Value): " << (int)charVec.Sum() << "\n";

	// Point Value
	std::cout << "\nPoint: " << '\n';
	Vector<Point> PointVec;
	FillPoints(PointVec);
	for (int i = 0; i < PointVec.VectorSize(); i++)
	{
		cout << PointVec[i] << " ";
	}
	std::cout << "\nPoint Sum: " << PointVec.Sum() << "\n";
}