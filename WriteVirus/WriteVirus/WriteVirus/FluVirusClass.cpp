#include<iostream>
#include "FluVirusClass.h"
#include<stdlib.h>
#include<time.h>

const int _red = 0x000ff;
const int _blue = 0xff0000;

FluVirusClass::FluVirusClass()
{
	this->DoBorn();
	this->InitResistance();
}

FluVirusClass::FluVirusClass(FluVirusClass * _fluVirus)
{
	this->SetColor(_fluVirus->m_color);
	this->SetDna(_fluVirus->GetDna());
	this->SetResistance(_fluVirus->GetResistance());
}

FluVirusClass::~FluVirusClass()
{
	delete FluVirusClass::DoClone();
}

void FluVirusClass::SetColor(int _m_color)
{
	if (_m_color != _red || _m_color != _blue)
	{
		std::cout << "Please choose right color!!!" << std::endl;
	}
	else
	{
		this->SetColor(_m_color);
	}
}

int FluVirusClass::GetColor()
{
	return m_color;
}

void FluVirusClass::DoBorn()
{
	FluVirusClass::LoadADNInformation();

	srand(time(NULL));

	if (rand()% 2 +  1 == 1)
	{
		m_color = _red;
	}
	else
	{
		m_color = _blue;
	}
}

VirusClass * FluVirusClass::DoClone()
{
	FluVirusClass *newFluVirus = new FluVirusClass(this);

	return newFluVirus;
}

void FluVirusClass::DoDie()
{
	FluVirusClass::~FluVirusClass();
}

void FluVirusClass::InitResistance()
{
	int set = 10;
	int red = 20;
	int blue = 15;
	if (this->m_color == _red)
	{
		this->SetResistance(rand() % (red - set + 1) + set);
	}
	else
	{
		this->SetResistance(rand() % (blue - set + 1) + set);
	}
}
