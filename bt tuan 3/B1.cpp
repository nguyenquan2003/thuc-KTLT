//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define MAXSIZE 100
//#define fNameIn_DSSV "input_DSSV.txt" //Định nghĩa tên mới để đọc file.
//#define fNameOut_DSSV "output_DSSV.txt" //Định nghĩa tên mới để ghi file.
////-----------------------------------------------------------------
//typedef struct SinhVien
//{
//	char mssv[11];
//	char ho[8], hoLot[20], ten[8];
//	double diemTB;
//	char xl[10];
//}SV;
////=================================================================
//void xuatTTSV(SV x)
//{ 
//	printf("%-15s%-10s%-20s%-10s%-10.2lf%-15s\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB,x.xl);
//}
////=================================================================
//void docTTSV(FILE *fi, SV &x)
//{ 
////Dùng phím # để ngăn cách các thành phần thông tin
//	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%lf\n", &x.mssv, &x.ho, &x.hoLot, &x.ten,&x.diemTB);
//}
////=================================================================
//void ghiTTSV(FILE *fo, SV x)
//{ //Xuất (ghi) ra file thông tin của 1 sinh viên
//	fprintf(fo, "%-15s%-10s%-20s%-10s%-101.2lf%-10s\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB,x.xl);
//}
////=================================================================
//void docDSSV(char fNameIn[], SV ds[], int &n)
//{ //Đọc thông tin của 1 danh sách có n sinh viên từ file
//	FILE *fi = fopen(fNameIn, "rt"); //rt: read text
//	if (fi == NULL)
//	{
//	printf("Loi: mo file de doc du lieu.");
//	getch();
//	return;
//	}
//	fscanf(fi, "%d\n", &n); //Đọc dòng đầu tiên của file để lấy số lượng
//	for (int i = 0; i < n; i++)
//	{
//		SV x;
//		docTTSV(fi, x);
//		if(x.diemTB>=8)
//			strcpy(x.xl,"Gioi");
//		else if(x.diemTB>=6.5)
//			strcpy(x.xl,"Kha");
//		else if(x.diemTB>=5)
//			strcpy(x.xl,"TB");
//		else
//			strcpy(x.xl,"Yeu");
//		ds[i] = x;
//	}
//	fclose(fi); //Đóng file vừa mở
//}
////=================================================================
//void ghiDSSV(char fNameOut[], SV ds[], int n)
//{ //Ghi thông tin của 1 danh sách có n sinh viên xuống file
//	FILE *fo = fopen(fNameOut, "wt"); //wt: write text
//	if (fo == NULL)
//	{
//	printf("Loi: mo file de ghi du lieu.");
//	getch();
//	return;
//	}
//	fprintf(fo, "%-5s%-15s%-40s%-10s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB","XEP LOAI");
//	for (int i = 0; i < n; i++)
//	{
//		fprintf(fo, "%-5d", i + 1);
//		ghiTTSV(fo, ds[i]);
//	}
//	fclose(fo); //Đóng file vừa mở
//}
////=================================================================
//void xuatDSSV(SV ds[], int &n)
//{ //Xuất danh sách có n sinh viên ra màn hình
//	printf("%-5s%-15s%-40s%-10s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB","XEP LOAI");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5d", i + 1);
//		xuatTTSV(ds[i]);
//	}
//}
////=====================================================================
//void sapxep(SV ds[],int n)
//{
//	int i,j;
//	for(i=0;i<n-1;i++)
//		for(j=i+1;j<n;j++)
//			if(ds[i].diemTB>ds[j].diemTB)
//				swap(ds[i],ds[j]);
//}
//void SelectionSortTang(SV ds[], int n)
//{
//    int i, j, min;
//	float b,c;
//    for (i = 0; i < n-1; i++)
//    {
//    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
//		min = i;
//		
//		for (j = i+1; j < n; j++)
//		{
//			if (ds[min].diemTB>ds[j].diemTB)
//			min = j;
//			swap(ds[min], ds[i]);
//		}
//    }
//}
//
////========================================================
//int partition (SV ds[], int low, int high)
//{
//	float pivot = ds[high].diemTB;   // pivot
//    int left = low;
//    int right = high - 1;
//    while(true)
//	{
//		while(left <= right && ds[left].diemTB < pivot) 
//			left++; // Tìm phần tử >= arr[pivot]
//		while(right >= left && ds[right].diemTB > pivot) 
//			right--; // Tìm phần tử <= arr[pivot]
//        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
//        swap(ds[left], ds[right]); // Nếu chưa xong, đổi chỗ.
//        left++; // Vì left hiện tại đã xét, nên cần tăng
//        right--; // Vì right hiện tại đã xét, nên cần giảm
//    }
//    swap(ds[left], ds[high]);
//    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
//}
//
//void quickSorttang(SV ds[], int low, int high)
//{
//    if (low < high)
//    {
//        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
//         và là phần tử chia mảng làm 2 mảng con trái & phải */
//        int pi = partition(ds, low, high);
// 
//        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
//        quickSorttang(ds, low, pi - 1);
//        quickSorttang(ds, pi + 1, high);
//    }
//}
////=================================================
//
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
//void showMenu()
//{
//	printf("\n*                 MENU                        *");
//	printf("\n***********************************************");
//	printf("\n* 1. Doc danh sach sinh vien tu file *");
//	printf("\n* 2. Xuat danh sach ra man hinh *");
//	printf("\n* 3. Ghi danh sach sinh vien xuong file *");
//	printf("\n* 4. Sap xep danh sach theo diem tb *");
//	printf("\n* 5. Sinh vien co diem trung binh cao nhat *");
//	printf("\n* 6. in Sinh vien kha gioi *");
//	printf("\n* 7. So luong sinh vien ho nguyen *");
//	printf("\n* 0. Thoat chuong trinh *");
//	printf("\n***********************************************");
//}
////======================================================
//void process()
//{
//	SV DS[MAXSIZE];
//	int N,x;
//	int chonChucNang;
//	do
//	{
//		showMenu();
//		printf("\nBan hay chon mot chuc nang bat ky: ");
//		scanf("%d", &chonChucNang);
//		switch (chonChucNang)
//		{
//			case 1:
//				docDSSV(fNameIn_DSSV, DS, N);
//				printf("DANH SACH SINH VIEN DOC TU FILE.\n");
//				xuatDSSV(DS, N);
//				break;
//			case 2:
//				printf("DANH SACH SINH VIEN LA:\n");
//				xuatDSSV(DS, N);
//				break;
//			case 3:
//				printf("GHI DANH SACH SINH VIEN XUONG FILE\n");
//				ghiDSSV(fNameOut_DSSV, DS, N);
//				break;
//			case 4:
//				sapxep(DS,N);
//				xuatDSSV(DS,N);
//				break;
//			case 5:
//				inMaxDTB(DS,N);
//				break;
//			case 6:
//				inSVKha_Gioi(DS,N);
//				break;
//			case 7:
//				x=demSV_N(DS,N);
//				printf("\n so luong sinh vien ho nguyen la %d",x);
//				break;
//		}
//	} while (chonChucNang != 0);
//}
////======================================================
//void main()
//{
//process();
//}