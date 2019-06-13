#pragma once
class MyPoint
{
private:
	int posX;
	int posY;
public:
	virtual void Text();

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
	double Distance(MyPoint p);
};


