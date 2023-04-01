#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define MAX 100
void Docfile(char file[], int a[][MAX],int d)

{
	FILE *f=fopen(file,"rt");
	if(!f)
		printf("loi file");
	else
	{
		int i,j;
		fscanf(f,"%d",&d);
		for(i=0;i<d;i++)
			for(j=0;j<d;j++)
				fscanf(f,"%d",&a[i][j]);
		fclose(f);
	}
}
void Random_Array(int a[][MAX],int n)
{
	int i,j;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=rand()%100;
}
void xuatdong(int a[][MAX],int n,int i)
{
	int j;
	for(j=0;j<n;j++)
		printf("%-4d",a[i][j]);
	printf("\n");
}
void Print_Array(int a[][MAX],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		xuatdong(a,n,i);
	}
}
//void xuatCDsongsong(int a[][MAX],int n)
//{
//	int i,j;
//	for(i=0;i<n;i++)
//		for(j=0;j<n-1;j++)
//		{
//			printf("%-4d",a[j-i][j]);
//			
//		}
//		printf("\n");
//}
void displayCheo(int a[][MAX],int n)
{
 
    for( int i = 1 ; i<n-1;i++)
	{
	    for(int j = 0 ; j< n - i ;j++)
          printf("%-4d ",a[i+j][j]);
		printf("\n");
		for( int j = 0 ; j< n-i ; j++)
			printf("%-4d ",a[j][i+j]);
		printf("\n");
 
   }
}
void sapzizac(int a[][MAX],int n)
{
	int i,j,k,m;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				for(m=0;m<n;m++)
					if(a[i][j]<a[k][m])
						swap(a[i][j],a[k][m]);
}
void saptangcheochinh(int a[][MAX],int n)
{
	int i,j;
	for (i=0;i<n;i++)
		 for (j=i+1;j<n;j++)
				if(a[i][i]>a[j][j])
			   swap(a[i][i],a[j][j]);
}
void Menu()
{
	printf("\n---------------MENU---------------------");
	printf("\n1. Tao mang ngau nhien.");
	printf("\n2. Xuat duong song song duong cheo chinh.");
	printf("\n3. Sap Zizaz.");
	printf("\n4. Sap tang  duong cheo chinh.");
	printf("\n5. Phan tu cuc dai.");
	printf("\n6. Phan tu cuc tieu.");
	printf("\n7. sap tang dong.");
	printf("\n8. Xuat dong toan chan.");
	printf("\n----------------------------------------");
}
void Process()
{
	int a[MAX][MAX];
	int n;
	int d,c;
	printf("NHap cap cho ma tran:");
	scanf("%d",&n);
	int chon;
	do
	{
		Menu();
		printf("\nChon chuc nang:");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			Random_Array(a,n);
			Print_Array(a,n);
			/*printf("\nGia tri nho nhat dong: %d",GTNN_DongI(a,m,n,1));
			printf("\nGia tri lon nhat dong: %d",GTLN_DongI(a,m,n,1));
			printf("\nGia tri nho nhat cot: %d",GTNN_CotJ(a,m,n,1));
			printf("\nGia tri lon nhat cot: %d",GTLN_CotJ(a,m,n,1));*/
			break;
		case 2:
			displayCheo(a,n);
			break;
		case 3:
			sapzizac(a,n);
			Print_Array(a,n);
			break;
		case 4:
			saptangcheochinh(a,n);
			Print_Array(a,n);
			break;
		case 5:
			//printf("\n Phan tu cuc dai:");
			//cucdai(a,m,n);
			break;
		case 6:
			//printf("\n Phan tu cuc tieu:");
			//cuctieu(a,m,n);
			break;
		case 7:
			//sapdongtang(a,m,n);
			//Print_Array(a,m,n);
			break;
		case 8:
			//xuatdongsochan(a,m,n);
			break;
		case 9:
			Docfile("data.txt",a,n);
			Print_Array(a,n);
		default:
			break;
		}

	}while(chon!=0);
}
void main()
{
	Process();
}
