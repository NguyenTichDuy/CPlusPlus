#pragma once
#include"VirusClass.h"
#include<list>
class PatientClass :public VirusClass
{
protected:
	int m_resistance;
	std::list<VirusClass*> m_virusList;
	int m_state;
public:
	PatientClass();
	~PatientClass();

	void InitResistance() override;
	VirusClass **DoClone() override;
	void DoBorn() override;
	void DoDie() override;

	void DoStart();
	void TakeMedicine(int medicine_resistance);
	int GetState();
	int GetResistance() override;
};

