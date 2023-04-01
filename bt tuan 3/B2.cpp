#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXSIZE 100
#define fNameIn_DSSV "dslop.txt" //Định nghĩa tên mới để đọc file.
#define fNameOut_DSSV "output_lop.txt" //Định nghĩa tên mới để ghi file.
//-----------------------------------------------------------------
typedef struct SinhVien
{
	char mssv[11];
	char ho[8], hoLot[20], ten[8];
	double diemTB;
	char xl[10];
}SV;
typedef struct Lophoc
{
	char tenlop[10];
	int siso;
	SV ds;
}LH;
//=================================================================
void xuatTTLH(LH x)
{ 
	printf("%-10s%-5d%-15s%-10s%-20s%-10s%-10.2lf%-15s\n",x.tenlop,x.siso, x.ds.mssv, x.ds.ho, x.ds.hoLot, x.ds.ten, x.ds.diemTB,x.ds.xl);
}
//=================================================================
void docTTLH(FILE *fi, LH &x)
{ 
//Dùng phím # để ngăn cách các thành phần thông tin
	char a[3];
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%lf\n",&x.tenlop,&a, &x.ds.mssv, &x.ds.ho, &x.ds.hoLot, &x.ds.ten,&x.ds.diemTB);
	x.siso=atoi(a);
}
//=================================================================
void ghiTTLH(FILE *fo, LH x)
{ //Xuất (ghi) ra file thông tin của 1 sinh viên
	fprintf(fo, "%-10s%-5d%-15s%-10s%-20s%-10s%-10.2lf%-15s\n",x.tenlop,x.siso, x.ds.mssv, x.ds.ho, x.ds.hoLot, x.ds.ten, x.ds.diemTB,x.ds.xl);
}
//=================================================================
void docDSLH(char fNameIn[], LH lop[], int &n)
{ //Đọc thông tin của 1 danh sách có n sinh viên từ file
	FILE *fi = fopen(fNameIn, "rt"); //rt: read text
	if (fi == NULL)
	{
	printf("Loi: mo file de doc du lieu.");
	return;
	}
	fscanf(fi, "%d\n", &n); //Đọc dòng đầu tiên của file để lấy số lượng
	for (int i = 0; i < n; i++)
	{
		LH x;
		docTTLH(fi, x);
		if(x.ds.diemTB>=8)
			strcpy(x.ds.xl,"Gioi");
		else if(x.ds.diemTB>=6.5)
			strcpy(x.ds.xl,"Kha");
		else if(x.ds.diemTB>=5)
			strcpy(x.ds.xl,"TB");
		else
			strcpy(x.ds.xl,"Yeu");
		lop[i] = x;
	}
	fclose(fi); //Đóng file vừa mở
}
//=================================================================
void ghiDSLH(char fNameOut[], LH lop[], int n)
{ //Ghi thông tin của 1 danh sách có n sinh viên xuống file
	FILE *fo = fopen(fNameOut, "wt"); //wt: write text
	if (fo == NULL)
	{
	printf("Loi: mo file de ghi du lieu.");
	return;
	}
	fprintf(fo, "%-5s%-10s%-7s%-15s%-40s%-10s%-10s\n", "STT", "TEN LOP","SI SO","MSSV", "HO VA TEN SINH VIEN", "DIEM TB","XEP LOAI");
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%-5d", i + 1);
		ghiTTLH(fo, lop[i]);
	}
	fclose(fo); //Đóng file vừa mở
}
//=================================================================
void xuatDSLH(LH lop[], int &n)
{ //Xuất danh sách có n sinh viên ra màn hình
	printf("%-5s%-10s%-7s%-15s%-40s%-10s%-10s\n", "STT", "TEN LOP","SI SO","MSSV", "HO VA TEN SINH VIEN", "DIEM TB","XEP LOAI");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTLH(lop[i]);
	}
}
//=====================================================================
void sapxep(LH lop[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(lop[i].tenlop,lop[j].tenlop)==1)
				swap(lop[i],lop[j]);
}
//================================================
void DemLGioi(LH lop[],int n)
{
	sapxep(lop,n);
	int i,dem=0;
	char TL[10];
	strcpy(TL,lop[0].tenlop);
	for(i=0;i<n;i++)
	{
		if(strcmpi(lop[i].tenlop,TL)==0 )
		{	
			if (lop[i].ds.diemTB>=8)
			dem++;
		}
		else
		{
			if(dem>=5)
			{
				printf("\nlop co HS gioi lon hon 5: Lop %-10s co %d HS gioi", lop[i-1].tenlop,dem);
			}
			if(lop[i].ds.diemTB>=8)
				dem=1;
			else
				dem=0;
			strcpy(TL,lop[i].tenlop);
		}
	}

}
int MaxSL(LH lop[],int n)
{
	sapxep(lop,n);
	char TL[10];
	char ten[10];
	strcpy(TL,lop[0].tenlop);
	int max=1;
		int i,dem=1;
	for(i=1;i<n;i++)
	{
		if(strcmpi(lop[i-1].tenlop,lop[i].tenlop)==0)
			dem++;
		else
		{
			if(max<dem)
			{
				max=dem;
			
			}
			dem=1;
			strcpy(TL,lop[i].tenlop);

		}
	}
	return max;
}
void InMaxSL(LH lop[],int n)
{
	char TL[10];
	char ten[10];
	strcpy(TL,lop[0].tenlop);
	int max=MaxSL(lop,n);
		int i,dem=1;
	for(i=1;i<n;i++)
	{
		if(strcmpi(lop[i-1].tenlop,lop[i].tenlop)==0)
			dem++;
		else
		{
			if(max==dem)
			{
				printf("\n lop co hoc sinh dong nhat: Lop %-10s co %d hoc sinh",TL,max);
			}
			dem=1;
			strcpy(TL,lop[i].tenlop);

		}
	}
	
}
void  MaxDTBL(LH lop[],int n)
{
	sapxep(lop,n);
	int vitri=0;
	int max=lop[0].ds.diemTB;
	int i;
	for(i=1;i<n;i++)
	{
		if(strcmpi(lop[i-1].tenlop,lop[i].tenlop)==0)
		{
			if(max<lop[i].ds.diemTB)
			{
				max=lop[i].ds.diemTB;
				vitri=i;
			}
		}
		else
		{
			printf("\n hoc sinh DTB cao nhat:");
			xuatTTLH(lop[vitri]);
			max=lop[i].ds.diemTB;
			vitri=i;
			

		}
	}

}
void SelectionSortTang(LH lop[], int n)
{
    int i, j, min;
	float b,c;
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min = i;
		
		for (j = i+1; j < n; j++)
		{
			if (strcmp(lop[min].tenlop,lop[j].tenlop)==1)
			min = j;
			swap(lop[min], lop[i]);
		}
    }
}

//========================================================
int partition (LH lop[], int low, int high)
{
	float pivot = lop[high].ds.diemTB;   // pivot
    int left = low;
    int right = high - 1;
    while(true)
	{
		while(left <= right && lop[left].ds.diemTB < pivot) 
			left++; // Tìm phần tử >= arr[pivot]
		while(right >= left && lop[right].ds.diemTB > pivot) 
			right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(lop[left], lop[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(lop[left], lop[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}

void quickSorttang(LH lop[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(lop, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSorttang(lop, low, pi - 1);
        quickSorttang(lop, pi + 1, high);
    }
}
//=================================================

//void inMaxDTB(SV ds[],int n)
//{
//	int max=0,i;
//	for(i=0;i<n;i++)
//		if(ds[i].diemTB>ds[max].diemTB)
//			swap(max,i);
//	printf("SV co diem trung binh cao nhat là:\n");
//	xuatTTSV(ds[max]);
//
//}
//void inSVKha_Gioi(SV ds[],int n)
//{
//	printf("\n Danh sach sinh vien kha gioi:\n");
//	for(int i=0;i<n;i++)
//		if(strcmpi(ds[i].xl,"gioi")==0||strcmpi(ds[i].xl,"kha")==0)
//			xuatTTSV(ds[i]);
//}
//int demSV_N(SV ds[],int n)
//{
//	int dem=0;int i;
//	for(i=0;i<n;i++)
//		if(strcmpi(ds[i].ho,"nguyen")==0)
//			dem++;
//	return dem;
//
//}
void showMenu()
{
	printf("\n*                 MENU                        *");
	printf("\n***********************************************");
	printf("\n* 1. Doc danh sach lop va sinh vien tu file *");
	printf("\n* 2. Xuat danh sach ra man hinh *");
	printf("\n* 3. Ghi danh sach lop hoc xuong file *");
	printf("\n* 4. in ra lop co hon 5 hoc sinh gioi *");
	printf("\n* 5. Sinh vien co diem trung binh cao nhat *");
	printf("\n* 6. in Sinh vien kha gioi *");
	printf("\n* 7. So luong sinh vien ho nguyen *");
	printf("\n* 0. Thoat chuong trinh *");
	printf("\n***********************************************");
}
//======================================================
void process()
{
	LH DS[MAXSIZE];
	int N,x;
	int chonChucNang;
	do
	{
		showMenu();
		printf("\nBan hay chon mot chuc nang bat ky: ");
		scanf("%d", &chonChucNang);
		switch (chonChucNang)
		{
			case 1:
				docDSLH(fNameIn_DSSV, DS, N);
				printf("DANH SACH SINH VIEN DOC TU FILE.\n");
				xuatDSLH(DS, N);
				break;
			case 2:
				printf("DANH SACH SINH VIEN LA:\n");
				xuatDSLH(DS, N);
				break;
			case 3:
				printf("GHI DANH SACH SINH VIEN XUONG FILE\n");
				ghiDSLH(fNameOut_DSSV, DS, N);
				break;
			case 4:
				DemLGioi(DS,N);
				//xuatDSLH(DS,N);
				break;
			case 5:
				SelectionSortTang(DS,N);
				xuatDSLH(DS,N);
				break;
			case 6:
				sapxep(DS,N);
				xuatDSLH(DS,N);
				break;
			case 7:
				InMaxSL(DS,N);
				break;
			case 8:
				MaxDTBL(DS,N);
				break;
		}
	} while (chonChucNang != 0);
}
//======================================================
void main()
{
process();
}