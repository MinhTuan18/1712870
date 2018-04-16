#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <wchar.h>
#include <stdlib.h>
struct SINHVIEN
{
	wchar_t MSSV[11];
	wchar_t HoTen[31];
	wchar_t Khoa[31];
	short KhoaHoc;
	wchar_t NgaySinh[11];
	wchar_t HinhCaNhan[21];
	wchar_t Mota[1001];
	wchar_t SoThich1[101];
	wchar_t SoThich2[101];
};
typedef struct SINHVIEN SV;
wchar_t** TaoMang(FILE*p, int &n) 
{
	n = 0;
	wchar_t **a = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	while (!feof(p))
	{
		a[n] = (wchar_t*)malloc(1600 * sizeof(wchar_t));
		fgetws(a[n], 1600, p);
		if (!feof(p))
		{
			n++;
			a = (wchar_t**)realloc(a, (n + 1)*sizeof(wchar_t*));
		}
		else
			break;
	}
	return a;
}
void Chuyen(wchar_t *a, wchar_t b[])
{
	for (int i = 0; i < wcslen(a); i++)
	{
		b[i] = *(a + i);
	}
}
void TachThongTin(wchar_t *a, SV* &sv)
{
	wchar_t *s = wcsdup(a);
	wchar_t	**b = (wchar_t**)malloc(9 * sizeof(wchar_t));
	wchar_t *p;
	p = wcstok(a, L",");
	while (p != NULL)
	{
		b[index] = p;
		index++;
		p = wcstok(NULL, L",");
}





  
void DocFile(FILE* p, int &n)
{
	SV *sv;

}

void main()
{
	FILE* fo = _wfopen(L"E:\\mot.html",L"wt,ccs=UTF-8");
	//_setmode(_fileno(fo), _O_U8TEXT);
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(fo, L"		<title>HCMUS - Nguyễn Văn A</title>");
	fwprintf(fo, L"	</head>\n");
	fwprintf(fo, L"	<body>\n");


	fclose(fo);
}