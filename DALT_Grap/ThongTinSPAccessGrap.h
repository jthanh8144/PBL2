#include "DataAccessGrap.h"
#include "ThongTinSanPham.h"
#pragma once
class ThongTinSPAccessGrap : public DataAccessGrap
{
public:
	void Select(ThongTinSanPham*&);
	int countRow();
	bool Insert(char*, char*, char*, char*, char*);

	bool Insert();
	bool Delete();
	bool Update();
	void Show();
};

