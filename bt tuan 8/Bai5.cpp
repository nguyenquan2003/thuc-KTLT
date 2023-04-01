//#include  <stdio.h>
//#include  <conio.h>
//#include  <stdlib.h>
//#define MAX 100
//#define TRUE 1
//#define FALSE 0
//int P[MAX], B[MAX], n, count = 0;
//void Init(void)
//{
//	 int i;
//	 printf("\n Nhap n="); 
//	 scanf("%d", &n);
//	 for (i = 1; i <= n; i++)
//	 B[i] = TRUE;
//}
//
//void Result(void)
//{
//	 int i; count++;
//	 printf("\n Hoan vi thu %d:", count);
//	 for (i = 1; i <= n; i++)
//	 printf("%3d", P[i]);
// // getch();
//
//}
//
//void Try(int i)
//{
//	 int j;
//	 for (j = 1; j <= n; j++)
//	 {
//		 if (B[j]) 
//		 {
//			 P[i] = j;
//			 B[j] = FALSE;
//			 if (i == n) 
//				 Result();
//			 else 
//				 Try(i + 1);
//			 B[j] = TRUE;
//		 }
//	 }
// }
//
//void main(void)
//{
//	 Init();
//	 Try(1);
//	 getch();
//}