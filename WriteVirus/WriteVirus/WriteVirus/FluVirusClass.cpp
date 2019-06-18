#include "FluVirusClass.h"

const int _red = 0x000ff;
const int _blue = 0xff0000;
VirusClass **fluVirusCopyPtr;
VirusClass *fluVirusCopy;

FluVirusClass::FluVirusClass()
{
	this->DoBorn();
	this->InitResistance();
}

FluVirusClass::FluVirusClass(FluVirusClass * _fluVirus)
{
	this->m_color = _fluVirus->m_color;
	//this->m_dna = _fluVirus->m_dna;
	this->m_resistance = _fluVirus->m_resistance;
}

FluVirusClass::~FluVirusClass()
{
	this->DoDie();
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

	if (rand()% 2  == 1)
	{
		m_color = _red;
	}
	else
	{
		m_color = _blue;
	}
	std::cout << "Flu virus is born!!!!!!" << std::endl;
	std::cout << "Color virus is " << m_color << std::endl;
}

VirusClass ** FluVirusClass::DoClone()
{
	fluVirusCopy = new FluVirusClass(this);

	fluVirusCopyPtr = &fluVirusCopy;
	std::cout << "Flu virus is clone!!!" << std::endl;
	return fluVirusCopyPtr;
}

void FluVirusClass::DoDie()
{
	std::cout << "Flu virus is die" << std::endl;
}

void FluVirusClass::InitResistance()
{
	int set = 10;
	int red = 20;
	int blue = 15;
	srand(time(NULL));
	if (this->m_color == _red)
	{
		this->m_resistance = (rand() % (red - set + 1) + set);
	}
	else
	{
		this->m_resistance = (rand() % (blue - set + 1) + set);
	}
	std::cout << "Initialization Flu virus : " << m_resistance << std::endl;
}
