#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	cout << "mang vua nhap la : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int KiemTraNguyenTo(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n > 2)
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		for (int i = 3; i <= sqrt((float)n); i += 2)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void Kt_SNT(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i]) == 1)
		{
			cout << a[i] << " ";
		}
	}
}
int Kiem_Tra(int n)
{
	int donvi;
	while (n >= 10)
	{
		donvi = n % 10;
		n /= 10;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	return 1;
}
int tinh_tong(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (Kiem_Tra(a[i]) == 1)
		{
			tong += a[i];
		}
	}
	return tong;
}
bool checkAcept(int num, int c, int b)
{
	int count = 0;
	bool cIsUsed = false;
	bool bIsUsed = false;
	while (num != 0)
	{
		if (count == 2)
		{
			return true;
		}
		int temp = num % 10;
		if (temp == c)
		{
			if (cIsUsed == false)
			{
				cIsUsed = true;
				count++;
			}
		}
		else
		{
			if (bIsUsed == false)
			{
				bIsUsed = true;
				count++;
			}
		}
		num = num / 10;
	}
	if (count != 2)
	{
		return false;
	}
}
void tim(int a[], int n, int x)
{
	int c = x / 10;
	int b = x % 10;
	for (int i = 0; i < n; i++)
	{
		if (checkAcept(a[i], c, b) == true)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void ledauchancuoi(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] % 2 != 0)
			{
				swap(a[i], a[j]);
				break;
			}
			for (int j = n - 1 - i; j >= 0; j--)
			{
				if (a[j] % 2 == 0)
				{
					swap(a[i], a[j]);
					break;
				}
			}
		}
		cout << a[i] << " ";
	}
}
void sap_xep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 == 0)
				{
					if (a[i] < a[j])
					{
						swap(a[i], a[j]);
					}
				}
			}
		}
		cout << a[i] << " ";
	}
}
int main()
{
	int a[50], n, chon, x;
	cout << "nhap n phan tu : ";
	cin >> n;
	nhap(a, n);
	cout << "===============MENU=============== " << endl;
	cout << "1. liet ke cac so ng to nho hon n " << endl;
	cout << "2. tinh tong cac ptu co chu so dau la chu so le " << endl;
	cout << "7. tim a trong cac ptu 2 va 8 " << endl;
	cout << "8. sap xap ptu chan tang, ptu le giu nguyen vi tri " << endl;
	cout << "9. sap xep so le o dau mang, so chan o cuoi mang " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	switch (chon)
	{
	case 1: xuat(a, n);
		cout << "so nguyen to la : ";
		Kt_SNT(a, n);
		break;
	case 2: cout << tinh_tong(a, n);
		break;
	case 7: cout << "nhap x = ";
		cin >> x;
		tim(a, n, x);
		break;
	case 8: cout << "mang sau khi sap xep la : ";
		sap_xep(a, n);
		break;
	case 9: cout << "mang sau khi sap xep la : ";
		ledauchancuoi(a, n);
		break;
	default: cout << "ban nhap sai cu phap moi ban nhap lai . ";
		break;
	}
}