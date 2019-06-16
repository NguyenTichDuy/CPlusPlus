#pragma once
#include"VirusClass.h"
#include<list>
class PatientClass :public VirusClass
{
private:
	std::list<VirusClass*> m_virusList;
	int m_state;
public:
	PatientClass();
	~PatientClass();

	void InitResistance() override;
	void DoStart();
	void TakeMedicine();
	void ReduceResistance(int _m_resistance);
	void DoDie() override;
	int GetState();
};

