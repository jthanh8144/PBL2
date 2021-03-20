#include "ThongTinKhachHang.h"

ThongTinKhachHang::ThongTinKhachHang()
{
    strcpy_s(this->MaKH, "");
    strcpy_s(this->TenKH, "");
    strcpy_s(this->SDT, "");
    strcpy_s(this->DiaChi, "");
}

ThongTinKhachHang::ThongTinKhachHang(char* MaKH, char* TenKH, char* SDT, char* DiaChi)
{
    strcpy_s(this->MaKH, 12, MaKH);
    strcpy_s(this->TenKH, 50, TenKH);
    strcpy_s(this->SDT, 20, SDT);
    strcpy_s(this->DiaChi, 50, DiaChi);
}

ThongTinKhachHang::~ThongTinKhachHang(){

}

char* ThongTinKhachHang::getMaKH()
{
    char* MaKH = this->MaKH;
    for (int i = 0; i < strlen(MaKH); i++) {
        if (MaKH[i] == ' ') {
            MaKH[i] = '\0';
            break;
        }
    }
    return MaKH;
}

char* ThongTinKhachHang::getTenKH()
{
    char* TenKH = this->TenKH;
    for (int i = strlen(TenKH) - 1; i >= 0; i--) {
        if (TenKH[i] != ' ') {
            TenKH[i + 1] = '\0';
            break;
        }
    }
    return TenKH;
}

char* ThongTinKhachHang::getSDT()
{
    char* SDT = this->SDT;
    for (int i = 0; i < strlen(SDT); i++) {
        if (SDT[i] == ' ') {
            SDT[i] = '\0';
            break;
        }
    }
    return SDT;
}

char* ThongTinKhachHang::getDiaChi()
{
    char* DiaChi = this->DiaChi;
    for (int i = strlen(DiaChi) - 1; i >= 0; i--) {
        if (DiaChi[i] != ' ') {
            DiaChi[i + 1] = '\0';
            break;
        }
    }
    return DiaChi;
}

void ThongTinKhachHang::setThongTinKhachHang()
{
    cout << "Nhap Ma Khach Hang: ";
    cin.getline(MaKH, 12);
    cout << "Nhap Ten Khach Hang: ";
    cin.getline(TenKH, 50);
    cout << "Nhap SDT: ";
    cin.getline(SDT, 20);
    cout << "Nhap Dia Chi: ";
    cin.getline(DiaChi, 50);
}
string ThongTinKhachHang::insertQuery()
{
    string t_MaKh(MaKH);
    string t_TenKH(TenKH);
    string t_SDT(SDT);
    string t_DiaChi(DiaChi);
    string query = t_MaKh + "','" + t_TenKH + "','" + t_SDT + "','" + t_DiaChi + "')";
    return query;
}
ostream& operator<<(ostream& o, const ThongTinKhachHang& t)
{
    o << t.MaKH << t.TenKH << t.SDT << t.DiaChi << endl;
    return o;
}
