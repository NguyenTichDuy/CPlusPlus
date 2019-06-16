#pragma once
#include"VirusClass.h"
class DengueVirusClass :public VirusClass
{
private:
	char *m_protein;
public:
	DengueVirusClass();
	~DengueVirusClass();

	void SetProtein(char *_m_protein);
	char *GetProtein();

	DengueVirusClass(DengueVirusClass *dengueVirus);

	void DoBorn() override;
	VirusClass **DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

