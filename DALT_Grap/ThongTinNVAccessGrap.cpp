#include "ThongTinNVAccessGrap.h"

void ThongTinNVAccessGrap::Select(ThongTinNhanVien*& t)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinNhanVien", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaNV[15];
		char HoTen[50];
		char NgaySinh[15];
		char GioiTinh[10];
		char SDT[20];
		char ChucVu[20];
		char DiaChi[50];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaNV, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, HoTen, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, NgaySinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, GioiTinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, SDT, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, ChucVu, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, DiaChi, SQL_RESULT_LEN, &PtrSQLVersion);
			ThongTinNhanVien* temp = new ThongTinNhanVien(MaNV, HoTen, NgaySinh, GioiTinh, SDT, ChucVu, DiaChi);
			*(t + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int ThongTinNVAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinNhanVien", SQL_NTS))
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

bool ThongTinNVAccessGrap::Insert(char* MaNV, char* HoTen, char* NgaySinh, char* GioiTinh, char* SDT, char* ChucVu, char* DiaChi) {
	string query = "insert into ThongTinNhanVien values ('";
	string t_MaNV(MaNV);
	string t_HoTen(HoTen);
	string t_NgaySinh(NgaySinh);
	string t_GioiTinh(GioiTinh);
	string t_SDT(SDT);
	string t_ChucVu(ChucVu);
	string t_DiaChi(DiaChi);
	query += t_MaNV + "','" + t_HoTen + "','" + t_NgaySinh + "','" + t_GioiTinh
		+ "','" + t_SDT + "','" + t_ChucVu + "','" + t_DiaChi + "')";
	const char* q = query.c_str();
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

bool ThongTinNVAccessGrap::Update(char* txt, char* MaNV, int choice) {
	string query = "Update ThongTinNhanVien set ";
	string t_txt(txt);
	string t_MaNV(MaNV);
	switch (choice)
	{
	case 1:
		query += "HoTen = '";
		break;
	case 2:
		query += "NgaySinh = '";
		break;
	case 3:
		query += "GioiTinh = '";
		break;
	case 4:
		query += "SDT = '";
		break;
	case 5:
		query += "ChucVu = '";
		break;
	case 6:
		query += "DiaChi = '";
		break;
	}
	query += t_txt + "' where MaNV = '" + t_MaNV + "'";
	cout << query << endl;
	const char* q = query.c_str();
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

bool ThongTinNVAccessGrap::Delete(char* MaNV) {
	string t_MaNV(MaNV);
	string query1 = "delete from Account where ID = '" + t_MaNV + "'";
	string query2 = "delete from ThongTinNhanVien where MaNV = '" + t_MaNV + "'";
	cout << query1 << endl << query2 << endl;
	const char* q1 = query1.c_str();
	const char* q2 = query2.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q1, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long kiem tra lai!" << endl;
		Close();
		return false;
	}
	else
	{
		SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q2, SQL_NTS);
		cout << "Xoa thanh cong!" << endl;
		Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}

bool ThongTinNVAccessGrap::Insert()
{
	string query = "insert into ThongTinNhanVien (MaNV, HoTen, NgaySinh, GioiTinh, SDT, ChucVu, DiaChi) values ('";
	ThongTinNhanVien t;
	t.setThongTinNhanVien();
	query += t.insertQuery();
	const char* q = query.c_str();
	cout << query << endl;
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
bool ThongTinNVAccessGrap::Update() {
	return false;
}
bool ThongTinNVAccessGrap::Delete()
{
	string c_query = "delete from ThongTinNhanVien where MaNV = '";
	string tmp;
	cout << "Nhap Ma Nhan Vien can xoa: ";
	cin >> tmp;
	tmp += "       ";
	const char* temp = tmp.c_str();
	ThongTinNhanVien* ptr = new ThongTinNhanVien[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaNV(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaNV(ptr[i].getMaNV());
			c_query = c_query + t_MaNV + "'";
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
				break;
			}
		}
	}
	cout << "Khong tim thay MaSP nao phu hop!!" << endl;
	return false;
}
void ThongTinNVAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinNhanVien", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaNV[15];
		char HoTen[50];
		char NgaySinh[15];
		char GioiTinh[10];
		char SDT[20];
		char ChucVu[20];
		char DiaChi[50];
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaNV, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, HoTen, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, NgaySinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, GioiTinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, SDT, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, ChucVu, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, DiaChi, SQL_RESULT_LEN, &PtrSQLVersion);
			cout << MaNV << HoTen << NgaySinh << " " << GioiTinh << SDT << ChucVu << DiaChi << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}
