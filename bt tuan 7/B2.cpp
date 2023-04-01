//#define _CRT_SECURE_NO_WARNINGS
//#include<conio.h>
//#include<stdio.h>
//#include<math.h>
//int USCLN(int a, int b) 
//{
//    if (b == 0) return a;
//    return USCLN(b, a % b);
//}
// int USCLN1(int a, int b) 
//{
//    if (b == 0) return a;
//	if(a>b)
//		return USCLN1(b, a - b);
//	else
//		return USCLN1(a,b-a);
//}
//int USCLN2(int a,int b)
//{
//	while (a != b)
//		if (a > b)
//			a = a-b;
//		else 
//			b = b-a;
//	return a;
//}
//void main()
//{
//	int a,b;
//	printf("NHap a,b:");
//	scanf("%d%d",&a,&b);
//	printf("\nUSCLN theo de quy: = %d", USCLN1(a,b));
//	printf("\nUSCLN khong de quy: = %d", USCLN2(a,b));
//	getch();
//}