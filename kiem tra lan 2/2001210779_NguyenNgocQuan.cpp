#include <iostream>
#include <string>
using namespace std;
void nhap(int a[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> a[i];
	}
}
void xuat(int a[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int Fibo(int b) 
{
	 if ( b <3 ) 
		return 1 ; 
	else 
		return (Fibo(b -1) + Fibo(b -2)) ; 
} 
int Fibo1(int b)
{
    int a1 = 1, a2 = 1;
    if (b == 1 || b == 2)
        return 1;
    int i = 3, a;
    while (i <= b)
    {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
        i++;
    }
    return a;
}
int kt_pt_chua_so_3(int n)
{
	if (n == 0) 
		return 0;
	else
	{
		if (n % 10 == 3) return 1;
		kt_pt_chua_so_3(n / 10);
	}

}
int pt_chua_so_3(int a[50], int n)
{
	if (n < 0)
		return 0;
	else {
		if (kt_pt_chua_so_3(a[n])) 
			cout<<a[n];
		pt_chua_so_3(a, n - 1);
	}
}
int pt_le_lon_nhat(int a[50], int n, int max)
{
	if (n < 0) 
		return max;
	else
	{
		if (a[n] % 2 == 1)
			if (a[n] > max) max = a[n];
		pt_le_lon_nhat(a, n - 1, max);
	}
}
int kt_pt_3_chu_so(int n, int dem)
{
	if (n == 0)
	{
		if (dem == 0) return 1;
		else return 0;
	}
	else
	{
		kt_pt_3_chu_so(n / 10, dem - 1);
	}
}
int xuat_pt_3_chu_so(int a[50], int n)
{
	if (n < 0) 
		return 0;
	else {
		if (kt_pt_3_chu_so(a[n], 3))
			cout<<a[n];
		xuat_pt_3_chu_so(a, n - 1);
	}
}
int dq_chu_so_lon_nhat(int n, int max)
{
	if (n == 0)
		return max;
	else
	{
		if (n % 10 > max) max = n % 10;
		dq_chu_so_lon_nhat(n / 10, max);
	}
}
//khong de quy
int chu_so_lon_nhat(int n)
{
	int max = 0;
	while (n)
	{
		if (n % 10 > max) max = n % 10;
		n /= 10;
	}
	return max;
}
//dequy
int dq_kt_toan_le(int b)
{
	if (b == 0) 
		return 1;
	else
	{
		if ((b % 10) % 2 == 0) 
			return 0;
		dq_kt_toan_le(b / 10);
	}
}
//khong de quy
bool kt_le(int n)
{
	int temp;
	while (n > 0)
	{
		temp = n % 10;
		if (temp % 2 != 1)
		{
			return false;
		}
		n = n / 10;
	}
	return true;

}

struct Nhathuoc
{
	string ma_thuoc, ten_thuoc, nha_sx, dang_thuoc, cong_dung;
	float don_gia;
};
void nhap_thong_tin(Nhathuoc& x)
{
	while (getchar() != '\n');
	cout << "nhap ma thuoc : ";
	getline(cin, x.ma_thuoc);

	cout << "nhap ten thuoc : ";
	getline(cin, x.ten_thuoc);

	cout << "nhap nha san xuat : ";
	getline(cin, x.nha_sx);

	cout << "nhap dang thuoc : ";
	getline(cin, x.dang_thuoc);

	cout << "nhap don gia : ";
	cin >> x.don_gia;
	cin.ignore();

	cout << "nhap cong dung : ";
	getline(cin, x.cong_dung);
}
void xuat_thong_tin(Nhathuoc x)
{
	cout << "\nma thuoc : " << x.ma_thuoc;
	cout << "\nten thuoc : " << x.ten_thuoc;
	cout << "\nnha san xuat : " << x.nha_sx;
	cout << "\ndang thuoc : " << x.dang_thuoc;
	cout << "\ndon gia : " << x.don_gia;
	cout << "\ncong dung : " << x.cong_dung;
}
void nhap_danh_sach(Nhathuoc a[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\t NHAP THONG TIN THUOC THU : " << i + 1 << endl;
		nhap_thong_tin(a[i]);
	}
}
void xuat_danh_sach(Nhathuoc a[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\t THONG TIN THUOC THU :" << i + 1 << endl;
		xuat_thong_tin(a[i]);
	}
}
int main()
{
	int chon,n,b,a[50];
	cout << "=================== MENU =================== " << endl;
	cout << "1. xuat cac ptu co chua so 3 " << endl;
	cout << "2. tim ptu le lon nhat " << endl;
	cout << "3. tim so FIBO lon nhat nhung nho hon so ng duong n " << endl;
	cout << "4. tao va xuat mang 1 chieu chua danh sach thuoc " << endl;
	cout << "5. xuat cac ptu co chua chu so 3 " << endl;
	cout << "6. tim so ng duong n lon nhat bang de qui " << endl;
	cout << "7. tim so ng duong n lon nhat bang khu de qui " << endl;
	cout << "8. kt so ng duong khong de qui " << endl;
	cout << "9. kt so ng duong bang de qui " << endl;
	cout << "============================================= " << endl;
	cout << endl;

	cout << "moi bn chon bai : ";
	cin >> chon;
	switch (chon)
	{
	case 1: cout << "nhap n phan tu : ";
		cin >> n;
		nhap(a, n);
		cout << "mang vua nhap la : ";
		xuat(a, n);
		cout << endl;
		cout << "mang co chua tat ca chu so 3 la : ";
		pt_chua_so_3(a, n);
		break;
	case 2: cout << "nhap n phan tu : ";
		cin >> n;
		nhap(a, n);
		cout << "mang vua nhap la : ";
		xuat(a, n);
		cout << endl;
		cout << "ptu le lon nhat trong mang : " << pt_le_lon_nhat(a, n, a[50 - 1]);
			break;
	case 3: cout << "nhap n : ";
		cin >> b;
		cout<<"gia tri cong thuc truy hoi de qui : "<< Fibo(b)<<endl;
		cout<<"gia tri cong thuc truy hoi khu de qui : "<<Fibo1(b);
		break;
	case 4: 
	{
		Nhathuoc a[50];
		cout << "nhap so luong thuoc : ";
		cin >> n;
		cout << "\n\n\t\t\tNHAP DANH SACH THUOC\n";
		cout << "=======================================================================";
		nhap_danh_sach(a, n);
		cout << "\n\n\t\t\tXUAT DANH SACH THUOC\n";
		cout << "=======================================================================";
		xuat_danh_sach(a, n);
		break;
	}
	case 5: cout << "nhap n phan tu : ";
		cin >> n;
		nhap(a, n);
		cout << "mang vua nhap la : ";
		xuat(a, n);
		cout << endl;
		cout << "ptu co chua 3 chu so : ";
		xuat_pt_3_chu_so(a, n);
		break;
	case 6: cout << "nhap n phan tu : ";
		cin >> n;
		nhap(a, n);
		cout << "mang vua nhap la : ";
		xuat(a, n);
		cout << endl;
		cout<<"chu so ng duong lon nhat : "<<dq_chu_so_lon_nhat(n, 0);
		break;
	case 7: cout << "nhap n phan tu : ";
		cin >> n;
		nhap(a, n);
		cout << "mang vua nhap la : ";
		xuat(a, n);
		cout << endl;
		cout <<"chu so ng duong lon nhat : "<< chu_so_lon_nhat(n);
		break;
	case 8: cout << "nhap n : ";
		cin >> b;
		if (kt_le(b) == true)
		cout << "toan so le ";
		  else
		cout << "khong co so le ";
		break;
	case 9: cout << "nhap n : ";
		cin >> b;
		if(dq_kt_toan_le(b) == 1)
		cout << "toan so le ";
		  else
		  cout << "khong co so le ";
		  break;
	default: cout << "ban nhap sai cu phap. Vui long nhap lai ";
		break;
	}
}