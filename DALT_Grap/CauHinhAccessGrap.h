#include "CauHinh.h"
#include "DataAccessGrap.h"
#pragma once
class CauHinhAccessGrap : public DataAccessGrap
{
public:
	void Select(CauHinh*&); 
	int countRow();
	bool Insert(char*, char*, char*, char*, char*, char*, char*, int, float, int);

	bool Insert();
	bool Update();
	bool Delete();
	void Show();
	void Sort();
};
