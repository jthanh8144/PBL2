#include "HoaDon.h"

HoaDon::HoaDon()
{
	strcpy_s(MaHD, "");
	strcpy_s(MaKH, "");
	this->TongThanhToan = 0;
	strcpy_s(ThoiGianXuat, "");
	strcpy_s(NhanVienXuat, "");
}

HoaDon::HoaDon(char* MaHD, char* MaKH, int TongThanhToan, char* ThoiGianXuat, char* NhanVienXuat)
{
	strcpy_s(this->MaHD, 15, MaHD);
	strcpy_s(this->MaKH, 15, MaKH);
	this->TongThanhToan = TongThanhToan;
	strcpy_s(this->ThoiGianXuat, 15, ThoiGianXuat);
	strcpy_s(this->NhanVienXuat, 15, NhanVienXuat);
}

HoaDon::~HoaDon() {

}

char* HoaDon::getMaHD()
{
	return this->MaHD;
}

char* HoaDon::getMaKH()
{
	return this->MaKH;
}

int HoaDon::getTongThanhToan() {
	return this->TongThanhToan;
}

char* HoaDon::getCharTongThanhToan()
{
	string t_TTT = to_string(this->TongThanhToan);
	const char* c = t_TTT.c_str();
	char* t = new char[t_TTT.size()];
	strcpy(t, c);
	return t;
}

char* HoaDon::getThoiGianXuat()
{
	return this->ThoiGianXuat;
}

char* HoaDon::getNhanVienXuat()
{
	return this->NhanVienXuat;
}

ostream& operator<<(ostream& o, const HoaDon& h)
{
	o << h.MaHD << " " << h.MaKH << " " << h.TongThanhToan << " " << h.ThoiGianXuat << " " << h.NhanVienXuat << endl;
	return o;
}