//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<time.h>
//#include <iostream>
//#include <math.h>
//  
//using namespace std;
//void nhapM1C (int * &a, int &n)
//{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
//	a = (int *)malloc(10*sizeof(int)); // cấp phát a co 10 phần tử
//	n = 10;
//	srand((unsigned)time(NULL));
//
//	for(int i = 0; i < n; i++)
//	*(a+i) = rand()%100;
//}
//void xuatM1C(int *a, int n)
//{
//	for(int i = 0; i < n; i++)
//	{
//		printf("\n gia tri %d dia chi %d ",*(a+i),(a+i));
//	}
//}
//void xuatMang(int *a, int n)
//{
//	for(int i = 0; i < n; i++)
//	{
//		printf(" %d ",*(a+i));
//	}
//	printf("\n");
//}
//void maxM1C(int *a,int n)
//{
//	int Max=*a;
//	int vitri=0;
//	for(int i=0;i<n;i++)
//		if(Max<*(a+i))
//		{
//			Max=*(a+i);
//			vitri=i;
//		}
//	printf("\n Gia tri lon nhat: %d dia chi %d ", Max,(a+vitri));
//}
//void maxChan(int *a,int n)
//{
//	int Max,vitri,i;
//	for(i=0;i<n;i++)
//		if(*(a+i)%2==0)
//		{
//			vitri=i;
//			break;
//		}
//	if(vitri<n)
//	{
//		Max=*(a+vitri);
//		for(i=i+1;i<n;i++)
//			if(Max<*(a+i)&&*(a+i)%2==0)
//			{
//				Max=*(a+i);
//				vitri=i;
//			}
//		printf("\n phan tu chan lon nhat la %d co dia chi %d",Max,(a+vitri));
//	}
//	else
//		printf("\n Khong co phan tu chan");
//}
//void minLe(int *a,int n)
//{
//	int Min,vitri,i;
//	for(i=0;i<n;i++)
//		if(*(a+i)%2!=0)
//		{
//			vitri=i;
//			break;
//		}
//	if(vitri<n)
//	{
//		Min=*(a+vitri);
//		for(i=i+1;i<n;i++)
//			if(Min>*(a+i)&&*(a+i)%2!=0)
//			{
//				Min=*(a+i);
//				vitri=i;
//			}
//		printf("\n phan tu le nho nhat la %d co dia chi %d",Min,(a+vitri));
//	}
//	else
//		printf("\n Khong co phan tu le");
//}
//void xoaX(int *a,int &n)
//{
//	int i,j;
//	for(i=0;i<n;i++)
//		if(a[i]==0)
//		{
//			for(j=i;j<n-1;j++)
//				a[j]=a[j+1];
//			n--;
//			realloc(a,sizeof(int*)*n);
//		}
//}
//void themPT(int *a,int &n, int giatri)
//{
//	realloc(a,sizeof(int*)*(n+1));
//	int i;
//	for(i=n;i>0;i--)
//		a[i]=a[i-1];
//	n++;
//	a[1]=giatri;
//}
//int SCP(int x)
//{
//	int sqr=sqrt(x);
//	if(sqr*sqr==x)
//		return 1;
//	else
//		return 0;
//}
//void tinhTongSCP(int *a, int n)
//{
//	int i,Tong=0;
//	for(i=0;i<n;i++)
//		if(SCP(a[i]))
//			Tong+=a[i];
//	printf("Tong cac so chinh phuong : %d\n",Tong);
//}
//void cucdai(int *a, int n)
//{
//	int i;
//	for(i=0;i<n;i++)
//		if(a[i]>a[i-1]&&a[i]>a[i+1])
//			printf("%d   ",a[i]);
//}
//void main()
//{
//	int *a = new int, n=0;
//	nhapM1C(a, n);
//	xuatM1C(a, n);
//	maxM1C(a,n);
//	maxChan(a,n);
//	minLe(a,n);
//	themPT(a,n,100);
//	xuatMang(a,n);
//	xoaX(a,n);
//	xuatMang(a,n);
//	tinhTongSCP(a,n);
//	cucdai(a,n);
//	getch();
//}