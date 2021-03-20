#pragma once
#include "Account.h"
#include "DataAccessGrap.h"
#include "ThongTinNVAccessGrap.h"
#include "Grap.h"

class AccountAccessGrap :
    public DataAccessGrap
{
public:
	int countRow();
	void Select(Account*&);
	bool Insert();
	bool Update();
	bool Delete();
	void Show();

	bool checkConnect();
	void checkLogin(int&);
	char* getChucVu(const char*);
	bool Update(char*, char*);
};

