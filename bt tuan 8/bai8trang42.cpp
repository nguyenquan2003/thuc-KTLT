#include <iostream>
#include <cmath>
using namespace std;
int tim_so_dau_tien(int n) //bai 1
{
        int temp;
        do
        {
                temp=n%10;
                n=n/10;
        } while (n>0);
        return temp;
}
int tim_so_dao_nguoc(int n) //bai 2
{
        int temp=0;
        while (n>0)
        {
                temp=temp*10+n%10;
                n=n/10;
        }
        return temp;
}
int tim_so_max(int n) //bai 3
{
        int max=0,temp;
        if(n==0)
        return 0;
        n=abs(n);
        while (n>0)
        {
                temp=n%10;
                n=n/10;
               if (temp>max)
               {
                       max=temp;
               }
        }
        return max;
}
int tim_so_min(int n)
{
        int temp,min=0;
        while(n>0)
        {
                temp=n%10;
                if(temp<min)
                {
                        min=temp;
                }
                n=n/10;
        }
        cout<<temp;
        return min;
}
bool kt_chan(int n)
{
        int temp;
        while (n>0)
        {
                temp=n%10;
                if(temp%2==1)
                {
                        return false;
                }
                n=n/10;
        }
        return true;
}
bool kt_le(int n)
{
        int temp;
        while (n>0)
        {
                temp=n%10;
                if(temp%2!=1)
                {
                        return false;
                }
                n=n/10;
        }
        return true;
        
}
int main()
{
        int n,chon;
        cout<<"moi bn chon bai : ";
        cin>>chon;
        cout<<"nhap n : ";
        cin>>n;
        switch (chon)
        {
        case 1: cout<<"chu so dau tien la : "<<tim_so_dau_tien(n);
        break;
        case 2: cout<<"chu so dao nguoc la : "<<tim_so_dao_nguoc(n);
        break;
        case 3: cout<<"chu so lon nhat la : "<<tim_so_max(n);
        break;
        case 4: cout<<"chu so nho nhat la : ";
        tim_so_min(n);
        break;
        case 5: if(kt_chan(n)==true)
        cout<<"toan so chan ";
        else
        cout<<"khong co so chan ";
        break;
        case 6: if(kt_le(n)==true)
        cout<<"toan so le ";
        else 
        cout<<"khong co so le ";
        break;
        default: cout<<"ban nhap sai cu phap. Vui long nhap lai . ";
                break;
        }
}