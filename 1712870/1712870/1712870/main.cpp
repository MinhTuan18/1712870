#include "khaibao.h"
void main()
{
	int n = 0;
	FILE* inp = _wfopen(L"Data.csv", L"r");
	_setmode(_fileno(inp), _O_U8TEXT);
	if (inp == NULL)
	{
		printf("Khong mo duoc tap tin!\n");
		return;
	}
	wchar_t **data = DocVaoChuoi(inp, n);

	for (int i = 0; i <= n; i++)
	{
		XuLi(data[i]);
	}
	printf("Thanh cong\n");
	for (int j = 0; j <= n; j++)
		free(data[j]);
	free(data);
	fclose(inp);
}