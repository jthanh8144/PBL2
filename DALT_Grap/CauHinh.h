#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CauHinh 
{
protected:
	char MaSP[10];
	char MaModel[10];
	char ManHinh[15];
	char CPU[25];
	char GPU[50];
	char RAM[15];
	char LuuTru[25];
	int Pin_Wh;
	float KhoiLuong_Kg;
	int Gia;
public:
	CauHinh();
	CauHinh(char*, char*, char*, char*, char*, char*, char*, int, float, int);
	~CauHinh();
	char* getMaSP();

	char* getMaModel();
	char* getManHinh();
	char* getCPU();
	char* getGPU();
	char* getRAM();
	char* getLuuTru();
	int getPin();
	float getKhoiLuong();
	int getGia();
	string insertQuery();
	friend ostream& operator<<(ostream&, const CauHinh&);
	void setCauHinh();
};

