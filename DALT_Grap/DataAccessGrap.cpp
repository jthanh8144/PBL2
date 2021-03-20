#include "DataAccessGrap.h"

bool DataAccessGrap::Init()
{
	SQLStateHandle = NULL;
	SQLConnectionHandle = NULL;
	//Allocates Handle
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvironmentHandle))
		Close();
	if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvironmentHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		Close();
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvironmentHandle, &SQLConnectionHandle))
		Close();

	switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; Server=ACERNITRO5;Database=DALT;UID=sa;PWD=123456;Trusted_Connection=True;",
		SQL_NTS,
		retConString,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		break;

	case SQL_SUCCESS_WITH_INFO:
		break;

	case SQL_INVALID_HANDLE:
		Close();
		break;

	case SQL_ERROR:
		Close();
		break;
	default:
		break;
	}
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStateHandle))
		Close();
	return true;
}

void DataAccessGrap::Close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStateHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvironmentHandle);
}
