#include <iostream>
#include <string>
#pragma once

using namespace std;

class HoaDon
{
protected:
	char MaHD[15];
	char MaKH[15];
	int TongThanhToan;
	char ThoiGianXuat[15];
	char NhanVienXuat[15];
public:
	HoaDon();
	HoaDon(char*, char*, int, char*, char*);
	~HoaDon();
	char* getMaHD();
	char* getMaKH();
	int getTongThanhToan();
	char* getCharTongThanhToan();
	char* getThoiGianXuat();
	char* getNhanVienXuat();

	friend ostream& operator<<(ostream&, const HoaDon&);
};

