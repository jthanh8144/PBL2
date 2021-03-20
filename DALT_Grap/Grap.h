#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "graphics.h"
#include "AccountAccessGrap.h"
#include "ThongTinNVAccessGrap.h"
#include "HoaDonAccessGrap.h"
#include "XuatKhoAccessGrap.h"
#include "NhapKhoAccessGrap.h"
#include "ThongTinKHAccessGrap.h"
#include "ThongTinSPAccessGrap.h"
#include "KhoAccessGrap.h"

using namespace std;

const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int RIGHT_ARROW = 77;
const int DOWN_ARROW = 80;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;
const int DEL = 127;

const int widthWindow = 1500, maxx = 1499;
const int heightWindow = 800, maxy = 799;
const int hmaxx = maxx / 2;
const int hmaxy = maxy / 2;
const int heightBox = 40, widthBox = 200, marginBox = 25;

int CtoI(char[]);
void ShowNotification(char*);
void Menu1(int);
void BoxMenu2(int);
void Menu2(char*&, char*&);
void ShowMenu3(int, int);
void Menu3(int);
void ShowMenu3_0(int, int);
void Menu3_1(int);
void BoxMenu3_1_2(int);
void Menu3_1_2(int);
void Menu3_2(int);
void BoxMenu3_2_1(int);
void Menu3_2_1(int);
void BoxMenu3_2_2(int);
void Menu3_2_2(int);
void BoxMenu3_3(int);
void ShowBill(char*, char*, int);
void Menu3_3(int);
void ShowMenu3_4(int, int);
void Menu3_4(int);
void BoxMenu3_4_1(int);
void Menu3_4_1(int);
void BoxMenu3_4_2(int);
void Menu3_4_2(int);
void Menu3_4_3(int);
void BoxMenu3_4_3(int);
void Menu3_4_3_1(int, char*);
void Menu3_4_3_0(int, int, char*);
void ShowMenu3_5(int);
void Menu3_5(int);
void BoxMenu3_5_1(int);
void Menu3_5_1(int);
void Show1Staff(int, char*, ThongTinNhanVien);
void Menu3_5_0(int, int);
void ShowMenu3_5_3(int);
void Menu3_5_3(int, char*&);
void Menu3_5_3_0(int, int, char*&);
void ShowMenu3_5_4(int);
void Menu3_5_4(int, char*);
void ShowAllStaff(int);
void Menu3_5_5(int);
void ShowStored(int);
void Menu3_6(int);
void Menu(int&);