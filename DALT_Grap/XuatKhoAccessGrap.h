#pragma once
#include "DataAccessGrap.h"
#include "XuatKho.h"
#include "CauHinhAccessGrap.h"

class XuatKhoAccessGrap :
    public DataAccessGrap
{
public:
    void Select(XuatKho*&);
    int countRow();
    bool Insert(char*, char*, int, int);
    int getGia(char*);

    bool Insert();
    bool Delete();
    bool Update();
    void Show();
};

