//#define _CRT_SECURE_NO_WARNINGS
//#include<conio.h>
//#include<stdio.h>
//#include<math.h>
//int TongDequy(int n)
//{
//	if(n==0)
//		return 0;
//	return n+TongDequy(n-1);
//}
//int Tong(int n)
//{
//	int tong=0;
//	for (int i=0;i<=n;i++)
//		tong+=i;
//	return tong;
//
//}
//float can(int n)
//{
//   float s=0;
//    for(int i=1;i<=n;i++)
//        s=sqrt(5+s);
//    return s;
//}
//float Candequy(int n)
//{
//    if(n<2)
//		return sqrt(5.0);
//    return sqrt(5+Candequy(n-1));
//}
//float c1(int n)
//{
//	if(n==1)
//		return 0.5;
//	return (float)n/(n+1)+c1(n-1);
//}
//float c2(int n)
//{
//	float tong=0;
//	for (int i=1;i<=n;i++)
//		tong+=(float)i/(i+1);
//	return tong;
//}
//float d1(float n)
//{
//	if(n==1)
//		return (float)1/3;
//	return (float)1/(2*n+1)+d1(n-1);
//}
//float d2(float n)
//{
//	float tong=0;
//	for (int i=1;i<=n;i++)
//		tong+=(float)1/(2*i+1);
//	return tong;
//}
//float e1(int n)
//{
//	if(n==1)
//		return 2;
//	return n*(n+1)+e1(n-1);
//}
//float e2(int n)
//{
//	float tong=0;
//	for(int i=1;i<=n;i++)
//		tong+=i*(i+1);
//	return tong;
//}
//float gt(int n)
//{
//	if(n==0)
//		return 1;
//	return n*gt(n-1);
//}
//float f1(float n)
//{
//	if(n==1)
//		return (1*gt(2))/(2+sqrt(3.0));
//	return (n*gt(n+1))/((n+1)+sqrt(n+2))+f1(n-1);
//}
//float f2(float n)
//{
//	float tong=0;
//	for(int i=1;i<=n;i++)
//		tong+=(i*gt(i+1))/((i+1)+sqrt(i+2.0));
//	return tong;
//}
//float g1(float n)
//{
//	if(n==0)
//		return  sqrt(1.0)/(1+sqrt(gt(2)));
//	return (n+sqrt(2*n+1))/((n+1)+sqrt(gt(n+2)))+g1(n-1);
//}
//float g2(float n)
//{
//	float tong=0;
//	for(int i=0;i<=n;i++)
//		tong +=(i+sqrt(2*i+1.0))/((i+1)+sqrt(gt(i+2)));
//	return tong;
//}
//void main()
//{
//	int n,tong;
//	printf("Nhap n: ");
//	scanf("%d",&n);
	/*printf("\nTong theo de quy: = %d", TongDequy(n));
	printf("\nTong khong de quy: = %d", Tong(n));
	printf("\ncan theo de quy: = %.3lf", Candequy(n));
	printf("\ncan khong de quy: = %.3lf", can(n));
	printf("\ncan theo de quy: = %.3lf", c1(n));
	printf("\ncan khong de quy: = %.3lf", c2(n));*/
	/*printf("\ncan theo de quy: = %.3lf", d1(n));
	printf("\ncan khong de quy: = %.3lf", d2(n));*/
	/*printf("\ncan theo de quy: = %.3lf", e1(n));
	printf("\ncan khong de quy: = %.3lf", e2(n));*/
	/*printf("\ncan theo de quy: = %.3lf", f1(n));
	printf("\ncan khong de quy: = %.3lf", f2(n));*/
	/*printf("\ncan theo de quy: = %.3lf", g1(n));
	printf("\ncan khong de quy: = %.3lf", g2(n));
	getch();*/
//}