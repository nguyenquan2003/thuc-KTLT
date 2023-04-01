#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void nhap(int a[][50], int& dong, int& cot)
{
	do
	{
		cout << "cho biet so dong cua mang : ";
		cin >> dong;
	} while (dong <= 0);
	do
	{
		cout << "cho biet so cot cua mang : ";
		cin >> cot;
	} while (cot <= 0);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "Gia tri phan tu a " << "[" << i << "]" << "[" << j << "] =";
			cin >> a[i][j];

		}
	}
}
void xuat(int a[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << "\t" << a[i][j];
		cout << endl;
	}
}
void xuat_cot_so_le(int a[][50], int dong, int cot)
{
	for (int i = 0; i < cot; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 != 0)
				cout << a[i][j]<<" ";
		}
	}
}
int tim_ptu_bien(int arr[][50], int dong, int cot)
{
	int max = arr[0][0];
	for (int i = 0; i < cot; i++)
	{
		if (max < arr[0][i])
		{
			max = arr[0][i];
		}
		if (max < arr[dong - 1][i])
		{
			max = arr[dong - 1][i];
		}
		for (int i = 1; i < dong - 1; i++)
		{
			if (max < arr[i][0])
			{
				max = arr[i][0];
			}
			if (max < arr[i][cot - 1])
			{
				max < arr[i][cot - 1];
			}
		}
	}
	return max;
}
void sap_xep_dong(int a[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			for(int k = j + 1; k < cot; k++)
			{
				if (i % 2 == 0)
				{
					if(a[i][j]>a[i][k])
					{
						swap(a[i][j], a[i][k]);
					}
				}
				else
				{
					if (a[i][j], a[i][k])
					{
						swap(a[i][j], a[i][k]);
					}
				}
			}
		}
	}
}
void sap_xep_cot(int a[][50], int dong, int cot)
{
	for (int i = 0; i < cot; i++)
	{
		for (int j = 0; j < dong - 1; j++)
		{
			for (int k = j + 1; k < dong; k++)
			{
				if (i % 2 == 0)
				{
					if (a[j][i] < a[k][i])
					{
						swap(a[j][i], a[k][i]);
					}
				}
				else
				{
					if (a[j][i] > a[k][i])
					{
						swap(a[j][i], a[k][i]);
					}
				}
			}
		}
	}
} 
void ma_tran_ziczac(int a[][50], int dong, int cot)
{
	int dem = 1;
	for (int i = 0; i < dong; i++)
	{
		// Với mỗi dòng chẵn, dem sẽ được gán vào từng phần tử của các cột từ trái sang phải
		if (i % 2 == 0)
		{
			for (int j = 0; j < cot; j++)
			{
				a[i][j] = dem++;
			}
		}
		// Với mỗi dòng lẻ, dem sẽ được gán vào từng phần tử của các cột từ phải sang trái
		else
		{
			for (int j = cot - 1; j >= 0; j--)
			{
				a[i][j] = dem++;
			}
		}
	}
}
void liet_ke_chan(int a[][50], int dong, int cot)
{
	for (int i = 0; i < cot ; i++)
	{
		for (int j = 0; j < dong; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				cout << a[i][j];
			}
		}
	}
}
void liet_ke_dong_giam(int a[][50], int dong, int cot)
{
	int flag = 1;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot - 1; j++)
		{
			if (a[i][j] < a[i][j + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "dong " << a[i] << " giam ";
		}
	}
}
int dem_so_lan(int a[][50], int dong, int cot, int x)
{
    int temp = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] == x)
            {
                temp++;
            }
        }
    }
    return temp;
}
int tim_gtri(int a[][50], int dong, int cot)
{
    int temp1, temp = dem_so_lan(a, dong, cot, a[0][0]), index1 = 0, index2 = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            temp1 = dem_so_lan(a, dong, cot, a[i][j]);
            if (temp < temp1)
            {
                temp = temp1;
                index1 = i;
                index2 = j;
            }
        }
    }
    return a[index1][index2];
}
void tach(int n, int b[])
{
	int chuso;
	n = abs(n);
	do
	{
		chuso = n % 10;
		b[chuso]++;
		n /= 10;
	} while (n > 0);
}
void tim_chu_so(int a[][50], int dong, int cot)
{
	int b[50];
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			tach(a[i][j], b);
		}
	}
	int chuso = 0;
	for (int i = 0; i < 50; i++)
	{
		if (b[chuso] < b[i])
		{
			chuso = i;
		}
	}
	cout << "cac chu so xuat hien nhieu nhat : ";
	for (int i = 0; i < 10; i++)
	{
		if (b[chuso] == b[i])
		{
			cout << i << " ";
		}
	}
}
void liet_ke_tong(int a[][50], int dong, int cot)
{
	int b[50] = { 0 };
	for (int i = 0; i < cot; i++)
	{
		for (int j = 0; j < dong; j++)
		{
			b[i] += a[j][i];
		}
	}
	// Tổng min
	int Min = b[0];
	for (int i = 1; i < cot; i++)
	{
		Min = (Min < b[i]) ? Min : b[i];
	}
	//Liet ke Tong Min 
	for (int i = 0; i < cot; i++)
	{
		if (Min == b[i])
		{
			cout << "cot " << i << " co tong ptu nho nhat la : " << Min;
		}
	}
}
void hoan_vi(int a[][50], int dong, int cot,int cot1,int cot2)
{
	if ((cot1 >= 0 && cot1 < cot) && (cot2 >= 0 && cot2 < cot))
	{
		for (int i = 0; i < dong; i++)
		{
			swap(a[i][cot1], a[i][cot2]);
		}
	}
}
void main()
{
	int chon, dong, cot, a[50][50],cot1,cot2;
	cout << "========================MENU======================== " << endl;
	cout << "1. Xuat cac cot chua so le " << endl;
	cout << "2. Tim ptu lon nhat tren bien " << endl;
	cout << "5. Sap xep le tang dan chan giam dan theo dong " << endl;
	cout << "6. Sap xep le giam dan chan tang dan theo cot " << endl;
	cout << "7. Kiem tra ma tran giam dan theo dong va cot (ziczac) " << endl;
	cout << "8. Liet ke cac dong chua gia tri chan " << endl;
	cout << "9. Liet ke cac dong chua gtri giam dan " << endl;
	cout << "10. Tim gtri xuat hien nhieu nhat " << endl;
	cout << "11. Tim chu so xuat hien nhieu nhat " << endl;
	cout << "12. Liet ke cot co tong ptu nho nhat " << endl;
	cout << "13. Hoan vi cot i va j " << endl;
	cout << "------------------------------------------------------------"<<endl;
	cout << "moi bn chon bai : ";
	cin >> chon;
	nhap(a, dong, cot);
	cout << "\nNoi dung cua mang la: \n";
	xuat(a, dong, cot);
	switch (chon)
	{
	case 1: cout << "cac cot chua so le la : ";
		xuat_cot_so_le(a, dong, cot); 
		break;
	case 2: cout<<"phan tu bien lon nhat la : "<<tim_ptu_bien(a, dong, cot);
		break;
	case 5: cout << "mang sau khi sap xep dong : " << endl;
		sap_xep_dong(a, dong, cot);
		xuat(a, dong, cot);
		break;
	case 6:cout << "mang sau khi sap xep cot : " << endl;
		sap_xep_cot(a, dong, cot);
		xuat(a, dong, cot);
		break;
	case 7: ma_tran_ziczac(a, dong, cot);
		cout << "mang sau khi sap xep theo ziczac la : " << endl;
		xuat(a, dong, cot);
		break;
	case 8: liet_ke_chan(a, dong, cot); 
		break;
	case 9: liet_ke_dong_giam(a, dong, cot);
		break;
	case 10: cout <<"gia tri xuat hien nhieu nhat la : " <<tim_gtri(a, dong, cot);
		break;
	case 11: tim_chu_so(a, dong, cot);
		break;
	case 12: liet_ke_tong(a, dong, cot);
		break;
	case 13: cout << "nhap cot 1 : ";
		cin >> cot1;
		cout << "nhap cot 2 : ";
		cin >> cot2;
		hoan_vi(a, dong, cot, cot1, cot2);
		cout << "ma tran sau khi hoan vi : " << endl;
		xuat(a, dong, cot);
		break;
	default: cout << "Ban nhap sai cu phap. Vui long nhap lai ";
		break;
	}
}
