#include "Grap.h"

int CtoI(char c[]) {
	int temp = 0;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] >= 48 && c[i] <= 57) temp = temp * 10 + (c[i] - '0');
		else return 0;
	}
	return temp;
}

void ShowNotification(char* ch) {
	char key;
	char txt[] = "Nhan Enter de tiep tuc";
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(ch) / 2, hmaxy - textheight(ch) / 2, ch);
	settextstyle(3, 0, 2);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	do {
		key = getch();
	} while (key != ENTER);
}

void Menu1(int choice) {
	int lenghtMenu = 0;
	char key;
	char* txt1[] = { "DO AN LAP TRINH", "GVHD: Phan Thanh Tao - Phan Chi Tung", "SVTH: Vo Van Thanh - Nguyen Duy Thinh",
		"De tai: Phan mem quan li cua hang Laptop", "Dang nhap", "Dang xuat", "Nhan Enter de tiep tuc, Esc de thoat chuong trinh" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	settextstyle(3, 0, 4);
	outtextxy(hmaxx - textwidth(txt1[0]) / 2, 20, txt1[0]);
	setcolor(2);
	settextstyle(3, 0, 2);
	outtextxy(hmaxx - textwidth(txt1[1]) / 2, 90, txt1[1]);
	outtextxy(hmaxx - textwidth(txt1[2]) / 2, 120, txt1[2]);
	setcolor(14);
	settextstyle(3, 0, 4);
	outtextxy(hmaxx - textwidth(txt1[3]) / 2, 150, txt1[3]);
	switch (choice) {
	case 1:
		setcolor(4);
		settextstyle(3, 0, 4);
		outtextxy(hmaxx - textwidth(txt1[4]) / 2, hmaxy - textheight(txt1[4]) / 2, txt1[4]);
		setcolor(3);
		settextstyle(3, 0, 2);
		outtextxy(hmaxx - textwidth(txt1[6]) / 2, maxy - 40, txt1[6]);
		do {
			key = getch();
		} while (key != ENTER && key != ESC);
		if (key == ESC) exit(0);
		break;
	case 2:
		setcolor(4);
		settextstyle(3, 0, 4);
		outtextxy(hmaxx - textwidth(txt1[5]) / 2, hmaxy - textheight(txt1[5]) / 2, txt1[5]);
		setcolor(3);
		settextstyle(3, 0, 2);
		outtextxy(hmaxx - textwidth(txt1[6]) / 2, maxy - 40, txt1[6]);
		do {
			key = getch();
		} while (key != ENTER && key != ESC);
		if (key == ESC) exit(0);
		if (key == ENTER) Menu(lenghtMenu);
		break;
	}
	
}

void BoxMenu2(int chooseBox) {
	cleardevice();
	char* txt[] = { "Nhan Enter de dang nhap, ESC de quay lai" , "Tai khoan: ", "Mat khau: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	if (chooseBox == 1) {
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
	}
	else {
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
	}
}

void Menu2(char*& ID, char*& Pass) {
	int i = 0, j = 0, keyPress = 0;
	char tmp, * sao;
	string s;
	ID = new char[15]; ID[i] = '\0';
	Pass = new char[25]; Pass[j] = '\0';
Id:
	cleardevice();
	BoxMenu2(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ID) / 2, ID);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			ID[i] = '\0';
		}
		else if (tmp == ESC) Menu1(1);
		else {
			ID[i] = tmp;
			ID[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu2(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ID) / 2, ID);
	} while (keyPress != ENTER);
	ID[i - 1] = '\0';

	cleardevice();
	BoxMenu2(2);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			j = j <= 0 ? 0 : j - 1;
			Pass[j] = '\0';
			if (!s.empty()) s.erase(s.size() - 1);
		}
		else if (tmp == ESC) goto Id;
		else {
			Pass[j] = tmp;
			Pass[j + 1] = '\0';
			j++;
			if (tmp != ENTER) s += '*';
		}
		sao = const_cast<char*>(s.c_str());
		keyPress = tmp;
		cleardevice();
		BoxMenu2(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sao) / 2, sao);
	} while (keyPress != ENTER);
	Pass[j - 1] = '\0';
}

void ShowMenu3(int choice, int lenMenu) {
	char* txt[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de dang xuat",  
		"Xuat kho", "Nhap kho", "Kho", "In hoa don", "Thong tin khach hang", "Thong tin nhan vien" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	int tmp = maxy / 3;
	for (int i = 0; i < lenMenu; i++) {
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(txt[i+1]) + 10;
		outtextxy(hmaxx - textwidth(txt[i+1]) / 2, tmp, txt[i+1]);
	}
}

void Menu3(int lengthMenu3List) {
	char keyPress;
	int choice = 0;
	ShowMenu3(choice, lengthMenu3List);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3List;
		else if (keyPress == ESC)
			Menu1(2);
		else if (keyPress == DEL) {
			
		}
		ShowMenu3(choice, lengthMenu3List);
	} while (keyPress != ENTER);
	switch (choice) {
		case 0: 
			Menu3_1(lengthMenu3List);
			return;
		case 1:
			Menu3_2(lengthMenu3List);
			return;
		case 2:
			Menu3_6(lengthMenu3List);
			return;
		case 3: 
			Menu3_3(lengthMenu3List);
			return;
		case 4: 
			Menu3_4(lengthMenu3List);
			return;
		case 5: 
			Menu3_5(lengthMenu3List);
			return;
	}
}

void ShowMenu3_0(int choice, int choose) {
	int i = 0;
	char *txt1[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai",
		"Them khach hang moi", "Nhap hoa don", "Xuat kho" },
		*txt2[] = { "Nhap kho", "San pham co san", "San pham moi" },
		*txt3[] = { "Co tiep tuc nhap san pham vao hoa don khong?", "Co", "Khong" };;
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt1[0]) / 2, maxy - 40, txt1[0]);
	int tmp = maxy / 3;
	switch (choose) {
		case 1:
			outtextxy(hmaxx - textwidth(txt1[3]) / 2, 20, txt1[3]);
			for (i = 0; i < 2; i++) {
				i == choice ? setcolor(4) : setcolor(2);
				tmp += textheight(txt1[i + 1]) + 10;
				outtextxy(hmaxx - textwidth(txt1[i + 1]) / 2, tmp, txt1[i + 1]);
			}
			break;
		case 2:
			outtextxy(hmaxx - textwidth(txt2[0]) / 2, 20, txt2[0]);
			for (i = 0; i < 2; i++) {
				i == choice ? setcolor(4) : setcolor(2);
				tmp += textheight(txt2[i + 1]) + 10;
				outtextxy(hmaxx - textwidth(txt2[i + 1]) / 2, tmp, txt2[i + 1]);
			}
			break;
		case 3:
			outtextxy(hmaxx - textwidth(txt3[0]) / 2, 20, txt3[0]);
			for (i = 0; i < 2; i++) {
				i == choice ? setcolor(4) : setcolor(2);
				tmp += textheight(txt3[i + 1]) + 10;
				outtextxy(hmaxx - textwidth(txt3[i + 1]) / 2, tmp, txt3[i + 1]);
			}
			break;
	}
}

void Menu3_1(int lengthMenu3List) {
	char keyPress;
	int choice = 0, lengthMenu3_0List = 2;
	ShowMenu3_0(choice, 1);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_0List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_0List;
		else if (keyPress == ESC)
			Menu3(lengthMenu3List);
		ShowMenu3_0(choice, 1);
	} while (keyPress != ENTER);
	switch (choice) {
		case 0:
			Menu3_4_1(lengthMenu3List);
			return;
		case 1:
			Menu3_1_2(lengthMenu3List);
			return;
	}
}

void BoxMenu3_1_2(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ma hoa don: ", "Ma khach hang: ", "Ma san pham: ",
		"So luong: ", "Thoi gian xuat: ", "Nhan vien xuat: ", "Xuat kho" };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[7]) / 2, 20, txt[7]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
		}
		case 3: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
			break;
		}
		case 4: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]);
			break;
		}
		case 5: {
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]);
			break;
		}
		case 6: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]);
			break;
		}
	}
}

void Menu3_1_2(int lengthMenu3List) {
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = { 0, 0, 0, 0, 0, 0, 0 };
	char tmp;
	char * MHD, * MKH, * MSP, * sl, * TGX, * NVX;
	MHD = new char[15]; MHD[index[0]] = '\0';
	MKH = new char[15]; MKH[index[2]] = '\0';
	MSP = new char[10]; MSP[index[3]] = '\0';
	sl = new char[3]; sl[index[4]] = '\0';
	TGX = new char[15]; TGX[index[5]] = '\0';
	NVX = new char[15]; NVX[index[6]] = '\0';
	int SL = 0;
MaHD:
	cleardevice();
	BoxMenu3_1_2(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MHD) / 2, MHD);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[0] = index[0] <= 0 ? 0 : index[0] - 1;
			MHD[index[0]] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_1(lengthMenu3List);
			break;
		}
		else {
			MHD[index[0]] = tmp;
			MHD[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MHD) / 2, MHD);
	} while (keyPress != ENTER);
	MHD[index[0] - 1] = '\0';
MaKH:
	cleardevice();
	BoxMenu3_1_2(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[2] = index[2] <= 0 ? 0 : index[2] - 1;
			MKH[index[2]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaHD;
			break;
		}
		else {
			MKH[index[2]] = tmp;
			MKH[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	} while (keyPress != ENTER);
	MKH[index[2] - 1] = '\0';
NhanVienXuat:
	cleardevice();
	BoxMenu3_1_2(6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVX) / 2, NVX);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[6] = index[6] <= 0 ? 0 : index[6] - 1;
			NVX[index[6]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaKH;
			break;
		}
		else {
			NVX[index[6]] = tmp;
			NVX[index[6] + 1] = '\0';
			index[6]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVX) / 2, NVX);
	} while (keyPress != ENTER);
	NVX[index[6] - 1] = '\0';
TGXuat:
	cleardevice();
	BoxMenu3_1_2(5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGX) / 2, TGX);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[5] = index[5] <= 0 ? 0 : index[5] - 1;
			TGX[index[5]] = '\0';
		}
		else if (tmp == ESC) {
			goto NhanVienXuat;
			break;
		}
		else {
			TGX[index[5]] = tmp;
			TGX[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGX) / 2, TGX);
	} while (keyPress != ENTER);
	TGX[index[5] - 1] = '\0';
	HoaDonAccessGrap hd;
	hd.Init();
	hd.Insert(MHD, MKH, TGX, NVX);
NhapSanPham:
MaSP:
	index[3] = 0; MSP[index[3]] = '\0';
	cleardevice();
	BoxMenu3_1_2(3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[3] = index[3] <= 0 ? 0 : index[3] - 1;
			MSP[index[3]] = '\0';
		}
		else if (tmp == ESC) {
			goto TGXuat;
			break;
		}
		else {
			MSP[index[3]] = tmp;
			MSP[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	} while (keyPress != ENTER);
	MSP[index[3] - 1] = '\0';
SoLuong:
	index[4] = 0; sl[index[4]] = '\0';
	cleardevice();
	BoxMenu3_1_2(4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[4] = index[4] <= 0 ? 0 : index[4] - 1;
			sl[index[4]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaSP;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("So luong chi gom so!");
		else {
			sl[index[4]] = tmp;
			sl[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1_2(4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	} while (keyPress != ENTER);
	sl[index[4] - 1] = '\0';
	SL = CtoI(sl);
	XuatKhoAccessGrap xk;
	xk.Init();
	xk.Insert(MHD, MSP, SL, xk.getGia(MSP)* SL);
	xk.Close();
	char keyPressLocal;
	int choice = 0, lengthMenu3_0List = 2;
	ShowMenu3_0(choice, 3);
	do {
		keyPressLocal = getch();
		if (keyPressLocal == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_0List - 1 : choice - 1;
		else if (keyPressLocal == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_0List;
		else if (keyPressLocal == ESC)
			goto SoLuong;
		ShowMenu3_0(choice, 3);
	} while (keyPressLocal != ENTER);
	switch (choice) {
		case 0:
			goto NhapSanPham;
			break;
		case 1:
			break;
	}

	hd.UpdateTTT(MHD);
	if (hd.getTongThanhToan(MHD) == 0 || hd.getTongThanhToan(MHD) == -1) 
		ShowNotification("Xuat kho that bai, vui long thu lai sau!");
	else ShowNotification("Xuat kho thanh cong!");
	hd.Close();
	Menu3_1(lengthMenu3List);
}

void Menu3_2(int lengthMenu3List) {
	char keyPress;
	int choice = 0, lengthMenu3_0List = 2;
	ShowMenu3_0(choice, 2);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_0List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_0List;
		else if (keyPress == ESC)
			Menu3(lengthMenu3List);
		ShowMenu3_0(choice, 2);
	} while (keyPress != ENTER);
	switch (choice) {
	case 0:
		Menu3_2_1(lengthMenu3List);
		return;
	case 1:
		Menu3_2_2(lengthMenu3List);
		return;
	}
}

void BoxMenu3_2_1(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ma san pham: ", "So luong: ", "Don gia: ", 
		"Noi nhap: ", "Thoi gian nhap: ", "Nhan vien nhap: ", "Nhap kho" };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[7]) / 2, 20, txt[7]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		case 2:
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
		case 3:
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
			break;
		case 4: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]);
			break;
		case 5:
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]);
			break;
		case 6: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]);
			break;
		case 7:
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 6; i++) {
				outtextxy(50, tmp, txt[i + 1]);
				tmp += textheight(txt[i + 1]) + 10;
			}
			break;
	}
}

void Menu3_2_1(int lengthMenu3List) {
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = { 0, 0, 0, 0, 0, 0 };
	char tmp;
	char* MSP, * sl, * dg, * NN, * TGN, * NVN;
	int SL, DG;
	MSP = new char[10]; MSP[index[0]] = '\0';
	sl = new char[3]; sl[index[1]] = '\0';
	dg = new char[3]; dg[index[2]] = '\0';
	NN = new char[15]; NN[index[3]] = '\0';
	TGN = new char[8]; TGN[index[4]] = '\0';
	NVN = new char[10]; NVN[index[5]] = '\0';
MaSP:
	cleardevice();
	BoxMenu3_2_1(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[0] = index[0] <= 0 ? 0 : index[0] - 1;
			MSP[index[0]] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_2(lengthMenu3List);
			break;
		}
		else {
			MSP[index[0]] = tmp;
			MSP[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	} while (keyPress != ENTER);
	MSP[index[0] - 1] = '\0';
SoLuong:
	cleardevice();
	BoxMenu3_2_1(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[1] = index[1] <= 0 ? 0 : index[1] - 1;
			sl[index[1]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaSP;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("So luong chi gom so!");
		else {
			sl[index[1]] = tmp;
			sl[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	} while (keyPress != ENTER);
	sl[index[1] - 1] = '\0';
	SL = CtoI(sl);
DonGia:
	cleardevice();
	BoxMenu3_2_1(3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[2] = index[2] <= 0 ? 0 : index[2] - 1;
			dg[index[2]] = '\0';
		}
		else if (tmp == ESC) {
			goto SoLuong;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("Don gia chi gom so!");
		else {
			dg[index[2]] = tmp;
			dg[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	} while (keyPress != ENTER);
	dg[index[2] - 1] = '\0';
	DG = CtoI(dg);
NoiNhap:
	cleardevice();
	BoxMenu3_2_1(4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[3] = index[3] <= 0 ? 0 : index[3] - 1;
			NN[index[3]] = '\0';
		}
		else if (tmp == ESC) {
			goto DonGia;
			break;
		}
		else {
			NN[index[3]] = tmp;
			NN[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	} while (keyPress != ENTER);
	NN[index[3] - 1] = '\0';
TGNhap:
	cleardevice();
	BoxMenu3_2_1(5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[4] = index[4] <= 0 ? 0 : index[4] - 1;
			TGN[index[4]] = '\0';
		}
		else if (tmp == ESC) {
			goto NoiNhap;
			break;
		}
		else {
			TGN[index[4]] = tmp;
			TGN[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	} while (keyPress != ENTER);
	TGN[index[4] - 1] = '\0';

	cleardevice();
	BoxMenu3_2_1(6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[5] = index[5] <= 0 ? 0 : index[5] - 1;
			NVN[index[5]] = '\0';
		}
		else if (tmp == ESC) {
			goto TGNhap;
			break;
		}
		else {
			NVN[index[5]] = tmp;
			NVN[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_1(6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	} while (keyPress != ENTER);
	NVN[index[5] - 1] = '\0';

	cleardevice();
	BoxMenu3_2_1(7);
	outtextxy(maxx / 3, temp, MSP);
	temp += textheight(MSP) + 10;
	outtextxy(maxx / 3, temp, sl);
	temp += textheight(sl) + 10;
	outtextxy(maxx / 3, temp, dg);
	temp += textheight(dg) + 10;
	outtextxy(maxx / 3, temp, NN);
	temp += textheight(NN) + 10;
	outtextxy(maxx / 3, temp, TGN);
	temp += textheight(TGN) + 10;
	outtextxy(maxx / 3, temp, NVN);
	getch();
	NhapKhoAccessGrap nk;
	nk.Init();
	if (nk.Insert(MSP, SL, DG, NN, TGN, NVN) == true) ShowNotification("Nhap kho thanh cong!");
	else ShowNotification("Co loi xay ra, vui long kiem tra du lieu nhap vao!");
	nk.Close();
	Menu3_2(lengthMenu3List);
	return;
}

void BoxMenu3_2_2(int choice) {
	cleardevice();
	int tmp = maxy / 6;
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ma san pham: ", "Ma model: ", "Man hinh: ", "CPU: ", "GPU", 
		"RAM: ", "Luu tru: ", "Pin: ", "Khoi luong: ", "Gia: ", "So luong: ", "Noi nhap: ", "Thoi gian nhap: ", "Nhan vien nhap: ", "Nhap kho",
		"Hang: ", "Ten san pham: ", "Xuat xu: ", "Ngay san xuat: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[7]) / 2, 20, txt[15]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
	case 1:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
		break;
	case 2:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
		break;
	case 3:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
		break;
	case 4:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]);
		break;
	case 5:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]);
		break;
	case 6:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]);
		break;
	case 7:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[7]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[7]) / 2, txt[7]);
		break;
	case 8:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[8]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[8]) / 2, txt[8]);
		break;
	case 9:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[9]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[9]) / 2, txt[9]);
		break;
	case 10:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[10]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[10]) / 2, txt[10]);
		break;
	case 11:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[11]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[11]) / 2, txt[11]);
		break;
	case 12:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[12]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[12]) / 2, txt[12]);
		break;
	case 13:
		outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[13]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[13]) / 2, txt[13]);
		break;
	case 14:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[14]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[14]) / 2, txt[14]);
		break;
	case 15:
		setcolor(0);
		rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
		setcolor(3);
		
		for (int i = 0; i < 14; i++) {
			outtextxy(50, tmp, txt[i + 1]);
			tmp += textheight(txt[i + 1]) + 10;
		}
		for (int i = 16; i < 20; i++) {
			outtextxy(50, tmp, txt[i]);
			tmp += textheight(txt[i]) + 10;
		}
		break;
	case 16:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[16]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[16]) / 2, txt[16]);
		break;
	case 17:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[17]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[17]) / 2, txt[17]);
		break;
	case 18:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[18]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[18]) / 2, txt[18]);
		break;
	case 19:
		outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[19]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[19]) / 2, txt[19]);
		break;
	}
}

void Menu3_2_2(int lengthMenu3List) {
	cleardevice();
	int temp = maxy / 6, keyPress = 0, index[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	char tmp;
	char *MSP, *MM, *MH, *CPU, *GPU, *RAM, *LT, *P, *kl, *dg, *sl, *NN, *TGN, *NVN, *Hang, *TSP, *XX, *NSX;
	int Pin, DG, SL;
	float KL;
	MSP = new char[10]; MSP[index[0]] = '\0';
	MM = new char[10]; MM[index[1]] = '\0';
	MH = new char[15]; MH[index[2]] = '\0';
	CPU = new char[25]; CPU[index[3]] = '\0';
	GPU = new char[50]; GPU[index[4]] = '\0';
	RAM = new char[15]; RAM[index[5]] = '\0';
	LT = new char[25]; LT[index[6]] = '\0';
	P = new char[3]; P[index[7]] = '\0';
	kl = new char[10]; kl[index[8]] = '\0';
	dg = new char[3]; dg[index[9]] = '\0';
	sl = new char[3]; sl[index[10]] = '\0';
	NN = new char[15]; NN[index[11]] = '\0';
	TGN = new char[8]; TGN[index[12]] = '\0';
	NVN = new char[10]; NVN[index[13]] = '\0';
	Hang = new char[15]; Hang[index[14]] = '\0';
	TSP = new char[25]; TSP[index[15]] = '\0';
	XX = new char[25]; XX[index[16]] = '\0';
	NSX = new char[15]; NSX[index[17]] = '\0';
MaSP:
	cleardevice();
	BoxMenu3_2_2(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[0] = index[0] <= 0 ? 0 : index[0] - 1;
			MSP[index[0]] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_2(lengthMenu3List);
			break;
		}
		else {
			MSP[index[0]] = tmp;
			MSP[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	} while (keyPress != ENTER);
	MSP[index[0] - 1] = '\0';
MaModel:
	cleardevice();
	BoxMenu3_2_2(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MM) / 2, MM);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[1] = index[1] <= 0 ? 0 : index[1] - 1;
			MM[index[1]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaSP;
			break;
		}
		else {
			MM[index[1]] = tmp;
			MM[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MM) / 2, MM);
	} while (keyPress != ENTER);
	MM[index[1] - 1] = '\0';
ManHinh:///loi o day
	cleardevice();
	BoxMenu3_2_2(3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MH) / 2, MH);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[2] = index[2] <= 0 ? 0 : index[2] - 1;
			MH[index[2]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaModel;
			break;
		}
		else {
			MH[index[2]] = tmp;
			MH[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MH) / 2, MH);
	} while (keyPress != ENTER);
	MH[index[2] - 1] = '\0';
cpu:
	cleardevice();
	BoxMenu3_2_2(4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CPU) / 2, CPU);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[3] = index[3] <= 0 ? 0 : index[3] - 1;
			CPU[index[3]] = '\0';
		}
		else if (tmp == ESC) {
			goto ManHinh;
			break;
		}
		else {
			CPU[index[3]] = tmp;
			CPU[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CPU) / 2, CPU);
	} while (keyPress != ENTER);
	CPU[index[3] - 1] = '\0';
gpu:
	cleardevice();
	BoxMenu3_2_2(5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GPU) / 2, GPU);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[4] = index[4] <= 0 ? 0 : index[4] - 1;
			GPU[index[4]] = '\0';
		}
		else if (tmp == ESC) {
			goto cpu;
			break;
		}
		else {
			GPU[index[4]] = tmp;
			GPU[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GPU) / 2, GPU);
	} while (keyPress != ENTER);
	GPU[index[4] - 1] = '\0';
ram:
	cleardevice();
	BoxMenu3_2_2(6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(RAM) / 2, RAM);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[5] = index[5] <= 0 ? 0 : index[5] - 1;
			RAM[index[5]] = '\0';
		}
		else if (tmp == ESC) {
			goto gpu;
			break;
		}
		else {
			RAM[index[5]] = tmp;
			RAM[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(RAM) / 2, RAM);
	} while (keyPress != ENTER);
	RAM[index[5] - 1] = '\0';
LuuTru:
	cleardevice();
	BoxMenu3_2_2(7);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(LT) / 2, LT);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[6] = index[6] <= 0 ? 0 : index[6] - 1;
			LT[index[6]] = '\0';
		}
		else if (tmp == ESC) {
			goto ram;
			break;
		}
		else {
			LT[index[6]] = tmp;
			LT[index[6] + 1] = '\0';
			index[6]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(7);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(LT) / 2, LT);
	} while (keyPress != ENTER);
	LT[index[6] - 1] = '\0';
pin:
	cleardevice();
	BoxMenu3_2_2(8);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(P) / 2, P);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[7] = index[7] <= 0 ? 0 : index[7] - 1;
			P[index[7]] = '\0';
		}
		else if (tmp == ESC) {
			goto LuuTru;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("Dung luong pin chi gom so!");
		else {
			P[index[7]] = tmp;
			P[index[7] + 1] = '\0';
			index[7]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(8);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(P) / 2, P);
	} while (keyPress != ENTER);
	P[index[7] - 1] = '\0';
	Pin = CtoI(P);
KhoiLuong:
	cleardevice();
	BoxMenu3_2_2(9);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(kl) / 2, kl);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[8] = index[8] <= 0 ? 0 : index[8] - 1;
			kl[index[8]] = '\0';
		}
		else if (tmp == ESC) {
			goto pin;
			break;
		}
		else if (tmp != ENTER && tmp != 46 && (tmp < 48 || tmp > 57)) ShowNotification("Khoi luong chi gom so!");
		else {
			kl[index[8]] = tmp;
			kl[index[8] + 1] = '\0';
			index[8]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(9);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(kl) / 2, kl);
	} while (keyPress != ENTER);
	kl[index[8] - 1] = '\0';
	string Khoiluong(kl);
	KL = stof(Khoiluong);
DonGia:
	cleardevice();
	BoxMenu3_2_2(10);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[9] = index[9] <= 0 ? 0 : index[9] - 1;
			dg[index[9]] = '\0';
		}
		else if (tmp == ESC) {
			goto KhoiLuong;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("Don gia chi gom so!");
		else {
			dg[index[9]] = tmp;
			dg[index[9] + 1] = '\0';
			index[9]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(10);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	} while (keyPress != ENTER);
	dg[index[9] - 1] = '\0';
	DG = CtoI(dg);
SoLuong:
	cleardevice();
	BoxMenu3_2_2(11);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[10] = index[10] <= 0 ? 0 : index[10] - 1;
			sl[index[10]] = '\0';
		}
		else if (tmp == ESC) {
			goto DonGia;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("So luong chi gom so!");
		else {
			sl[index[10]] = tmp;
			sl[index[10] + 1] = '\0';
			index[10]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(11);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	} while (keyPress != ENTER);
	sl[index[10] - 1] = '\0';
	SL = CtoI(sl);
NoiNhap:
	cleardevice();
	BoxMenu3_2_2(12);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[11] = index[11] <= 0 ? 0 : index[11] - 1;
			NN[index[11]] = '\0';
		}
		else if (tmp == ESC) {
			goto SoLuong;
			break;
		}
		else {
			NN[index[11]] = tmp;
			NN[index[11] + 1] = '\0';
			index[11]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(12);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	} while (keyPress != ENTER);
	NN[index[11] - 1] = '\0';
TGNhap:
	cleardevice();
	BoxMenu3_2_2(13);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[12] = index[12] <= 0 ? 0 : index[12] - 1;
			TGN[index[12]] = '\0';
		}
		else if (tmp == ESC) {
			goto NoiNhap;
			break;
		}
		else {
			TGN[index[12]] = tmp;
			TGN[index[12] + 1] = '\0';
			index[12]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(13);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	} while (keyPress != ENTER);
	TGN[index[12] - 1] = '\0';
NVNhap:
	cleardevice();
	BoxMenu3_2_2(14);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[13] = index[13] <= 0 ? 0 : index[13] - 1;
			NVN[index[13]] = '\0';
		}
		else if (tmp == ESC) {
			goto TGNhap;
			break;
		}
		else {
			NVN[index[13]] = tmp;
			NVN[index[13] + 1] = '\0';
			index[13]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(14);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	} while (keyPress != ENTER);
	NVN[index[13] - 1] = '\0';
HANG:
	BoxMenu3_2_2(16);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(Hang) / 2, Hang);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[14] = index[14] <= 0 ? 0 : index[14] - 1;
			Hang[index[14]] = '\0';
		}
		else if (tmp == ESC) {
			goto NVNhap;
			break;
		}
		else {
			Hang[index[14]] = tmp;
			Hang[index[14] + 1] = '\0';
			index[14]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(16);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(Hang) / 2, Hang);
	} while (keyPress != ENTER);
	Hang[index[14] - 1] = '\0';
TenSP:
	BoxMenu3_2_2(17);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TSP) / 2, TSP);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[15] = index[15] <= 0 ? 0 : index[15] - 1;
			TSP[index[15]] = '\0';
		}
		else if (tmp == ESC) {
			goto HANG;
			break;
		}
		else {
			TSP[index[15]] = tmp;
			TSP[index[15] + 1] = '\0';
			index[15]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(17);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TSP) / 2, TSP);
	} while (keyPress != ENTER);
	TSP[index[15] - 1] = '\0';
XuatXu:
	BoxMenu3_2_2(18);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(XX) / 2, XX);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[16] = index[16] <= 0 ? 0 : index[16] - 1;
			XX[index[17]] = '\0';
		}
		else if (tmp == ESC) {
			goto TenSP;
			break;
		}
		else {
			XX[index[16]] = tmp;
			XX[index[16] + 1] = '\0';
			index[16]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(18);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(XX) / 2, XX);
	} while (keyPress != ENTER);
	XX[index[16] - 1] = '\0';

	BoxMenu3_2_2(19);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NSX) / 2, NSX);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[17] = index[17] <= 0 ? 0 : index[17] - 1;
			NSX[index[17]] = '\0';
		}
		else if (tmp == ESC) {
			goto XuatXu;
			break;
		}
		else {
			NSX[index[17]] = tmp;
			NSX[index[17] + 1] = '\0';
			index[17]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2_2(19);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NSX) / 2, NSX);
	} while (keyPress != ENTER);
	NSX[index[17] - 1] = '\0';

	cleardevice();
	BoxMenu3_2_2(15);
	outtextxy(maxx / 3, temp, MSP);
	temp += textheight(MSP) + 10;
	outtextxy(maxx / 3, temp, MM);
	temp += textheight(MM) + 10;
	outtextxy(maxx / 3, temp, MH);
	temp += textheight(MH) + 10;
	outtextxy(maxx / 3, temp, CPU);
	temp += textheight(CPU) + 10;
	outtextxy(maxx / 3, temp, GPU);
	temp += textheight(GPU) + 10;
	outtextxy(maxx / 3, temp, RAM);
	temp += textheight(RAM) + 10;
	outtextxy(maxx / 3, temp, LT);
	temp += textheight(LT) + 10;
	outtextxy(maxx / 3, temp, P);
	temp += textheight(P) + 10;
	outtextxy(maxx / 3, temp, kl);
	temp += textheight(kl) + 10;
	outtextxy(maxx / 3, temp, dg);
	temp += textheight(dg) + 10;
	outtextxy(maxx / 3, temp, sl);
	temp += textheight(sl) + 10;
	outtextxy(maxx / 3, temp, NN);
	temp += textheight(NN) + 10;
	outtextxy(maxx / 3, temp, TGN);
	temp += textheight(TGN) + 10;
	outtextxy(maxx / 3, temp, NVN);
	temp += textheight(NVN) + 10;
	outtextxy(maxx / 3, temp, Hang);
	temp += textheight(Hang) + 10;
	outtextxy(maxx / 3, temp, TSP);
	temp += textheight(TSP) + 10;
	outtextxy(maxx / 3, temp, XX);
	temp += textheight(XX) + 10;
	outtextxy(maxx / 3, temp, NSX);
	getch();
	CauHinhAccessGrap ch;
	NhapKhoAccessGrap nk;
	ThongTinSPAccessGrap sp;
	KhoAccessGrap k;
	sp.Init();
	sp.Insert(MM, Hang, TSP, XX, NSX);
	sp.Close();
	ch.Init();
	ch.Insert(MSP, MM, MH, CPU, GPU, RAM, LT, Pin, KL, DG);
	ch.Close();
	nk.Init();
	nk.Insert(MSP, SL, DG, NN, TGN, NVN);
	nk.Close();
	k.Init();
	if (k.Insert(MSP, SL) == true)
		ShowNotification("Nhap kho thanh cong!");
	else ShowNotification("Co loi xay ra, vui long kiem tra lai!");
	k.Close();
	Menu3_2(lengthMenu3List);
}

void BoxMenu3_3(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Tu ngay: ", "Den ngay: ", "In hoa don: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[3]) / 2, 20, txt[3]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: 
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		case 2: 
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
	}
}

void ShowBill(char* TuNgay, char* DenNgay, int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len giua cac tab, ESC de quay lai", "Ma hoa don", "Ma khach hang", "Tong thanh toan",
		"Thoi gian xuat", "Nhan vien xuat", "In hoa don" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[6]) / 2, 30, txt[6]);
	outtextxy(250, 60, txt[1]);
	outtextxy(450, 60, txt[2]);
	outtextxy(650, 60, txt[3]);
	outtextxy(850, 60, txt[4]);
	outtextxy(1050, 60, txt[5]);
	HoaDonAccessGrap h;
	h.Init();
	HoaDon* ptr = new HoaDon[h.countRowShow(TuNgay, DenNgay)];
	h.InHD(TuNgay, DenNgay, ptr);
	int tmp = 70 + textheight(txt[1]); cout << choice * 10 - 1;
	if (choice * 10 > h.countRowShow(TuNgay, DenNgay)) {
		for (int i = choice * 10 - 10; i < h.countRowShow(TuNgay, DenNgay); i++) {
			outtextxy(250, tmp, ptr[i].getMaHD());
			outtextxy(450, tmp, ptr[i].getMaKH());
			outtextxy(650, tmp, ptr[i].getCharTongThanhToan());
			outtextxy(850, tmp, ptr[i].getThoiGianXuat());
			outtextxy(1050, tmp, ptr[i].getNhanVienXuat());
			tmp += textheight(ptr[i].getMaHD()) + 10;
		}
	}
	else {
		for (int i = choice * 10 - 10; i < choice * 10; i++) {
			outtextxy(250, tmp, ptr[i].getMaHD());
			outtextxy(450, tmp, ptr[i].getMaKH());
			outtextxy(650, tmp, ptr[i].getCharTongThanhToan());
			outtextxy(850, tmp, ptr[i].getThoiGianXuat());
			outtextxy(1050, tmp, ptr[i].getNhanVienXuat());
			tmp += textheight(ptr[i].getMaHD()) + 10;
		}
	}
	h.Close();
}

void Menu3_3(int lengthMenu3List) {
	int i = 0, j = 0, keyPress = 0;
	char tmp;
	char* TN, * DN;
	TN = new char[8]; TN[i] = '\0';
	DN = new char[8]; DN[j] = '\0';
TuNgay:
	cleardevice();
	BoxMenu3_3(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TN) / 2, TN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			TN[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3(lengthMenu3List);
			break;
		}
		else {
			TN[i] = tmp;
			TN[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_3(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TN) / 2, TN);
	} while (keyPress != ENTER);
	TN[i - 1] = '\0';

	cleardevice();
	BoxMenu3_3(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DN) / 2, DN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			j = j <= 0 ? 0 : j - 1;
			DN[j] = '\0';
		}
		else if (tmp == ESC) {
			goto TuNgay;
			break;
		}
		else {
			DN[j] = tmp;
			DN[j + 1] = '\0';
			j++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_3(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DN) / 2, DN);
	} while (keyPress != ENTER);
	DN[j - 1] = '\0';
	//Xu li in hoa don
	int choice = 0, list = 0;
	char keyPressLocal;
	HoaDonAccessGrap h;
	h.Init();
	if (h.countRowShow(TN, DN) % 10 == 0) list = h.countRowShow(TN, DN) / 10;
	else list = h.countRowShow(TN, DN) / 10 + 1;
	ShowBill(TN, DN, choice + 1);
	do {
		keyPressLocal = getch();
		if (keyPressLocal == UP_ARROW)
			choice = (choice - 1) < 0 ? list - 1 : choice - 1;
		else if (keyPressLocal == DOWN_ARROW)
			choice = (choice + 1) % list;
		cout << choice << endl;
		ShowBill(TN, DN, choice + 1);
	} while (keyPressLocal != ESC);
	Menu3(lengthMenu3List);
}

void ShowMenu3_4(int choice, int choose) {
	char* txt1[] = { "Them khach hang", "Tim khach hang", "Cap nhap khach hang",
		"Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai" },
		* txt2[] = { "Ten khach hang", "So dien thoai", "Dia chi" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt1[3]) / 2, maxy - 40, txt1[3]);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	switch (choose)
	{
	case 1:
		for (int i = 0; i < 3; i++) {
			i == choice ? setcolor(4) : setcolor(2);
			tmp += textheight(txt1[i]) + 10;
			outtextxy(hmaxx - textwidth(txt1[i]) / 2, tmp, txt1[i]);
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			i == choice ? setcolor(4) : setcolor(2);
			tmp += textheight(txt2[i]) + 10;
			outtextxy(hmaxx - textwidth(txt2[i]) / 2, tmp, txt2[i]);
		}
		break;
	}
}

void Menu3_4(int lengthMenu3List) {
	char keyPress;
	int choice = 0, lengthMenu3_4List = 3;
	ShowMenu3_4(choice, 1);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_4List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_4List;
		else if (keyPress == ESC)
			Menu3(lengthMenu3List);
		ShowMenu3_4(choice, 1);
	} while (keyPress != ENTER);
	switch (choice) {
		case 0: 
			Menu3_4_1(lengthMenu3List);
			break;
		case 1: 
			Menu3_4_2(lengthMenu3List);
			break;
		case 2:
			Menu3_4_3(lengthMenu3List);
			break;
	}
}

void BoxMenu3_4_1(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ma khach hang: ", "Ten khach hang: ", "SDT: ", "Dia chi: ", "Thong tin khach hang: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[5]) / 2, 20, txt[5]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		case 2: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
		case 3: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
			break;
		case 4: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]);
			break;
		case 5: 
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 4; i++) {
				outtextxy(50, tmp, txt[i + 1]);
				tmp += textheight(txt[i + 1]) + 10;
			}
			break;
	}
}

void Menu3_4_1(int lengthMenu3List) {
	int temp = maxy / 3, keyPress = 0, index[] = { 0, 0, 0, 0, 0 };
	char tmp;
	char* MKH, * TKH, * SDT, * DC;
	MKH = new char[10]; MKH[index[1]] = '\0';
	TKH = new char[45]; TKH[index[2]] = '\0';
	SDT = new char[15]; SDT[index[3]] = '\0';
	DC = new char[50]; DC[index[4]] = '\0';
MaKH:
	cleardevice();
	BoxMenu3_4_1(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[1] = index[1] <= 0 ? 0 : index[1] - 1;
			MKH[index[1]] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_4(lengthMenu3List);
			break;
		}
		else {
			MKH[index[1]] = tmp;
			MKH[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_1(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	} while (keyPress != ENTER);
	MKH[index[1] - 1] = '\0';
TenKH:
	cleardevice();
	BoxMenu3_4_1(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TKH) / 2, TKH);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[2] = index[2] <= 0 ? 0 : index[2] - 1;
			TKH[index[2]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaKH;
			break;
		}
		else {
			TKH[index[2]] = tmp;
			TKH[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_1(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TKH) / 2, TKH);
	} while (keyPress != ENTER);
	TKH[index[2] - 1] = '\0';
SoDT:
	cleardevice();
	BoxMenu3_4_1(3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[3] = index[3] <= 0 ? 0 : index[3] - 1;
			SDT[index[3]] = '\0';
		}
		else if (tmp == ESC) {
			goto TenKH;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("SDT chi gom so!");
		else {
			SDT[index[3]] = tmp;
			SDT[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_1(3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[index[3] - 1] = '\0';

	cleardevice();
	BoxMenu3_4_1(4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[4] = index[4] <= 0 ? 0 : index[4] - 1;
			DC[index[4]] = '\0';
		}
		else if (tmp == ESC) {
			goto SoDT;
			break;
		}
		else {
			DC[index[4]] = tmp;
			DC[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_1(4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	} while (keyPress != ENTER);
	DC[index[4] - 1] = '\0';

	cleardevice();
	BoxMenu3_4_1(5);
	outtextxy(maxx / 3, temp, MKH);
	temp += textheight(MKH) + 10;
	outtextxy(maxx / 3, temp, TKH);
	temp += textheight(TKH) + 10;
	outtextxy(maxx / 3, temp, SDT);
	temp += textheight(SDT) + 10;
	outtextxy(maxx / 3, temp, DC);
	getch();
	ThongTinKHAccessGrap kh;
	kh.Init();
	if (kh.Insert(MKH, TKH, SDT, DC) == true) ShowNotification("Them khach hang thanh cong!");
	else ShowNotification("Them khach hang that bai, vui long kiem tra lai!");
	kh.Close();
	Menu3_4(lengthMenu3List);
}

void BoxMenu3_4_2(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai", "Nhap SDT khach hang: ", 
		"Ma khach hang: ", "Ten khach hang: ", "So dien thoai: ", "Dia chi: ", "Thong tin khach hang" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	switch (choice) {
	case 1:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
		rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
		break;
	case 2:
		outtextxy(hmaxx - textwidth(txt[6])/2, 20, txt[6]);
		int tmp = maxy / 3;
		for (int i = 2; i < 6; i++) {
			outtextxy(50, tmp, txt[i]);
			tmp += textheight(txt[i]) + 10;
		}
		break;
	}
}

void Menu3_4_2(int lengthMenu3List) {
	int i = 0, keyPress = 0;
	char tmp;
	char* SDT;
	SDT = new char[15]; SDT[i] = '\0';

	cleardevice();
	BoxMenu3_4_2(1);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			SDT[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_4(lengthMenu3List);
			return;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("SDT chi gom so!");
		else {
			SDT[i] = tmp;
			SDT[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_2(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[i - 1] = '\0';
	//Xu li tim kiem thong tin khach hang
	int temp = maxy / 3;
	ThongTinKHAccessGrap kh;
	kh.Init();
	if (kh.Search(SDT) == true) {
		cleardevice();
		BoxMenu3_4_2(2);
		outtextxy(maxx / 3, temp, kh.getMKH(SDT));
		temp += textheight(kh.getMKH(SDT)) + 10;
		outtextxy(maxx / 3, temp, kh.getTKH(SDT));
		temp += textheight(kh.getTKH(SDT)) + 10;
		outtextxy(maxx / 3, temp, SDT);
		temp += textheight(SDT) + 10;
		outtextxy(maxx / 3, temp, kh.getDC(SDT));
		getch();
	}
	else ShowNotification("Khong tim thay so dien thoai khach hang vua nhap!");
	Menu3_4(lengthMenu3List);
}

void Menu3_4_3(int lengthMenu3List) {
	int i = 0, keyPress = 0;
	char tmp;
	char* SDT;
	SDT = new char[15]; SDT[i] = '\0';

	cleardevice();
	BoxMenu3_4_2(1);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			SDT[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_4(lengthMenu3List);
			return;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("SDT chi gom so!");
		else {
			SDT[i] = tmp;
			SDT[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_2(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[i - 1] = '\0';
	ThongTinKHAccessGrap kh;
	kh.Init();
	if (kh.Search(SDT) == true) Menu3_4_3_1(lengthMenu3List, SDT);
	else {
		ShowNotification("Khong tim thay so dien thoai khach hang vua nhap!");
		Menu3_4(lengthMenu3List);
	}
}

void BoxMenu3_4_3(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ten khach hang: ", "SDT: ", "Dia chi: ", "Cap nhap khach hang" };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[4]) / 2, 20, txt[4]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
	case 1:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
		break;
	case 2:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
		break;
	case 3:
		outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
		break;
	case 4:
		setcolor(0);
		rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
		setcolor(3);
		int tmp = maxy / 3;
		for (int i = 0; i < 3; i++) {
			outtextxy(50, tmp, txt[i + 1]);
			tmp += textheight(txt[i + 1]) + 10;
		}
		break;
	}
}

void Menu3_4_3_1(int lengthMenu3List, char* SDT) {
	char keyPress;
	int choice = 0, lengthMenu3_4List = 3;
	ShowMenu3_4(choice, 2);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_4List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_4List;
		else if (keyPress == ESC)
			Menu3_4_3(lengthMenu3List);
		ShowMenu3_4(choice, 2);
	} while (keyPress != ENTER);
	switch (choice) {
	case 0:
		Menu3_4_3_0(lengthMenu3List, 1, SDT);
		break;
	case 1:
		Menu3_4_3_0(lengthMenu3List, 2, SDT);
		break;
	case 2:
		Menu3_4_3_0(lengthMenu3List, 3, SDT);
		break;
	}
}

void Menu3_4_3_0(int lengthMenu3List, int choose, char* SDT) {
	int i = 0, keyPress = 0;
	char tmp;
	char* txt;
	txt = new char[15]; txt[i] = '\0';
	cleardevice();
	BoxMenu3_4_3(choose);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			txt[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_4(lengthMenu3List);
			return;
		}
		else if (choose == 2 && tmp != ENTER && (tmp < 48 || tmp > 57)) 
			ShowNotification("SDT chi gom so!");
		else {
			txt[i] = tmp;
			txt[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_4_3(choose);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt) / 2, txt);
	} while (keyPress != ENTER);
	txt[i - 1] = '\0';
	ThongTinKHAccessGrap kh;
	kh.Init();
	switch (choose) {
		case 1:
			if (kh.Update(txt, SDT, 1) == true) ShowNotification("Cap nhap khach hang thanh cong!");
			else ShowNotification("Cap nhap khach hang that bai, vui long thu lai sau!");
			break;
		case 2:
			if (kh.Update(txt, SDT, 2) == true) ShowNotification("Cap nhap khach hang thanh cong!");
			else ShowNotification("Cap nhap khach hang that bai, vui long thu lai sau!");
			break;
		case 3:
			if (kh.Update(txt, SDT, 3) == true) ShowNotification("Cap nhap khach hang thanh cong!");
			else ShowNotification("Cap nhap khach hang that bai, vui long thu lai sau!");
			break;
	}
	kh.Close();
	Menu3_4(lengthMenu3List);
}

void ShowMenu3_5(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai",
		"Them nhan vien", "Tim nhan vien", "Sua nhan vien", "Xoa nhan vien", "Tat ca nhan vien" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	for (int i = 0; i < 5; i++) {
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(txt[i + 1]) + 10;
		outtextxy(hmaxx - textwidth(txt[i + 1]) / 2, tmp, txt[i + 1]);
	}
}

void Menu3_5(int lengthMenu3List) {
	static char* MaNV = "";
	char keyPress;
	int choice = 0, lengthMenu3_5List = 5;
	ShowMenu3_5(choice);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_5List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_5List;
		else if (keyPress == ESC)
			Menu3(lengthMenu3List);
		ShowMenu3_5(choice);
	} while (keyPress != ENTER);
	switch (choice) {
		case 0: 
			Menu3_5_1(lengthMenu3List);
			return;
		case 1: 
			Menu3_5_0(lengthMenu3List, 2);
			return;
		case 2: 
			Menu3_5_0(lengthMenu3List, 3);
			return;
		case 3:
			Menu3_5_0(lengthMenu3List, 4);
			break;
		case 4:
			Menu3_5_5(lengthMenu3List);
			break;
	}
}

void BoxMenu3_5_1(int choice) {
	cleardevice();
	int tmp;
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Ma nhan vien: ", "Ten nhan vien: ", "Ngay sinh: ", 
		"Gioi tinh: ", "SDT", "Chuc vu: ", "Dia chi: ", "Nhap ma nhan vien: ", "Mat khau: ", "Thong tin nhan vien: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[10]) / 2, 20, txt[10]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		case 2: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
		case 3:
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]);
			break;
		case 4: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]);
			break;
		case 5: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]);
			break;
		case 6: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]);
			break;
		case 7: 
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[7]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[7]) / 2, txt[7]);
			break;
		case 8: 
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			tmp = maxy / 3;
			for (int i = 0; i < 7; i++) {
				outtextxy(50, tmp, txt[i + 1]);
				tmp += textheight(txt[i + 1]) + 10;
			}
			break;
		case 9:
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[8]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[8]) / 2, txt[8]);
			break;
		case 10:
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[9]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[9]) / 2, txt[9]);
			break;
	}
}

void Menu3_5_1(int lengthMenu3List) {
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = { 0, 0, 0, 0, 0, 0, 0 };
	char tmp;
	char* MNV, * TNV, * NS, * GT, * SDT, * CV, * DC;
	MNV = new char[10]; MNV[index[0]] = '\0';
	TNV = new char[45]; TNV[index[1]] = '\0';
	NS = new char[8]; NS[index[2]] = '\0';
	GT = new char[5]; GT[index[3]] = '\0';
	SDT = new char[15]; SDT[index[4]] = '\0';
	CV = new char[15]; CV[index[5]] = '\0';
	DC = new char[50]; DC[index[6]] = '\0';
MaNV:
	cleardevice();
	BoxMenu3_5_1(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[0] = index[0] <= 0 ? 0 : index[0] - 1;
			MNV[index[0]] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_5(lengthMenu3List);
			break;
		}
		else {
			MNV[index[0]] = tmp;
			MNV[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	} while (keyPress != ENTER);
	MNV[index[0] - 1] = '\0';
TenNV:
	cleardevice();
	BoxMenu3_5_1(2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TNV) / 2, TNV);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[1] = index[1] <= 0 ? 0 : index[1] - 1;
			TNV[index[1]] = '\0';
		}
		else if (tmp == ESC) {
			goto MaNV;
			break;
		}
		else {
			TNV[index[1]] = tmp;
			TNV[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TNV) / 2, TNV);
	} while (keyPress != ENTER);
	TNV[index[1] - 1] = '\0';
NgaySinh:
	cleardevice();
	BoxMenu3_5_1(3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NS) / 2, NS);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[2] = index[2] <= 0 ? 0 : index[2] - 1;
			NS[index[2]] = '\0';
		}
		else if (tmp == ESC) {
			goto TenNV;
			break;
		}
		else {
			NS[index[2]] = tmp;
			NS[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NS) / 2, NS);
	} while (keyPress != ENTER);
	NS[index[2] - 1] = '\0';
GioiTinh:
	cleardevice();
	BoxMenu3_5_1(4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GT) / 2, GT);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[3] = index[3] <= 0 ? 0 : index[3] - 1;
			GT[index[3]] = '\0';
		}
		else if (tmp == ESC) {
			goto NgaySinh;
			break;
		}
		else {
			GT[index[3]] = tmp;
			GT[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GT) / 2, GT);
	} while (keyPress != ENTER);
	GT[index[3] - 1] = '\0';
SoDT:
	cleardevice();
	BoxMenu3_5_1(5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[4] = index[4] <= 0 ? 0 : index[4] - 1;
			SDT[index[4]] = '\0';
		}
		else if (tmp == ESC) {
			goto GioiTinh;
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("SDT chi gom so!");
		else {
			SDT[index[4]] = tmp;
			SDT[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[index[4] - 1] = '\0';
ChucVu:
	cleardevice();
	BoxMenu3_5_1(6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CV) / 2, CV);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[5] = index[5] <= 0 ? 0 : index[5] - 1;
			CV[index[5]] = '\0';
		}
		else if (tmp == ESC) {
			goto SoDT;
			break;
		}
		else {
			CV[index[5]] = tmp;
			CV[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CV) / 2, CV);
	} while (keyPress != ENTER);
	CV[index[5] - 1] = '\0';

	cleardevice();
	BoxMenu3_5_1(7);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			index[6] = index[6] <= 0 ? 0 : index[6] - 1;
			DC[index[6]] = '\0';
		}
		else if (tmp == ESC) {
			goto ChucVu;
			break;
		}
		else {
			DC[index[6]] = tmp;
			DC[index[6] + 1] = '\0';
			index[6]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(7);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	} while (keyPress != ENTER);
	DC[index[6] - 1] = '\0';

	cleardevice();
	BoxMenu3_5_1(8);
	outtextxy(maxx / 3, temp, MNV);
	temp += textheight(MNV) + 10;
	outtextxy(maxx / 3, temp, TNV);
	temp += textheight(TNV) + 10;
	outtextxy(maxx / 3, temp, NS);
	temp += textheight(NS) + 10;
	outtextxy(maxx / 3, temp, GT);
	temp += textheight(GT) + 10;
	outtextxy(maxx / 3, temp, SDT);
	temp += textheight(SDT) + 10;
	outtextxy(maxx / 3, temp, CV);
	temp += textheight(CV) + 10;
	outtextxy(maxx / 3, temp, DC);
	ThongTinNVAccessGrap nv;
	nv.Init();
	if (nv.Insert(MNV, TNV, NS, GT, SDT, CV, DC) == true) ShowNotification("Them nhan vien thanh cong!");
	else ShowNotification("Them nhan vien that bai, vui long kiem tra lai!");
	nv.Close();
	getch();
	Menu3_5(lengthMenu3List);
}

void Show1Staff(int lengthMenu3List, char* MNV, ThongTinNhanVien nv) {
	int temp = maxy / 3;
	BoxMenu3_5_1(8);
	outtextxy(maxx / 3, temp, MNV);
	temp += textheight(MNV) + 10;
	outtextxy(maxx / 3, temp, nv.getHoTen());
	temp += textheight(nv.getHoTen()) + 10;
	outtextxy(maxx / 3, temp, nv.getNgaySinh());
	temp += textheight(nv.getNgaySinh()) + 10;
	outtextxy(maxx / 3, temp, nv.getGioiTinh());
	temp += textheight(nv.getGioiTinh()) + 10;
	outtextxy(maxx / 3, temp, nv.getSDT());
	temp += textheight(nv.getSDT()) + 10;
	outtextxy(maxx / 3, temp, nv.getChucVu());
	temp += textheight(nv.getChucVu()) + 10;
	outtextxy(maxx / 3, temp, nv.getDiaChi());
	getch();
	Menu3_5(lengthMenu3List);
}

void Menu3_5_0(int lengthMenu3List, int choose) {
	int i = 0, keyPress = 0;
	char tmp;
	char* MNV;
	MNV = new char[15];

	cleardevice();
	BoxMenu3_5_1(9);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			MNV[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_5(lengthMenu3List);
			return;
		}
		else {
			MNV[i] = tmp;
			MNV[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(9);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	} while (keyPress != ENTER);
	MNV[i - 1] = '\0';
	int temp = maxy / 3;
	ThongTinNVAccessGrap nv;
	nv.Init();
	ThongTinNhanVien* ptr = new ThongTinNhanVien[nv.countRow()];
	nv.Select(ptr);
	for (int j = 0; j < nv.countRow(); j++) {
		if (strcmp(ptr[j].getMaNV(), MNV) == 0) {
			nv.Close();
			switch (choose) {
			case 2:
				Show1Staff(lengthMenu3List, MNV, ptr[j]);
				break;
			case 3:
				Menu3_5_3(lengthMenu3List, MNV);
				break;
			case 4:
				Menu3_5_4(lengthMenu3List, MNV);
				break;
			}
			return;
		}
	}
	nv.Close();
	ShowNotification("Ma nhan vien khong ton tai!");
	Menu3_5(lengthMenu3List);
}

void ShowMenu3_5_3(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai",
		"Ten nhan vien", "Ngay sinh", "Gioi tinh", "So dien thoai", "Chuc vu", "Dia chi", "Mat khau" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	for (int i = 0; i < 7; i++) {
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(txt[i + 1]) + 10;
		outtextxy(hmaxx - textwidth(txt[i + 1]) / 2, tmp, txt[i + 1]);
	}
}

void Menu3_5_3(int lengthMenu3List, char* &MaNV) {
	char keyPress;
	int choice = 0, lengthMenu3_5List = 7;
	ShowMenu3_5_3(choice);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_5List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_5List;
		else if (keyPress == ESC)
			Menu3_5(lengthMenu3List);
		ShowMenu3_5_3(choice);
	} while (keyPress != ENTER);
	switch (choice) {
	case 0:
		Menu3_5_3_0(lengthMenu3List, 2, MaNV);
		return;
	case 1:
		Menu3_5_3_0(lengthMenu3List, 3, MaNV);
		return;
	case 2:
		Menu3_5_3_0(lengthMenu3List, 4, MaNV);
		return;
	case 3:
		Menu3_5_3_0(lengthMenu3List, 5, MaNV);
		return;
	case 4:
		Menu3_5_3_0(lengthMenu3List, 6, MaNV);
		return;
	case 5:
		Menu3_5_3_0(lengthMenu3List, 7, MaNV);
		return;
	case 6:
		Menu3_5_3_0(lengthMenu3List, 10, MaNV);
		return;
	}
}

void Menu3_5_3_0(int lengthMenu3List, int choose, char* &MaNV) {
	int i = 0, keyPress = 0;
	char tmp;
	char* txt;
	txt = new char[50]; txt[i] = '\0';
	cleardevice();
	BoxMenu3_5_1(choose);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			txt[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3_5(lengthMenu3List);
			return;
		}
		else if (choose == 5 && tmp != ENTER && (tmp < 48 || tmp > 57))
			ShowNotification("SDT chi gom so!");
		else {
			txt[i] = tmp;
			txt[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_5_1(choose);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt) / 2, txt);
	} while (keyPress != ENTER);
	txt[i - 1] = '\0';
	ThongTinNVAccessGrap nv;
	nv.Init();
	switch (choose) {
	case 2:
		if (nv.Update(txt, MaNV, 1) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
	case 3:
		if (nv.Update(txt, MaNV, 2) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
		break;
	case 4:
		if (nv.Update(txt, MaNV, 3) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
	case 5:
		if (nv.Update(txt, MaNV, 4) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
	case 6:
		if (nv.Update(txt, MaNV, 5) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
	case 7:
		if (nv.Update(txt, MaNV, 6) == true) ShowNotification("Cap nhap nhan vien thanh cong!");
		else ShowNotification("Cap nhap nhan vien that bai, vui long thu lai sau!");
		break;
	case 10:
		AccountAccessGrap acc;
		acc.Init();
		if (acc.Update(txt, MaNV) == true) ShowNotification("Cap nhap mat khau nhan vien thanh cong!");
		else ShowNotification("Cap nhap mat khau nhan vien that bai, vui long thu lai sau!");
		acc.Close();
		break;
	}
	nv.Close();
	Menu3_5_3(lengthMenu3List, MaNV);
}

void ShowMenu3_5_4(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai",
		"Co", "Khong" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	for (int i = 0; i < 2; i++) {
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(txt[i + 1]) + 10;
		outtextxy(hmaxx - textwidth(txt[i + 1]) / 2, tmp, txt[i + 1]);
	}
}

void Menu3_5_4(int lengthMenu3List, char* MaNV) {
	char keyPress;
	int choice = 0, lengthMenu3_5List = 2;
	ShowMenu3_5_4(choice);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_5List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_5List;
		else if (keyPress == ESC)
			Menu3_5(lengthMenu3List);
		ShowMenu3_5_4(choice);
	} while (keyPress != ENTER);
	ThongTinNVAccessGrap nv;
	switch (choice) {
		case 0:
			nv.Init();
			if (nv.Delete(MaNV) == true) ShowNotification("Xoa nhan vien thanh cong!");
			else ShowNotification("Xoa nhan vien that bai, vui long thu lai!");
			nv.Close();
			break;
		case 1:
			Menu3_5(lengthMenu3List);
			break;
	}
	Menu3_5(lengthMenu3List);
}

void ShowAllStaff(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len giua cac tab, ESC de quay lai", "MaNV", "Ho ten", "Ngay sinh",
		"Gioi tinh", "So dien thoai", "Chuc vu", "Dia chi", "Thong tin nhan vien" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[8]) / 2, 30, txt[8]);
	outtextxy(30, 60, txt[1]);
	outtextxy(180, 60, txt[2]);
	outtextxy(450, 60, txt[3]);
	outtextxy(650, 60, txt[4]);
	outtextxy(800, 60, txt[5]);
	outtextxy(950, 60, txt[6]);
	outtextxy(1100, 60, txt[7]);
	ThongTinNVAccessGrap nv;
	nv.Init();
	ThongTinNhanVien* ptr = new ThongTinNhanVien[nv.countRow()];
	nv.Select(ptr);
	int tmp = 70 + textheight(txt[1]);
	if (choice *10 > nv.countRow()) {
		for (int i = choice * 10 - 10; i < nv.countRow(); i++) {
			outtextxy(30, tmp, ptr[i].getMaNV());
			outtextxy(180, tmp, ptr[i].getHoTen());
			outtextxy(450, tmp, ptr[i].getNgaySinh());
			outtextxy(650, tmp, ptr[i].getGioiTinh());
			outtextxy(800, tmp, ptr[i].getSDT());
			outtextxy(950, tmp, ptr[i].getChucVu());
			outtextxy(1100, tmp, ptr[i].getDiaChi());
			tmp += textheight(ptr[i].getMaNV()) + 10;
		}
	}
	else {
		for (int i = choice * 10 - 10; i < choice * 10; i++) {
			outtextxy(30, tmp, ptr[i].getMaNV());
			outtextxy(180, tmp, ptr[i].getHoTen());
			outtextxy(450, tmp, ptr[i].getNgaySinh());
			outtextxy(650, tmp, ptr[i].getGioiTinh());
			outtextxy(800, tmp, ptr[i].getSDT());
			outtextxy(950, tmp, ptr[i].getChucVu());
			outtextxy(1100, tmp, ptr[i].getDiaChi());
			tmp += textheight(ptr[i].getMaNV()) + 10;
		}
	}
	nv.Close();
}

void Menu3_5_5(int lengthMenu3List) {
	int choice = 0, list = 0;
	char keyPress;
	ThongTinNVAccessGrap nv;
	nv.Init();
	if (nv.countRow() % 10 == 0) list = nv.countRow() / 10;
	else list = nv.countRow() / 10 + 1;
	ShowAllStaff(choice + 1);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? list - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % list;
		ShowAllStaff(choice + 1);
	} while (keyPress != ESC);
	Menu3_5(lengthMenu3List);
}

void ShowStored(int choice) {
	char* txt[] = { "Dung phim mui ten de di chuyen len giua cac tab, ESC de quay lai", "Ma san pham", "So luong", "Kho" };
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[3]) / 2, 30, txt[3]);
	outtextxy(600, 60, txt[1]);
	outtextxy(800, 60, txt[2]);
	KhoAccessGrap k;
	k.Init();
	Kho* ptr = new Kho[k.countRow()];
	k.Select(ptr);
	int tmp = 70 + textheight(txt[1]);
	if (choice * 10 > k.countRow()) {
		for (int i = choice * 10 - 10; i < k.countRow(); i++) {
			outtextxy(600, tmp, ptr[i].getMaSP());
			outtextxy(800, tmp, ptr[i].getCharSoLuong());
			tmp += textheight(ptr[i].getMaSP()) + 10;
		}
	}
	else {
		for (int i = choice * 10 - 10; i < choice * 10; i++) {
			outtextxy(600, tmp, ptr[i].getMaSP());
			outtextxy(800, tmp, ptr[i].getCharSoLuong());
			tmp += textheight(ptr[i].getMaSP()) + 10;
		}
	}
	k.Close();
}

void Menu3_6(int lengthMenu3List) {
	int choice = 0, list = 0;
	char keyPress;
	KhoAccessGrap k;
	k.Init();
	if (k.countRow() % 10 == 0) list = k.countRow() / 10;
	else list = k.countRow() / 10 + 1;
	ShowStored(choice + 1);
	do {
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? list - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % list;
		ShowStored(choice + 1);
	} while (keyPress != ESC);
	Menu3(lengthMenu3List);
}

void Menu(int& lenghtMenu) {
	AccountAccessGrap acc;
	acc.checkConnect();
	acc.Init();
	Menu1(1);
	acc.checkLogin(lenghtMenu);
	Menu3(lenghtMenu);
	acc.Close();
}