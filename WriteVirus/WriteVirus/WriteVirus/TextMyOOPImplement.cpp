#include"FluVirusClass.h"
#include"DengueVirusClass.h"
using namespace std;


int main()
{
	VirusClass *virus = new FluVirusClass();
	
	cout << virus->GetResistance() << endl;
	cout << virus->DoClone() << endl;

	delete virus;
	system("pause");
}