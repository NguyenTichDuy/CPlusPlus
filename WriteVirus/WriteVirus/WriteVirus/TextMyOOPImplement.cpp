#include<iostream>
#include"FluVirusClass.h"
using namespace std;

int main()
{
	VirusClass *virus = new FluVirusClass();
	
	cout << virus->GetResistance() << endl;
	

	delete virus;
	system("pause");
}