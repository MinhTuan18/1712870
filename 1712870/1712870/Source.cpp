﻿#include "khaibao.h"
void DoiKiTu(wchar_t a[], int i, int j)
{
	for (i; i < j; i++)
	{
		if (a[i] == L',') a[i] = L'*';
	}
}

wchar_t * upper(wchar_t* line){
	wchar_t* temp = (wchar_t *)malloc((wcslen(line) + 1)*sizeof(wchar_t));
	for (int i = 0; i < wcslen(line); i++){
		if (line[i] >= 256 && line[i] % 2 != 0)
			temp[i] = line[i] - 1;
		else if (line[i] == 32 || (line[i] >= 256 && line[i] % 2 == 0) || (line[i] >= 65 && line[i] <= 90))
			temp[i] = line[i];
		else
			temp[i] = line[i] - 32;

	}
	temp[wcslen(line)] = L'\0';
	return temp;
}

void XuLiChuoi(wchar_t a[])//Kiem tra chuoi co dau " hay khong va xu li
{
	int length = wcslen(a), i = 0;

	while (i<length)
	{
		if (a[i] == L'\"')

		{
			for (int j = i + 1; j < length; j++)
			{
				if (a[j] == L'"')
				{
					DoiKiTu(a, i, j);
					i = j + 1;
					break;
				}
			}
		}
		else
			i++;
	}
}

wchar_t** DocVaoChuoi(FILE*p, int &n)
{
	n = 0;
	wchar_t **a = (wchar_t**)malloc(100 * sizeof(wchar_t*));
	a[n] = (wchar_t*)malloc(1400 * sizeof(wchar_t));

	a[n] = fgetws(a[n], 1400, p);

	while (a[n] != NULL)
	{
		XuLiChuoi(a[n]);
		n++;
		a[n] = (wchar_t*)malloc(1400 * sizeof(wchar_t));
		a[n] = fgetws(a[n], 1400, p);
	}
	a = (wchar_t**)realloc(a, (n)*sizeof(wchar_t*));
	n--;
	return a;
}

void TraLaiKiTu(wchar_t *a)
{
	int n = wcslen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == L'*') a[i] = L',';
	}
	if (a[0] == L'\"')
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		a[n - 2] = L'\0';
		if (a[n - 3] == L'\"')
			a[n - 3] = L'\0';
	}
}

void ChuyenChuoi(wchar_t *a, wchar_t b[])
{
	for (int i = 0; i < wcslen(a); i++)
	{
		b[i] = a[i];
	}
}

SV* TachThongTin(wchar_t *a)
{
	SV *sv = (SV*)malloc(sizeof(SV));
	wcscpy(sv->SoThich1, L"");
	wcscpy(sv->SoThich2, L"");
	swscanf(a, L"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", &sv->MSSV, &sv->HoTen, &sv->Khoa, &sv->KhoaHoc, &sv->NgaySinh, &sv->Email, &sv->HinhCaNhan, &sv->Mota, &sv->SoThich1, &sv->SoThich2);
	TraLaiKiTu(sv->MSSV);
	TraLaiKiTu(sv->HoTen);
	TraLaiKiTu(sv->Khoa);
	TraLaiKiTu(sv->NgaySinh);
	TraLaiKiTu(sv->Email);
	TraLaiKiTu(sv->HinhCaNhan);
	TraLaiKiTu(sv->Mota);
	TraLaiKiTu(sv->SoThich1);
	TraLaiKiTu(sv->SoThich2);
	return sv;
}

void InHTML(SV *sv)
{
	wchar_t filename[20];
	wcscpy(filename, sv->MSSV);
	wcscat(filename, L".html");
	wchar_t *khoa = upper(sv->Khoa);
	FILE *out = _wfopen(filename, L"wt");
	_setmode(_fileno(out), _O_U8TEXT);
	fwprintf(out, L"<!DOCTYPE html PUBLIC\" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(out, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(out, L"	<head>\n");
	fwprintf(out, L"		<meta http-equiv=\"Content-Type\" content=\"text / html; charset=utf-8\" />\n");
	fwprintf(out, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(out, L"		<title>HCMUS - %ls</title>\n", sv->HoTen);
	fwprintf(out, L"	</head>\n");
	fwprintf(out, L"	<body>\n");
	fwprintf(out, L"		<div class=\"Layout_container\">\n");
	fwprintf(out, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(out, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(out, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\"height=\"105\" /></div>\n");
	fwprintf(out, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
	fwprintf(out, L"			</div>\n");
	fwprintf(out, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(out, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(out, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(out, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(out, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(out, L"					<!-- Begin Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(out, L"					<div class=\"Personal_Location\">\n");
	fwprintf(out, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(out, L"						<div class=\"Personal_FullName\">%ls - %ls</div>\n", sv->HoTen, sv->MSSV);
	fwprintf(out, L"						<div class=\"Personal_Department\">KHOA %ls</div>\n", khoa);
	fwprintf(out, L"						<br />\n");
	fwprintf(out, L"						<div class=\"Personal_Phone\">\n");
	fwprintf(out, L"							Email: %ls", sv->Email);
	fwprintf(out, L"						</div>\n");
	fwprintf(out, L"						<br />\n");
	fwprintf(out, L"						<br />\n");
	fwprintf(out, L"					</div>\n");
	fwprintf(out, L"					<!-- End Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(out, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(out, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->HinhCaNhan);
	fwprintf(out, L"					</div>\n");
	fwprintf(out, L"				</div>\n");
	fwprintf(out, L"				<!-- End Below Banner Region -->\n");
	fwprintf(out, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(out, L"				<div class=\"MainContain\">\n");
	fwprintf(out, L"\n");
	fwprintf(out, L"					<!-- Begin Top Region -->\n");
	fwprintf(out, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(out, L"\n");
	fwprintf(out, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(out, L"						<div>\n");
	fwprintf(out, L"							<ul class=\"TextInList\">\n");
	fwprintf(out, L"								<li>Họ và tên: %ls</li>\n", sv->HoTen);
	fwprintf(out, L"								<li>MSSV: %ls</li>\n", sv->MSSV);
	fwprintf(out, L"								<li>Sinh viên khoa %ls</li>\n", sv->Khoa);
	fwprintf(out, L"								<li>Ngày sinh: %ls</li>\n", sv->NgaySinh);
	fwprintf(out, L"								<li>Email: %ls</li>\n", sv->Email);
	fwprintf(out, L"							</ul>\n");
	fwprintf(out, L"						</div>\n");
	if (wcscmp(sv->SoThich1, L"") != 0)
	{
		fwprintf(out, L"						<div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(out, L"						<div>\n");
		fwprintf(out, L"							<ul class=\"TextInList\">\n");
		fwprintf(out, L"								<li>%ls</li>\n", sv->SoThich1);
		if (wcscmp(sv->SoThich2, L"") != 0)
			fwprintf(out, L"								<li>%ls</li>\n", sv->SoThich2);
		fwprintf(out, L"							</ul>\n");
		fwprintf(out, L"						</div>\n");
	}
	fwprintf(out, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(out, L"						<div class=\"Description\">\n");
	fwprintf(out, L"							%ls\n", sv->Mota);
	fwprintf(out, L"						</div>\n");
	fwprintf(out, L"					</div>\n");
	fwprintf(out, L"				</div>\n");
	fwprintf(out, L"			</div>\n");
	fwprintf(out, L"\n");
	fwprintf(out, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(out, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(out, L"				<div class=\"divCopyright\">\n");
	fwprintf(out, L"					<br />\n");
	fwprintf(out, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(out, L"					<br />\n");
	fwprintf(out, L"					@2018</br>\n");
	fwprintf(out, L"					Đồ án giữ kỳ</br>\n");
	fwprintf(out, L"				Kỹ thuật lập trình</br>\n");
	fwprintf(out, L"				TH2018/04</br>\n");
	fwprintf(out, L"				1712870 - Hồ Minh Tuấn</br>\n");
	fwprintf(out, L"				</div>\n");
	fwprintf(out, L"			</div>\n");
	fwprintf(out, L"			<!-- End Layout Footer -->\n");
	fwprintf(out, L"		</div>\n");
	fwprintf(out, L"	</body>\n");
	fwprintf(out, L"</html>\n");
	fclose(out);
}

void XuLi(wchar_t *a)
{
	SV *sv = (SV*)malloc(sizeof(SV));
	sv = TachThongTin(a);
	InHTML(sv);
}