#include "VirusClass.h"
#include <fstream>
#include <string>


VirusClass::VirusClass()
{
	this->m_dna = new char[100];
	m_resistance = 0;
}

VirusClass::VirusClass(char * _m_dna, int _m_resistance)
{
	this->m_dna = _m_dna;
	this->m_resistance = _m_resistance;
}

VirusClass::~VirusClass()
{
	if (this->m_dna != nullptr)
	{
		delete[] m_dna;
		m_dna = nullptr;
	}
}

void VirusClass::SetDna(char * _m_dna)
{
	if (_m_dna != nullptr)
	{
		this->m_dna = _m_dna;
	}
}

char * VirusClass::GetDna()
{
	return m_dna;
}

void VirusClass::SetResistance(int _m_resistance)
{
	if (_m_resistance >= 10 || _m_resistance <= 30)
	{
		this->m_resistance = _m_resistance;
	}
	else
	{
		std::cout << "Virus resistance is beyond the scope" << std::endl;
	}
}

int VirusClass::GetResistance()
{
	return m_resistance;
}

void VirusClass::LoadADNInformation()
{
	std::ifstream input;

	input.open("ATGX.bin");

	if (input.is_open())
	{
		input.getline(m_dna, 1000, '\0');
	}
	else
	{
		std::cout << "Error!! Can't open the file ATGX.bin" << std::endl;
	}
	input.close();
}

void VirusClass::ReduceResistance(int medicine_resistance)
{
	m_resistance = m_resistance - medicine_resistance;
	if (m_resistance <= 0)
	{
		std::cout << "Virus was detroyed" << std::endl;
	}
}
