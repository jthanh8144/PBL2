#include "ThongTinKHAccessGrap.h"

void ThongTinKHAccessGrap::Select(ThongTinKhachHang*& t)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinKhachHang", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER SQLPtrVersion;
		char MaKH[12];
		char TenKH[50];
		char SDT[20];
		char DiaChi[50];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaKH, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, TenKH, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, SDT, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, DiaChi, SQL_RESULT_LEN, &SQLPtrVersion);
			ThongTinKhachHang* temp = new ThongTinKhachHang(MaKH, TenKH, SDT, DiaChi);
			*(t + i) = *(temp);
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int ThongTinKHAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinKhachHang", SQL_NTS))
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

bool ThongTinKHAccessGrap::Insert(char* MaKH, char* TenKH, char* SDT, char* DiaChi) {
	string query = "insert into ThongTinKhachHang (MaKH, TenKH, SDT, DiaChi) values ('";
	string t_MaKh(MaKH);
	string t_TenKH(TenKH);
	string t_SDT(SDT);
	string t_DiaChi(DiaChi);
	query += t_MaKh + "','" + t_TenKH + "','" + t_SDT + "','" + t_DiaChi + "')";
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

char* ThongTinKHAccessGrap::getMKH(char* SDT) {
	ThongTinKHAccessGrap kh;
	kh.Init();
	ThongTinKhachHang* ptr = new ThongTinKhachHang[kh.countRow()];
	kh.Select(ptr);
	for (int i = 0; i < kh.countRow(); i++) {
		if (strcmp(ptr[i].getSDT(), SDT) == 0) return ptr[i].getMaKH();
	}
	return "";
}

char* ThongTinKHAccessGrap::getTKH(char* SDT) {
	ThongTinKHAccessGrap kh;
	kh.Init();
	ThongTinKhachHang* ptr = new ThongTinKhachHang[kh.countRow()];
	kh.Select(ptr);
	for (int i = 0; i < kh.countRow(); i++) {
		if (strcmp(ptr[i].getSDT(), SDT) == 0) return ptr[i].getTenKH();
	}
	return "";
}

char* ThongTinKHAccessGrap::getDC(char* SDT) {
	ThongTinKHAccessGrap kh;
	kh.Init();
	ThongTinKhachHang* ptr = new ThongTinKhachHang[kh.countRow()];
	kh.Select(ptr);
	for (int i = 0; i < kh.countRow(); i++) {
		if (strcmp(ptr[i].getSDT(), SDT) == 0) return ptr[i].getDiaChi();
	}
	return "";
}

bool ThongTinKHAccessGrap::Search(char* SDT) {
	ThongTinKHAccessGrap kh;
	kh.Init();
	ThongTinKhachHang* ptr = new ThongTinKhachHang[kh.countRow()];
	kh.Select(ptr);
	for (int i = 0; i < kh.countRow(); i++) {
		if (strcmp(ptr[i].getSDT(), SDT) == 0) return true;
	}
	return false;
}

bool ThongTinKHAccessGrap::Update(char* txt, char* SDT, int choice) {
	string query = "Update ThongTinKhachHang set ";
	string t_txt(txt);
	string t_SDT(SDT);
	switch (choice)
	{
	case 1:
		query += "TenKH = '";
		break;
	case 2:
		query += "SDT = '";
		break;
	case 3:
		query += "DiaChi = '";
		break;
	}
	query += t_txt + "' where SDT = '" + t_SDT + "'";
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

bool ThongTinKHAccessGrap::Insert()
{
	string query = "insert into ThongTinKhachHang (MaKH, TenKH, SDT, DiaChi) values ('";
	ThongTinKhachHang t;
	t.setThongTinKhachHang();
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
bool ThongTinKHAccessGrap::Update(){
	return false;
}
bool ThongTinKHAccessGrap::Delete()
{
	string c_query = "delete from ThongTinKhachHang where MaKH = '";
	char temp[20];
	cout << "Nhap Ma Khach Hang can xoa: ";
	cin.getline(temp, 20);
	ThongTinKhachHang* ptr = new ThongTinKhachHang[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaKH(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_TGX(ptr[i].getMaKH());
			c_query = c_query + t_TGX + "'";
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
				return true;
				break;
			}
		}
	}
	cout << "Khong tim thay MaSP nao phu hop!!" << endl;
	return false;
}
void ThongTinKHAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM ThongTinKhachHang", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER SQLPtrVersion;
		char MaKH[12];
		char TenKH[50];
		char SDT[20];
		char DiaChi[50];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaKH, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, TenKH, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, SDT, SQL_RESULT_LEN, &SQLPtrVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, DiaChi, SQL_RESULT_LEN, &SQLPtrVersion);
			cout << MaKH << TenKH << SDT << DiaChi << endl;
		}
	}
	SQLCancel(SQLStateHandle);
}
