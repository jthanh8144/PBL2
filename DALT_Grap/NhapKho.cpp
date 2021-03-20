#include "NhapKho.h"

NhapKho::NhapKho()
{
	strcpy_s(this->MaSP, "");
	this->SoLuong = 0;
	this->DonGia = 0;
	strcpy_s(this->NoiNhap, "");
	strcpy_s(this->ThoiGianNhap, "");
	strcpy_s(this->NhanVienNhap, "");
}

NhapKho::NhapKho(char* MaSP, int SoLuong, int DonGia, char* NoiNhap, char* ThoiGianNhap, char* NhanVienNhap)
{
	strcpy_s(this->MaSP, 10, MaSP);
	this->SoLuong = SoLuong;
	this->DonGia = DonGia;
	strcpy_s(this->NoiNhap, 20, NoiNhap);
	strcpy_s(this->ThoiGianNhap, 15, ThoiGianNhap);
	strcpy_s(this->NhanVienNhap, 15, NhanVienNhap);
}

NhapKho::~NhapKho(){

}

char* NhapKho::getMaSP()
{
	return this->MaSP;
}

int NhapKho::getSoLuong()
{
	return this->SoLuong;
}

int NhapKho::getDonGia()
{
	return this->DonGia;
}

char* NhapKho::getNoiNhap()
{
	return this->NoiNhap;
}

char* NhapKho::getThoiGianNhap()
{
	return this->ThoiGianNhap;
}

char* NhapKho::getNhanVienNhap()
{
	return this->NhanVienNhap;
}

ostream& operator<<(ostream& o, const NhapKho& n)
{
	o << n.MaSP << n.SoLuong << " " << n.DonGia << " " << n.NoiNhap << n.ThoiGianNhap << n.NhanVienNhap << endl;
	return o;
}
