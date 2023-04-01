#include <iostream>
#include <cmath>
using namespace std;
double bai1(int n)
{
	if (n == 1)
		return 1/6.0;
	return bai1(n-1) +1/( n * (n + 1) * (n + 2));
}
float bai2(int n)
{
	if (n == 1)
		return 1;
	return bai2(n-1)+n*n;
}
int bai3(int n)
{
	if (n == 1)
		return 1;
	int tich = 1;
	for (int i = 1; i <= n; i++)
	{
		tich *= i;
	}
	return bai3(n - 1) + tich;
}
int fibo(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return (n - 1) + (n - 2);
		return fibo(n - 1) + fibo(n - 2);
}
int cap_so_nhan(int a,int n,int q)
{
	if(n==1)
	return a;
	int un_1=a;//<=> u1=a
	int un;// u2
	for(int i=2;i<=n;i++)
	{
		un=q*un_1;
		un_1=un;
	}
	return un;
}
int bai_18(int n)
{
	if(n==0)
	return 1;
	else if(n==1)
	return 2;
	else
	{
		int tg=0;
		for(int i=0;i<n;i++)
		{
			tg=tg+(n-1)*bai_18(i);
		}
		return tg;
	}
}
int bai_17(int n)
{
	int x1=1,x2=1;
	{
		for(int i=3;i<=n;i++)
		{
			x1=x1+x2;
			x2=x1-x2;
		}
	}
	cout<<"so trong khoang la : "<<x1<<endl;
	return 0;
}
int bai16_de_qui(int n)
{
	if(n==1)
	return 1;
	if(n==2)
	return 2;
	if(n==3)
	return 3;
	return bai16_de_qui(n-1)+2*bai16_de_qui(n-2)+3*bai16_de_qui(n-3);
}
int bai16_khu_de_qui(int n)
{
	if(n==1)
	return 1;
	if(n==2)
	return 2;
	if(n==3)
	return 3;
	int y1=1,y2=2,y3=3;
	int yn=y3+2*y2+3*y1;
	for(int i=4;i<=n;i++)
	{
		yn=y3+2*y2+3*y1;
		y1=y2;
		y2=y3;
		y3=yn;
	}
	return yn;
}
int main()
{
	int n,m, chon;
	cout << "moi ban chon bai : ";
	cin >> chon;
	switch (chon)
	{
	case 1: cout<<"nhap n : ";
		cin>>n;
		cout << "S = "<<bai1(n);
		break;
	case 2: cout << "nhap n : ";
		cin >> n;
		cout << "S = " << bai2(n);
		break;
	case 3: cout << "nhap n : ";
		cin >> n;
		cout << "S = " << bai3(n);
		break;
	case 10: cout << "nhap m : ";
		cin >> m;
		cout << "nhap n : ";
		cin >> n;
		for (int i = m; i <= n; i++)
		{
			cout << fibo(i) << " ";
		}
		break;
	case 13: int a,m,q;
		cout<<"nhap so hang dau : ";
		cin>>a;
		cout<<"nhap n : ";
		cin>>n;
		cout<<"nhap cong boi : ";
		cin>>q;
		cout<<"gia tri cua cap so nhan la : "<<cap_so_nhan(a,n,q);
		break;
	case 16: cout<<"nhap n : ";
		cin>>n;
		cout<<"ket qua cua de qui : "<<bai16_de_qui(n)<<endl;
		cout<<"ket qua cua khu de qui : "<<bai16_khu_de_qui(n);
		break;
	case 17: cout<<"nhap n : ";
		cin>>n;
		bai_17(n);
		break;
	case 18: cout<<"nhap n : ";
		cin>>n;
		cout<<"gia tri cong thuc truy hoi : "<<bai_18(n);
		break;
	default: cout<<"ban nhap sai cu phap. Vui long nhap lai ";
		break;
	}

}
