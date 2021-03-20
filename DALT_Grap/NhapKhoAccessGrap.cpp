#include "NhapKhoAccessGrap.h"

void NhapKhoAccessGrap::Select(NhapKho*& n)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM NhapKho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[10];
		int SoLuong;
		int DonGia;
		char NoiNhap[25];
		char ThoiGianNhap[25];
		char NhanVienNhap[20];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &SoLuong, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &DonGia, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, NoiNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, ThoiGianNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, NhanVienNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			NhapKho* temp = new NhapKho(MaSP, SoLuong, DonGia, NoiNhap, ThoiGianNhap, NhanVienNhap);
			*(n + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int NhapKhoAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM NhapKho", SQL_NTS))
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

bool NhapKhoAccessGrap::Insert(char* MaSP, int SoLuong, int DonGia, char* NoiNhap, char* ThoiGianNhap, char* NhanVienNhap)
{
	string query = "insert into NhapKho (MaSP, SoLuong, DonGia, NoiNhap, ThoiGianNhap, NhanVienNhap) values ('";
	string t_MaSP(MaSP);
	string t_SoLuong = to_string(SoLuong);
	string t_DonGia = to_string(DonGia);
	string t_NoiNhap(NoiNhap);
	string t_ThoiGianNhap(ThoiGianNhap);
	string t_NhanVienNhap(NhanVienNhap);
	query += t_MaSP + "'," + t_SoLuong + "," + t_DonGia + ",'" + t_NoiNhap + "','" + t_ThoiGianNhap + "','" + t_NhanVienNhap + "')";
	const char* q = query.c_str();
	cout << q << endl;
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

bool NhapKhoAccessGrap::Insert() {
	return true;
}
bool NhapKhoAccessGrap::Delete()
{
	string c_query = "delete from NhapKho where MaSP = '";
	string tmp;
	cout << "Nhap Ma San Pham can xoa: ";
	getline(cin, tmp);
	tmp = tmp + " ";
	const char* temp = tmp.c_str();
	NhapKho* ptr = new NhapKho[countRow()];
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
bool NhapKhoAccessGrap::Update(){
	return true;
}
void NhapKhoAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM NhapKho", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[10];
		int SoLuong;
		int DonGia;
		char NoiNhap[25];
		char ThoiGianNhap[25];
		char NhanVienNhap[20];
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &SoLuong, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &DonGia, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, NoiNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, ThoiGianNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, NhanVienNhap, SQL_RESULT_LEN, &PtrSQLVersion);
			cout << MaSP << SoLuong << " " << DonGia << " " << NoiNhap << ThoiGianNhap << NhanVienNhap << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}
