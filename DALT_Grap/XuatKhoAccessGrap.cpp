#include "XuatKhoAccessGrap.h"

void XuatKhoAccessGrap::Select(XuatKho*& x)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM XuatKho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaHD[15];
		char MaSP[10];
		int SoLuong;
		int ThanhTien;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &SoLuong, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_INTEGER, &ThanhTien, SQL_RESULT_LEN, &PtrSQLVersion);
			XuatKho* temp = new XuatKho(MaHD, MaSP, SoLuong, ThanhTien);
			*(x + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int XuatKhoAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM XuatKho", SQL_NTS))
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

bool XuatKhoAccessGrap::Insert(char* MaHD, char* MaSP, int SoLuong, int ThanhTien)
{
	string query = "insert into XuatKho (MaHD, MaSP, SoLuong, ThanhTien) values ('";
	string t_MaHD(MaHD);
	string t_MaSP(MaSP);
	string t_SoLuong = to_string(SoLuong);
	string t_ThanhTien = to_string(ThanhTien);
	query += t_MaHD + "','" + t_MaSP + "'," + t_SoLuong + "," + t_ThanhTien + ")";
	cout << query << endl;
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
		//Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}

int XuatKhoAccessGrap::getGia(char* MaSP)
{
	CauHinhAccessGrap x;
	x.Init();
	CauHinh* ptr = new CauHinh[x.countRow()];
	x.Select(ptr);
	for (int i = 0; i < x.countRow(); i++)
	{
		if (strcmp(ptr[i].getMaSP(), MaSP) == 0)
		{
			return ptr[i].getGia();
		}
	}
	//cout << "Khong co MaSP nao la " << temp << ", vui long kiem tra lai!" << endl;
	return 0;
}

bool XuatKhoAccessGrap::Insert() {
	return true;
}
bool XuatKhoAccessGrap::Delete()
{
	string c_query = "delete from XuatKho where MaHD = '";
	string tmp;
	cout << "Nhap Ma Hoa Don can xoa: ";
	getline(cin, tmp);
	tmp = tmp + "       ";
	const char* temp = tmp.c_str();
	XuatKho* ptr = new XuatKho[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaHD(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaHD(ptr[i].getMaHD());
			c_query = c_query + t_MaHD + "'";
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
					cout << "Khong tim thay MaHD nao phu hop!!" << endl;
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
	cout << "Khong tim thay Ma Hoa Don nao phu hop!!" << endl;
	return false;
}
bool XuatKhoAccessGrap::Update()
{
	return true;
}
void XuatKhoAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM XuatKho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaHD[15];
		char MaSP[10];
		int SoLuong;
		int ThanhTien;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &SoLuong, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_INTEGER, &ThanhTien, 1, &PtrSQLVersion);
			cout << MaHD << MaSP << SoLuong << " " << ThanhTien << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}
