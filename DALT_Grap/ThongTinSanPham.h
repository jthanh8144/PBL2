#include <iostream>
#include <string>
#pragma once

using namespace std;

class ThongTinSanPham
{
protected:
	char MaModel[10];
	char Hang[15];
	char TenSP[25];
	char XuatXu[25];
	char NSX[15];
public:
	ThongTinSanPham();
	ThongTinSanPham(char*, char*, char*, char*, char*);
	~ThongTinSanPham();
	char* getMaModel();
	char* getHang();
	char* getTenSP();
	char* getXuatXu();
	char* getNSX();

	friend ostream& operator<<(ostream&, const ThongTinSanPham&);
	void setThongTinSanPham();
	string insertQuery();
};

