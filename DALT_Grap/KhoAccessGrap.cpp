#include "KhoAccessGrap.h"

void KhoAccessGrap::Select(Kho*& k)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM Kho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[10];
		int SoLuong;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &SoLuong, 1, &PtrSQLVersion);
			Kho* temp = new Kho(MaSP, SoLuong);
			*(k + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int KhoAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM Kho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS) n++;
	}
	SQLCancel(SQLStateHandle);
	return n;
}

bool KhoAccessGrap::Insert(char* MaSP, int SoLuong) {
	string t_MaSP(MaSP);
	string t_SL = to_string(SoLuong);
	string query = "insert into Kho values ('" + t_MaSP + "', " + t_SL + ")";
	const char* q = query.c_str();
	cout << endl;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long kiem tra du lieu nhap vao!" << endl;
		Close();
		return false;
	}
	else
	{
		cout << "Them du lieu thanh cong!" << endl;
		Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}

bool KhoAccessGrap::Insert()
{
	string query = "insert into Kho (MaSP, SoLuong) values ('";
	Kho t;
	t.setKho();
	query += t.insertQuery();
	const char* q = query.c_str();
	cout << endl;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long kiem tra du lieu nhap vao!" << endl;
		Close();
		return false;
	}
	else
	{
		cout << "Them du lieu thanh cong!" << endl;
		Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}
bool KhoAccessGrap::Delete()
{
	string c_query = "delete from Kho where MaSP = '";
	string tmp;
	cout << "Nhap Ma San Pham can xoa: ";
	getline(cin, tmp);
	tmp = tmp + " ";
	const char* temp = tmp.c_str();
	Kho* ptr = new Kho[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaSP(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaSP(ptr[i].getMaSP());
			c_query = c_query + t_MaSP + "'";
			const char* q = c_query.c_str();
			cout << "Ban co chac chan muon xoa ban ghi" << "? (Y/N): ";
			char ans;
			cin >> ans;
			switch (ans)
			{
			case 'Y':
			case 'y':
				if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
				{
					cout << "Khong tim thay MaSP nao phu hop!!" << endl;
					Close();
					return false;
				}
				else
				{
					Show();
					cout << "Xoa ban ghi thanh cong!!" << endl;
					return true;
				}
			default:
				return false;
				break;
			}
		}
	}
	cout << "Khong tim thay Ma San Pham nao phu hop!!" << endl;
	return false;
}
bool KhoAccessGrap::Update()
{
	return false;
}
void KhoAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM Kho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[10];
		int SoLuong;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &SoLuong, 1, &PtrSQLVersion);
			cout << MaSP << SoLuong << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}