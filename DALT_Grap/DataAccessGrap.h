#pragma once
#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string>

using namespace std;

class DataAccessGrap
{
protected:
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
#define MAX_ROW_SHOW 10
	SQLHANDLE SQLConnectionHandle;
	SQLHANDLE SQLStateHandle;
	SQLHANDLE SQLEnvironmentHandle;
	SQLCHAR retConString[SQL_RETURN_CODE_LEN];
public:
	bool Init();
	void Select();
	virtual int countRow() = 0;
	virtual bool Insert() = 0;
	virtual bool Delete() = 0;
	virtual bool Update() = 0;
	virtual void Show() = 0;
	void Close();
};