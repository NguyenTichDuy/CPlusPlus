#include"FluVirusClass.h"
#include"DengueVirusClass.h"
#include"PatientClass.h"
#include<Windows.h>
#include<vld.h>

using namespace std;


int main()
{
	PatientClass p;
	int t = 0;
	while(p.GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES)" << endl;
		cin >> t;
		if(t == 1)
		{
			int min = 1;
			int max = 10;
			int _medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(_medicine_resistance);
		}
	}
	//cout << typeid(FluVirusClass*).name() << endl;

	system("pause");
}