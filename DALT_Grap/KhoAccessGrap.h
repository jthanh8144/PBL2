#pragma once
#include "DataAccessGrap.h"
#include "Kho.h"
class KhoAccessGrap :
    public DataAccessGrap
{
public:
    void Select(Kho*&);
    int countRow();
    bool Insert(char*, int);

    bool Insert();
    bool Delete();
    bool Update();
    void Show();
};

