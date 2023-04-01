#include <iostream>
using namespace std;
void nhap(int a[50],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << "A[" << i << "]=";
		cin >> a[i];
    }
}
void xuat(int a[50],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void tich(int a[50],int n)
{
    int tich=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            tich=tich*a[i];
        }
    }
    cout<<"tich cac so chan la : "<<tich;
}
int de_qui(int n)
{
    if(n==1)
    return 1;
    return de_qui(n-1)*n;
}
int kt(int a)
{
    while (a>0)
    {
        int b=a%10;
        if(b==4)
        return 1;
        a=a/10;
    }
    return -1;
}
int xuat_so_bon(int a[50],int n)
{
    int d=-1;
    for(int i=0;i<n;i++)
    {
        if(kt(a[i])==1)
        {
            d=1;
            cout<<a[i]<<" ";
        }
    }
    return d;
}
int fibo(int n)
{
    if(n==1)
    return 1;
    if(n==2)
    return fibo(n-1)+fibo(n-2);
}
int tinh_tong(int a[50],int n)
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
       if (a[i]> 0) 
        {
            if(a[i]%2==0)
            {
                tong=tong+a[i];
            }
        }
    }
    cout<<"tong cac so nguyen duong chan la : "<<tong;
}
int main()
{
    int chon,a[50],n,b,m;
    cout<<"moi bn chon bai : ";
    cin>>chon;
    switch (chon)
    {
    case 1:cout<<"nhap n phan tu : ";
    cin>>n;
    nhap(a,n);
    cout<<"mang vua nhap la : ";
    xuat(a,n);
    cout<<endl;
    tich(a,n);
        break;
    case 2: cout<<"nhap n phan tu : ";
    cin>>n;
    nhap(a,n);
    cout<<"mang vua nhap la : ";
    xuat(a,n);
    cout<<endl;
    cout<<"mang co chua tat ca chu so 4 la : ";
    xuat_so_bon(a,n);
        break;
    case 3: cout<<"nhap n : ";
    cin>>b;
    cout<<"ket qua la : "<<de_qui(n);
        break;
    case 4: cout<<"nhap m : ";
        cin>>m;
        cout<<"nhap n : ";
        cin>>n;
        cout<<"cac so le thuoc doan : ";
        for(int i=m;i<=n;i++)
        {
            if(fibo(i)%2!=0)
            {
                cout<<fibo(i)<<" ";
            }
        }
        break;
    case 5: cout<<"nhap n phan tu : ";
    cin>>n;
    nhap(a,n);
    cout<<"mang vua nhap la : ";
    xuat(a,n);
    cout<<endl;
    tinh_tong(a,n);
    break;
    default: cout<<"ban nhap sai cu phap. Vui long nhap lai ";
        break;
    }
}