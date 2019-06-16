#include<iostream>
#include "DengueVirusClass.h"
#include<cstdlib>

const int SizeOfString = 3;
DengueVirusClass *dengueVirusCopy;

enum Protein
{
	NS3,
	NS5,
	E
};

DengueVirusClass::DengueVirusClass()
{
	this->DoBorn();
	this->InitResistance();
}


DengueVirusClass::~DengueVirusClass()
{
	this->DoDie();
}

void DengueVirusClass::SetProtein(char *_m_protein)
{
	if (std::strlen(_m_protein) == SizeOfString)
	{
		this->m_protein = _m_protein;
	}
	else
	{
		std::cout << "The string input is fail !!!!!" << std::endl;
	}
}

char *DengueVirusClass::GetProtein()
{
	return this->m_protein;
}

DengueVirusClass::DengueVirusClass(DengueVirusClass * dengueVirus)
{
	this->m_protein = dengueVirus->m_protein;
	this->m_dna = dengueVirus->m_dna;
	this->m_resistance = dengueVirus->m_resistance;
}

void DengueVirusClass::DoBorn()
{
	LoadADNInformation();
	switch (rand() % +3)
	{
	case NS3:
		this->m_protein = "NS3";
		break;
	case NS5:
		this->m_protein = "NS5";
		break;
	case E:
		this->m_protein = "E";
		break;
	default:
		std::cout << "Wrong protein!!!!" << std::endl;
		break;
	}
}

VirusClass * DengueVirusClass::DoClone()
{
	dengueVirusCopy = new DengueVirusClass(this);
	return dengueVirusCopy;
}

void DengueVirusClass::DoDie()
{
	if (dengueVirusCopy != nullptr)
	{
		delete dengueVirusCopy;
		dengueVirusCopy = nullptr;
	}
}

void DengueVirusClass::InitResistance()
{
}
