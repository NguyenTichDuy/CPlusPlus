#include<iostream>
using namespace std;

char Player1[50], Player2[50];
char soNhap[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool start();
bool XuLiThua();
void XuLi();
void BanChoi();
void NhapTenNhanVat();
void Nguoi2();
void Nguoi1();
void VeLai();


//------------Bat Dau -----------------
bool start()
{
	int selectMode,c;
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact nguyentichduy10a15cmg@gmail.com\n" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin >> selectMode;

	if (selectMode == 1)
		return true;
	return false;
}
//-----------------Xu li thua --------------
bool XuLiThua()
{
	if ((soNhap[0] == soNhap[1] && soNhap[1] == soNhap[2]) ||
		(soNhap[3] == soNhap[4] && soNhap[4] == soNhap[5]) ||
		(soNhap[6] == soNhap[7] && soNhap[7] == soNhap[8]) ||
		(soNhap[0] == soNhap[4] && soNhap[4] == soNhap[8]) ||
		(soNhap[2] == soNhap[4] && soNhap[4] == soNhap[6]) ||
		(soNhap[0] == soNhap[3] && soNhap[3] == soNhap[6]) ||
		(soNhap[1] == soNhap[4] && soNhap[4] == soNhap[7]) ||
		(soNhap[2] == soNhap[5] && soNhap[5] == soNhap[8]))
	{
		return true;
	}
	return false;
}

//-----------------Xu li luot choi ---------------
void XuLi()
{
	int dem = 0;
	bool endGame = true;
	while (endGame)
	{

		if (dem == 9)
		{
			cout << "Game Over !!!!!" << endl;
			cout << "Game hoa :)" << endl;
			endGame = false;
			system("pause");
			continue;
		}
		if (XuLiThua())
		{
			cout << "Game Over !!!!!" << endl;
			cout << "Nguoi chien thang la: " << Player2 << endl;
			endGame = false;
			system("pause");
			continue;
		}
		else
		{
			Nguoi1();
		}
		dem++;
		if (dem == 9)
		{
			cout << "Game Over !!!!!" << endl;
			cout << "Game hoa :)" << endl;
			system("pause");
			endGame = false;
			continue;
		}
		if (XuLiThua())
		{
			cout << "game over !!!!!" << endl;
			cout << "nguoi chien thang la: " << Player1 << endl;
			endGame = false;
			system("pause");
			continue;
		}
		else
		{
			Nguoi2();
		}
		dem++;
	}
}
//-------------Ve ban choi---------------
void BanChoi()
{
	/*cout << endl;*/
	cout << "_____________________________________________ " << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "\t" << soNhap[0] << "\t|" << "\t" << soNhap[1] << "\t|\t" << soNhap[2] << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "_____________________________________________ " << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "\t" << soNhap[3] << "\t|" << "\t" << soNhap[4] << "\t|\t" << soNhap[5] << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "_____________________________________________ " << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "\t" << soNhap[6] << "\t|" << "\t" << soNhap[7] << "\t|\t" << soNhap[8] << endl;
	cout << "\t \t|\t \t|" << endl;
	cout << "_____________________________________________ " << endl;
}
void NhapTenNhanVat()
{
	system("cls");

	cout << "Enter Player 1 Name: ";
	cin.getline(Player1, 50, '\n');
	cout << "Enter Player 2 Name: ";
	cin.getline(Player2, 50, '\n');
	cout << Player1 << "\n" << Player2 << endl;
}
//---------------Nguoi 1 di ---------------
void Nguoi1()
{
	int num;
	char so1 = 'O';
	cout << "Your Turn " << Player1 << " - " << so1 << ": ";
	cin >> num;

	switch (num)
	{
	case 11:
		soNhap[0] = so1;
		break;
	case 12:
		soNhap[1] = so1;
		break;
	case 13:
		soNhap[2] = so1;
		break;
	case 21:
		soNhap[3] = so1;
		break;
	case 22:
		soNhap[4] = so1;
		break;
	case 23:
		soNhap[5] = so1;
		break;
	case 31:
		soNhap[6] = so1;
		break;
	case 32:
		soNhap[7] = so1;
		break;
	case 33:
		soNhap[8] = so1;
		break;
	default:
		cout << "Nhap sai moi nhap lai!!!" << endl;
		break;
	}
	VeLai();
}

void VeLai()
{
	system("cls");
	BanChoi();
}

//---------------Nguoi choi 2 di -----------------
void Nguoi2()
{
	int num;
	char so2 = 'X';
	cout << "Your Turn " << Player2 << " - " << so2 << ": ";
	cin >> num;
	switch (num)
	{
	case 11:
		soNhap[0] = so2;
		break;
	case 12:
		soNhap[1] = so2;
		break;
	case 13:
		soNhap[2] = so2;
		break;
	case 21:
		soNhap[3] = so2;
		break;
	case 22:
		soNhap[4] = so2;
		break;
	case 23:
		soNhap[5] = so2;
		break;
	case 31:
		soNhap[6] = so2;
		break;
	case 32:
		soNhap[7] = so2;
		break;
	case 33:
		soNhap[8] = so2;
		break;
	default:
		cout << "Nhap sai moi nhap lai!!!" << endl;
		break;
	}
	VeLai();
}
int main()
{
	if (start())
	{
		NhapTenNhanVat();
		BanChoi();
		XuLi();
	}
}