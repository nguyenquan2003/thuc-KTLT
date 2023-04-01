#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#define Max 10
using namespace std;
typedef int iTem;
struct Phanso
{
	iTem TuSo;
	iTem MauSo;
};
struct Honso
{
	iTem Pnguyen;
	Phanso PS;
};
int USCLN(int a,int b)
{
	if(a == 0 || a == 0) return 1;
	a = abs(a);
	b = abs(b);
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
void KiemTraDoiDau(Phanso &x)
{
	if(x.MauSo < 0)
	{
		x.TuSo *= -1;
		x.MauSo *= -1;
	}
}
void RutGonPhanSo(Phanso &x)
{
	KiemTraDoiDau(x);
	int usc = USCLN(x.TuSo, x.MauSo);
	x.TuSo /= usc;
	x.MauSo /= usc;
}
void NhapHonso(Honso HS[],int &n)
{
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("NHap phan nguyen:");
		scanf("%d",	&HS[i].Pnguyen);
		printf("NHap tu so:");
		scanf("%d",	&HS[i].PS.TuSo);
		printf("nhap mau so:");
		scanf("%d",&HS[i].PS.MauSo);
		RutGonPhanSo(HS[i].PS);
		if(abs(HS[i].PS.TuSo)>=abs(HS[i].PS.MauSo))
		{
			HS[i].Pnguyen+=HS[i].PS.TuSo/HS[i].PS.MauSo;
			HS[i].PS.TuSo=HS[i].PS.TuSo%HS[i].PS.MauSo;
		}
		try
		{
			if(HS[i].PS.MauSo==0)
				throw 101;
		}
		catch (int error)
		{
			if(error==101)
			{
				printf("mau so khong the bang 0");
				return;
			}
		}
		
	}
}
void RandHonso(Honso HS[],int &n)
{
	int i;
	printf("Nhap so phan tu cua mang: ");
			scanf("%d",&n);
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		HS[i].Pnguyen=rand()%100-20;
		HS[i].PS.TuSo=rand()%100-20;
		HS[i].PS.MauSo=rand()%100-20;
		RutGonPhanSo(HS[i].PS);
		if(abs(HS[i].PS.TuSo)>=abs(HS[i].PS.MauSo))
		{
			HS[i].Pnguyen+=HS[i].PS.TuSo/HS[i].PS.MauSo;
			HS[i].PS.TuSo=HS[i].PS.TuSo%HS[i].PS.MauSo;
		}
		try
		{
			if(HS[i].PS.MauSo==0)
				throw 101;
		}
		catch (int error)
		{
			if(error==101)
			{
				printf("mau so khong the bang 0");
				return;
			}
		}
		
	}
}
void XuatHonso(Honso HS[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(HS[i].Pnguyen==0)
			printf("%d/%d, ",HS[i].PS.TuSo,HS[i].PS.MauSo);
		else if(HS[i].PS.TuSo==0)
			printf("%d,  ",HS[i].Pnguyen);
		else
			printf("%d.%d/%d,  ",HS[i].Pnguyen,HS[i].PS.TuSo,HS[i].PS.MauSo);
	printf("\n");
}
void Xuatphanso(Phanso PS[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf(" %d/%d",PS[i].TuSo,PS[i].MauSo);
	printf("\n");
}
void Chuyen1HS_PS(Honso a,Phanso &b)
{
		b.MauSo=a.PS.MauSo;
		b.TuSo=a.PS.TuSo+a.Pnguyen*a.PS.MauSo;
		RutGonPhanSo(b);
	
}

void ChuyenHS_PS(Honso a[],Phanso b[],int &n)
{
	for(int i=0;i<n;i++)
	{
		Chuyen1HS_PS(a[i],b[i]);
	}

	
}
void chuyen1PS_HS(Honso &a,Phanso b)
{
		a.Pnguyen=b.TuSo/b.MauSo;
		a.PS.TuSo=b.TuSo%b.MauSo;
		a.PS.MauSo=b.MauSo;
}
void chuyenPS_HS(Honso a[],Phanso b[],int &n)
{
	for(int i=0;i<n;i++)
	{
		chuyen1PS_HS(a[i],b[i]);
	}
	
}
float Giatri(Honso a)
{
	return (float)(a.Pnguyen*a.PS.MauSo+a.PS.TuSo)/a.PS.MauSo;
}
float tongHS(Honso a[],int n)
{
	float tong=0;
	for(int i=0;i<n;i++)
		tong+=Giatri(a[i]);
	return tong;
}
float hieuHS(Honso a[],int n)
{
	float hieu=0;
	for(int i=0;i<n;i++)
		hieu-=Giatri(a[i]);
	return hieu;
}
float tichHS(Honso a[],int n)
{
	float tich=1;
	for(int i=0;i<n;i++)
		tich*=Giatri(a[i]);
	return tich;
}
float thuongHS(Honso a[],int n)
{
	float thuong=1;
	for(int i=0;i<n;i++)
		thuong/=Giatri(a[i]);
	return thuong;
}
void InterchangeSortTang(Honso a[],int n)
{
	int i,j;
	float b,c;
	for(i=0; i<n-1; i++)
	{
		b=Giatri(a[i]);
		for(j=i+1; j<n; j++)
		{
			c=Giatri(a[j]);
			if(b>c)
			{
				swap(a[i],a[j]);//hoán vị a[i] và a[j]
			}
		}
	}
}
void InterchangeSortGiam(Honso a[],int n)
{
	int i,j;
	float b,c;
	for(i=0; i<n-1; i++)
	{
		b=Giatri(a[i]);
		for(j=i+1; j<n; j++)
		{
			c=Giatri(a[j]);
			if(b<c)
			{
				swap(a[i],a[j]);//hoán vị a[i] và a[j]
			}
		}
	}
}

void SelectionSortTang(Honso a[], int n)
{
    int i, j, min;
	float b,c;
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min = i;
		
		for (j = i+1; j < n; j++)
		{
			b=Giatri(a[min]);
			c=Giatri(a[j]);
			if (b>c)
			min = j;
			swap(a[min], a[i]);
		}
    }
}
void SelectionSortGiam(Honso a[], int n)
{
    int i, j, min;
	float b,c;
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min = i;
		
		for (j = i+1; j < n; j++)
		{
			b=Giatri(a[min]);
			c=Giatri(a[j]);
			if (b<c)
			min = j;
			swap(a[min], a[i]);
		}
    }
}
int partition (Honso arr[], int low, int high)
{
    float pivot = Giatri(arr[high]);   // pivot
    int left = low;
    int right = high - 1;
    while(true)
	{
        while(left <= right && Giatri(arr[left]) < pivot) 
			left++; // Tìm phần tử >= arr[pivot]
        while(right >= left && Giatri(arr[right]) > pivot) 
			right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(arr[left], arr[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
int partition1 (Honso arr[], int low, int high)
{
    float pivot = Giatri(arr[high]);   // pivot
    int left = low;
    int right = high - 1;
    while(true)
	{
        while(left <= right && Giatri(arr[left]) > pivot) 
			left++; // Tìm phần tử >= arr[pivot]
        while(right >= left && Giatri(arr[right]) < pivot) 
			right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(arr[left], arr[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quickSorttang(Honso arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSorttang(arr, low, pi - 1);
        quickSorttang(arr, pi + 1, high);
    }
}
void quickSortgiam(Honso arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition1(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSorttang(arr, low, pi - 1);
        quickSorttang(arr, pi + 1, high);
    }
}
void Menu()
{
	printf("\n-----------------MENU---------------------");
	printf("\n1. Tao mang hon so");
	printf("\n2. Tao mang Hon so ngau nhien");
	printf("\n3. Chuyen hon so thanh phan so");
	printf("\n4. Chuyen phan so thanh hon so");
	printf("\n5. Interchangsort Tang");
	printf("\n6. Interchangsort Giam");
	printf("\n7. Selectionsort tang");
	printf("\n8. Selectionsort giam");
	printf("\n9. Quicksort tang");
	printf("\n10. Quicksort giam");
	printf("\n11. Tong, Hieu, Tich, Thuong Hon so");
	printf("\n-----------------------------------------");
}
void Process()
{
	Honso HS[Max];
	Phanso PS[Max];
	int n,chon;
	float x;
	do
	{
		Menu();
		printf("\nNhap so thuc hien: ");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			NhapHonso(HS,n);
			XuatHonso(HS,n);
			break;
		case 2:
			RandHonso(HS,n);
			XuatHonso(HS,n);
			break;
		case 3:
			ChuyenHS_PS(HS,PS,n);
			Xuatphanso(PS,n);
			break;
		case 4:
			chuyenPS_HS(HS,PS,n);
			XuatHonso(HS,n);
			break;
			case 5:
			InterchangeSortTang(HS,n);
			XuatHonso(HS,n);
			break;
		case 6:
			InterchangeSortGiam(HS,n);
			XuatHonso(HS,n);
			break;
		case 7:
			SelectionSortTang(HS,n);
			XuatHonso(HS,n);
			break;
		case 8:
			SelectionSortGiam(HS,n);
			XuatHonso(HS,n);
			break;
		case 9:
			quickSorttang(HS,0,n-1);
			XuatHonso(HS,n);
			break;
		case 10:
			quickSortgiam(HS,0,n-1);
			XuatHonso(HS,n);
			break;
		case 11:
			x=tongHS(HS,n);
			printf("\n Tong Hon so =%.2f",x);
			x=hieuHS(HS,n);
			printf("\n Hieu Hon so =%.2f",x);
			x=tichHS(HS,n);
			printf("\n Tich Hon so =%.2f",x);
			x=thuongHS(HS,n);
			printf("\n Thuong Hon so =%.2f",x);
			break;
		default:
			break;
		}
	}while(chon!=0);

}
void main()
{
	Process();
	system("pause");
}