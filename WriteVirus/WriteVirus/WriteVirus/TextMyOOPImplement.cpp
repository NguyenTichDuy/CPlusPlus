#include<iostream>
#include"FluVirusClass.h"
#include"DengueVirusClass.h"
using namespace std;


int main()
{
	VirusClass *virus = new DengueVirusClass();
	
	cout << virus->GetResistance() << endl;
	cout << virus->DoClone() << endl;
	cout << virus->GetDna() << endl;

	delete virus;
	system("pause");
}