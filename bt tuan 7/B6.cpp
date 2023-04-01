#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<math.h>
int Dem(int n)
{
	if(n<10)
		return 1;
	return 1+Dem(n/10) ; 
	 

}
int Dem1(int n)
{
	int dem=0;
    while(n>0)
	{
		dem++;
        n/=10; 
        
    }
	return dem;
}
void main()
{
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	printf("\n Gia tri cong thuc truy hoi: %d",Dem(n));
	printf("\n Gia tri cong thuc truy hoi: %d",Dem1(n));
	getch();
}