//#include<stdio.h>
//#include<conio.h>
//#include<ctime>
//int tinhTuoi (int namSinh) 
//{
////cần khai báo thư viện #include <ctime> để dùng được time_t và tm
//	time_t now = time(0);
//	tm *ltm = localtime(&now);
//
//	printf("%d\n",ltm->tm_year);
//	printf("%x\n",now);
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
//	int tuoi=tinhTuoi(1975);
//	printf("Tuoi cua toi=%d",tuoi);
//	getch();
//}