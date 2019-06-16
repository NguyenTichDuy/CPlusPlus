#pragma once
#include<iostream>
#include"VirusClass.h"
#include<stdlib.h>
#include<time.h>

class FluVirusClass :public VirusClass
{
private:
	int m_color;
public:
	FluVirusClass();
	FluVirusClass(FluVirusClass* _fluVirus);
	~FluVirusClass();

	void SetColor(int _m_color);
	int GetColor();

	void DoBorn() override;
	VirusClass *DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

