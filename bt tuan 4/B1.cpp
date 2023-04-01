//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<algorithm>
//#include<stdlib.h>
//#include<time.h>
//using namespace std;
//#define MAX 100
//void Random_Array(int a[][MAX],int d,int c)
//{
//	int i,j;
//	srand((unsigned)time(NULL));
//	for(i=0;i<d;i++)
//		for(j=0;j<c;j++)
//			a[i][j]=rand()%100;
//}
//void xuatdong(int a[][MAX],int d,int c,int i)
//{
//	int j;
//	for(j=0;j<c;j++)
//		printf("%-3d",a[i][j]);
//	printf("\n");
//}
//void Print_Array(int a[][MAX],int d,int c)
//{
//	int i,j;
//	for(i=0;i<d;i++)
//	{
//		xuatdong(a,d,c,i);
//	}
//}
//int GTLN_DongI(int a[][100],int m,int n,int i)
//{
//	int Max=a[i][0];
//	for(int j=1;j<n;j++)
//		if(Max<a[i][j])
//			Max=a[i][j];
//	return Max;
//}
//int GTNN_DongI(int a[][100],int m,int n,int i)
//{
//	int Min=a[i][0];
//	for(int j=1;j<n;j++)
//		if(Min>a[i][j])
//			Min=a[i][j];
//	return Min;
//}
//
//int GTLN_CotJ(int a[][100],int m,int n,int j)
//{
//	int Max=a[0][j];
//	for(int i=1;i<m;i++)
//		if(Max<a[i][j])
//			Max=a[i][j];
//	return Max;
//}
//int GTNN_CotJ(int a[][100],int m,int n,int j)
//{
//	int Min=a[0][j];
//	for(int i=1;i<m;i++)
//		if(Min>a[i][j])
//			Min=a[i][j];
//	return Min;
//}
////void timDiemYenNgua (int a[][100], int m, int n) 
////{
////	for (int i = 0;i<m;i++)
////		for (int j=0;j<n;j++)
////			if (( a[i][j]== GTNN_DongI(a, m, n, i) && a[i][j] == GTLN_CotJ(a, m, n, j) )|| ( a[i][j]==GTLN_DongI(a, m, n, i) && a[i][j] == GTNN_CotJ(a, m, n, j) ) )
////				printf("%5d", a[i][j]);
////}
//void Tongdong(int a[][MAX],int d,int c)
//{
//	int i,j,tongdong;
//	for(i=0;i<d;i++)
//	{
//		tongdong=0;
//		for(j=0;j<c;j++)
//			tongdong+=a[i][j];
//		printf("\nTong dong %d la:%d",i,tongdong);
//	}
//}
//void MaxCot(int a[][MAX],int d,int c)
//{
//	int i;
//	for(i=0;i<c;i++)
//		printf("\n Phan tu lon nhat cot %d la %d",i,GTLN_CotJ(a,d,c,i)); 
//}
//void Xuatbien(int a[][MAX],int d,int c)
//{
//	int i;
//	printf("\n bien tren: ");
//	xuatdong(a,d,c,0);
//	printf("\n bien duoi: ");
//	xuatdong(a,d,c,d-1);
//	printf("\n bien trai: ");
//	for(i=0;i<d;i++)
//		printf("\n%-4d",a[i][0]);
//	printf("\n bien phai: ");
//	for(i=0;i<d;i++)
//		printf("\n%-4d",a[i][c-1]);
//}
//void cucdai(int a[][MAX],int d,int c)
//{
//	int i,j;
//	for(i=0;i<d;i++)
//		for(j=0;j<c;j++)
//			if((a[i][j]>a[i][j+1])&&(a[i][j]>a[i][j-1])&&(a[i][j]>a[i+1][j])&&(a[i][j]>a[i-1][j])&&(a[i][j]>a[i-1][j-1])&&(a[i][j]>a[i+1][j+1])&&(a[i][j]>a[i-1][j+1])&&(a[i][j]>a[i+1][j-1]))
//				printf("%-4d",a[i][j]);
//}
//void cuctieu(int a[][MAX],int d,int c)
//{
//	int i,j;
//	for(i=0;i<d;i++)
//		for(j=0;j<c;j++)
//			if((a[i][j]<a[i][j+1])&&(a[i][j]<a[i][j-1])&&(a[i][j]<a[i+1][j])&&(a[i][j]<a[i-1][j])&&(a[i][j]<a[i-1][j-1])&&(a[i][j]<a[i+1][j+1])&&(a[i][j]<a[i-1][j+1])&&(a[i][j]<a[i+1][j-1]))
//				printf("%-4d",a[i][j]);
//}
//void sapdongtang(int a[][MAX],int d,int c)
//{
//	int i,j,k;
//	for(k=0;k<d;k++)
//	{
//		for(i=0;i<c-1;i++)
//			for(j=i+1;j<c;j++)
//				if(a[k][i]>a[k][j])
//					swap(a[k][i],a[k][j]);
//	}
//	
//}
//void xuatdongsochan(int a[][MAX],int d,int c)
//{
//	int i,j,flag;
//	for(i=0;i<d;i++)
//	{
//		flag=1;
//		for(j=0;j<c;j++)
//			if(a[i][j]%2!=0)
//			{
//				flag=0;
//				break;
//			}
//		if(flag)
//			xuatdong(a,d,c,i);	
//	}
//}
//void Menu()
//{
//	printf("\n---------------MENU---------------------");
//	printf("\n1. Tao mang ngau nhien.");
//	printf("\n2. Tong tung dong.");
//	printf("\n3. Max tung cot.");
//	printf("\n4. Xuat duong bien.");
//	printf("\n5. Phan tu cuc dai.");
//	printf("\n6. Phan tu cuc tieu.");
//	printf("\n7. sap tang dong.");
//	printf("\n8. Xuat dong toan chan.");
//	printf("\n----------------------------------------");
//}
//void Process()
//{
//	int a[MAX][MAX];
//	int n,m;
//	printf("NHap so dong cho ma tran:");
//	scanf("%d",&m);
//	printf("Nhap so cot cho ma tran:");
//	scanf("%d",&n);
//	int chon;
//	do
//	{
//		Menu();
//		printf("\nChon chuc nang:");
//		scanf("%d",&chon);
//		switch (chon)
//		{
//		case 1:
//			Random_Array(a,m,n);
//			Print_Array(a,m,n);
//			/*printf("\nGia tri nho nhat dong: %d",GTNN_DongI(a,m,n,1));
//			printf("\nGia tri lon nhat dong: %d",GTLN_DongI(a,m,n,1));
//			printf("\nGia tri nho nhat cot: %d",GTNN_CotJ(a,m,n,1));
//			printf("\nGia tri lon nhat cot: %d",GTLN_CotJ(a,m,n,1));*/
//			break;
//		case 2:
//			Tongdong(a,m,n);
//			break;
//		case 3:
//			MaxCot(a,m,n);
//			break;
//		case 4:
//			Xuatbien(a,m,n);
//			break;
//		case 5:
//			printf("\n Phan tu cuc dai:");
//			cucdai(a,m,n);
//			break;
//		case 6:
//			printf("\n Phan tu cuc tieu:");
//			cuctieu(a,m,n);
//			break;
//		case 7:
//			sapdongtang(a,m,n);
//			Print_Array(a,m,n);
//			break;
//		case 8:
//			xuatdongsochan(a,m,n);
//			break;
//		default:
//			break;
//		}
//
//	}while(chon!=0);
//}
//void main()
//{
//	Process();
//}
