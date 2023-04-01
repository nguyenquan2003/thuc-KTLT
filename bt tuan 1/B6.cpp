//#include<stdio.h>
//#include<conio.h>
//#include<ctime>
////#include<string.h>
//#include<string>
//struct NLD
//{
//	char hoten[30];
//	int ngaysinh;
//	int thangsinh;
//	int namsinh;
//	char gioitinh[10];
//};
//
//int tinhTuoi (int namSinh); 
//void hien(NLD nld)
//{
//	int tuoi=tinhTuoi(nld.namsinh);
//	try
//	{
//		if(tuoi<18)
//			throw 101;
//		else if(strcmpi(nld.gioitinh,"nam")!=0 && strcmpi(nld.gioitinh,"nu")!=0)
//			throw 102;
//		else if((tuoi>60 && strcmpi(nld.gioitinh,"nu")==0)||(tuoi>62 && strcmpi(nld.gioitinh,"nam")==0))
//			throw 103;
//		else
//		{
//			if(strcmpi(nld.gioitinh,"nam")==0)
//				printf(" Thoi gian nghi huu %d/%d",nld.thangsinh,nld.namsinh+62);
//			else
//				printf(" Thoi gian nghi huu %d/%d",nld.thangsinh,nld.namsinh+60);
//		}
//
//	}
//	catch(int errcode)
//	{
//		if(errcode==101)
//			printf("chưa đen tuoi lao dong");
//		else if(errcode==102)
//			printf("Gioi tinh khong phai chuoi");
//		else
//			printf("Da qua tuoi  huu");
//
//	}
//}
//int tinhTuoi (int namSinh) 
//{
////cần khai báo thư viện #include <ctime> để dùng được time_t và tm
//	time_t now = time(0);
//	tm *ltm = localtime(&now);
//	int namHH = 1900 + ltm->tm_year;
//	try 
//	{
//		if(namSinh <= 0 || namSinh > namHH)
//		throw 101; //mã lỗi 101
//		else
//		if(namSinh < 1920)
//		throw 102; //mã lỗi 102
//		else
//		return namHH - namSinh;
//	}
//	catch (int errCode) 
//	{
//		if( errCode == 101)
//		printf("nam sinh khong hop le\n");
//		else
//		printf("nam sinh <1920 \n");
//		return -1;
//	}
//}
//void main()
//{
//	NLD nld;
//	fflush(stdin);
//	printf("NHap ho ten: ");
//	gets(nld.hoten);
//	printf("Nhap ngay thang nam sinh :");
//	scanf_s("%d %d %d",&nld.ngaysinh,&nld.thangsinh,&nld.namsinh);
//	fflush(stdin);
//	printf("Nhap gioi tinh:");
//	gets(nld.gioitinh);
//	hien(nld);
//	getch();
//}