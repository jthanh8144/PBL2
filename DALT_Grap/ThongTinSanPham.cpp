#include "ThongTinSanPham.h"

ThongTinSanPham::ThongTinSanPham()
{
	strcpy_s(this->MaModel, "");
	strcpy_s(this->Hang, "");
	strcpy_s(this->TenSP, "");
	strcpy_s(this->XuatXu, "");
	strcpy_s(this->NSX, "");
}

ThongTinSanPham::ThongTinSanPham(char* MaModel, char* Hang, char* TenSP, char* XuatXu, char* NSX)
{
	strcpy_s(this->MaModel, 10, MaModel);
	strcpy_s(this->Hang, 15, Hang);
	strcpy_s(this->TenSP, 25, TenSP);
	strcpy_s(this->XuatXu, 25, XuatXu);
	strcpy_s(this->NSX, 15, NSX);
}

ThongTinSanPham::~ThongTinSanPham()
{

}

char* ThongTinSanPham::getMaModel()
{
	return this->MaModel;
}

char* ThongTinSanPham::getHang()
{
	return this->Hang;
}

char* ThongTinSanPham::getTenSP()
{
	return this->TenSP;
}

char* ThongTinSanPham::getXuatXu()
{
	return this->XuatXu;
}

char* ThongTinSanPham::getNSX()
{
	return this->NSX;
}

ostream& operator<<(ostream& o, const ThongTinSanPham& t)
{
	o << t.MaModel << t.Hang << t.TenSP << t.XuatXu << t.NSX << endl;
	return o;
}
void ThongTinSanPham::setThongTinSanPham()
{
	cout << "Nhap Ma Model: ";
	cin.getline(MaModel, 10);
	cout << "Nhap Ten Hang: ";
	cin.getline(Hang, 15);
	cout << "Nhap Ten San Pham: ";
	cin.getline(TenSP, 20);
	cout << "Nhap Xuat Xu: ";
	cin.getline(XuatXu, 20);
	cout << "Nhap NSX: ";
	cin.getline(NSX, 15);
}
string ThongTinSanPham::insertQuery()
{
	string t_MaModel(MaModel);
	string t_Hang(Hang);
	string t_TenSP(TenSP);
	string t_XuatXu(XuatXu);
	string t_NSX(NSX);
	string query = t_MaModel + "','" + t_Hang + "','" + t_TenSP + "','" + t_XuatXu + "','" + t_NSX + "')";
	return query;
}