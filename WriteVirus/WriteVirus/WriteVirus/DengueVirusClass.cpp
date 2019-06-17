
#include "DengueVirusClass.h"

const int SizeOfString = 3;
VirusClass **dengueVirusCopyPtr;
const int numNewVirus = 2;

//---------Type of protein-------
char *proteinNS3 = "NS3";
char *proteinNS5 = "NS5";
char *proteinE = "E";

//---------Set to random -------
short startrNS3 = 1;
short endNS3 = 10;
short startNS5 = 11;
short endNS5 = 20;
short startE = 21;
short endE = 30;
short value = 1;

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
	srand(time(NULL));
	switch (rand() % 3)
	{
	case NS3:
		this->m_protein = proteinNS3;
		break;
	case NS5:
		this->m_protein = proteinNS5;
		break;
	case E:
		this->m_protein = proteinE;
		break;
	default:
		std::cout << "Wrong protein!!!!" << std::endl;
		break;
	}
	std::cout << "Dengue virus is born!!!!!" << std::endl;
	std::cout << "Dengue Virus:" << m_protein << std::endl;
}	

VirusClass **DengueVirusClass::DoClone()
{
	VirusClass *dengueVirusCopy[2];
	for (int i = 0; i < numNewVirus; i++)
	{
		dengueVirusCopy[i] = new DengueVirusClass(this);
	}
	dengueVirusCopyPtr = dengueVirusCopy;
	std::cout << "New Dengue virus are clone" << std::endl;

	return dengueVirusCopyPtr;
}

void DengueVirusClass::DoDie()
{
	if (*dengueVirusCopyPtr != nullptr)
	{
		delete[] *dengueVirusCopyPtr;
		*dengueVirusCopyPtr = nullptr;
		std::cout << "Virus dengue is detroys" << std::endl;
	}
}

void DengueVirusClass::InitResistance()
{
	if (m_protein == proteinNS3)
	{
		m_resistance = rand() % (endNS3 - startrNS3 + value) + startrNS3;
	}
	else if (m_protein == proteinNS5)
	{
		m_resistance = rand() % (endNS5 - startNS5 + value) + startNS5;
	}
	else if (m_protein == proteinE)
	{
		m_resistance = rand() % (endE - startE + value) + startE;
	}
	else
	{
		std::cout << "Fail to random !!!\nCan't to see protein!!!" << std::endl;
	}
	std::cout << "Initialization resistance of virus : " << m_resistance << std::endl;
}
