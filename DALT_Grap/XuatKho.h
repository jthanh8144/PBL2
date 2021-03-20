#include <iostream>
#include <string>
#pragma once

using namespace std;

class XuatKho
{
protected:
	char MaHD[15];
	char MaSP[10];
	int SoLuong;
	int ThanhTien;
public:
	XuatKho();
	XuatKho(char*, char*, int, int);
	~XuatKho();
	char* getMaHD();
	char* getMaSP();
	int getSoLuong();
	int getThanhTien();

	friend ostream& operator<<(ostream&, const XuatKho&);
};

