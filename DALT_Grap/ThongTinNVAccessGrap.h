#include "DataAccessGrap.h"
#include "ThongTinNhanVien.h"
#pragma once

class ThongTinNVAccessGrap : public DataAccessGrap
{
public:
	void Select(ThongTinNhanVien*&);
	int countRow();
	bool Insert(char*, char*, char*, char*, char*, char*, char*);
	bool Update(char*, char*, int);
	bool Delete(char*);

	bool Insert();
	bool Update();
	bool Delete();
	void Show();
};

