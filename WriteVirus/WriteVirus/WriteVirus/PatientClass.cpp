#include "PatientClass.h"
#include"FluVirusClass.h"
#include"DengueVirusClass.h"
#include<Windows.h>

//---------Set to random-------------
const short startResistance = 1000;
const short endResistance = 9000;
const short startVirus = 10;
const short endVirus = 20;
const short	startReduceResistance = 1;
const short endReduceResistance = 60;
int sumRandom = (endVirus - startVirus + 1) + startVirus;
std::list<VirusClass *>::iterator iter;

int sumResistanceOfVirus = 0;

PatientClass::PatientClass()
{
	this->InitResistance();
	this->DoStart();
}

PatientClass::~PatientClass()
{
	DoDie();
}

void PatientClass::InitResistance()
{
	//srand(time(NULL));
	this->m_resistance = rand() % (endResistance - startResistance + 1) + startResistance;
	std::cout << "Resistance patient : " << m_resistance << std::endl;
}

VirusClass ** PatientClass::DoClone()
{
	return nullptr;
}

void PatientClass::DoBorn()
{
}

void PatientClass::DoStart()
{
	srand(time(NULL));
	int random = rand() % 2;
	
	for (int  i = 0; i < sumRandom; i++)
	{
		Sleep(100);
		if (random == 0)
		{
			this->m_virusList.push_back(new FluVirusClass);
		}
		else
		{
			this->m_virusList.push_back(new DengueVirusClass);
		}
	}
	std::cout << "\nSum virus : " << sumRandom << "\n" << std::endl;
	this->m_state = 1;
}

void PatientClass::TakeMedicine(int medicine_resistance)
{
	std::cout << "Take medicine: " << medicine_resistance << std::endl;
	
	iter = m_virusList.begin();
	while (iter != m_virusList.end())
	{
		Sleep(50);
		(*iter)->ReduceResistance(medicine_resistance);
		if ((*iter)->GetResistance() > 0)
		{
			sumResistanceOfVirus = (*iter)->GetResistance();

			m_virusList.push_front(*((*iter)->DoClone()));
			++iter;
		}
		else
		{
			delete (*iter);
			iter = m_virusList.erase(iter);		
		}
	}
	std::cout << "Virus size: " << m_virusList.size() << std::endl;

	if (this->m_resistance < sumResistanceOfVirus)
	{
		std::cout << "The patient is die!!!!!" << std::endl;
		DoDie();
	}

	if (m_virusList.size() == 0)
	{
		std::cout << "All virus is die!!!!!" << std::endl;
		DoDie();
	}
}

void PatientClass::DoDie()
{
	m_state = 0;
}

int PatientClass::GetState()
{
	return m_state;
}

int PatientClass::GetResistance()
{
	return this->m_resistance;
}
