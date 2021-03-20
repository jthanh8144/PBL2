#include "AccountAccessGrap.h"

void AccountAccessGrap::Select(Account*& ac)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM Account", SQL_NTS)) {
		ShowNotification("Co loi xay ra, vui long thu lai!!");
		Close();
	}
	else {
		SQLINTEGER PtrSQLVersion;
		char tID[15];
		char tPass[25];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)	{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, tID, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, tPass, SQL_RESULT_LEN, &PtrSQLVersion);
			Account* temp = new Account(tID, tPass);
			*(ac + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int AccountAccessGrap::countRow() {
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM Account", SQL_NTS)) {
		ShowNotification("Co loi xay ra, vui long thu lai!!");
		Close();
	}
	else {
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS) n++;
	}
	SQLCancel(SQLStateHandle);
	return n;
}

bool AccountAccessGrap::checkConnect() {
	AccountAccessGrap acc;
	char* txt[] = {"Dang ket noi den CSDL...", "Nhan Enter de tiep tuc"};
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, hmaxy - textheight(txt[0]) / 2, txt[0]);
	settextstyle(3, 0, 2);
	outtextxy(hmaxx - textwidth(txt[1]) / 2, maxy - 40, txt[1]);
	delay(800);
	if (acc.Init() == true) {
		ShowNotification("Ket noi thanh cong!");
		acc.Close();
		return true;
	}
	ShowNotification("Khong the ket noi voi CSDL! Vui long thu lai sau.");
	acc.Close();
	getch();
	exit(0);
	return false;
}

char* AccountAccessGrap::getChucVu(const char* ID) {
	ThongTinNVAccessGrap nvac;
	nvac.Init();
	ThongTinNhanVien* ptr = new ThongTinNhanVien[nvac.countRow()];
	nvac.Select(ptr);
	for (int i = 0; i < nvac.countRow(); i++)
	{
		if (strcmp(ptr[i].getMaNV(), ID) == 0)
		{
			return ptr[i].getChucVu();
		}
	}
}

void AccountAccessGrap::checkLogin(int &lenghtMenu) {
	char *ID, *Pass, *ChucVu;
	Menu2(ID, Pass);
	Account* ac = new Account[countRow()];
	Select(ac);
	for (int i = 0; i < countRow(); ++i) {
		if (strcmp(ac[i].getID(), ID) == 0 && strcmp(ac[i].getPass(), Pass) == 0) {
			ShowNotification("Dang nhap thanh cong!");
			if (strcmp(getChucVu(ID), "Quan li") == 0) lenghtMenu = 6;
			else lenghtMenu = 5;
			return;
		}
	}
	ShowNotification("Sai tai khoan hoac mat khau, vui long thu lai!");
	checkLogin(lenghtMenu);
}

bool AccountAccessGrap::Update(char* MatKhau, char* ID) {
	string query = "Update Account set ";
	string t_MatKhau(MatKhau);
	string t_ID(ID);
	query += "Pass = '" + t_MatKhau + "' where ID = '" + t_ID + "'";
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

void AccountAccessGrap::Show(){
	
}
bool AccountAccessGrap::Insert() {
	return true;
}
bool AccountAccessGrap::Update() {
	return true;
}
bool AccountAccessGrap::Delete() {
	return true;
}