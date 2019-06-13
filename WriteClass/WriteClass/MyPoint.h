#pragma once
class MyPoint
{
private:
	int posX;
	int posY;
public:

	//------Constructor-------
	MyPoint(int _x, int _y);
	MyPoint();
	//------Destructor--------
	~MyPoint();
	
	//------Packed--------------
	void SetX(int _x);
	int GetX();

	void SetY(int _y);
	int GetY();

	//------Funtion member----
	void Display();
	float Distance(MyPoint p);
};

