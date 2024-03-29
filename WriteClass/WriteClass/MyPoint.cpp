#include "MyPoint.h"
#include<iostream>
#include"juniorPoint.h"

MyPoint::MyPoint()
{
	this->posX = 0;
	this->posY = 0;
}
void MyPoint::Text()
{
	std::cout << "Thang Cha" << std::endl;
}
MyPoint::MyPoint(int _x, int _y)
{
	this->posX = _x;
	this->posY = _y;
}

MyPoint::~MyPoint()
{

}

void MyPoint::SetX(int _x)
{
	if (typeid(_x).name() == typeid(int).name())
	{
		this->posX = _x;
	}
	else
	{
		std::cout << "Please input a correct data type (recomment interger" << std::endl;
	}
}

int MyPoint::GetX()
{
	return posX;
}

void MyPoint::SetY(int _y)
{
	if (typeid(_y).name() == typeid(int).name())
	{
		this->posY = _y;
	}
	else
	{
		std::cout << "Please input a correct data type (recomment interger" << std::endl;
	}
}

int MyPoint::GetY()
{
	return posY;
}

void MyPoint::Display()
{
	std::cout << "Position X: " << posX << std::endl;
	std::cout << "Position Y: " << posY << std::endl;

}

double MyPoint::Distance(MyPoint p)
{
	return sqrt(pow((p.posX - this->posX), 2) + pow((p.posY - this->posY), 2));
}