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
	srand(time(NULL));
	this->m_resistance = rand() % (endResistance - startResistance + 1) + startResistance;
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
	if (this->m_resistance < sumResistanceOfVirus)
	{
		this->DoDie();
	}
	

	for (iter = m_virusList.begin(); iter != m_virusList.end(); ++iter)
	{
		VirusClass *virus = *iter;
		virus->ReduceResistance(medicine_resistance);
		if (virus->GetResistance() > 0)
		{
			sumResistanceOfVirus = virus->GetResistance();
		}
	}
}

void PatientClass::DoDie()
{
	if (*iter != nullptr)
	{
		for (iter = this->m_virusList.begin(); iter != this->m_virusList.end(); ++iter)
		{
			delete *iter;
		}
		*iter = nullptr;
	}
}

int PatientClass::GetState()
{
	return m_state;
}

int PatientClass::GetResistance()
{
	return this->m_resistance;
}
