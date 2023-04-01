#include<iostream>
using namespace std;
void nhap(int*& a, int& n)
{
	a = (int*)malloc(100 * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> a[i];
	}
}
void xuat(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void xoa_ptu(int*& a, int& n, int vtxoa)
{
	for (int i = vtxoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void Them_Ptu(int a[], int& n, int ViTriThem, int PhanTuThem)
{
	for (int i = n; i > ViTriThem; i--)
	{
		a[i] = a[i - 1];
	}
	a[ViTriThem] = PhanTuThem;
	n++;
}
void swap(int& a, int& n)
{
	int temp = a;
	a = n;
	n = temp;
}
void dao_so(int* a, int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] % 2 != 0)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (a[i] % 2 == 0)
					swap(a[i], a[j]);
				break;
			}
		}
	}
}
void kiemtraChanle(int a[], int n)
{
	int flag = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) //khong chan le
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "Mang chan le lien tuc";
	else
		cout << "Mang khong chan le lien tuc";
}
void CT(int* a, int& n)
{
	int t = 0;
	try
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (a[i] < a[i + 1] && a[i] < a[i - 1])
			{
				cout << a[i];
				t = 1;
			}
			if (t == 0)
			{
				throw"khong co so cuc tieu ";
			}
		}
	}
	catch (...)
	{
		cout << "mang da cho khong co so cuc tieu ";
	}
}
void main()
{
	int n, vtxoa, chon;
	int ViTriThem, PhanTuThem;
	int* a = new int;
	cout << "nhap n phan tu : ";
	cin >> n;
	nhap(a, n);
	cout << "==============MENU==============" << endl;
	cout << "1. xuat cac so cuc tieu "<<endl;
	cout << "2. xoa ptu tai vi tri k " << endl;
	cout << "3. them ptu x tai vi tri k " << endl;
	cout << "4. chuyen so chan len dau mang so le xuong cuoi mang " << endl;
	cout << "5. kt mang chan le xe ke " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	switch (chon)
	{
	case 1: CT(a, n);
		break;
	case 2: cout << "nhap vi tri can xoa : ";
		cin >> vtxoa;
		xoa_ptu(a, n, vtxoa);
		cout << "mang sau khi xoa la : ";
		xuat(a, n);
		break;
	case 3: do
	{
		cout << "nhap vao vi tri can them : ";
		cin >> ViTriThem;

		if (ViTriThem < 0 || ViTriThem > n)
		{
			cout << "vi tri khong hop le. Xin kiem tra lai ! ";
		}
	} while (ViTriThem < 0 || ViTriThem > n);
	cout << "nhap vao phan tu can them: ";
	cin >> PhanTuThem;
	Them_Ptu(a, n, ViTriThem, PhanTuThem);
	cout << "mang sau khi them la : ";
	xuat(a, n);
	break;
	case 4:
		cout << "mang sau khi da doi la :  ";
		dao_so(a, n);
		xuat(a, n);
		break;
	case 5: kiemtraChanle(a, n);
	default: cout << "cu phap khong hop le vui long nhap lai : ";
		break;
	}
}