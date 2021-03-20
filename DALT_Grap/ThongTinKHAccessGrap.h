#pragma once
#include "DataAccessGrap.h"
#include "ThongTinKhachHang.h"
class ThongTinKHAccessGrap :
    public DataAccessGrap
{
public:
	void Select(ThongTinKhachHang*&);
	int countRow();
	bool Insert(char*, char*, char*, char*);
	bool Search(char*);
	char* getMKH(char*);
	char* getTKH(char*);
	char* getDC(char*);
	bool Update(char*, char*, int);

	bool Insert();
	bool Update();
	bool Delete();
	void Show();
};