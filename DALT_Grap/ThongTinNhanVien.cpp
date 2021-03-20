#include "ThongTinNhanVien.h"

ThongTinNhanVien::ThongTinNhanVien()
{
	strcpy_s(this->MaNV, "");
	strcpy_s(this->HoTen, "");
	strcpy_s(this->NgaySinh, "");
	strcpy_s(this->GioiTinh, "");
	strcpy_s(this->SDT, "");
	strcpy_s(this->ChucVu, "");
	strcpy_s(this->DiaChi, "");
}

ThongTinNhanVien::ThongTinNhanVien(char* MaNV, char* HoTen, char* NgaySinh, char* GioiTinh, char* SDT, char* ChucVu, char* DiaChi)
{
	strcpy_s(this->MaNV, 15, MaNV);
	strcpy_s(this->HoTen, 50, HoTen);
	strcpy_s(this->NgaySinh, 15, NgaySinh);
	strcpy_s(this->GioiTinh, 10, GioiTinh);
	strcpy_s(this->SDT, 20, SDT);
	strcpy_s(this->ChucVu, 20, ChucVu);
	strcpy_s(this->DiaChi, 50, DiaChi);
}

ThongTinNhanVien::~ThongTinNhanVien(){

}

char* ThongTinNhanVien::getMaNV()
{
	char* MaNV = this->MaNV;
	for (int i = 0; i < strlen(MaNV); i++) {
		if (MaNV[i] == ' ') {
			MaNV[i] = '\0';
			break;
		}
	}
	return MaNV;
}

char* ThongTinNhanVien::getHoTen()
{
	return this->HoTen;
}

char* ThongTinNhanVien::getNgaySinh()
{
	return this->NgaySinh;
}

char* ThongTinNhanVien::getGioiTinh()
{
	return this->GioiTinh;
}

char* ThongTinNhanVien::getSDT()
{
	return this->SDT;
}

char* ThongTinNhanVien::getChucVu()
{
	char* ChucVu = this->ChucVu;
	for (int i = strlen(ChucVu) - 1; i >= 0; i--) {
		if (ChucVu[i] != ' ') {
			ChucVu[i+1] = '\0';
			break;
		}
	}
	return ChucVu;
}

char* ThongTinNhanVien::getDiaChi()
{
	return this->DiaChi;
}

string ThongTinNhanVien::insertQuery()
{
	string t_MaNV(MaNV);
	string t_HoTen(HoTen);
	string t_NgaySinh(NgaySinh);
	string t_GioiTinh(GioiTinh);
	string t_SDT(SDT);
	string t_ChucVu(ChucVu);
	string t_DiaChi(DiaChi);
	string query = t_MaNV + "','" + t_HoTen + "','" + t_NgaySinh + "','" + t_GioiTinh
		+ "','" + t_SDT + "','" + t_ChucVu + "','" + t_DiaChi + "')";
	return query;
}
void ThongTinNhanVien::setThongTinNhanVien()
{
	cout << "Nhap Ma Nhan Vien: ";
	cin.getline(MaNV, 15);
	cout << "Nhap Ho Va Ten Nhan Vien: ";
	cin.getline(HoTen, 50);
	cout << "Nhap Ngay Sinh: ";
	cin.getline(NgaySinh, 15);
	cout << "Nhap Gioi Tinh: ";
	cin.getline(GioiTinh, 10);
	cout << "Nhap SDT: ";
	cin.getline(SDT, 20);
	cout << "Nhap Chuc Vu: ";
	cin.getline(ChucVu, 20);
	cout << "Nhap Dia Chi: ";
	cin.getline(DiaChi, 50);
}
ostream& operator<<(ostream& o, ThongTinNhanVien& t)
{
	o << t.MaNV << t.HoTen << t.NgaySinh << t.GioiTinh << t.SDT << t.ChucVu << t.DiaChi << endl;
	return o;
}
