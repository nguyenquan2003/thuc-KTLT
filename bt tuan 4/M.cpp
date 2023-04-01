//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<algorithm>
//using namespace std;
//#define MAX 100
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
//	int Min;
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
//	int Min;
//	for(int i=1;i<m;i++)
//		if(Min>a[i][j])
//			Min=a[i][j];
//	return Min;
//}
//void timDiemYenNgua (int a[][100], int m, int n) 
//{
//	for (int i = 0;i<m;i++)
//		for (int j=0;j<n;j++)
//			if (( a[i][j]== GTNN_DongI(a, m, n, i) && a[i][j] == GTLN_CotJ(a, m, n, j) )|| ( a[i][j]==GTLN_DongI(a, m, n, i) && a[i][j] == GTNN_CotJ(a, m, n, j) ) )
//				printf("%5d", a[i][j]);
//}
//int xetDuongCheo (int a[][100], int dong, int cot, int i, int j) 
//{
//	int k, h; //k: dong, h: cot
//	for (k=i, h=j; k>=0 && h<cot; k--, h++)
//		if (a[k][h] > a[i][j])
//			return 0;
//	for (k=i+1, h=j-1; k<dong && h>=0; k++, h--)
//		if (a[k][h] > a[i][j])
//			return 0;
//	for (k=i-1, h =j-1; k>=0 && h>=0; k--, h--)
//		if (a[k][h] > a[i][j])
//			return 0;
//	for (k=i+1, h=j+1; k<dong && h<cot; k++, h++)
//		if (a[k][h] > a[i][j])
//			return 0;
//	return 1;
//}
//int xetCotDong (int a[][100], int dong, int cot, int i, int j) 
//{
//	for (int k=0; k<dong; k++)
//		if (a[k][j]>a[i][j])
//			return 0;
//	for (int k=0; k<cot; k++)
//		if (a[i][k]>a[i][j])
//			return 0;
//	return 1;
//}
//int xetTongQuat (int a[][MAX], int dong, int cot, int i, int j) 
//{
//	if (xetCotDong(a, dong, cot, i, j)==1)
//		if (xetDuongCheo(a, dong, cot, i, j)==1)
//			return 1;
//	return 0;
//}