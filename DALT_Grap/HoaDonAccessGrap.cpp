#include "HoaDonAccessGrap.h"

void HoaDonAccessGrap::Select(HoaDon*& h)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM HoaDon", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaHD[12];
		char MaKH[12];
		int TongThanhToan;
		char ThoiGianXuat[15];
		char NhanVienXuat[12];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaKH, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &TongThanhToan, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, ThoiGianXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NhanVienXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			HoaDon* temp = new HoaDon(MaHD, MaKH, TongThanhToan, ThoiGianXuat, NhanVienXuat);
			*(h + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int HoaDonAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM HoaDon", SQL_NTS))
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

bool HoaDonAccessGrap::Insert() {
	return true;
}

bool HoaDonAccessGrap::Insert(char* MaHD, char* MaKH, char* ThoiGianXuat, char* NhanVienXuat) {
	string query = "insert into HoaDon (MaHD, MaKH, TongThanhToan, ThoiGianXuat, NhanVienXuat) values (";
	string s_MaHD(MaHD);
	string s_MaKH(MaKH);
	string s_ThoiGianXuat(ThoiGianXuat);
	string s_NhanVienXuat(NhanVienXuat);
	query += "'" + s_MaHD + "', '" + s_MaKH + "', 0, '" + s_ThoiGianXuat + "', '" + s_NhanVienXuat + "')";
	const char* q = query.c_str();
	cout << query << endl;
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

bool HoaDonAccessGrap::Insert(char* MaHD, char* MaKH, int TongThanhToan, char* ThoiGianXuat, char* NhanVienXuat)
{
	string query = "insert into HoaDon (MaHD, MaKH, TongThanhToan, ThoiGianXuat, NhanVienXuat) values (";
	string s_MaHD(MaHD);
	string s_MaKH(MaKH);
	string s_TongThanhToan = to_string(TongThanhToan);
	string s_ThoiGianXuat(ThoiGianXuat);
	string s_NhanVienXuat(NhanVienXuat);
	query += "'" + s_MaHD + "','" + s_MaKH + "'," + s_TongThanhToan + ",'" + s_ThoiGianXuat + "','" + s_NhanVienXuat + "')";
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
		Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
}

int HoaDonAccessGrap::countRowShow(char* TuNgay, char* DenNgay) {
	string t_TuNgay(TuNgay);
	string t_DenNgay(DenNgay);
	string query = "Select * from HoaDon where ThoiGianXuat >= '" + t_TuNgay + "' and ThoiGianXuat <= '" + t_DenNgay + "'";
	const char* q = query.c_str();
	cout << query << endl;
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
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

void HoaDonAccessGrap::InHD(char* TuNgay, char* DenNgay, HoaDon*& h) {
	string t_TuNgay(TuNgay);
	string t_DenNgay(DenNgay);
	string query = "Select * from HoaDon where ThoiGianXuat >= '" + t_TuNgay + "' and ThoiGianXuat <= '" + t_DenNgay + "'";
	const char* q = query.c_str();
	cout << query << endl;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaHD[15];
		char MaKH[15];
		int TongThanhToan;
		char ThoiGianXuat[15];
		char NhanVienXuat[15];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaKH, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &TongThanhToan, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, ThoiGianXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NhanVienXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			HoaDon* temp = new HoaDon(MaHD, MaKH, TongThanhToan, ThoiGianXuat, NhanVienXuat);
			*(h + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int HoaDonAccessGrap::CalTongThanhToan(char* MaHD) {
	int tmp = 0;
	XuatKhoAccessGrap xk;
	xk.Init();
	XuatKho* ptr = new XuatKho[xk.countRow()];
	xk.Select(ptr);
	for (int i = 0; i < xk.countRow(); i++) {
		if (strcmp(ptr[i].getMaHD(), MaHD) == 0) {
			tmp += ptr[i].getThanhTien();
		}
	}
	return tmp;
}

int HoaDonAccessGrap::getTongThanhToan(char* MaHD) {
	HoaDon* ptr = new HoaDon[this->countRow()];
	this->Select(ptr);
	for (int i = 0; i < this->countRow(); i++) {
		if (strcmp(ptr[i].getMaHD(), MaHD)) {
			return ptr[i].getTongThanhToan();
		}
	}
	return -1;
}

bool HoaDonAccessGrap::UpdateTTT(char* MaHD) {
	string query = "Update HoaDon set TongThanhToan = ";
	string t_MaHD(MaHD);
	string t_TTT = to_string(CalTongThanhToan(MaHD));
	query += t_TTT + "where MaHD = " + t_MaHD;
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

bool HoaDonAccessGrap::Update(){
	return true;
}
bool HoaDonAccessGrap::Delete()
{
	string c_query = "delete from HoaDon where ThoiGianXuat = '";
	char temp[20];
	cout << "Nhap Thoi Gian can xoa: ";
	cin.getline(temp, 20);
	HoaDon* ptr = new HoaDon[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getThoiGianXuat(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_TGX(ptr[i].getThoiGianXuat());
			c_query = c_query + t_TGX + "'";
			cout << c_query << endl;
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
void HoaDonAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM HoaDon", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaHD[12];
		char MaKH[12];
		int TongThanhToan;
		char ThoiGianXuat[15];
		char NhanVienXuat[12];
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaKH, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &TongThanhToan, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, ThoiGianXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NhanVienXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			cout << MaHD << " " << MaKH << " " << TongThanhToan << " " << ThoiGianXuat << " " << NhanVienXuat << endl;
			if (n == MAX_ROW_SHOW) break;
			n++;
		}
	}
	SQLCancel(SQLStateHandle);
}
void HoaDonAccessGrap::Search() //chưa sài đc :V
{
	string query = "select * from HoaDon where ";
	cout << "Nhap thong tin can tim kiem: ";
	string inf;
	cin >> inf;
	string tmp;
	cout << "Nhap " << inf << ": ";
	cin >> tmp;
	query = query + inf + " = " + "'" + tmp + "'";
	const char* q = query.c_str();
	system("pause");
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << "Cac ban ghi co " << inf << " la " << tmp << ":" << endl;
		SQLINTEGER PtrSQLVersion;
		char MaHD[12];
		char MaKH[12];
		int TongThanhToan;
		char ThoiGianXuat[15];
		char NhanVienXuat[12];
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaHD, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaKH, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &TongThanhToan, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, ThoiGianXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, NhanVienXuat, SQL_RESULT_LEN, &PtrSQLVersion);
			cout << MaHD << " " << MaKH << " " << TongThanhToan << " " << ThoiGianXuat << " " << NhanVienXuat << endl;
			if (n == MAX_ROW_SHOW) break;
			n++;
		}
	}
	SQLCancel(SQLStateHandle);
}