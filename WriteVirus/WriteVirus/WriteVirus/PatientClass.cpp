#include "PatientClass.h"
#include"FluVirusClass.h"
#include"DengueVirusClass.h"

//---------Set to random-------------
const short startResistance = 1000;
const short endResistance = 9000;
const short startVirus = 10;
const short endVirus = 20;
const short	startReduceResistance = 1;
const short endReduceResistance = 60;
int sumRandom = (endVirus - startVirus + 1) + startVirus;

int sumResistanceOfVirus = 0;

PatientClass::PatientClass()
{
	this->InitResistance();
	this->DoStart();
}

PatientClass::~PatientClass()
{
	DoDie();
	for (auto v : m_virusList)
	{
		delete v;
	}
	m_virusList.clear();
}

void PatientClass::InitResistance()
{
	srand(time(NULL));
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
	int random = rand() % 2;

	for (int  i = 0; i < sumRandom; i++)
	{
		if (random == 0)
		{
			this->m_virusList.push_back(new FluVirusClass);
		}
		else
		{
			this->m_virusList.push_back(new DengueVirusClass);
		}
	}
	this->m_state = 1;
}

void PatientClass::TakeMedicine(int medicine_resistance)
{
	std::cout << "Take medicine: " << medicine_resistance << std::endl;

	std::list<VirusClass *>::iterator iter;
	iter = m_virusList.begin();
	while (iter != m_virusList.end())
	{
		VirusClass *virus = *iter;
		virus->ReduceResistance(medicine_resistance);
		if (virus->GetResistance() > 0)
		{
			sumResistanceOfVirus = virus->GetResistance();

			m_virusList.push_front(*virus->DoClone());
			++iter;
		}
		else
		{
			iter = m_virusList.erase(iter);
			//delete virus;
		}
	}
	

	if (this->m_resistance < sumResistanceOfVirus)
	{
		std::cout << "The patient is die!!!!!" << std::endl;
		DoDie();
	}

	if (sumResistanceOfVirus <= 0)
	{
		std::cout << "All virus is die!!!!!" << std::endl;
		DoDie();
	}
}

void PatientClass::DoDie()
{
	m_virusList.clear();
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
