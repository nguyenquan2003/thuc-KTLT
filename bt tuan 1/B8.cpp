//#include<stdio.h>
//#include<iostream>
//#include<conio.h>
//using namespace std;
//typedef int iTem;
//struct phanSo
//{
//	iTem TuSo;
//	iTem MauSo;
//};
//void NhapPS(phanSo * &PS,int &n)
//{
//	int i;
//	PS=(phanSo*)malloc(sizeof(phanSo)*5);
//	n=5;
//	for(i=0;i<n;i++)
//	{
//		printf("NHap tu so:");
//		scanf("%d",	&PS[i].TuSo);
//		printf("nhap mau so:");
//		scanf("%d",&PS[i].MauSo);
//		try
//		{
//			if(PS[i].MauSo==0)
//				throw 101;
//		}
//		catch (int error)
//		{
//			if(error==101)
//				printf("mau so khong the bang 0");
//			return;
//		}
//	}
//}
//void XuatPS(phanSo *PS,int n)
//{
//	int i;
//	for(i=0;i<n;i++)
//		printf("  %d/%d",PS[i].TuSo,PS[i].MauSo);
//	printf("\n");
//}
//void XuatPSMaulonhonTu(phanSo *PS,int n)
//{
//	int i;
//	for(i=0;i<n;i++)
//		if(PS[i].MauSo>PS[i].TuSo)
//			printf("  %d/%d",PS[i].TuSo,PS[i].MauSo);
//	printf("\n");
//}
//void DemMvaTChan(phanSo *PS,int n)
//{
//	int i,dem=0;
//	for(i=0;i<n;i++)
//		if(PS[i].TuSo%2==0&&PS[i].MauSo%2==0)
//			dem++;
//	printf("So luong cac PS co mau va tu chan: %d\n",dem);
//}
//int USCLN(int a,int b)
//{
//	if(a == 0 || a == 0) return 1;
//	a = abs(a);
//	b = abs(b);
//	while(a!=b)
//	{
//		if(a>b)
//			a=a-b;
//		else
//			b=b-a;
//	}
//	return a;
//}
//void KiemTraDoiDau(phanSo &x)
//{
//	if(x.MauSo < 0)
//	{
//		x.TuSo *= -1;
//		x.MauSo *= -1;
//	}
//}
//void RutGonPhanSo(phanSo &x)
//{
//	KiemTraDoiDau(x);
//	int usc = USCLN(x.TuSo, x.MauSo);
//	x.TuSo /= usc;
//	x.MauSo /= usc;
//}
//
//void main()
//{
//	phanSo *PS=new phanSo; int n=0;
//	NhapPS(PS,n);
//	XuatPS(PS,n);
//	XuatPSMaulonhonTu(PS,n);
//	getch();
//}