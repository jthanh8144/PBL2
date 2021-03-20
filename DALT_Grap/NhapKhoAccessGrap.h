#pragma once
#include "DataAccessGrap.h"
#include "NhapKho.h"
class NhapKhoAccessGrap :
    public DataAccessGrap
{
public:
    void Select(NhapKho*&);
    int countRow();
    bool Insert(char*, int, int, char*, char*, char*);

    bool Insert();
    bool Delete();
    bool Update();
    void Show();
};

