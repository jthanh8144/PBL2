//NO PRIMARY KEY!
#include <iostream>
#include <string>
#pragma once

using namespace std;

class NhapKho
{
protected:
	char MaSP[10];
	int SoLuong;
	int DonGia;
	char NoiNhap[20];
	char ThoiGianNhap[15];
	char NhanVienNhap[15];
public:
	NhapKho();
	NhapKho(char*, int, int, char*, char*, char*);
	~NhapKho();
	char* getMaSP();
	int getSoLuong();
	int getDonGia();
	char* getNoiNhap();
	char* getThoiGianNhap();
	char* getNhanVienNhap();

	friend ostream& operator<<(ostream&, const NhapKho&);
};

