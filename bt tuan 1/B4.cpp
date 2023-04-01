#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void nhapM1C (int * &a, int &n)
{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
	a = (int *)malloc(10*sizeof(int)); // cấp phát a co 10 phần tử
	n = 10;
	for(int i = 0; i < n; i++)
	*(a+i) = rand()%100;
}
void xuatM1C(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a+i), a+i);
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a+i);
	}
}
void main()
{
	int *a = new int, n=0;
	nhapM1C(a, n);
	xuatM1C(a, n);
	getch();
}