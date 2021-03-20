#include <iostream>
#include <string>
#pragma once

using namespace std;

class ThongTinNhanVien
{
protected:
	char MaNV[20];
	char HoTen[50];
	char NgaySinh[15];
	char GioiTinh[10];
	char SDT[20];
	char ChucVu[20];
	char DiaChi[50];
public:
	ThongTinNhanVien();
	ThongTinNhanVien(char*, char*, char*, char*, char*, char*, char*);
	~ThongTinNhanVien();
	char* getMaNV();
	char* getHoTen();
	char* getNgaySinh();
	char* getGioiTinh();
	char* getSDT();
	char* getChucVu();
	char* getDiaChi();

	friend ostream& operator<<(ostream&, ThongTinNhanVien&);
	string insertQuery();
	void setThongTinNhanVien();
};

