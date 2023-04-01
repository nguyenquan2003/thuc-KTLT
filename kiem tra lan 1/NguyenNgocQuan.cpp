#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;
void nhap_mang(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i << "]=";
        cin >> b[i];
    }
}
void xuat_mang(int b[], int n)
{
    cout << "mang vua nhap la : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}
void nhap(int* a, int& n)
{
    a = (int*)malloc(10 * sizeof(int));
    n = 10;
    for (int i = 0; i < n; i++)
        *(a + i) = rand() % 100;
}
void xuat(int* a, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "phan tu co gia tri " << *(a + i) << " va dia chi o nho la : " << a + i << endl;
    }
}
int TimViTriChanDau(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            return i;
        }
    }
    return -1;
}
int TimLeLonNhat(int* a, int n)
{
    int LeMax = *a;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0 && a[i] > LeMax)
        {
            a[i] = LeMax;
        }
    }
    return LeMax;
}
void random(int arr[][50], int& dong, int& cot)
{
    do
    {
        cout << "nhap so dong : ";
        cin >> dong;
    } while (dong < 0 || dong>100);
    do
    {
        cout << "nhap so cot : ";
        cin >> cot;
    } while (cot < 0 || cot>100);
    srand((int)time(0));
    for (int i = 0; i < dong; i++)
        for (int j = 0; j < cot; j++)
        {
            arr[i][j] = rand() % 100;
        }
}
void nhap_ma_tran(int arr[][50], int& dong, int& cot)
{
    do
    {
        cout << "nhap so dong cua mang : ";
        cin >> dong;
    } while (dong <= 0);
    do
    {
        cout << "nhap so cot cua mang : ";
        cin >> cot;
    } while (cot <= 0);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "gia tri phan tu a " << "[" << i << "]" << "[" << j << "] =";
            cin >> arr[i][j];
        }
    }
}
void xuat_ma_tran(int arr[][50], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
            cout << "\t" << arr[i][j];
        cout << endl;
    }
}
void LietKe(int arr[][50], int dong, int cot)
{
    int flag;
    for (int i = 0; i < dong; i++)
    {
        flag = 1;
        for (int j = 0; j < cot; j++)
        {
            if (arr[i][j] % 2 != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cout<<"Dong "<<i<< " toan chan ";
        }
    }
}
long max_bien(int arr[][50], int dong, int cot)
{
    int max = arr[0][0];
    for (int i = 0; i < cot; i++)
    {
        if (max < arr[0][i])
            max = arr[0][i];
        if (max < arr[dong - 1][i])
            max = arr[dong - 1][i];
    }
    for (int i = 1; i < dong - 1; i++)
    {
        if (max < arr[i][0])
            max = arr[i][0];
        if (max < arr[i][cot - 1])
            max < arr[i][cot - 1];
    }
    return max;
}
struct SanPham
{
    string manv, hoten, phong;
    long luongcoban, thuong;
};
struct danhsachSP
{
    SanPham sanpham[50];
    int n = 6;
};
void docFile(danhsachSP& sp)
{
    ifstream file;
    file.open("data.txt", ios::in);
    file >> sp.n;
    for (int i = 0; i < sp.n; i++)
    {
        getline(file, sp.sanpham[i].manv, '#');
        getline(file, sp.sanpham[i].hoten, '#');
        getline(file, sp.sanpham[i].phong, '#');
        file >> sp.sanpham[i].luongcoban, '#';
        file.seekg(1, 1);
        file >> sp.sanpham[i].thuong;
    }
    file.close();
}
void in_1_sp(SanPham sp)
{
    cout << sp.manv;
    cout << sp.hoten;
    cout << sp.phong;
    cout << sp.luongcoban;
    cout << sp.thuong << endl;
}
void inDSSP(danhsachSP dssp)
{
    for (int i = 0; i < dssp.n; i++)
    {
        in_1_sp(dssp.sanpham[i]);
        cout << "----------------------------------\n";
    }
}
void tinhthuclinh(danhsachSP dssp)
{
    for (int i = 0; i < dssp.n; i++)
    {
        long thuclinh = dssp.sanpham[i].luongcoban + dssp.sanpham[i].thuong;
        in_1_sp(dssp.sanpham[i]);
        cout << "Thuc linh : " << thuclinh << endl;
        cout << "----------------------------------\n";
    }
}
int main()
{
    int* a = new int, n = 0;
    int* c = new int;
    int b[50], dong, cot, arr[50][50];;
    int chon;
    danhsachSP dssp;
    cout << "=========================MENU========================= "<<endl;
    cout << "1. Tao va xuat mang a chua gia tri ngau nhien trong mang " << endl;
    cout << "2. Xuat gia tri va dia chi cac pty cua mang a " << endl;
    cout << "3. Tim ptu le lon nhat trong mang a " << endl;
    cout << "4. Tao va xuat mang a chua gia tri ngau trong ma tran " << endl;
    cout << "5. Liet ke chi so cac dong chua toan gia tri chan trong ma tran " << endl;
    cout << "6. Tim ptu lon nhat tren bien cua ma tran " << endl;
    cout << "7. Doc du lieu tu file " << endl;
    cout << "8. Xuat thong tin danh sach va tinh thuc linh " << endl;
    cout << "Moi ban chon bai : ";
    cin >> chon;
    switch (chon)
    {
    case 1: int ptu;
        cout << "nhap n phan tu : ";
        cin >> ptu;
        nhap_mang(a, n);
        xuat_mang(a, n);
        break;
    case 2: nhap(a, n);
        xuat(a, n);
        break;
    case 3: cout << "nhap n phan tu : ";
        cin >> n;
        nhap(b, n);
        xuat(a, n);
        cout << "so chan nho nhat trong mang la : " << TimLeLonNhat(a, n);
        break;
    case 4: random(arr, dong, cot);
        cout << "\nNoi dung cua mang \n ";
        xuat_ma_tran(arr, dong, cot);
        break;
    case 5: nhap_ma_tran(arr, dong, cot);
        cout << "\nNoi dung cua mang \n ";
        xuat_ma_tran(arr, dong, cot);
        LietKe(arr, dong, cot);
        break;
    case 6: nhap_ma_tran(arr, dong, cot);
        cout << "\nNoi dung cua mang \n ";
        xuat_ma_tran(arr, dong, cot);
        cout<<"phan tu lon nhat tren bien la : "<<max_bien(arr, dong, cot);
        break;
    case 7: docFile(dssp);
        return 0;
        break;
    case 8: docFile(dssp);
        tinhthuclinh(dssp);
        break;
    default:cout << "Ban nhap sai cu phap. Vui long nhap lai ";
        break;
    }
}