#include "MyPoint.h"
#include<iostream>


MyPoint::MyPoint()
{
	this->PosX = 0;
	this->PosY = 0;
}
MyPoint::MyPoint(int _x, int _y)
{
	this->PosX = _x;
	this->PosY = _y;
}

MyPoint::~MyPoint()
{
}

void MyPoint::SetX(int _x)
{
	if (_x >= 0)
	{

	}
}

int MyPoint::GetX()
{
	return PosX;
}

void MyPoint::SetY(int _y)
{
	PosY = _y;
}

int MyPoint::GetY()
{
	return PosY;
}

void MyPoint::Display()
{
	std::cout << "Position X: " << PosX << std::endl;
	std::cout << "Position Y: " << PosY << std::endl;
}
