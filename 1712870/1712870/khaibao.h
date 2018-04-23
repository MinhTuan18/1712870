#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <wchar.h>
#include <stdlib.h>
#include <fcntl.h>
struct SINHVIEN
{
	wchar_t MSSV[11];
	wchar_t HoTen[31];
	wchar_t Khoa[31];
	int KhoaHoc;
	wchar_t NgaySinh[11];
	wchar_t Email[30];
	wchar_t HinhCaNhan[21];
	wchar_t Mota[1001];
	wchar_t SoThich1[101];
	wchar_t SoThich2[101];
}; 
typedef struct SINHVIEN SV;
void DoiKiTu(wchar_t a[], int i, int j);
void XuLiChuoi(wchar_t a[]);
wchar_t** DocVaoChuoi(FILE*p, int &n);
void TraLaiKiTu(wchar_t *a);
void ChuyenChuoi(wchar_t *a, wchar_t b[]);
SV* TachThongTin(wchar_t *a);
void InHTML(SV *sv);
void XuLi(wchar_t *a);