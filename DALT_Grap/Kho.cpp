#include "Kho.h"

Kho::Kho()
{
	strcpy_s(this->MaSP, "");
	this->SoLuong = 0;
}

Kho::Kho(char* MaSP, int SoLuong)
{
	strcpy_s(this->MaSP, 10, MaSP);
	this->SoLuong = SoLuong;
}

Kho::~Kho()
{

}

char* Kho::getMaSP()
{
	return this->MaSP;
}

char* Kho::getCharSoLuong()
{
	string t_SL = to_string(this->SoLuong);
	const char* c = t_SL.c_str();
	char* t = new char[t_SL.size()];
	strcpy(t, c);
	return t;
}

ostream& operator<<(ostream& o, const Kho& k)
{
	o << k.MaSP << k.SoLuong << endl;
	return o;
}
void Kho::setKho()
{
	cout << "Nhap Ma San Pham: ";
	cin.getline(this->MaSP, 10);
	cout << "Nhap So Luong: ";
	cin >> this->SoLuong;
}
string Kho::insertQuery()
{
	string t_MaSP(MaSP);
	string t_SoLuong = to_string(SoLuong);
	string query = t_MaSP + "'," + t_SoLuong + ")";
	return query;
}