#include<iostream>
#include "DengueVirusClass.h"
#include<cstdlib>

const int SizeOfString = 3;

enum Protein
{
	NS3,
	NS5,
	E
};

DengueVirusClass::DengueVirusClass()
{
	DoBorn();

}


DengueVirusClass::~DengueVirusClass()
{

}

void DengueVirusClass::SetProtein(char *_m_protein)
{
	if (std::strlen(_m_protein) == SizeOfString)
	{
		m_protein = _m_protein;
	}
	else
	{
		std::cout << "The string input is fail !!!!!" << std::endl;
	}
}

char *DengueVirusClass::GetProtein()
{
	return m_protein;
}

DengueVirusClass::DengueVirusClass(DengueVirusClass * dengueVirus)
{
	this->m_protein = dengueVirus->m_protein;
	this->SetDna(dengueVirus->GetDna());
	this->SetResistance(this->GetResistance());
}

void DengueVirusClass::DoBorn()
{
	LoadADNInformation();
	switch (rand() % +3)
	{
	case NS3:
		this->SetProtein("NS3");
		break;
	case NS5:
		this->SetProtein("NS5");
		break;
	case E:
		this->SetProtein("E");
		break;
	default:
		break;
	}
}

VirusClass * DengueVirusClass::DoClone()
{
	return nullptr;
}

void DengueVirusClass::DoDie()
{
}

void DengueVirusClass::InitResistance()
{
}
