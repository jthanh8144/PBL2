#include "CauHinhAccessGrap.h"

void CauHinhAccessGrap::Select(CauHinh*& ch)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM CauHinhChiTiet", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[10];
		char MaModel[10];
		char ManHinh[15];
		char CPU[25];
		char GPU[50];
		char RAM[15];
		char LuuTru[25];
		int Pin_Wh;
		float KhoiLuong_Kg;
		int Gia;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 9, SQL_C_FLOAT, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);

			CauHinh* temp = new CauHinh(MaSP, MaModel, ManHinh, CPU, GPU, RAM, LuuTru, Pin_Wh, KhoiLuong_Kg, Gia);
			*(ch + i) = *temp; 
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int CauHinhAccessGrap::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM CauHinhChiTiet", SQL_NTS))
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

bool CauHinhAccessGrap::Insert(char* MaSP, char* MaModel, char* MH, char* CPU, char* GPU, char* RAM, char* LuuTru, int Pin, float KL, int Gia) {
	string t_MaSP(MaSP);
	string t_MaModel(MaModel);
	string t_ManHinh(MH);
	string t_CPU(CPU);
	string t_GPU(GPU);
	string t_RAM(RAM);
	string t_LuuTru(LuuTru);
	string t_Pin = to_string(Pin);
	string t_KhoiLuong = to_string(KL);
	string t_Gia = to_string(Gia);
	string query = "insert into CauHinhChiTiet values ('" + t_MaSP + "', '" + t_MaModel + "', '" + t_ManHinh + "', '" + t_CPU
		+ "', '" + t_GPU + "', '" + t_RAM + "', '" + t_LuuTru + "', " + t_Pin + ", " + t_KhoiLuong + ", " + t_Gia + ")";
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
		return true;
	}
	SQLCancel(SQLStateHandle);
}

bool CauHinhAccessGrap::Insert()
{
	string c_query = "insert into CauHinhChiTiet (MaSP, MaModel, ManHinh, CPU, GPU, RAM, LuuTru, [Pin(Wh)], [KhoiLuong(Kg)], Gia) values (";
	CauHinh ch;
	ch.setCauHinh();
	c_query += ch.insertQuery();
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long kiem tra du lieu nhap vao!" << endl;
		Close();
		return false;
	}
	else
	{
		cout << "Them du lieu thanh cong!" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle); 
}
bool CauHinhAccessGrap::Update(){
	return true;
}
bool CauHinhAccessGrap::Delete()
{
	string c_query = "delete from CauHinhChiTiet where MaSP = '";
	char temp[20];
	cout << "Nhap MaSP can xoa: ";
	cin.ignore();
	cin.getline(temp, 20);
	CauHinh* ptr = new CauHinh[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaSP(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaSP(ptr[i].getMaSP());
			c_query = c_query + t_MaSP + "'";
			const char* q = c_query.c_str();
			cout << "Ban co chac chan muon xoa ban ghi " << ptr[i].getMaSP() << "? (Y/N): ";
			char ans;
			cin >> ans;
			switch (ans)
			{
			case 'Y':
			case 'y':
				if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*) q, SQL_NTS))
				{
					cout << "Khong tim thay MaSP nao phu hop!!" << endl;
					Close();
					return false;
				}
				else
				{
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
void CauHinhAccessGrap::Sort()
{
	char temp[20];
	cout << "Nhap cot muon sap xep: ";
	//cin.ignore();
	cin >> temp;
	string t(temp);
	if (t == "KhoiLuong") t = "[KhoiLuong(Kg)]";
	if (t == "Pin") t = "[Pin(Wh)]";
	string query = "select * from CauHinhChiTiet order by " + t + " desc";
	const char* q = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Khong tim thay cot, vui long kiem tra lai" << endl;
		return;
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[20];
		char MaModel[20];
		char ManHinh[20];
		char CPU[30];
		char GPU[50];
		char RAM[30];
		char LuuTru[21];
		int Pin_Wh;
		double KhoiLuong_Kg;
		int Gia;
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 9, SQL_DOUBLE, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);

			cout << MaSP << " " << MaModel << " " << ManHinh << " " << CPU << " " << GPU << " " << RAM << " " << Pin_Wh << " " << KhoiLuong_Kg << " " << Gia << " " << endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}
void CauHinhAccessGrap::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)"SELECT * FROM CauHinhChiTiet", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[20];
		char MaModel[20];
		char ManHinh[20];
		char CPU[30];
		char GPU[50];
		char RAM[30];
		char LuuTru[21];
		int Pin_Wh;
		double KhoiLuong_Kg;
		int Gia;
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 9, SQL_DOUBLE, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);
		
			cout << MaSP << " " << MaModel << " " << ManHinh << " " << CPU << " " << GPU << " " << RAM << " " << LuuTru << " " << Pin_Wh << " " << KhoiLuong_Kg << " " << Gia << " " << endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}