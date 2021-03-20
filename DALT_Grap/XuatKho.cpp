#include "XuatKho.h"

XuatKho::XuatKho()
{
	strcpy_s(this->MaHD, "");
	strcpy_s(this->MaSP, "");
	this->SoLuong = 0;
	this->ThanhTien = 0;
}

XuatKho::XuatKho(char* MaHD, char* MaSP, int SoLuong, int ThanhTien)
{
	strcpy_s(this->MaHD, 15, MaHD);
	strcpy_s(this->MaSP, 10, MaSP);
	this->SoLuong = SoLuong;
	this->ThanhTien = ThanhTien;
}

XuatKho::~XuatKho()
{

}

char* XuatKho::getMaHD()
{
	char* MaHD = this->MaHD;
	for (int i = 0; i < strlen(MaHD); i++) {
		if (MaHD[i] == ' ') {
			MaHD[i] = '\0';
			break;
		}
	}
	return MaHD;
}

char* XuatKho::getMaSP()
{
	return this->MaSP;
}

int XuatKho::getSoLuong()
{
	return this->SoLuong;
}

int XuatKho::getThanhTien()
{
	return this->ThanhTien;
}

ostream& operator<<(ostream& o, const XuatKho& x)
{
	o << x.MaHD << x.MaSP << x.SoLuong << " " << x.ThanhTien << endl;
	return o;
}
