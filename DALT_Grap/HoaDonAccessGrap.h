#include "HoaDon.h"
#include "DataAccessGrap.h"
#include "XuatKhoAccessGrap.h"
#pragma once

class HoaDonAccessGrap : public DataAccessGrap
{
public:
	void Select(HoaDon*&);
	int countRow();
	bool Insert(char*, char*, char*, char*);
	int CalTongThanhToan(char*);
	int getTongThanhToan(char*);
	bool UpdateTTT(char*);
	bool Insert(char*, char*, int, char*, char*);
	int countRowShow(char*, char*);
	void InHD(char*, char*, HoaDon*&);

	bool Insert();
	bool Update();
	bool Delete();
	void Show();
	void Search();
};

