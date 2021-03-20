#include "ThongTinSPAccessGrap.h"

void ThongTinSPAccessGrap::Select(ThongTinSanPham*& t)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinSanPham", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaModel[10];
		char Hang[15];
		char TenSP[25];
		char XuatXu[25];
		char NSX[15];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, Hang, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, TenSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, XuatXu, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NSX, SQL_RESULT_LEN, &PtrSQLVersion);
			ThongTinSanPham* temp = new ThongTinSanPham(MaModel, Hang, TenSP, XuatXu, NSX);
			*(t + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int ThongTinSPAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinSanPham", SQL_NTS))
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

bool ThongTinSPAccessGrap::Insert(char* MaModel, char* Hang, char* TenSP, char* XuatXu, char* NSX) {
	string query = "insert into ThongTinSanPham (MaModel, Hang, TenSP, XuatXu, NSX) values ('";
	string t_MaModel(MaModel);
	string t_Hang(Hang);
	string t_TenSP(TenSP);
	string t_XuatXu(XuatXu);
	string t_NSX(NSX);
	query += t_MaModel + "','" + t_Hang + "','" + t_TenSP + "','" + t_XuatXu + "','" + t_NSX + "')";
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

bool ThongTinSPAccessGrap::Insert()
{
	string query = "insert into ThongTinSanPham (MaModel, Hang, TenSP, XuatXu, NSX) values ('";
	ThongTinSanPham t;
	t.setThongTinSanPham();
	query += t.insertQuery();
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
		Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}
bool ThongTinSPAccessGrap::Delete()
{
	string c_query = "delete from ThongTinSanPham where MaModel = '";
	string tmp;
	cout << "Nhap Ma Model can xoa: ";
	getline(cin, tmp);
	tmp = tmp + "  ";
	const char* temp = tmp.c_str();
	ThongTinSanPham* ptr = new ThongTinSanPham[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaModel(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaModel(ptr[i].getMaModel());
			c_query = c_query + t_MaModel + "'";
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
	cout << "Khong tim thay Ma Model nao phu hop!!" << endl;
	return false;
}
bool ThongTinSPAccessGrap::Update()
{
	return true;
}
void ThongTinSPAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinSanPham", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaModel[10];
		char Hang[15];
		char TenSP[25];
		char XuatXu[25];
		char NSX[15];
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, Hang, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, TenSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, XuatXu, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NSX, SQL_RESULT_LEN, &PtrSQLVersion);
			cout << MaModel << Hang << TenSP << XuatXu << NSX << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}