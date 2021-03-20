//Not have primary key
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Kho
{
protected:
	char MaSP[10];
	int SoLuong;
public:
	Kho();
	Kho(char*, int);
	~Kho();
	char* getMaSP();
	char* getCharSoLuong();

	friend ostream& operator<<(ostream&, const Kho&);
	void setKho();
	string insertQuery();
};

