//#include<conio.h>
//#include<stdio.h>
//void nhapmang(int a[],int &n)
//{
//	int i;
//	for(i=0;i<n;i++)
//	{
//		printf("NHap phan tu mang: ");
//		scanf("%d",&a[i]);
//	}
//}
//void xuatmang(int a[], int n)
//{
//	printf("\nXuat mang: ");
//	for(int i=0;i<n;i++)
//		printf("%d  ",a[i]);
//}
//int tong(int a[],int n)
//{
//	
//	if(n==1)
//		return a[0];
//
//	else
//	return a[n-1]+tong(a,n-1);
//	
//}
//int A(int a[],int n)//tong chan
//{
//	int tong=0;
//	if(n<1)
//		return 0;
//	if(a[n-1]%2==0)
//		tong+=a[n-1];
//	tong+=A(a,n-1);
//	return tong;
//}
//int  BinarySearch(int a[],int l,int r,int x)
//{
//	if(r>=l)
//	{	
//	int m=(l+r)/2;
//	if (a[m]==x) return m;
//	if ( x <a[m]) return BinarySearch(a,l,m-1,x);
//	if (x > a[m]) return BinarySearch(a,m+1,r,x);
//         
//	}
//	 return -1;
//}
//int Max(int a,int b)
//{
//	return a>b?a:b;
//}
//int C(int a[],int n)//max chan
//{
//	int max;
//	if(n<1)
//		return -1;
//	if(a[n-1]%2==0)
//		max=a[n-1];
//	max=Max(C(a,n-1),max);
//	return max;
//}
//int D(int a[],int n)//tong le
//{
//	int tong=0;
//	if(n<1)
//		return 0;
//	if(a[n-1]%2!=0)
//		tong+=a[n-1];
//	tong+=D(a,n-1);
//	return tong;
//}
//void xuatle(int a[],int n)
//{
//	if(n<1)
//		return;
//	if((n-1)%2!=0)
//		printf("%d  ",a[n-1]);
//	xuatle(a,n-1);
//}
//void main()
//{
//	int a[20];
//
//	int n,Tong;
//	printf("NHap n: ");
//	scanf("%d",&n);
//	nhapmang(a,n);
//	xuatmang(a,n);
//	Tong=A(a,n);
//	printf("\n tong cac phan tu mang: %d",Tong);
//	Tong=D(a,n);
//	printf("\n tong cac phan tu mang: %d",Tong);
//	printf("\n Xuat le: ");
//	xuatle(a,n);
//	//printf("\n Max chan: %d",C(a,n));
//	getch();
//}