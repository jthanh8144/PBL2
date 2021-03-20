#include <iostream>
#include <string>
#pragma once

using namespace std;

class ThongTinKhachHang
{
protected:
	char MaKH[15];
	char TenKH[50];
	char SDT[20];
	char DiaChi[50];
public:
	ThongTinKhachHang();
	ThongTinKhachHang(char*, char*, char*, char*);
	~ThongTinKhachHang();
	char* getMaKH();
	char* getTenKH();
	char* getSDT();
	char* getDiaChi();

	friend ostream& operator<<(ostream&, const ThongTinKhachHang&);
	void setThongTinKhachHang();
	string insertQuery();
};

