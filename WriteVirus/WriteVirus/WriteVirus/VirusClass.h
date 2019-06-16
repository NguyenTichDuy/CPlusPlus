#pragma once
class VirusClass
{
protected:
	char *m_dna;
	int m_resistance;
public:
	VirusClass();
	VirusClass(char *_m_dna, int _m_resistance);
	~VirusClass();

	void SetDna(char *_m_dna);
	char *GetDna();

	void SetResistance(int _m_resistance);
	int GetResistance();

	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);

	virtual void DoBorn() = 0;
	virtual VirusClass *DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};


